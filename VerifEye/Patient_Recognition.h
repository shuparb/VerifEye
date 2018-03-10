#pragma once

#include <QWidget>
#include <qmessagebox.h>
#include <qlabel.h>
#include <qgraphicsscene.h>
#include "recog.h"
#include "patient.h"
#include "modnn.h"
#include "Patient_Repeats.h"
namespace Ui { class Patient_Recognition; };

class Patient_Recognition : public QWidget
{
	Q_OBJECT

public:
	Patient_Recognition(QWidget *parent = Q_NULLPTR);
	~Patient_Recognition();
	void loadPatient(Patient*);
	void showEvent(QShowEvent*);
	void loadPreImage();
	void loadPostImage();
	void loadProfile();
	void updateLabel(QLabel*, QString);
	void loadModnn(Modnn*);

private:
	Ui::Patient_Recognition *ui;
	Patient* patient;
	Modnn* modnn;
	Recognizer recognizer;
	QGraphicsScene* pre_scene;
	QGraphicsScene* post_scene;
	Patient_Repeats* patient_repeats;

private slots:
	void on_pushButton_recog_clicked();
	void on_pushButton_same_clicked();
	void on_pushButton_different_clicked();
};
