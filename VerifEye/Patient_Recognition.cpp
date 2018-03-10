#include "Patient_Recognition.h"
#include "ui_Patient_Recognition.h"

Patient_Recognition::Patient_Recognition(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Patient_Recognition();
	ui->setupUi(this);
}

Patient_Recognition::~Patient_Recognition()
{
	delete ui;
	delete patient;
	delete pre_scene;
	delete post_scene;
	delete modnn;
	delete patient_repeats;
}


void Patient_Recognition::loadPatient(Patient * patient)
{
	this->patient = patient;
	recognizer = Recognizer();
}

void Patient_Recognition::showEvent(QShowEvent *event)
{
	QWidget::showEvent(event);
	loadProfile();
	patient->cropPreFullRect();
	patient->cropPostFullRect();
	patient->cropPreHalfRect();
	patient->cropPostHalfRect();
	loadPreImage();
	loadPostImage();
}

void Patient_Recognition::loadPreImage()
{
	pre_scene = new QGraphicsScene();
	pre_scene->addPixmap(QPixmap::fromImage(QImage(patient->pre.halfFp)));
	ui->graphicsView_preHalf->setScene(pre_scene);
}

void Patient_Recognition::loadPostImage()
{
	post_scene = new QGraphicsScene();
	post_scene->addPixmap(QPixmap::fromImage(QImage(patient->post.halfFp)));
	ui->graphicsView_postHalf->setScene(post_scene);

}

void Patient_Recognition::loadProfile()
{
	updateLabel(ui->label_full_name, patient->get_fullname());
	updateLabel(ui->label_eid, patient->get_eid());
	updateLabel(ui->label_hospital, patient->get_hospital());
}

void Patient_Recognition::updateLabel(QLabel* label, QString append)
{
	QString prevText = label->text();
	prevText.append(append);
	label->setText(append);
}

void Patient_Recognition::loadModnn(Modnn* modnn)
{
	this->modnn = modnn;
}

void Patient_Recognition::on_pushButton_same_clicked()
{
	patient->verdictStrCont = ui->label->text();
	patient->real_verdictStrCont = "Same";
	if (patient->verdictStrCont == "Different")
		patient->resultStrCont = "error";
	else
		patient->resultStrCont = "accept";
	if (patient->saveAll())
		QMessageBox::information(this, "Data entry success!", "Patient information saved successfully!");
	else
		QMessageBox::warning(this, "Data entry failed!", "Patient information lost!");
	patient_repeats = new Patient_Repeats();
	patient_repeats->load_patient(patient);
	patient_repeats->show();
	close();
}

void Patient_Recognition::on_pushButton_different_clicked()
{
	patient->verdictStrCont = ui->label->text();
	patient->real_verdictStrCont = "Different";
	if (patient->verdictStrCont == "Same")
		patient->resultStrCont = "error";
	else
		patient->resultStrCont = "reject";
	if (patient->saveAll())
		QMessageBox::information(this, "Data entry success!", "Patient information saved successfully!");
	else
		QMessageBox::warning(this, "Data entry failed!", "Patient information lost!");
	patient_repeats = new Patient_Repeats();
	patient_repeats->load_patient(patient);
	patient_repeats->show();
	close();

}

void Patient_Recognition::on_pushButton_recog_clicked() {
	std::vector<matrix<float, 0, 1>> mat = recognizer.getMat(&patient->pre.halfFace, &patient->post.halfFace);
	double diff = length(mat[1] - mat[0]);
	patient->verdictStrCont = recognizer.getVerdict(diff);
	ui->label->setText(patient->verdictStrCont);
	ui->label_probability->setText(recognizer.getAccu(diff));
	ui->double_diff->setValue((1.2-diff)*100);
	patient->mat = mat;
}