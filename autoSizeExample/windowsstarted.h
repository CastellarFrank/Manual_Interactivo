#ifndef WINDOWSSTARTED_H
#define WINDOWSSTARTED_H
#include "mainwindow.h"
#include <QMainWindow>
#include <QDir>
#include "header.h"
#include "metadata.h"
#include <QString>
#include <QFileInfo>
#include <QDebug>
#include <QStringList>

namespace Ui {
    class WindowsStarted;
}

class WindowsStarted : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowsStarted(QWidget *parent = 0);
    ~WindowsStarted();

private:
    Ui::WindowsStarted *ui;
    MainWindow valor;
    QString pathTemp;
    void unCompressData();

    int getSize(QFileInfo file);
    Header head;
    QStringList files;
    QStringList directories;
    void writeFilesData(QFile *archivo);
    QString destinyPath;
    QString fixPath(QString p);

private slots:
    void on_pushButton_clicked();

};

#endif // WINDOWSSTARTED_H
