#include "compiler.h"
#include "ui_compiler.h"

Compiler::Compiler(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Compiler)
{
    this->destinyPath=QDir::tempPath();
    this->destinyPath+="/TutoC";
    this->filesDirectory=this->destinyPath+"/files";
    this->bytesWrited=0;
    this->decrementX=0;
    this->decrementY=32;
    this->classCant=0;
    ui->setupUi(this);
    this->createMainWindowStyle();

    int num=23;
    ui->lblTextEditMinusZoom->setGeometry(0,0,num,num);
    ui->lblTextEditPlusZoom->setGeometry(0,0,num,num);

    ui->lblOutputMinusZoom->setGeometry(0,0,num,num);
    ui->lblOutputPlusZoom->setGeometry(0,0,num,num);

    this->editors.append(new CodeEditor());
    QVBoxLayout *Lay=new QVBoxLayout();
    Lay->setMargin(0);
    Lay->addWidget(this->editors[0]);
    ui->tabWidget->currentWidget()->setLayout(Lay);


    this->editors[0]->setTabStopWidth(25);
    new EditorHighLighter(editors[0]->document());
    splitter=new QSplitter();
    splitter->addWidget(ui->tabWidget);
    splitter->addWidget(ui->widget);
    splitter->setOrientation(Qt::Vertical);
    splitter->setMaximumSize(0,300);
    splitter->setMinimumSize(0,300);
    QVBoxLayout *Lay2=new QVBoxLayout();
    Lay2->addWidget(splitter);
    ui->centralwidget->setLayout(Lay2);

    connect(splitter,SIGNAL(splitterMoved(int,int)),this,SLOT(splitterMoveAction(int,int)));

    ui->lblOutputMinusZoom->raise();
    ui->lblOutputPlusZoom->raise();
    ui->lblTextEditMinusZoom->raise();
    ui->lblTextEditPlusZoom->raise();

    setDefaultFont();

    this->adminClases=new ClasesForm();
    this->setToolBarIcons();
    this->startProcess();
    connect(this->adminClases,SIGNAL(newClass(QWidget*)),this,SLOT(newClassReciever(QWidget*)));
    connect(this->adminClases,SIGNAL(closeClass(QString)),this,SLOT(removeClass(QString)));

    connect(this,SIGNAL(adminClasesNewClass(QString)),this->adminClases,SLOT(addNewClass(QString)));
    connect(this,SIGNAL(adminClasesRemoveClass(int)),this->adminClases,SLOT(removeClass(int)));

}

Compiler::~Compiler()
{
    delete this->splitter;
    delete this->adminClases;
    delete ui;
}

void Compiler::resizeEvent(QResizeEvent *event){


    int positionX1=ui->tabWidget->width()-50-decrementX;
    int positionX2=ui->tabWidget->width()-20-decrementX;
    int positionY=ui->tabWidget->height()+141-decrementY;

    int num=26;
    ui->lblTextEditPlusZoom->setGeometry(positionX1,2,num,num);
    ui->lblTextEditMinusZoom->setGeometry(positionX2,2,num,num);

    ui->lblOutputPlusZoom->setGeometry(positionX1,positionY,num,num);
    ui->lblOutputMinusZoom->setGeometry(positionX2,positionY,num,num);
    if(decrementX==0){
        this->decrementX=4;
        this->decrementY=125;
    }
}

void Compiler::splitterMoveAction(int x, int y){
    if(x==0){
        ui->lblTextEditMinusZoom->setVisible(false);
        ui->lblTextEditPlusZoom->setVisible(false);
    }else if(ui->lblTextEditMinusZoom->isHidden()){
        ui->lblTextEditMinusZoom->setVisible(true);
        ui->lblTextEditPlusZoom->setVisible(true);
    }

    if(x+4==this->splitter->height()){
        ui->lblOutputMinusZoom->setVisible(false);
        ui->lblOutputPlusZoom->setVisible(false);
    }else if(ui->lblOutputMinusZoom->isHidden()){
        ui->lblOutputMinusZoom->setVisible(true);
        ui->lblOutputPlusZoom->setVisible(true);
    }

    this->resizeEvent(NULL);
}

void Compiler::createMainWindowStyle(){
    QString style="QWidget#widget{border-width:1px; border-style:solid; border-color:#aaa; border-radius:3px;}"
                  "QPushButton#lblTextEditPlusZoom,QPushButton#lblOutputPlusZoom{background-image:url(url1)}"
                  "QPushButton#lblOutputMinusZoom,QPushButton#lblTextEditMinusZoom{background-image:url(url2)}"
                  "QPushButton#lblTextEditPlusZoom:pressed,QPushButton#lblOutputPlusZoom:pressed,QPushButton#lblOutputMinusZoom:pressed,QPushButton#lblTextEditMinusZoom:pressed{border: 2px solid #333399;}";

    QString path=this->destinyPath;
    path+="/img/generales/zoomIconPlus.png";
    style.replace("url1",path);

    path=this->destinyPath;
    path+="/img/generales/zoomIconMinus.png";
    style.replace("url2",path);

    qApp->setStyleSheet(style);
}

