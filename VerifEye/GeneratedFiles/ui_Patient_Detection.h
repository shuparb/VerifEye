/********************************************************************************
** Form generated from reading UI file 'Patient_Detection.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENT_DETECTION_H
#define UI_PATIENT_DETECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Patient_Detection
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *layout_full_name;
    QLabel *label_fullName_head;
    QLabel *label_full_name;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *layout_eyepatch;
    QLabel *label_eyepatchID_head;
    QLabel *label_eid;
    QHBoxLayout *layout_hid;
    QLabel *label_hid_head;
    QLabel *label_hospital;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_preELA;
    QGraphicsView *graphicsView_preImage;
    QTextEdit *textEdit_preInfo;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_postELA;
    QGraphicsView *graphicsView_postImage;
    QTextEdit *textEdit_postInfo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_task;
    QPushButton *pushButton_recog;

    void setupUi(QWidget *Patient_Detection)
    {
        if (Patient_Detection->objectName().isEmpty())
            Patient_Detection->setObjectName(QStringLiteral("Patient_Detection"));
        Patient_Detection->resize(1142, 734);
        gridLayout = new QGridLayout(Patient_Detection);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        layout_full_name = new QHBoxLayout();
        layout_full_name->setSpacing(6);
        layout_full_name->setObjectName(QStringLiteral("layout_full_name"));
        layout_full_name->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_fullName_head = new QLabel(Patient_Detection);
        label_fullName_head->setObjectName(QStringLiteral("label_fullName_head"));
        label_fullName_head->setStyleSheet(QLatin1String("font-size: 36px;\n"
"background-color: #c4c4c4;"));

        layout_full_name->addWidget(label_fullName_head);

        label_full_name = new QLabel(Patient_Detection);
        label_full_name->setObjectName(QStringLiteral("label_full_name"));
        label_full_name->setStyleSheet(QLatin1String("font-size: 36px;\n"
"background-color: #c4c4c4;"));

        layout_full_name->addWidget(label_full_name);


        verticalLayout_3->addLayout(layout_full_name);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        layout_eyepatch = new QHBoxLayout();
        layout_eyepatch->setSpacing(6);
        layout_eyepatch->setObjectName(QStringLiteral("layout_eyepatch"));
        label_eyepatchID_head = new QLabel(Patient_Detection);
        label_eyepatchID_head->setObjectName(QStringLiteral("label_eyepatchID_head"));
        label_eyepatchID_head->setStyleSheet(QLatin1String("font-size: 36px;\n"
"background-color: #c4c4c4;"));

        layout_eyepatch->addWidget(label_eyepatchID_head);

        label_eid = new QLabel(Patient_Detection);
        label_eid->setObjectName(QStringLiteral("label_eid"));
        label_eid->setStyleSheet(QLatin1String("font-size: 36px;\n"
"background-color: #c4c4c4;"));

        layout_eyepatch->addWidget(label_eid);


        horizontalLayout_3->addLayout(layout_eyepatch);

        layout_hid = new QHBoxLayout();
        layout_hid->setSpacing(6);
        layout_hid->setObjectName(QStringLiteral("layout_hid"));
        label_hid_head = new QLabel(Patient_Detection);
        label_hid_head->setObjectName(QStringLiteral("label_hid_head"));
        label_hid_head->setStyleSheet(QLatin1String("font-size: 36px;\n"
"background-color: #c4c4c4;"));

        layout_hid->addWidget(label_hid_head);

        label_hospital = new QLabel(Patient_Detection);
        label_hospital->setObjectName(QStringLiteral("label_hospital"));
        label_hospital->setStyleSheet(QLatin1String("font-size: 36px;\n"
"background-color: #c4c4c4;"));

        layout_hid->addWidget(label_hospital);


        horizontalLayout_3->addLayout(layout_hid);


        verticalLayout_3->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_preELA = new QPushButton(Patient_Detection);
        pushButton_preELA->setObjectName(QStringLiteral("pushButton_preELA"));

        verticalLayout->addWidget(pushButton_preELA);

        graphicsView_preImage = new QGraphicsView(Patient_Detection);
        graphicsView_preImage->setObjectName(QStringLiteral("graphicsView_preImage"));

        verticalLayout->addWidget(graphicsView_preImage);

        textEdit_preInfo = new QTextEdit(Patient_Detection);
        textEdit_preInfo->setObjectName(QStringLiteral("textEdit_preInfo"));

        verticalLayout->addWidget(textEdit_preInfo);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_postELA = new QPushButton(Patient_Detection);
        pushButton_postELA->setObjectName(QStringLiteral("pushButton_postELA"));

        verticalLayout_2->addWidget(pushButton_postELA);

        graphicsView_postImage = new QGraphicsView(Patient_Detection);
        graphicsView_postImage->setObjectName(QStringLiteral("graphicsView_postImage"));

        verticalLayout_2->addWidget(graphicsView_postImage);

        textEdit_postInfo = new QTextEdit(Patient_Detection);
        textEdit_postInfo->setObjectName(QStringLiteral("textEdit_postInfo"));

        verticalLayout_2->addWidget(textEdit_postInfo);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(200);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_task = new QPushButton(Patient_Detection);
        pushButton_task->setObjectName(QStringLiteral("pushButton_task"));
        pushButton_task->setStyleSheet(QStringLiteral("font-size: 28px;"));

        horizontalLayout_2->addWidget(pushButton_task);

        pushButton_recog = new QPushButton(Patient_Detection);
        pushButton_recog->setObjectName(QStringLiteral("pushButton_recog"));
        pushButton_recog->setStyleSheet(QLatin1String("font-size: 26px;\n"
""));

        horizontalLayout_2->addWidget(pushButton_recog);


        verticalLayout_4->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(Patient_Detection);

        QMetaObject::connectSlotsByName(Patient_Detection);
    } // setupUi

    void retranslateUi(QWidget *Patient_Detection)
    {
        Patient_Detection->setWindowTitle(QApplication::translate("Patient_Detection", "Patient_Detection", 0));
        label_fullName_head->setText(QApplication::translate("Patient_Detection", "Full Name: ", 0));
        label_full_name->setText(QString());
        label_eyepatchID_head->setText(QApplication::translate("Patient_Detection", "Eyepatch ID: ", 0));
        label_eid->setText(QString());
        label_hid_head->setText(QApplication::translate("Patient_Detection", "HID: ", 0));
        label_hospital->setText(QString());
        pushButton_preELA->setText(QApplication::translate("Patient_Detection", "Show ELA", 0));
        pushButton_postELA->setText(QApplication::translate("Patient_Detection", "Show ELA", 0));
        pushButton_task->setText(QApplication::translate("Patient_Detection", "STEP DETECT 1", 0));
        pushButton_recog->setText(QApplication::translate("Patient_Detection", "Recognize->", 0));
    } // retranslateUi

};

namespace Ui {
    class Patient_Detection: public Ui_Patient_Detection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENT_DETECTION_H
