/********************************************************************************
** Form generated from reading UI file 'VerifEye.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFEYE_H
#define UI_VERIFEYE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerifEyeClass
{
public:
    QAction *actionNewPatient;
    QAction *actionOpen_Patient;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionRefresh;
    QAction *actionExit_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *num_patients;
    QLabel *num_patients_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *num_accepted;
    QLabel *num_accepted_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *num_rejected;
    QLabel *num_rejected_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *num_errored;
    QLabel *num_errored_2;
    QTableView *patient_table;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_show;
    QPushButton *pushButton_refresh;
    QPushButton *remove;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VerifEyeClass)
    {
        if (VerifEyeClass->objectName().isEmpty())
            VerifEyeClass->setObjectName(QStringLiteral("VerifEyeClass"));
        VerifEyeClass->resize(1159, 776);
        actionNewPatient = new QAction(VerifEyeClass);
        actionNewPatient->setObjectName(QStringLiteral("actionNewPatient"));
        actionOpen_Patient = new QAction(VerifEyeClass);
        actionOpen_Patient->setObjectName(QStringLiteral("actionOpen_Patient"));
        actionExit = new QAction(VerifEyeClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(VerifEyeClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionRefresh = new QAction(VerifEyeClass);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        actionExit_2 = new QAction(VerifEyeClass);
        actionExit_2->setObjectName(QStringLiteral("actionExit_2"));
        centralWidget = new QWidget(VerifEyeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        num_patients = new QLabel(centralWidget);
        num_patients->setObjectName(QStringLiteral("num_patients"));
        num_patients->setStyleSheet(QLatin1String("font-size: 32px;\n"
"color: blue;\n"
"background-color: lightgray;"));

        horizontalLayout_2->addWidget(num_patients);

        num_patients_2 = new QLabel(centralWidget);
        num_patients_2->setObjectName(QStringLiteral("num_patients_2"));
        num_patients_2->setStyleSheet(QLatin1String("font-size: 32px;\n"
"color: blue;\n"
"background-color: lightgray;"));

        horizontalLayout_2->addWidget(num_patients_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        num_accepted = new QLabel(centralWidget);
        num_accepted->setObjectName(QStringLiteral("num_accepted"));
        num_accepted->setStyleSheet(QLatin1String("font-size: 32px;\n"
"color: green;\n"
"background-color: lightgray;"));

        horizontalLayout_3->addWidget(num_accepted);

        num_accepted_2 = new QLabel(centralWidget);
        num_accepted_2->setObjectName(QStringLiteral("num_accepted_2"));
        num_accepted_2->setStyleSheet(QLatin1String("font-size: 32px;\n"
"color: green;\n"
"background-color: lightgray;"));

        horizontalLayout_3->addWidget(num_accepted_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        num_rejected = new QLabel(centralWidget);
        num_rejected->setObjectName(QStringLiteral("num_rejected"));
        num_rejected->setStyleSheet(QLatin1String("font-size: 32px;\n"
"color: red;\n"
"background-color: lightgray;\n"
""));

        horizontalLayout_4->addWidget(num_rejected);

        num_rejected_2 = new QLabel(centralWidget);
        num_rejected_2->setObjectName(QStringLiteral("num_rejected_2"));
        num_rejected_2->setStyleSheet(QLatin1String("font-size: 32px;\n"
"color: red;\n"
"background-color: lightgray;\n"
""));

        horizontalLayout_4->addWidget(num_rejected_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        num_errored = new QLabel(centralWidget);
        num_errored->setObjectName(QStringLiteral("num_errored"));
        num_errored->setStyleSheet(QLatin1String("font-size: 32px;\n"
"color: #fffb42;\n"
"background-color: lightgray;"));

        horizontalLayout_5->addWidget(num_errored);

        num_errored_2 = new QLabel(centralWidget);
        num_errored_2->setObjectName(QStringLiteral("num_errored_2"));
        num_errored_2->setStyleSheet(QLatin1String("font-size: 32px;\n"
"color: #fffb42;\n"
"background-color: lightgray;"));

        horizontalLayout_5->addWidget(num_errored_2);


        verticalLayout->addLayout(horizontalLayout_5);

        patient_table = new QTableView(centralWidget);
        patient_table->setObjectName(QStringLiteral("patient_table"));
        patient_table->setStyleSheet(QStringLiteral("font-size: 25px;"));
        patient_table->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(patient_table);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_show = new QPushButton(centralWidget);
        pushButton_show->setObjectName(QStringLiteral("pushButton_show"));

        horizontalLayout->addWidget(pushButton_show);

        pushButton_refresh = new QPushButton(centralWidget);
        pushButton_refresh->setObjectName(QStringLiteral("pushButton_refresh"));

        horizontalLayout->addWidget(pushButton_refresh);

        remove = new QPushButton(centralWidget);
        remove->setObjectName(QStringLiteral("remove"));

        horizontalLayout->addWidget(remove);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        VerifEyeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VerifEyeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1159, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        VerifEyeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VerifEyeClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VerifEyeClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VerifEyeClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VerifEyeClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewPatient);
        menuFile->addAction(actionOpen_Patient);
        menuFile->addSeparator();
        menuFile->addAction(actionExit_2);
        menuHelp->addAction(actionAbout);

        retranslateUi(VerifEyeClass);

        QMetaObject::connectSlotsByName(VerifEyeClass);
    } // setupUi

    void retranslateUi(QMainWindow *VerifEyeClass)
    {
        VerifEyeClass->setWindowTitle(QApplication::translate("VerifEyeClass", "VerifEye", 0));
        actionNewPatient->setText(QApplication::translate("VerifEyeClass", "New Patient", 0));
        actionOpen_Patient->setText(QApplication::translate("VerifEyeClass", "Open Patient", 0));
        actionExit->setText(QApplication::translate("VerifEyeClass", "Exit", 0));
        actionAbout->setText(QApplication::translate("VerifEyeClass", "About", 0));
        actionRefresh->setText(QApplication::translate("VerifEyeClass", "Refresh", 0));
        actionExit_2->setText(QApplication::translate("VerifEyeClass", "Exit", 0));
        num_patients->setText(QApplication::translate("VerifEyeClass", "Number of Patients: ", 0));
        num_patients_2->setText(QString());
        num_accepted->setText(QApplication::translate("VerifEyeClass", "Number of Accepted Patients: ", 0));
        num_accepted_2->setText(QString());
        num_rejected->setText(QApplication::translate("VerifEyeClass", "Number of Rejected Patients: ", 0));
        num_rejected_2->setText(QString());
        num_errored->setText(QApplication::translate("VerifEyeClass", "Number of Errored Patients: ", 0));
        num_errored_2->setText(QString());
        pushButton_show->setText(QApplication::translate("VerifEyeClass", "Show", 0));
        pushButton_refresh->setText(QApplication::translate("VerifEyeClass", "Refresh", 0));
        remove->setText(QApplication::translate("VerifEyeClass", "Remove", 0));
        menuFile->setTitle(QApplication::translate("VerifEyeClass", "File", 0));
        menuHelp->setTitle(QApplication::translate("VerifEyeClass", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class VerifEyeClass: public Ui_VerifEyeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFEYE_H
