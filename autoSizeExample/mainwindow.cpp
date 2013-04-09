#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tutorial Básico C++");
    this->disminuir=false;

    this->destinyPath=QDir::tempPath();
    this->destinyPath+="/TutoC";

    this->connect(ui->treeWidget,SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this,SLOT(treeWidgetClick(QTreeWidgetItem*,QTreeWidgetItem*)));

    this->loadElements();
    this->loadTreeWidget();
    this->currentDocument=0;
    this->hidden=false;
    QDesktopWidget *desktop = QApplication::desktop();
    this->move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resizeEvent(QResizeEvent *event){
    int ancho=this->width()-300;
    if(!this->hidden){
        ui->pushButton->setGeometry(ancho-85,this->height()-33,
                                80,30);
    }else{
        ui->pushButton->setGeometry(this->width()-85,this->height()-33,80,30);
    }
    ui->label->setGeometry(0,0,ancho,this->height());
    ui->label_2->setGeometry(ancho,0,300,this->height());
    ui->gridWidget->setGeometry(0,0,this->width(),this->height());
    if(this->height()<=520){
        ui->treeWidget->setMaximumHeight(280);
        if(!this->disminuir){
            ui->verticalWidget_2->setContentsMargins(ui->verticalWidget_2->contentsMargins().left(),
                                                 ui->verticalWidget_2->contentsMargins().top()-20,
                                                 ui->verticalWidget_2->contentsMargins().right(),
                                                 ui->verticalWidget_2->contentsMargins().bottom());
            disminuir=true;
        }
    }else if(this->height()>520&&this->height()<=540){
        ui->treeWidget->setMaximumHeight(300);
    }else if(this->height()>540 &&this->height()<=570){
        ui->treeWidget->setMaximumHeight(320);
    }else if(this->height()>570 && this->height()<630){
        ui->treeWidget->setMaximumHeight(350);
    }else if(this->height()<680){
        ui->treeWidget->setMaximumHeight(370);
    }else{
        ui->treeWidget->setMaximumHeight(400);
    }
    if(disminuir && this->height()>520){
        ui->verticalWidget_2->setContentsMargins(ui->verticalWidget_2->contentsMargins().left(),
                                             ui->verticalWidget_2->contentsMargins().top()+20,
                                             ui->verticalWidget_2->contentsMargins().right(),
                                             ui->verticalWidget_2->contentsMargins().bottom());
        disminuir=false;
    }
}

//void MainWindow::on_pushButton_2_clicked()
//{
//    ui->webView->load(QUrl("./funciones_1.html"));
//}

void MainWindow::loadHtml(QString file,QString pos){
    if(file.isEmpty())
        return;
    QString path=this->destinyPath;
    path+="/html/";
    path.append(file);
    qDebug()<<"Archivo"<<path;
    ui->webView->load(QUrl(path));
    this->currentDocument=pos.toInt();
}

//void MainWindow::on_pushButton_clicked()
//{
//    ui->webView->load(QUrl(":funciones_2.html"));
//}

void MainWindow::loadElements(){
    QStringList list1,list2,list3,list4,list5;
    list1.append("Iniciando en C++");
    list1.append("Intro_1.html");
    list1.append("0");

    list2.append("Variables y Declaración");
    list2.append("Intro_2.html");
    list2.append("1");

    list3.append("Cadenas y Operadores");
    list3.append("Intro_3.html");
    list3.append("2");

    list4.append("Más Operadores");
    list4.append("Intro_4.html");
    list4.append("3");

    list5.append("Lirerías (#Include)");
    list5.append("Intro_5.html");
    list5.append("4");

    this->elements.append(new QTreeWidgetItem(list1));
    this->elements.append(new QTreeWidgetItem(list2));
    this->elements.append(new QTreeWidgetItem(list3));
    this->elements.append(new QTreeWidgetItem(list4));
    this->elements.append(new QTreeWidgetItem(list5));

    list1.clear();list2.clear();list3.clear();list4.clear();list5.clear();

    list1.append("Ejemplos y Más");
    list1.append("Intro_6.html");
    list1.append("5");
    this->elements.append(new QTreeWidgetItem(list1));
    list1.clear();

    list1.append("Bloques en C++");
    list1.append("bloques.html");
    list1.append("6");

    list2.append("Clases (Archivo.h)");
    list2.append("bloques1.html");
    list2.append("7");

    list3.append("Clases (Archivo.cpp)");
    list3.append("bloques2.html");
    list3.append("8");

    this->elements.append(new QTreeWidgetItem(list1));
    this->elements.append(new QTreeWidgetItem(list2));
    this->elements.append(new QTreeWidgetItem(list3));

    list4.append("Introducción y Repaso");
    list4.append("Estructuras.html");
    list4.append("9");

    list5.append("Estructuras del IF");
    list5.append("Estructuras1.html");
    list5.append("10");

    this->elements.append(new QTreeWidgetItem(list4));
    this->elements.append(new QTreeWidgetItem(list5));

    list1.clear();list2.clear();list3.clear();list4.clear();list5.clear();

    list1.append("Estructuras del SWITCH");
    list1.append("Estructuras2.html");
    list1.append("11");

    this->elements.append(new QTreeWidgetItem(list1));

    list2.append("Ciclo For");
    list2.append("Estructuras3.html");
    list2.append("12");

    list3.append("While y Do While");
    list3.append("Estructuras4.html");
    list3.append("13");

    this->elements.append(new QTreeWidgetItem(list2));
    this->elements.append(new QTreeWidgetItem(list3));

    list4.append("Arreglos Unidimensionales");
    list4.append("arreglos1.html");
    list4.append("14");

    list5.append("Arreglos Bidimensionales");
    list5.append("arreglos2.html");
    list5.append("15");

    this->elements.append(new QTreeWidgetItem(list4));
    this->elements.append(new QTreeWidgetItem(list5));

    list1.clear();list2.clear();list3.clear();list4.clear();list5.clear();

    list1.append("Estructura Básica");
    list1.append("funciones_1.html");
    list1.append("16");

    list2.append("Parámetros de una Función");
    list2.append("funciones_2.html");
    list2.append("17");

    list3.append("Funciones en Clases");
    list3.append("funciones_3.html");
    list3.append("18");

    this->elements.append(new QTreeWidgetItem(list1));
    this->elements.append(new QTreeWidgetItem(list2));
    this->elements.append(new QTreeWidgetItem(list3));

    list4.append("Explicación y Ejemplos");
    list4.append("recursividad.html");
    list4.append("19");

    this->elements.append(new QTreeWidgetItem(list4));

}

