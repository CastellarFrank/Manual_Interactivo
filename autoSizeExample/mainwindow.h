#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <QResizeEvent>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QTreeWidgetItem>
#include <QDesktopWidget>
#include <QDir>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent ( QResizeEvent * event );
    void loadStyles();

private:
    Ui::MainWindow *ui;
    bool disminuir;
    void loadElements();
    void loadTreeWidget();
    void loadHtml(QString file,QString pos);
    QList<QTreeWidgetItem*> elements;
    int currentDocument;
    bool hidden;
    QString createContentStyle();
    QString destinyPath;


private slots:
    void on_pushButton_clicked();
    void on_btnSig_clicked();
    void on_btnAnt_clicked();
    void treeWidgetClick(QTreeWidgetItem *item1,QTreeWidgetItem *item2);

};

#endif // MAINWINDOW_H
