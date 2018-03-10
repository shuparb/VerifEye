/********************************************************************************
** Form generated from reading UI file 'Patient_Repeats.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENT_REPEATS_H
#define UI_PATIENT_REPEATS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Patient_Repeats
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_fullName_head;
    QLabel *label_full_name;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_eyepatchID_head;
    QLabel *label_eid;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_hid_head;
    QLabel *label_hospital;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_postHalf_head;
    QGraphicsView *graphicsView_preHalf;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_preHalf_head;
    QGraphicsView *graphicsView_postHalf;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QListWidget *preList;
    QPushButton *pushButton_preView;
    QVBoxLayout *verticalLayout_3;
    QListWidget *postList;
    QPushButton *pushButton_postView;

    void setupUi(QWidget *Patient_Repeats)
    {
        if (Patient_Repeats->objectName().isEmpty())
            Patient_Repeats->setObjectName(QStringLiteral("Patient_Repeats"));
        Patient_Repeats->resize(1505, 811);
        gridLayout = new QGridLayout(Patient_Repeats);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_fullName_head = new QLabel(Patient_Repeats);
        label_fullName_head->setObjectName(QStringLiteral("label_fullName_head"));
        label_fullName_head->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_3->addWidget(label_fullName_head);

        label_full_name = new QLabel(Patient_Repeats);
        label_full_name->setObjectName(QStringLiteral("label_full_name"));
        label_full_name->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_3->addWidget(label_full_name);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_eyepatchID_head = new QLabel(Patient_Repeats);
        label_eyepatchID_head->setObjectName(QStringLiteral("label_eyepatchID_head"));
        label_eyepatchID_head->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_5->addWidget(label_eyepatchID_head);

        label_eid = new QLabel(Patient_Repeats);
        label_eid->setObjectName(QStringLiteral("label_eid"));
        label_eid->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_5->addWidget(label_eid);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_hid_head = new QLabel(Patient_Repeats);
        label_hid_head->setObjectName(QStringLiteral("label_hid_head"));
        label_hid_head->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_4->addWidget(label_hid_head);

        label_hospital = new QLabel(Patient_Repeats);
        label_hospital->setObjectName(QStringLiteral("label_hospital"));
        label_hospital->setStyleSheet(QLatin1String("font-size: 32px;\n"
"background-color: #c4c4c4;"));

        horizontalLayout_4->addWidget(label_hospital);


        horizontalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_6);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_postHalf_head = new QLabel(Patient_Repeats);
        label_postHalf_head->setObjectName(QStringLiteral("label_postHalf_head"));
        label_postHalf_head->setStyleSheet(QLatin1String("font-size: 26px;\n"
""));

        verticalLayout->addWidget(label_postHalf_head);

        graphicsView_preHalf = new QGraphicsView(Patient_Repeats);
        graphicsView_preHalf->setObjectName(QStringLiteral("graphicsView_preHalf"));

        verticalLayout->addWidget(graphicsView_preHalf);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_preHalf_head = new QLabel(Patient_Repeats);
        label_preHalf_head->setObjectName(QStringLiteral("label_preHalf_head"));
        label_preHalf_head->setStyleSheet(QLatin1String("font-size: 26px;\n"
""));

        verticalLayout_2->addWidget(label_preHalf_head);

        graphicsView_postHalf = new QGraphicsView(Patient_Repeats);
        graphicsView_postHalf->setObjectName(QStringLiteral("graphicsView_postHalf"));

        verticalLayout_2->addWidget(graphicsView_postHalf);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        preList = new QListWidget(Patient_Repeats);
        preList->setObjectName(QStringLiteral("preList"));

        verticalLayout_4->addWidget(preList);

        pushButton_preView = new QPushButton(Patient_Repeats);
        pushButton_preView->setObjectName(QStringLiteral("pushButton_preView"));

        verticalLayout_4->addWidget(pushButton_preView);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        postList = new QListWidget(Patient_Repeats);
        postList->setObjectName(QStringLiteral("postList"));

        verticalLayout_3->addWidget(postList);

        pushButton_postView = new QPushButton(Patient_Repeats);
        pushButton_postView->setObjectName(QStringLiteral("pushButton_postView"));

        verticalLayout_3->addWidget(pushButton_postView);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_5);


        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);


        retranslateUi(Patient_Repeats);

        QMetaObject::connectSlotsByName(Patient_Repeats);
    } // setupUi

    void retranslateUi(QWidget *Patient_Repeats)
    {
        Patient_Repeats->setWindowTitle(QApplication::translate("Patient_Repeats", "Patient_Repeats", 0));
        label_fullName_head->setText(QApplication::translate("Patient_Repeats", "Full Name: ", 0));
        label_full_name->setText(QString());
        label_eyepatchID_head->setText(QApplication::translate("Patient_Repeats", "Eyepatch ID: ", 0));
        label_eid->setText(QString());
        label_hid_head->setText(QApplication::translate("Patient_Repeats", "HID: ", 0));
        label_hospital->setText(QString());
        label_postHalf_head->setText(QApplication::translate("Patient_Repeats", "POST HALF", 0));
        label_preHalf_head->setText(QApplication::translate("Patient_Repeats", "PRE HALF", 0));
        pushButton_preView->setText(QApplication::translate("Patient_Repeats", "View", 0));
        pushButton_postView->setText(QApplication::translate("Patient_Repeats", "View", 0));
    } // retranslateUi

};

namespace Ui {
    class Patient_Repeats: public Ui_Patient_Repeats {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENT_REPEATS_H
