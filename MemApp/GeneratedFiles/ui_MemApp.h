/********************************************************************************
** Form generated from reading UI file 'MemApp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMAPP_H
#define UI_MEMAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemAppClass
{
public:
    QWidget *centralWidget;
    QLineEdit *loginLine;
    QLineEdit *passwordLine;
    QPushButton *loginButton;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MemAppClass)
    {
        if (MemAppClass->objectName().isEmpty())
            MemAppClass->setObjectName(QStringLiteral("MemAppClass"));
        MemAppClass->resize(253, 228);
        centralWidget = new QWidget(MemAppClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        loginLine = new QLineEdit(centralWidget);
        loginLine->setObjectName(QStringLiteral("loginLine"));
        loginLine->setGeometry(QRect(90, 20, 113, 20));
        passwordLine = new QLineEdit(centralWidget);
        passwordLine->setObjectName(QStringLiteral("passwordLine"));
        passwordLine->setGeometry(QRect(90, 60, 113, 20));
        loginButton = new QPushButton(centralWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(130, 100, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 47, 13));
        MemAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MemAppClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 253, 21));
        MemAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MemAppClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MemAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MemAppClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MemAppClass->setStatusBar(statusBar);

        retranslateUi(MemAppClass);

        QMetaObject::connectSlotsByName(MemAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *MemAppClass)
    {
        MemAppClass->setWindowTitle(QApplication::translate("MemAppClass", "MemApp", Q_NULLPTR));
        loginButton->setText(QApplication::translate("MemAppClass", "Login", Q_NULLPTR));
        label->setText(QApplication::translate("MemAppClass", "Login:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MemAppClass", "Password:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemAppClass: public Ui_MemAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMAPP_H
