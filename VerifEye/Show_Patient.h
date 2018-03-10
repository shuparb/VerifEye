#pragma once

#include <QWidget>
#include <qmessagebox.h>
#include "patient.h"
namespace Ui { class Show_Patient; };

class Show_Patient : public QWidget
{
	Q_OBJECT

public:
	Show_Patient(QWidget *parent = Q_NULLPTR);
	~Show_Patient();
	void load_patient(int);

private:
	Ui::Show_Patient *ui;
	Patient* patient;
};