void MainWindow::loadTreeWidget(){

    QStringList cabezera,list1,list2,list3,list5,list4;
    cabezera<<"Menú Principal";
    ui->treeWidget->setHeaderLabels(cabezera);

    QTreeWidgetItem *item1 = new QTreeWidgetItem(ui->treeWidget, QStringList(QObject::tr("Introducción")));
    item1->addChild(this->elements[0]);
    item1->addChild(this->elements[1]);
    item1->addChild(this->elements[2]);
    item1->addChild(this->elements[3]);
    item1->addChild(this->elements[4]);
    item1->addChild(this->elements[5]);
    QTreeWidgetItem *item8= new QTreeWidgetItem(item1,QStringList(QObject::tr("Ejercicios")));
    list1.append("Ver Todos");
    list1.append("Intro_ejercicios.html");
    list1.append("5");
    item8->addChild(new QTreeWidgetItem(item8,list1));


    QTreeWidgetItem *item2 = new QTreeWidgetItem(ui->treeWidget, QStringList(QObject::tr("Bloques y Clases")));
    item2->addChild(this->elements[6]);
    item2->addChild(this->elements[7]);
    item2->addChild(this->elements[8]);
    QTreeWidgetItem *item9=new QTreeWidgetItem(item2,QStringList(QObject::tr("Ejercicios")));
    list2.append("Ejercicio #1 y #2");
    list2.append("bloques_ejercicios1.html");
    list2.append("8");
    item9->addChild(new QTreeWidgetItem(item9,list2));
    list3.append("Ejercicio #3 y #4");
    list3.append("bloques_ejercicios2.html");
    list3.append("8");
    item9->addChild(new QTreeWidgetItem(item9,list3));

    QTreeWidgetItem *item3=new QTreeWidgetItem(ui->treeWidget,QStringList(QObject::tr("Estructuras")));
    item3->addChild(this->elements[9]);

    QTreeWidgetItem *item20 = new QTreeWidgetItem(item3, QStringList(QObject::tr("Estructuras Condicionales")));
    item20->addChild(this->elements[10]);
    item20->addChild(this->elements[11]);


    QTreeWidgetItem *item4 = new QTreeWidgetItem(item3, QStringList(QObject::tr("Estructuras Secuenciales")));
    item4->addChild(this->elements[12]);
    item4->addChild(this->elements[13]);
    QTreeWidgetItem *item10=new QTreeWidgetItem(item3,QStringList(QObject::tr("Ejercicios")));
    list4.append("Ver Todos");
    list4.append("Estructuras_ejercicios.html");
    list4.append("13");
    item10->addChild(new QTreeWidgetItem(item10,list4));

    QTreeWidgetItem *item5 = new QTreeWidgetItem(ui->treeWidget, QStringList(QObject::tr("Arreglos")));
    item5->addChild(this->elements[14]);
    item5->addChild(this->elements[15]);
    QTreeWidgetItem *item11=new QTreeWidgetItem(item5,QStringList(QObject::tr("Ejercicios")));
    list5.append("Ejercicio #1 y #2");
    list5.append("arreglos_ejercicios_1_2.html");
    list5.append("15");
    item11->addChild(new QTreeWidgetItem(item11,list5));
    list1.clear();list2.clear();list3.clear();list4.clear();list5.clear();
    list1.append("Ejercicio #3 y #4");
    list1.append("arreglos_ejercicios_3_4.html");
    list1.append("15");
    item11->addChild(new QTreeWidgetItem(item11,list1));
    list2.append("Ejercicio #5");
    list2.append("arreglos_ejercicios_5.html");
    list2.append("15");
    item11->addChild(new QTreeWidgetItem(item11,list2));


    QTreeWidgetItem *item6 = new QTreeWidgetItem(ui->treeWidget, QStringList(QObject::tr("Funciones")));
    item6->addChild(this->elements[16]);
    item6->addChild(this->elements[17]);
    item6->addChild(this->elements[18]);
    QTreeWidgetItem *item12=new QTreeWidgetItem(item6,QStringList(QObject::tr("Ejercicios")));
    list3.append("Ejercicio #1 y #2");
    list3.append("funciones_Ejercicio1_2.html");
    list3.append("18");
    item12->addChild(new QTreeWidgetItem(item12,list3));
    list4.append("Ejercicio #3 y #4");
    list4.append("funciones_Ejercicio3_4.html");
    list4.append("18");
    item12->addChild(new QTreeWidgetItem(item12,list4));
    list5.append("Ejercicio #5");
    list5.append("funciones_Ejercicio5.html");
    list5.append("18");
    item12->addChild(new QTreeWidgetItem(item12,list5));
    list1.clear();list2.clear();list3.clear();list4.clear();list5.clear();

    QTreeWidgetItem *item7 = new QTreeWidgetItem(ui->treeWidget, QStringList(QObject::tr("Recursividad")));
    item7->addChild(this->elements[19]);


    ui->treeWidget->expandItem(item1);
    ui->treeWidget->expandItem(item2);
    ui->treeWidget->expandItem(item3);
    ui->treeWidget->expandItem(item5);
    ui->treeWidget->expandItem(item6);
    ui->treeWidget->expandItem(item7);
}