void Compiler::setDefaultFont(){
    this->sizeFontEdit=10;
    this->sizeFontOutput=10;
    this->updateAllEditorsFont();
    this->updateOutPutFont();
}

void Compiler::on_lblTextEditPlusZoom_clicked()
{
    if(this->sizeFontEdit<24){
        this->sizeFontEdit+=2;
        this->updateAllEditorsFont();
    }
}

void Compiler::updateAllEditorsFont(){
    QFont newFont("Courier New",this->sizeFontEdit,-1,false);
    for(int i=0;i<this->editors.count();i++){
        this->editors[i]->setFont(newFont);
    }
}

void Compiler::on_lblTextEditMinusZoom_clicked()
{
    if(this->sizeFontEdit>4){
        this->sizeFontEdit-=2;
        this->updateAllEditorsFont();
    }
}

void Compiler::updateOutPutFont(){
    ui->textEdit->setFont(QFont("MS Shell Dlg 2",this->sizeFontOutput,-1,false));
}

void Compiler::on_lblOutputPlusZoom_clicked()
{
    if(this->sizeFontOutput<24){
        this->sizeFontOutput+=2;
        this->updateOutPutFont();
    }
}

void Compiler::on_lblOutputMinusZoom_clicked()
{
    if(this->sizeFontOutput>4){
        this->sizeFontOutput-=2;
        this->updateOutPutFont();
    }
}

void Compiler::on_actionNueva_Clase_triggered()
{
    this->newClass(this);
}

void Compiler::newClass(QWidget *parent){
    QString option;
    bool test=false,ok=true,repetido=false;

    while(true){
        if(repetido){
            QMessageBox::warning(parent,"Nombre inválido","Ya existe una clase con ese nombre.");
        }else if(test){
            QMessageBox::warning(parent,"Nombre inválido","El nombre ingresado es inválido");
        }
        option=QInputDialog::getText(parent,"Información","Nombre de la clase:",QLineEdit::Normal,"",&ok);
        if(!ok)
            break;

        if(option.isEmpty())
            test=true;
        else if(this->checkClassName(option))
            repetido=true;
        else
            break;
    }
    if(ok){
        this->addNewClass(option);
    }
}

void Compiler::addNewClass(QString name){
    this->classCant++;

    this->clases.append(name);
    emit adminClasesNewClass(name);
    QString name1=name; name1+=".h";
    QString name2=name; name2+=".cpp";

    this->editors.append(new CodeEditor());
    this->editors.append(new CodeEditor());

    new EditorHighLighter(editors[this->editors.count()-2]->document());
    new EditorHighLighter(editors[this->editors.count()-1]->document());

    this->editors[this->editors.count()-2]->setTabStopWidth(25);
    this->editors[this->editors.count()-1]->setTabStopWidth(25);

    QVBoxLayout *Lay=new QVBoxLayout();
    Lay->setMargin(0);
    Lay->addWidget(this->editors[this->editors.count()-2]);

    QVBoxLayout *Lay2=new QVBoxLayout();
    Lay2->setMargin(0);
    Lay2->addWidget(this->editors[this->editors.count()-1]);

    QWidget *temp=new QWidget();
    temp->setLayout(Lay);

    QWidget *temp2=new QWidget();
    temp2->setLayout(Lay2);

    ui->tabWidget->addTab(temp,name1);
    ui->tabWidget->addTab(temp2,name2);

    this->updateAllEditorsFont();

}

void Compiler::on_actionBorrar_Clase_triggered()
{
    if(this->clases.count()==0){
        QMessageBox::information(this,"Mensaje","No hay ninguna clase para eliminar.");
        return;
    }
    this->adminClases->show();
}

bool Compiler::checkClassName(QString name){
    qDebug()<<"Research Name";
    if(name.isEmpty())
        return false;
    return this->clases.contains(name);
}

void Compiler::newClassReciever(QWidget *parent){
    this->newClass(parent);
}

void Compiler::removeClass(QString name){
    int i;
    for(i=0;i<this->clases.count();i++){
        qDebug()<<i<<"Compare"<<clases.at(i)<<name;
        if(this->clases.at(i)==name)
            break;
    }
    int number=(i+1)*2;
    int number2=number-1;

    qDebug()<<"Remove"<<name<<number<<number2;

    ui->tabWidget->removeTab(number);
    ui->tabWidget->removeTab(number2);

    delete this->editors.takeAt(number);
    delete this->editors.takeAt(number2);

    qDebug()<<"Emit remove"<<this->clases.at(i);
    emit adminClasesRemoveClass(i);
    this->clases.removeAt(i);
}

