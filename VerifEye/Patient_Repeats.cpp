#include "Patient_Repeats.h"
#include "ui_Patient_Repeats.h"

Patient_Repeats::Patient_Repeats(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Patient_Repeats();
	ui->setupUi(this);
	loadDb();
}

Patient_Repeats::~Patient_Repeats()
{
	db->closeDb();
	delete ui;
	delete patient;
	delete db;
	delete preHalf;
	delete postHalf;
}

void Patient_Repeats::load_patient(Patient* patient)
{
	this->patient = patient;
}

void Patient_Repeats::loadDb()
{
	db = new Database("./main.db");
	QSqlQuery query = QSqlQuery(db->db);
	query.prepare("select pid, pre_hface_path, post_hface_path, pmat_path from patients");
	query.exec();
	while (query.next()) {
		QSqlRecord record = query.record();
		QStringList tmp;
		for (int i = 0; i < record.count(); i++) {
			tmp << record.value(i).toString();
		}
		preList.append(tmp);
		postList.append(tmp);
	}
}

void Patient_Repeats::showEvent(QShowEvent *event)
{
	QWidget::showEvent(event);
	loadDb();
	loadProfile();
	evalPre();
	evalPost();
	loadPreImage();
	loadPostImage();
	recognizer = Recognizer();
}

void Patient_Repeats::loadProfile()
{
	updateLabel(ui->label_full_name, patient->get_fullname());
	updateLabel(ui->label_eid, patient->get_eid());
	updateLabel(ui->label_hospital, patient->get_hospital());
}

void Patient_Repeats::updateLabel(QLabel* label, QString append)
{
	QString prevText = label->text();
	prevText.append(append);
	label->setText(append);
}

void Patient_Repeats::loadPreImage()
{
	preHalf = new QGraphicsScene();
	preHalf->addPixmap(QPixmap::fromImage(QImage(patient->pre.halfFp)));
	ui->graphicsView_preHalf->setScene(preHalf);
	ui->preList->setViewMode(QListWidget::IconMode);
	ui->preList->setIconSize(QSize(256, 128));
	for (QStringList a : preList) {
		ui->preList->addItem(new QListWidgetItem(QIcon(a.at(1)), a.at(0)));
	}
}

void Patient_Repeats::loadPostImage()
{
	postHalf = new QGraphicsScene();
	postHalf->addPixmap(QPixmap::fromImage(QImage(patient->post.halfFp)));
	ui->graphicsView_postHalf->setScene(postHalf);
	ui->postList->setViewMode(QListWidget::IconMode);
	ui->postList->setIconSize(QSize(256, 128));
	for (QStringList a : postList) {
		ui->postList->addItem(new QListWidgetItem(QIcon(a.at(2)), a.at(0)));
	}
}

void Patient_Repeats::evalPre()
{
	std::vector<matrix<float, 0, 1>> mat;
	for (int i = 0; i < preList.size();i++) {
		deserialize(preList[i].at(3).toStdString()) >> mat;
		if (length(mat[0] - patient->mat[0]) > 0.63) {
			preList.removeAt(i);
		}
	}
}

void Patient_Repeats::evalPost()
{
	std::vector<matrix<float, 0, 1>> mat;
	for (int i = 0; i < postList.size(); i++) {
		deserialize(postList[i].at(3).toStdString()) >> mat;
		if (length(mat[1] - patient->mat[1]) > 0.63) {
			postList.removeAt(i);
		}
	}
}
