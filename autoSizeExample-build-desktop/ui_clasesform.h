/********************************************************************************
** Form generated from reading UI file 'clasesform.ui'
**
** Created: Tue 9. Apr 10:20:47 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASESFORM_H
#define UI_CLASESFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClasesForm
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *ClasesForm)
    {
        if (ClasesForm->objectName().isEmpty())
            ClasesForm->setObjectName(QString::fromUtf8("ClasesForm"));
        ClasesForm->resize(400, 250);
        ClasesForm->setMinimumSize(QSize(400, 250));
        ClasesForm->setMaximumSize(QSize(400, 250));
        centralwidget = new QWidget(ClasesForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(30, 30, 181, 191));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 60, 111, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 130, 111, 41));
        ClasesForm->setCentralWidget(centralwidget);

        retranslateUi(ClasesForm);

        QMetaObject::connectSlotsByName(ClasesForm);
    } // setupUi

    void retranslateUi(QMainWindow *ClasesForm)
    {
        ClasesForm->setWindowTitle(QApplication::translate("ClasesForm", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ClasesForm", "Nueva Clase", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ClasesForm", "Borrar Clase", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClasesForm: public Ui_ClasesForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASESFORM_H
