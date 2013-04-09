#ifndef CLASESFORM_H
#define CLASESFORM_H

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>


namespace Ui {
    class ClasesForm;
}

class ClasesForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClasesForm(QWidget *parent = 0);
    ~ClasesForm();

private:
    Ui::ClasesForm *ui;


signals:
    void newClass(QWidget *parent);
    void closeClass(QString);

protected:
     void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void addNewClass(QString name);
    void removeClass(int number);

};

#endif // CLASESFORM_H
