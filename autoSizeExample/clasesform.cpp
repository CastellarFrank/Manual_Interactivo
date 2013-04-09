#include "clasesform.h"
#include "ui_clasesform.h"

ClasesForm::ClasesForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClasesForm)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint); //Set window to fixed size
}

ClasesForm::~ClasesForm()
{
    delete ui;
}


void ClasesForm::on_pushButton_clicked()
{
    emit newClass(this);
}


void ClasesForm::closeEvent(QCloseEvent *event){
    event->ignore();
    this->hide();
}

void ClasesForm::addNewClass(QString name){
    ui->listWidget->addItem(new QListWidgetItem(name));
}

void ClasesForm::removeClass(int number){
    delete ui->listWidget->takeItem(number);
    if(ui->listWidget->count()==0){
        this->close();
    }
}

void ClasesForm::on_pushButton_2_clicked()
{
    QString val=ui->listWidget->currentItem()->text();
    emit closeClass(val);

}
