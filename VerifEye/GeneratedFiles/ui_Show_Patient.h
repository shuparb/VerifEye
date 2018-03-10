/********************************************************************************
** Form generated from reading UI file 'Show_Patient.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_PATIENT_H
#define UI_SHOW_PATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Show_Patient
{
public:

    void setupUi(QWidget *Show_Patient)
    {
        if (Show_Patient->objectName().isEmpty())
            Show_Patient->setObjectName(QStringLiteral("Show_Patient"));
        Show_Patient->resize(400, 300);

        retranslateUi(Show_Patient);

        QMetaObject::connectSlotsByName(Show_Patient);
    } // setupUi

    void retranslateUi(QWidget *Show_Patient)
    {
        Show_Patient->setWindowTitle(QApplication::translate("Show_Patient", "Show_Patient", 0));
    } // retranslateUi

};

namespace Ui {
    class Show_Patient: public Ui_Show_Patient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_PATIENT_H
