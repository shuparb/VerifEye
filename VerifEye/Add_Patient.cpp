#include "Add_Patient.h"
#include "ui_Add_Patient.h"

Add_Patient::Add_Patient(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Add_Patient();
	db = Database();
	ui->setupUi(this);
	connect(ui->pushButton_cancel, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui->pushButton_PreImage, SIGNAL(clicked()), this, SLOT(openImportPreImage()));
	connect(ui->pushButton_PostImage, SIGNAL(clicked()), this, SLOT(openImportPostImage()));
	fillHospitalComboBox();
}

Add_Patient::~Add_Patient()
{
	delete patient;
	delete ui;
	delete pd;
	delete modnn;
}

void Add_Patient::loadModnn(Modnn* modnn)
{
	this->modnn = modnn;
}

void Add_Patient::openImportPreImage() {
	QString filename = QFileDialog::getOpenFileName(this, "Open Document", QDir::currentPath(), "JPG files (*.jpg)");
	ui->lineEdit_preImage->setText(filename);
}

void Add_Patient::openImportPostImage() {
	QString filename = QFileDialog::getOpenFileName(this, "Open Document", QDir::currentPath(), "JPG files (*.jpg)");
	ui->lineEdit_postImage->setText(filename);
}

void Add_Patient::fillHospitalComboBox() {
	QSqlQuery query = QSqlQuery(db.db);
	query.prepare("select hname from hospitals");
	query.exec();
	while (query.next()) {
		ui->comboBox_hospital->addItem(query.value("hname").toString());
	}
}

void Add_Patient::on_pushButton_ok_clicked() {
	QString fname, lname, preImage_path, postImage_path, eyepatch, state, hid;
	fname = ui->lineEdit_firstName->text();
	lname = ui->lineEdit_lastName->text();
	preImage_path = ui->lineEdit_preImage->text();
	postImage_path = ui->lineEdit_postImage->text();
	if (ui->radioButton_leftEyePatch->isChecked())
		eyepatch = "left";
	else if (ui->radioButton_rightEyePatch->isChecked())
		eyepatch = "right";
	else
		eyepatch = "none";
	QSqlQuery query = QSqlQuery(db.db);
	query.prepare("select hid from hospitals where hname='" + ui->comboBox_hospital->currentText() + "'");
	query.exec();
	hid = db.getSingleValueFromQuery(query);
	state = ui->lineEdit_state->text();
	// query.prepare("insert into patients (fname, lname, pre_img_path, post_img_path, eid, hid, state) values('" + fname + "','" + lname + "','" + preImage_path + "','" + postImage_path + "','" + eyepatch + "','" + hid + "','" + state + "')");
	// if (query.exec())
	// 	QMessageBox::information(this, "Database", "Insertion successfull!\ninsert into patients (fname, lname, pre_img_path, post_img_path, eid, hid, state) values('" + fname + "','" + lname + "','" + preImage_path + "','" + postImage_path + "','" + eyepatch + "'," + hid + ",'" + state + "')");
	// else
	// 	QMessageBox::warning(this, "Database", "Insertion Unsuccessfull!\ninsert into patients (fname, lname, pre_img_path, post_img_path, eid, hid, state) values('" + fname + "','" + lname + "','" + preImage_path + "','" + postImage_path + "','" + eyepatch + "'," + hid + ",'" + state + "')");
	if (patient)
		patient = 0;
	patient = new Patient(fname, lname, preImage_path, postImage_path, eyepatch, hid, state);
	close();
	pd = new Patient_Detection();
	pd->loadModnn(modnn);
	pd->loadPatient(patient);
	pd->show();
}