/********************************************************************************
** Form generated from reading UI file 'Patient_Recognition.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENT_RECOGNITION_H
#define UI_PATIENT_RECOGNITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Patient_Recognition
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_fullName_head;
    QLabel *label_full_name;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_eyepatchID_head;
    QLabel *label_eid;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_hid_head;
    QLabel *label_hospital;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_resolved_head;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_preHalf_head;
    QGraphicsView *graphicsView_preHalf;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_postHalf_head;
    QGraphicsView *graphicsView_postHalf;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_recog;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_verdict_head;
    QLabel *label;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_probability_head;
    QLabel *label_probability;
    QDoubleSpinBox *double_diff;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_real_verdict_head;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_same;
    QPushButton *pushButton_different;

    void setupUi(QWidget *Patient_Recognition)
    {
        if (Patient_Recognition->objectName().isEmpty())
            Patient_Recognition->setObjectName(QStringLiteral("Patient_Recognition"));
        Patient_Recognition->resize(1332, 760);
        Patient_Recognition->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(Patient_Recognition);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_fullName_head = new QLabel(Patient_Recognition);
        label_fullName_head->setObjectName(QStringLiteral("label_fullName_head"));
        label_fullName_head->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout->addWidget(label_fullName_head);

        label_full_name = new QLabel(Patient_Recognition);
        label_full_name->setObjectName(QStringLiteral("label_full_name"));
        label_full_name->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout->addWidget(label_full_name);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_eyepatchID_head = new QLabel(Patient_Recognition);
        label_eyepatchID_head->setObjectName(QStringLiteral("label_eyepatchID_head"));
        label_eyepatchID_head->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_2->addWidget(label_eyepatchID_head);

        label_eid = new QLabel(Patient_Recognition);
        label_eid->setObjectName(QStringLiteral("label_eid"));
        label_eid->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_2->addWidget(label_eid);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_hid_head = new QLabel(Patient_Recognition);
        label_hid_head->setObjectName(QStringLiteral("label_hid_head"));
        label_hid_head->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_3->addWidget(label_hid_head);

        label_hospital = new QLabel(Patient_Recognition);
        label_hospital->setObjectName(QStringLiteral("label_hospital"));
        label_hospital->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_3->addWidget(label_hospital);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_resolved_head = new QLabel(Patient_Recognition);
        label_resolved_head->setObjectName(QStringLiteral("label_resolved_head"));
        label_resolved_head->setStyleSheet(QLatin1String("font-size: 32px;\n"
""));

        verticalLayout_3->addWidget(label_resolved_head);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_preHalf_head = new QLabel(Patient_Recognition);
        label_preHalf_head->setObjectName(QStringLiteral("label_preHalf_head"));
        label_preHalf_head->setStyleSheet(QLatin1String("font-size: 26px;\n"
""));

        verticalLayout->addWidget(label_preHalf_head);

        graphicsView_preHalf = new QGraphicsView(Patient_Recognition);
        graphicsView_preHalf->setObjectName(QStringLiteral("graphicsView_preHalf"));

        verticalLayout->addWidget(graphicsView_preHalf);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_postHalf_head = new QLabel(Patient_Recognition);
        label_postHalf_head->setObjectName(QStringLiteral("label_postHalf_head"));
        label_postHalf_head->setStyleSheet(QLatin1String("font-size: 26px;\n"
""));

        verticalLayout_2->addWidget(label_postHalf_head);

        graphicsView_postHalf = new QGraphicsView(Patient_Recognition);
        graphicsView_postHalf->setObjectName(QStringLiteral("graphicsView_postHalf"));

        verticalLayout_2->addWidget(graphicsView_postHalf);


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_3);


        verticalLayout_8->addLayout(verticalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_recog = new QPushButton(Patient_Recognition);
        pushButton_recog->setObjectName(QStringLiteral("pushButton_recog"));
        pushButton_recog->setStyleSheet(QLatin1String("font-size: 32px;\n"
""));

        horizontalLayout_8->addWidget(pushButton_recog);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(30);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(80, -1, -1, -1);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_verdict_head = new QLabel(Patient_Recognition);
        label_verdict_head->setObjectName(QStringLiteral("label_verdict_head"));
        label_verdict_head->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_6->addWidget(label_verdict_head);

        label = new QLabel(Patient_Recognition);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_6->addWidget(label);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_probability_head = new QLabel(Patient_Recognition);
        label_probability_head->setObjectName(QStringLiteral("label_probability_head"));
        label_probability_head->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_7->addWidget(label_probability_head);

        label_probability = new QLabel(Patient_Recognition);
        label_probability->setObjectName(QStringLiteral("label_probability"));
        label_probability->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_7->addWidget(label_probability);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_6->addLayout(verticalLayout_4);

        double_diff = new QDoubleSpinBox(Patient_Recognition);
        double_diff->setObjectName(QStringLiteral("double_diff"));
        double_diff->setStyleSheet(QStringLiteral("font-size: 40px;"));

        verticalLayout_6->addWidget(double_diff);


        horizontalLayout_8->addLayout(verticalLayout_6);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_10->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_real_verdict_head = new QLabel(Patient_Recognition);
        label_real_verdict_head->setObjectName(QStringLiteral("label_real_verdict_head"));
        label_real_verdict_head->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        verticalLayout_9->addWidget(label_real_verdict_head);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton_same = new QPushButton(Patient_Recognition);
        pushButton_same->setObjectName(QStringLiteral("pushButton_same"));
        pushButton_same->setStyleSheet(QLatin1String("font-size: 28px;\n"
""));

        horizontalLayout_9->addWidget(pushButton_same);

        pushButton_different = new QPushButton(Patient_Recognition);
        pushButton_different->setObjectName(QStringLiteral("pushButton_different"));
        pushButton_different->setStyleSheet(QLatin1String("font-size: 28px;\n"
""));

        horizontalLayout_9->addWidget(pushButton_different);


        verticalLayout_9->addLayout(horizontalLayout_9);


        verticalLayout_10->addLayout(verticalLayout_9);


        gridLayout->addLayout(verticalLayout_10, 0, 0, 1, 1);

        graphicsView_preHalf->raise();
        graphicsView_postHalf->raise();
        label_preHalf_head->raise();
        label_postHalf_head->raise();
        label_resolved_head->raise();
        label_verdict_head->raise();
        label_probability_head->raise();
        label->raise();
        label_full_name->raise();
        pushButton_same->raise();
        label_real_verdict_head->raise();
        pushButton_different->raise();
        label_fullName_head->raise();
        pushButton_recog->raise();
        label_probability->raise();
        label_eid->raise();
        label_eyepatchID_head->raise();
        label_hid_head->raise();
        label_hospital->raise();
        double_diff->raise();

        retranslateUi(Patient_Recognition);

        QMetaObject::connectSlotsByName(Patient_Recognition);
    } // setupUi

    void retranslateUi(QWidget *Patient_Recognition)
    {
        Patient_Recognition->setWindowTitle(QApplication::translate("Patient_Recognition", "Patient_Recognition", 0));
        label_fullName_head->setText(QApplication::translate("Patient_Recognition", "Full Name: ", 0));
        label_full_name->setText(QString());
        label_eyepatchID_head->setText(QApplication::translate("Patient_Recognition", "Eyepatch ID: ", 0));
        label_eid->setText(QString());
        label_hid_head->setText(QApplication::translate("Patient_Recognition", "HID: ", 0));
        label_hospital->setText(QString());
        label_resolved_head->setText(QApplication::translate("Patient_Recognition", "Resolved faces", 0));
        label_preHalf_head->setText(QApplication::translate("Patient_Recognition", "PRE HALF", 0));
        label_postHalf_head->setText(QApplication::translate("Patient_Recognition", "POST HALF", 0));
        pushButton_recog->setText(QApplication::translate("Patient_Recognition", "Run Recognizer", 0));
        label_verdict_head->setText(QApplication::translate("Patient_Recognition", "Verdict: ", 0));
        label->setText(QString());
        label_probability_head->setText(QApplication::translate("Patient_Recognition", "Probability: ", 0));
        label_probability->setText(QString());
        label_real_verdict_head->setText(QApplication::translate("Patient_Recognition", " Final Verdict: ", 0));
        pushButton_same->setText(QApplication::translate("Patient_Recognition", "Same", 0));
        pushButton_different->setText(QApplication::translate("Patient_Recognition", "Different", 0));
    } // retranslateUi

};

namespace Ui {
    class Patient_Recognition: public Ui_Patient_Recognition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENT_RECOGNITION_H
