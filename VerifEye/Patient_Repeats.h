#pragma once

#include <QWidget>
#include <qlabel.h>
#include <qgraphicsscene.h>
#include "patient.h"
#include "recog.h"
namespace Ui { class Patient_Repeats; };

using namespace verifEye;

class Patient_Repeats : public QWidget
{
	Q_OBJECT

public:
	Patient_Repeats(QWidget *parent = Q_NULLPTR);
	~Patient_Repeats();
	void load_patient(Patient*);
	void loadDb();
	void showEvent(QShowEvent*);
	void loadProfile();
	void updateLabel(QLabel*, QString);
	void loadPreImage();
	void loadPostImage();
	void evalPre();
	void evalPost();

private:
	Ui::Patient_Repeats *ui;
	Patient* patient;
	Database* db;
	std::vector<std::vector<matrix<float, 0, 1>>> preMat;
	std::vector<std::vector<matrix<float, 0, 1>>> postMat;
	QVector<QStringList> preList;
	QVector<QStringList> postList;
	QGraphicsScene *preHalf;
	QGraphicsScene *postHalf;
	Recognizer recognizer;
};
