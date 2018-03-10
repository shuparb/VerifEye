#pragma once

#include <QtWidgets/QMainWindow>
#include <qmessagebox.h>
#include "modnn.h"
#include "ui_VerifEye.h"
#include "Show_Patient.h"
#include "db.h"
#include "Add_Patient.h"

using namespace verifEye;

class VerifEye : public QMainWindow
{
	Q_OBJECT

public:
	VerifEye(QWidget *parent = Q_NULLPTR);
	~VerifEye();
	void addFunctions();
	void doDatabase();
	void doStats();
	void updateLabel(QLabel*, QString);
	void loadModnn();
	void initFill_patient_table();

private:
	Modnn* modnn;
	Ui::VerifEyeClass ui;
	verifEye::Database db;
	Add_Patient* add_patient;
	QItemSelectionModel* select;
	//Show_Patient* show_patient;

private slots:
	void openAdd_Patient();
	void on_pushButton_refresh_clicked();
	//void on_pushButton_show_clicked();
};
