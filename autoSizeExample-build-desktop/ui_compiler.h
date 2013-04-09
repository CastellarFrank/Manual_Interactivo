/********************************************************************************
** Form generated from reading UI file 'compiler.ui'
**
** Created: Tue 9. Apr 10:20:46 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPILER_H
#define UI_COMPILER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Compiler
{
public:
    QAction *actionNueva_Clase;
    QAction *actionBorrar_Clase;
    QAction *actionEjecutar_C_digo;
    QWidget *centralwidget;
    QPushButton *lblOutputMinusZoom;
    QPushButton *lblTextEditPlusZoom;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QPushButton *lblTextEditMinusZoom;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *lblOutputPlusZoom;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Compiler)
    {
        if (Compiler->objectName().isEmpty())
            Compiler->setObjectName(QString::fromUtf8("Compiler"));
        Compiler->resize(603, 500);
        Compiler->setMinimumSize(QSize(460, 0));
        actionNueva_Clase = new QAction(Compiler);
        actionNueva_Clase->setObjectName(QString::fromUtf8("actionNueva_Clase"));
        actionBorrar_Clase = new QAction(Compiler);
        actionBorrar_Clase->setObjectName(QString::fromUtf8("actionBorrar_Clase"));
        actionEjecutar_C_digo = new QAction(Compiler);
        actionEjecutar_C_digo->setObjectName(QString::fromUtf8("actionEjecutar_C_digo"));
        centralwidget = new QWidget(Compiler);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lblOutputMinusZoom = new QPushButton(centralwidget);
        lblOutputMinusZoom->setObjectName(QString::fromUtf8("lblOutputMinusZoom"));
        lblOutputMinusZoom->setGeometry(QRect(550, 200, 31, 23));
        lblTextEditPlusZoom = new QPushButton(centralwidget);
        lblTextEditPlusZoom->setObjectName(QString::fromUtf8("lblTextEditPlusZoom"));
        lblTextEditPlusZoom->setGeometry(QRect(510, 0, 31, 23));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 198, 581, 244));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(30);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 150));
        widget->setMaximumSize(QSize(16777215, 16777215));
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 20));
        label->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMinimumSize(QSize(0, 100));
        textEdit->setMaximumSize(QSize(16777215, 16777215));
        textEdit->setTextInteractionFlags(Qt::TextEditorInteraction);

        verticalLayout->addWidget(textEdit);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 20));
        lineEdit->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(lineEdit);

        lblTextEditMinusZoom = new QPushButton(centralwidget);
        lblTextEditMinusZoom->setObjectName(QString::fromUtf8("lblTextEditMinusZoom"));
        lblTextEditMinusZoom->setGeometry(QRect(550, 0, 31, 23));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(9, 9, 581, 181));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(70);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        lblOutputPlusZoom = new QPushButton(centralwidget);
        lblOutputPlusZoom->setObjectName(QString::fromUtf8("lblOutputPlusZoom"));
        lblOutputPlusZoom->setGeometry(QRect(510, 200, 31, 23));
        Compiler->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Compiler);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 603, 20));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
        Compiler->setMenuBar(menubar);
        toolBar = new QToolBar(Compiler);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Compiler->addToolBar(Qt::TopToolBarArea, toolBar);
        Compiler->insertToolBarBreak(toolBar);

        menubar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionNueva_Clase);
        menuArchivo->addAction(actionBorrar_Clase);
        toolBar->addAction(actionNueva_Clase);
        toolBar->addSeparator();
        toolBar->addAction(actionBorrar_Clase);
        toolBar->addSeparator();
        toolBar->addAction(actionEjecutar_C_digo);

        retranslateUi(Compiler);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Compiler);
    } // setupUi

    void retranslateUi(QMainWindow *Compiler)
    {
        Compiler->setWindowTitle(QApplication::translate("Compiler", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNueva_Clase->setText(QApplication::translate("Compiler", "Nueva Clase...", 0, QApplication::UnicodeUTF8));
        actionNueva_Clase->setShortcut(QApplication::translate("Compiler", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionBorrar_Clase->setText(QApplication::translate("Compiler", "Borrar Clase...", 0, QApplication::UnicodeUTF8));
        actionBorrar_Clase->setShortcut(QApplication::translate("Compiler", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionEjecutar_C_digo->setText(QApplication::translate("Compiler", "Ejecutar C\303\263digo", 0, QApplication::UnicodeUTF8));
        actionEjecutar_C_digo->setShortcut(QApplication::translate("Compiler", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        lblOutputMinusZoom->setText(QString());
        lblTextEditPlusZoom->setText(QString());
        label->setText(QApplication::translate("Compiler", "Resultado de Ejecuci\303\263n", 0, QApplication::UnicodeUTF8));
        lblTextEditMinusZoom->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Compiler", "Main", 0, QApplication::UnicodeUTF8));
        lblOutputPlusZoom->setText(QString());
        menuArchivo->setTitle(QApplication::translate("Compiler", "Archivo", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("Compiler", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Compiler: public Ui_Compiler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPILER_H
