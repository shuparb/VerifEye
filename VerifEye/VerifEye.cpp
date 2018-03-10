#include "VerifEye.h"

VerifEye::VerifEye(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	addFunctions();
	doDatabase();
}

VerifEye::~VerifEye()
{
	delete modnn;
	delete select;
	//delete show_patient;
}

void VerifEye::addFunctions()
{
	connect(ui.actionNewPatient, SIGNAL(triggered()), this, SLOT(openAdd_Patient()));
	connect(ui.actionExit_2, SIGNAL(triggered()), this, SLOT(close()));
	loadModnn();
}

void VerifEye::doDatabase()
{
	db = verifEye::Database("./main.db");
	if (db.connected) {
		doStats();
		initFill_patient_table();
	}
	db.closeDb();
}

void VerifEye::doStats()
{
	QSqlQuery num_patients;
	QString num_patients_text, num_rejected_text, num_accepted_text, num_errored_text;
	// number of patients
	num_patients = QSqlQuery(db.db);
	num_patients.prepare("select count(*) from patients");
	if (num_patients.exec())
		num_patients_text = db.getSingleValueFromQuery(num_patients);
	updateLabel(ui.num_patients_2, num_patients_text);
	// number of rejected patients
	num_patients.prepare("select count(*) from patients where "+result+"='"+verifEye::resultStrOptReject+"'");
	if (num_patients.exec())
		num_rejected_text = db.getSingleValueFromQuery(num_patients);
	updateLabel(ui.num_rejected_2, num_rejected_text);
	// number of accepted patients
	num_patients.prepare("select count(*) from patients where " + result + "='" + verifEye::resultStrOptAccept + "'");
	if (num_patients.exec())
		num_accepted_text = db.getSingleValueFromQuery(num_patients);
	updateLabel(ui.num_accepted_2, num_accepted_text);
	// number of errored patients
	num_patients.prepare("select count(*) from patients where " + result + "='" + verifEye::resultStrOptError + "'");
	if (num_patients.exec())
		num_errored_text = db.getSingleValueFromQuery(num_patients);
	updateLabel(ui.num_errored_2, num_errored_text);
}

void VerifEye::on_pushButton_refresh_clicked()
{
	QSqlQueryModel* model = new QSqlQueryModel();
	QSqlQuery query = QSqlQuery(db.db);
	query.prepare("select date,"+fnameStr+","+lnameStr+","+eidStr+","+_hnameStr+","+stateStr+","+result+" from " + patients+", "+hospitals+" where patients.hid = hospitals.hid");
	if (query.exec())
		model->setQuery(query);
	ui.patient_table->setModel(model);
	doStats();
}

//void VerifEye::on_pushButton_show_clicked()
//{
//		show_patient = new Show_Patient();
//		show_patient->load_patient(select->selectedRows().back().row());
//		show_patient->show();
//	
//}

void VerifEye::updateLabel(QLabel* label, QString appendText)
{
	QString prevtext = label->text();
	prevtext.append(appendText);
	label->repaint();
	label->setText(appendText);
}

void VerifEye::loadModnn()
{
	modnn = new Modnn();
}

void VerifEye::initFill_patient_table()
{
	QSqlQueryModel* model = new QSqlQueryModel();
	QSqlQuery query = QSqlQuery(db.db);
	query.prepare("select date," + fnameStr + "," + lnameStr + "," + eidStr + "," + _hnameStr + "," + stateStr + "," + result + " from " + patients + ", " + hospitals + " where patients.hid = hospitals.hid");
	if (query.exec())
		model->setQuery(query);
	ui.patient_table->setModel(model);
	ui.patient_table->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.patient_table->setSelectionMode(QAbstractItemView::SingleSelection);
	select = ui.patient_table->selectionModel();
}

void VerifEye::openAdd_Patient()
{
	add_patient = new Add_Patient();
	add_patient->loadModnn(modnn);
	add_patient->setWindowModality(Qt::WindowModal);
	add_patient->show();
}
