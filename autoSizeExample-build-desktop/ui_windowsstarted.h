/********************************************************************************
** Form generated from reading UI file 'windowsstarted.ui'
**
** Created: Tue 9. Apr 10:20:46 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSSTARTED_H
#define UI_WINDOWSSTARTED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowsStarted
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QMainWindow *WindowsStarted)
    {
        if (WindowsStarted->objectName().isEmpty())
            WindowsStarted->setObjectName(QString::fromUtf8("WindowsStarted"));
        WindowsStarted->resize(700, 300);
        WindowsStarted->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(WindowsStarted);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 700, 300));
        label->setScaledContents(true);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 180, 271, 91));
        WindowsStarted->setCentralWidget(centralwidget);

        retranslateUi(WindowsStarted);

        QMetaObject::connectSlotsByName(WindowsStarted);
    } // setupUi

    void retranslateUi(QMainWindow *WindowsStarted)
    {
        WindowsStarted->setWindowTitle(QApplication::translate("WindowsStarted", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WindowsStarted: public Ui_WindowsStarted {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSSTARTED_H
