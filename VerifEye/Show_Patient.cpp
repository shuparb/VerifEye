#include "Show_Patient.h"
#include "ui_Show_Patient.h"

Show_Patient::Show_Patient(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::Show_Patient();
	ui->setupUi(this);
}

Show_Patient::~Show_Patient()
{
	delete patient;
	delete ui;
}

void Show_Patient::load_patient(int id)
{
	patient = new Patient(id);
	QMessageBox::information(this, "hello", "HELLO" + patient->fnameStrCont);
}