void MainWindow::treeWidgetClick(QTreeWidgetItem *item1, QTreeWidgetItem *item2){
    this->loadHtml(item1->text(1),item1->text(2));
}



void MainWindow::on_btnAnt_clicked()
{
    if(this->currentDocument==0){
        return;
    }
    ui->treeWidget->setCurrentItem(this->elements[--this->currentDocument],0);
}

void MainWindow::on_btnSig_clicked()
{
    if(this->currentDocument==this->elements.count()-1){
        return;
    }
    ui->treeWidget->setCurrentItem(this->elements[++this->currentDocument],0);
}

void MainWindow::on_pushButton_clicked()
{
    if(this->hidden){
        ui->verticalWidget_2->setVisible(true);
        QString tempPath=this->destinyPath;
        tempPath+="/img/generales/backgroundPart2.png";
        QPixmap val(tempPath);
        ui->label_2->setPixmap(val);
        this->hidden=false;
        ui->pushButton->setText("Ocultar Menú");
        ui->pushButton->setGeometry(this->width()-385,this->height()-33,80,30);
    }else{
        QString tempPath=this->destinyPath;
        tempPath+="/img/generales/backgroundPart1.png";
        ui->verticalWidget_2->setVisible(false);
        QPixmap val(tempPath);
        ui->label_2->setPixmap(val);
        this->hidden=true;
        ui->pushButton->setText("Mostrar Menú");
        ui->pushButton->setGeometry(this->width()-85,this->height()-33,80,30);
    }

}
QString MainWindow::createContentStyle(){
    QString content="QPushButton#btnAnt,QPushButton#btnSig,QPushButton#pushButton{background-color: #aacbe8;border-radius:10px;}"
                    "QPushButton#btnAnt{background-image:url(urlAnt1)}"
                    "QPushButton#btnAnt:hover{background-image:url(urlAnt2)}"
                    "QPushButton#btnSig{background-image:url(urlSig1)}"
                    "QPushButton#btnSig:hover{background-image:url(urlSig2)}"
                    "QPushButton#btnAnt:pressed,QPushButton#btnSig:pressed{border: 1px solid #333399;}"
                    "QPushButton#pushButton:hover{background-color:#001A66; color:#FFFFFF;}"
                    "QPushButton#pushButton{border: 1px solid #000000;}";
    QString path=this->destinyPath;
    path+="/img/generales/botonAtras1.png";
    content.replace("urlAnt1",path);

    path=this->destinyPath;
    path+="/img/generales/botonAtras2.png";
    content.replace("urlAnt2",path);

    path=this->destinyPath;
    path+="/img/generales/botonSiguiente1.png";
    content.replace("urlSig1",path);

    path=this->destinyPath;
    path+="/img/generales/botonSiguiente2.png";
    content.replace("urlSig2",path);

    return content;

}

void MainWindow::loadStyles(){
    qApp->setStyleSheet(this->createContentStyle());

    QString tempPath=this->destinyPath;
    tempPath+="/img/generales/backgroundPart1.png";
    ui->label->setPixmap(QPixmap(tempPath));

    tempPath=this->destinyPath;
    tempPath+="/img/generales/backgroundPart2.png";
    ui->label_2->setPixmap(QPixmap(tempPath));

    ui->treeWidget->setCurrentItem(this->elements[this->currentDocument],0);
}
