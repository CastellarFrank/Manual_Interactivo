/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 9. Apr 10:20:46 2013
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QWebView *webView;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAnt;
    QPushButton *btnSig;
    QWidget *verticalWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *treeWidget;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setMinimumSize(QSize(700, 500));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 700, 600));
        label->setScaledContents(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(700, 0, 300, 600));
        label_2->setScaledContents(true);
        gridWidget = new QWidget(centralWidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(0, 0, 1000, 600));
        gridWidget->setMinimumSize(QSize(600, 500));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        webView = new QWebView(gridWidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setUrl(QUrl("about:blank"));

        verticalLayout->addWidget(webView);

        horizontalWidget = new QWidget(gridWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setStrikeOut(false);
        font.setKerning(true);
        horizontalWidget->setFont(font);
        horizontalWidget->setAcceptDrops(false);
        horizontalWidget->setAutoFillBackground(false);
        horizontalWidget->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnAnt = new QPushButton(horizontalWidget);
        btnAnt->setObjectName(QString::fromUtf8("btnAnt"));
        btnAnt->setMinimumSize(QSize(0, 60));
        btnAnt->setMaximumSize(QSize(180, 60));
        btnAnt->setLayoutDirection(Qt::LeftToRight);
        btnAnt->setAutoFillBackground(true);
        btnAnt->setStyleSheet(QString::fromUtf8(""));
        btnAnt->setIconSize(QSize(204, 50));
        btnAnt->setCheckable(false);
        btnAnt->setAutoRepeat(false);
        btnAnt->setAutoExclusive(false);
        btnAnt->setAutoRepeatDelay(300);
        btnAnt->setAutoRepeatInterval(100);
        btnAnt->setAutoDefault(false);
        btnAnt->setDefault(false);
        btnAnt->setFlat(false);

        horizontalLayout->addWidget(btnAnt);

        btnSig = new QPushButton(horizontalWidget);
        btnSig->setObjectName(QString::fromUtf8("btnSig"));
        btnSig->setMinimumSize(QSize(0, 60));
        btnSig->setMaximumSize(QSize(180, 60));
        btnSig->setAutoFillBackground(true);
        btnSig->setIconSize(QSize(204, 50));
        btnSig->setAutoDefault(false);
        btnSig->setDefault(false);
        btnSig->setFlat(false);

        horizontalLayout->addWidget(btnSig);

        btnSig->raise();
        btnAnt->raise();

        verticalLayout->addWidget(horizontalWidget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalWidget_2 = new QWidget(gridWidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalWidget_2->sizePolicy().hasHeightForWidth());
        verticalWidget_2->setSizePolicy(sizePolicy1);
        verticalWidget_2->setMinimumSize(QSize(300, 500));
        verticalWidget_2->setMaximumSize(QSize(300, 16777215));
        verticalWidget_2->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_2 = new QHBoxLayout(verticalWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(27, 38, -1, -1);
        treeWidget = new QTreeWidget(verticalWidget_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy2);
        treeWidget->setMinimumSize(QSize(200, 0));
        treeWidget->setMaximumSize(QSize(240, 350));

        horizontalLayout_2->addWidget(treeWidget);


        gridLayout->addWidget(verticalWidget_2, 0, 2, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(600, 560, 80, 30));
        pushButton->setMinimumSize(QSize(80, 30));
        pushButton->setMaximumSize(QSize(80, 30));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QString());
#ifndef QT_NO_WHATSTHIS
        horizontalWidget->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        horizontalWidget->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        horizontalWidget->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        btnAnt->setText(QString());
        btnSig->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Ocultar Men\303\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
