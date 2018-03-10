#pragma once

#include <QWidget>
#include <patient.h>
#include <qmessagebox.h>
#include <qlabel.h>
#include <qtextedit.h>
#include <qmessagebox.h>
#include <qsplashscreen.h>
#include "Patient_Recognition.h"
#include "detector.h"
#include "landmark.h"
#include "ui_Patient_Detection.h"
#include "modnn.h"

using namespace verifEye;

class Patient_Detection : public QWidget
{
	Q_OBJECT

public:
	Patient_Detection(QWidget *parent = Q_NULLPTR);
	void loadPatient(Patient* patient);
	void showEvent(QShowEvent*);
	void loadProfile();
	void loadPreImage();
	void loadPostImage();
	void doProc(QWidget*);
	void detectPreImage();
	void detectPostImage();
	void detectEyepatch();
	void detectPreLandmark();
	void detectPostLandmark();
	void rotatePre();
	void rotatePost();
	void updatePreInfo();
	void updatePostInfo();
	void updatePreDraw();
	void updatePostDraw();
	void clearPlots();
	void loadModnn(Modnn*);
	void updateLabel(QLabel*, QString);
	void updateTextEdit(QTextEdit*, QString);
	QRectF getPoint(int x, int y);

	~Patient_Detection();

private:
	Patient* patient;
	Ui::Patient_Detection* ui;
	QGraphicsScene* pre_scene;
	QGraphicsScene* post_scene;
	Patient_Recognition* pr;
	Detector detector;
	Landmark landmark;
	QString detected_eid;
	QSplashScreen* flash;
	Modnn* modnn;
	int j = 0;


private slots:
	void on_pushButton_task_clicked();
	void on_pushButton_recog_clicked();
	void on_graphicsView_preImage_clicked();
	void on_pushButton_preELA_clicked();
	void on_pushButton_postELA_clicked();
};
