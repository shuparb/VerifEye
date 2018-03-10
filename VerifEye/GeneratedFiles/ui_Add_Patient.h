/********************************************************************************
** Form generated from reading UI file 'Add_Patient.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_PATIENT_H
#define UI_ADD_PATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add_Patient
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_head;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_firstName;
    QLineEdit *lineEdit_firstName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_lastName;
    QLineEdit *lineEdit_lastName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_preImage;
    QLineEdit *lineEdit_preImage;
    QPushButton *pushButton_PreImage;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_postImage;
    QLineEdit *lineEdit_postImage;
    QPushButton *pushButton_PostImage;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_eyepatch;
    QRadioButton *radioButton_leftEyePatch;
    QRadioButton *radioButton_rightEyePatch;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_hospital;
    QComboBox *comboBox_hospital;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_state;
    QLineEdit *lineEdit_state;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_cancel;

    void setupUi(QWidget *Add_Patient)
    {
        if (Add_Patient->objectName().isEmpty())
            Add_Patient->setObjectName(QStringLiteral("Add_Patient"));
        Add_Patient->resize(1168, 792);
        gridLayout = new QGridLayout(Add_Patient);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(30, 10, 30, 30);
        label_head = new QLabel(Add_Patient);
        label_head->setObjectName(QStringLiteral("label_head"));

        verticalLayout_2->addWidget(label_head);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(40);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(30, -1, 30, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_firstName = new QLabel(Add_Patient);
        label_firstName->setObjectName(QStringLiteral("label_firstName"));
        label_firstName->setStyleSheet(QLatin1String("font-size: 32px;\n"
""));

        horizontalLayout->addWidget(label_firstName);

        lineEdit_firstName = new QLineEdit(Add_Patient);
        lineEdit_firstName->setObjectName(QStringLiteral("lineEdit_firstName"));
        lineEdit_firstName->setStyleSheet(QStringLiteral("font-size: 28px;"));

        horizontalLayout->addWidget(lineEdit_firstName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_lastName = new QLabel(Add_Patient);
        label_lastName->setObjectName(QStringLiteral("label_lastName"));
        label_lastName->setStyleSheet(QLatin1String("font-size: 32px;\n"
""));

        horizontalLayout_2->addWidget(label_lastName);

        lineEdit_lastName = new QLineEdit(Add_Patient);
        lineEdit_lastName->setObjectName(QStringLiteral("lineEdit_lastName"));
        lineEdit_lastName->setStyleSheet(QStringLiteral("font-size: 28px;"));

        horizontalLayout_2->addWidget(lineEdit_lastName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_preImage = new QLabel(Add_Patient);
        label_preImage->setObjectName(QStringLiteral("label_preImage"));
        label_preImage->setStyleSheet(QLatin1String("font-size: 32px;\n"
""));

        horizontalLayout_3->addWidget(label_preImage);

        lineEdit_preImage = new QLineEdit(Add_Patient);
        lineEdit_preImage->setObjectName(QStringLiteral("lineEdit_preImage"));
        lineEdit_preImage->setStyleSheet(QStringLiteral("font-size: 28px;"));

        horizontalLayout_3->addWidget(lineEdit_preImage);

        pushButton_PreImage = new QPushButton(Add_Patient);
        pushButton_PreImage->setObjectName(QStringLiteral("pushButton_PreImage"));

        horizontalLayout_3->addWidget(pushButton_PreImage);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_postImage = new QLabel(Add_Patient);
        label_postImage->setObjectName(QStringLiteral("label_postImage"));
        label_postImage->setStyleSheet(QLatin1String("font-size: 32px;\n"
""));

        horizontalLayout_4->addWidget(label_postImage);

        lineEdit_postImage = new QLineEdit(Add_Patient);
        lineEdit_postImage->setObjectName(QStringLiteral("lineEdit_postImage"));
        lineEdit_postImage->setStyleSheet(QStringLiteral("font-size: 28px;"));

        horizontalLayout_4->addWidget(lineEdit_postImage);

        pushButton_PostImage = new QPushButton(Add_Patient);
        pushButton_PostImage->setObjectName(QStringLiteral("pushButton_PostImage"));

        horizontalLayout_4->addWidget(pushButton_PostImage);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_eyepatch = new QLabel(Add_Patient);
        label_eyepatch->setObjectName(QStringLiteral("label_eyepatch"));
        label_eyepatch->setStyleSheet(QLatin1String("font-size: 32px;\n"
""));

        horizontalLayout_8->addWidget(label_eyepatch);

        radioButton_leftEyePatch = new QRadioButton(Add_Patient);
        radioButton_leftEyePatch->setObjectName(QStringLiteral("radioButton_leftEyePatch"));
        radioButton_leftEyePatch->setStyleSheet(QStringLiteral("font-size: 28px;"));

        horizontalLayout_8->addWidget(radioButton_leftEyePatch);

        radioButton_rightEyePatch = new QRadioButton(Add_Patient);
        radioButton_rightEyePatch->setObjectName(QStringLiteral("radioButton_rightEyePatch"));
        radioButton_rightEyePatch->setStyleSheet(QStringLiteral("font-size: 28px;"));

        horizontalLayout_8->addWidget(radioButton_rightEyePatch);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(30);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_hospital = new QLabel(Add_Patient);
        label_hospital->setObjectName(QStringLiteral("label_hospital"));
        label_hospital->setStyleSheet(QLatin1String("font-size: 32px;\n"
""));

        horizontalLayout_5->addWidget(label_hospital);

        comboBox_hospital = new QComboBox(Add_Patient);
        comboBox_hospital->setObjectName(QStringLiteral("comboBox_hospital"));
        comboBox_hospital->setStyleSheet(QLatin1String("font-size: 28px;\n"
"color: #0000ff;"));

        horizontalLayout_5->addWidget(comboBox_hospital);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_state = new QLabel(Add_Patient);
        label_state->setObjectName(QStringLiteral("label_state"));
        label_state->setStyleSheet(QLatin1String("font-size: 32px;\n"
""));

        horizontalLayout_7->addWidget(label_state);

        lineEdit_state = new QLineEdit(Add_Patient);
        lineEdit_state->setObjectName(QStringLiteral("lineEdit_state"));
        lineEdit_state->setStyleSheet(QStringLiteral("font-size: 28px;"));

        horizontalLayout_7->addWidget(lineEdit_state);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(180);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(60, -1, 60, -1);
        pushButton_ok = new QPushButton(Add_Patient);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));
        pushButton_ok->setStyleSheet(QStringLiteral("font-size: 26px;"));

        horizontalLayout_6->addWidget(pushButton_ok);

        pushButton_cancel = new QPushButton(Add_Patient);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setStyleSheet(QStringLiteral("font-size: 26px;"));

        horizontalLayout_6->addWidget(pushButton_cancel);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(Add_Patient);

        QMetaObject::connectSlotsByName(Add_Patient);
    } // setupUi

    void retranslateUi(QWidget *Add_Patient)
    {
        Add_Patient->setWindowTitle(QApplication::translate("Add_Patient", "Add_Patient", 0));
        label_head->setText(QApplication::translate("Add_Patient", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; font-weight:600; color:#00007f;\">Add New Patient: </span></p></body></html>", 0));
        label_firstName->setText(QApplication::translate("Add_Patient", "First Name: ", 0));
        label_lastName->setText(QApplication::translate("Add_Patient", "Last Name: ", 0));
        label_preImage->setText(QApplication::translate("Add_Patient", "Pre Image: ", 0));
        pushButton_PreImage->setText(QApplication::translate("Add_Patient", "...", 0));
        label_postImage->setText(QApplication::translate("Add_Patient", "Post Image: ", 0));
        pushButton_PostImage->setText(QApplication::translate("Add_Patient", "...", 0));
        label_eyepatch->setText(QApplication::translate("Add_Patient", "Eyepatch: ", 0));
        radioButton_leftEyePatch->setText(QApplication::translate("Add_Patient", "Left Eyepatch", 0));
        radioButton_rightEyePatch->setText(QApplication::translate("Add_Patient", "Right Eyepatch", 0));
        label_hospital->setText(QApplication::translate("Add_Patient", "Hospital: ", 0));
        label_state->setText(QApplication::translate("Add_Patient", "State: ", 0));
        pushButton_ok->setText(QApplication::translate("Add_Patient", "Analyze->", 0));
        pushButton_cancel->setText(QApplication::translate("Add_Patient", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class Add_Patient: public Ui_Add_Patient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_PATIENT_H