void Compiler::saveClassCode(QString name){

}

void Compiler::setToolBarIcons(){
    QString iconsPath=this->destinyPath;
    iconsPath+="/img/generales/";
    QList<QAction*> list=ui->toolBar->actions();

    QString Icon=iconsPath;
    Icon+="new.png";
    qDebug()<<"Path"<<Icon;
    list[0]->setIcon(QIcon(Icon));

    Icon=iconsPath;
    Icon+="close.png";
    list[2]->setIcon(QIcon(Icon));

    Icon=iconsPath;
    Icon+="run.png";
    list[4]->setIcon(QIcon(Icon));

}


void Compiler::startProcess(){
    qDebug()<<"iniciando";
    QString program = "cmd.exe";
    this->myProcess=new QProcess();
    myProcess->start(program);

    if (myProcess->waitForStarted(1000) == false)
        qDebug() << "Error starting external program";
    else
        qDebug() << "external program running";
    myProcess->waitForReadyRead(100);
    myProcess->waitForFinished(100);
    qDebug()<<"Inicio"<<myProcess->readAllStandardOutput();
}

QString Compiler::checkOutputChannel(bool &err,bool &esp){
    esp=false;
    int i=0;
    while(i<=20){
        myProcess->waitForBytesWritten(100);
        myProcess->waitForReadyRead(100);
        myProcess->waitForFinished(100);
        QString val=QString(myProcess->readAllStandardOutput());
        val.remove(0,this->bytesWrited);
        QString error=QString(myProcess->readAllStandardError());
        error.remove(0,this->bytesWrited);
        if(val.isEmpty() && error.isEmpty()){
            i++;
            continue;
        }else if(!error.isEmpty()){
            err=true;
            qDebug()<<"Retorno error"<<error;
            return error;
        }else{
            err=false;
            qDebug()<<"Retorno respuesta"<<val;
            return val;
        }
    }
    esp=err=true;
    return "El proceso está tardando demasiado...\n";
}

QString Compiler::sendCommand(QString comm, bool &err, bool &esp){
    comm.append("\n");
    qDebug()<<"Escribir:"<<comm;
    myProcess->waitForReadyRead(100);
    myProcess->waitForFinished(100);
    this->bytesWrited=myProcess->write(QByteArray(comm.toStdString().c_str()));
    QString value=this->checkOutputChannel(err,esp);
    qDebug()<<"Recibio"<<value;
    return value;
}

void Compiler::on_lineEdit_returnPressed()
{
    bool err,esp;
    QString commandR=this->sendCommand(ui->lineEdit->text(),err,esp);
    qDebug()<<"Interesting"<<commandR;
    ui->textEdit->append(commandR);
}

void Compiler::on_actionEjecutar_C_digo_triggered()
{
    this->createAllFiles();
    this->checkFilesCode();
}

void Compiler::createAllFiles(bool request){
    QString tempPath="";
    if(request){
        tempPath=QFileDialog::getExistingDirectory(this,"Seleccione un directorio");
        if(tempPath.isEmpty())
            return;
    }else{
        tempPath=this->filesDirectory;
        this->pathFiles.clear();
    }
    tempPath.append("/");
    int classPos=0;
    for(int i=0;i<this->editors.count();i++){
        QString f=tempPath;
        QString name;
        if(i==0){
            name="main.cpp";
            //f.append("main.cpp");
        }else{
            name=this->clases.at(classPos);
            //f.append(this->clases.at(classPos));
            if(i%2==0){
                name.append(".cpp");
                //f.append(".cpp");
                classPos++;
            }else{
                name.append(".h");
                //f.append(".h");
            }
        }
        f.append(name);
        QString val=this->editors.at(i)->toPlainText();
        if(!request)
            this->pathFiles.append(name);
        QFile file(f);
        file.open(QIODevice::Text |QIODevice::WriteOnly);
        file.write(val.toStdString().c_str());
        file.close();
    }
}

void Compiler::checkFilesCode(){
    bool err,esp;
    QString MainPath,value;
    MainPath="cd ";
    MainPath.append(this->filesDirectory);
    value=this->sendCommand(MainPath,err,esp);
    qDebug()<<"path"<<MainPath<<"answ"<<value;
    for(int i=0;i<this->pathFiles.count();i++){
        MainPath="g++ ";
        MainPath.append(pathFiles.at(i));
        qDebug()<<"Comando"<<MainPath;
        value=this->sendCommand(MainPath,err,esp);
        if(err | esp){
            ui->textEdit->append(value);
            return;
        }
    }
    ui->textEdit->append("Compilación realizada exitosamente...\n");

}


void Compiler::on_textEdit_textChanged()
{
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
}
