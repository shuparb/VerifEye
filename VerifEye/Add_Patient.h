#pragma once

#include <QWidget>
#include <qfiledialog.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qmessagebox.h>
#include "db.h"
#include "patient.h"
#include "Patient_Detection.h"

using namespace verifEye;

namespace Ui { class Add_Patient; };

class Add_Patient : public QWidget
{
	Q_OBJECT

public:
	Add_Patient(QWidget *parent = Q_NULLPTR);
	~Add_Patient();
	void loadModnn(Modnn*);

private:
	Patient* patient;
	Modnn* modnn;
	Ui::Add_Patient *ui;
	Patient_Detection* pd;
	Database db;

private slots:
	void fillHospitalComboBox();
	void openImportPreImage();
	void openImportPostImage();
	void on_pushButton_ok_clicked();
};
