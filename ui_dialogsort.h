/********************************************************************************
** Form generated from reading UI file 'dialogsort.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSORT_H
#define UI_DIALOGSORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSort
{
public:
    QWidget *centralwidget;
    QProgressBar *pPercentage;
    QPushButton *btnStart;
    QPushButton *btnClose;
    QSpinBox *sbCount;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DialogSort)
    {
        if (DialogSort->objectName().isEmpty())
            DialogSort->setObjectName(QStringLiteral("DialogSort"));
        DialogSort->resize(800, 359);
        centralwidget = new QWidget(DialogSort);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pPercentage = new QProgressBar(centralwidget);
        pPercentage->setObjectName(QStringLiteral("pPercentage"));
        pPercentage->setGeometry(QRect(50, 80, 601, 81));
        pPercentage->setValue(24);
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(404, 190, 91, 23));
        btnClose = new QPushButton(centralwidget);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(524, 190, 91, 23));
        sbCount = new QSpinBox(centralwidget);
        sbCount->setObjectName(QStringLiteral("sbCount"));
        sbCount->setGeometry(QRect(260, 190, 101, 22));
        sbCount->setMaximum(1000000000);
        DialogSort->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DialogSort);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        DialogSort->setMenuBar(menubar);
        statusbar = new QStatusBar(DialogSort);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        DialogSort->setStatusBar(statusbar);

        retranslateUi(DialogSort);

        QMetaObject::connectSlotsByName(DialogSort);
    } // setupUi

    void retranslateUi(QMainWindow *DialogSort)
    {
        DialogSort->setWindowTitle(QApplication::translate("DialogSort", "MainWindow", Q_NULLPTR));
        btnStart->setText(QApplication::translate("DialogSort", "Start", Q_NULLPTR));
        btnClose->setText(QApplication::translate("DialogSort", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogSort: public Ui_DialogSort {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSORT_H
