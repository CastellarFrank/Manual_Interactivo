#include "windowsstarted.h"
#include "ui_windowsstarted.h"

WindowsStarted::WindowsStarted(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowsStarted)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint); //Set window to fixed size
    this->setWindowFlags(Qt::CustomizeWindowHint); //Set window with no title bar
    this->setWindowFlags(Qt::FramelessWindowHint); //Set a frameless window

    this->setStyleSheet("QPushButton#pushButton{border:0px;background-image:none; background-color:rgba(0,0,255,0.1);}");
    this->unCompressData();
    this->valor.loadStyles();

    QString dirIcon=this->destinyPath;
    dirIcon+="/img/generales/Start.png";
    qDebug()<<dirIcon;
    ui->label->setPixmap(QPixmap(dirIcon));

}

WindowsStarted::~WindowsStarted()
{
    delete ui;
}

void WindowsStarted::on_pushButton_clicked()
{
    this->valor.show();
    this->close();

}
void WindowsStarted::unCompressData(){
    this->destinyPath=QDir::tempPath();
    this->files.clear();
    this->directories.clear();
    QFile archivo("data/data.bnrcd");
    QFileInfo info(archivo);
    qDebug()<<"path"<<info.absoluteFilePath();
    if(!archivo.open(QIODevice::ReadWrite))
        return;
    archivo.read(reinterpret_cast<char*>(&this->head),sizeof(Header));
    this->destinyPath+="/";
    this->destinyPath+=head.mainDirectory;
    qDebug()<<"HEAD"<<head.mainDirectory;
    QDir dir;
    dir.mkdir(this->destinyPath);
    int pos=archivo.pos();
    for(int i=0;i<head.cantMetada;i++){
        MetaData temp;
        archivo.seek(pos);
        qDebug()<<pos;
        archivo.read(reinterpret_cast<char*>(&temp),sizeof(MetaData));
        pos=archivo.pos();
        qDebug()<<pos;
        QString pathFixed=this->fixPath(QString(temp.path));
        if(temp.archivoDirectory==0){
            dir.mkdir(pathFixed);
        }else{
            qDebug()<<"Curioso"<<temp.path<<temp.startData<<temp.sizeData<<temp.archivoDirectory;
            QFile tempFile(pathFixed);
            if(!tempFile.open(QIODevice::WriteOnly))
                return;
            archivo.seek(temp.startData);
            tempFile.write(archivo.read(temp.sizeData));
            tempFile.close();
        }
    }
    archivo.close();
}

int WindowsStarted::getSize(QFileInfo file){
    if(file.isFile()){
        this->files.push_back(file.absoluteFilePath());
        return file.size();
    }else{
        this->directories.push_back(file.absoluteFilePath());
        QDir temp(file.absoluteFilePath());
        QFileInfoList fi=temp.entryInfoList();
        fi.removeFirst();
        fi.removeFirst();
        int val=0;
        foreach(QFileInfo la,fi){
            val+=getSize(la);
        }
        return val;
    }
}

void WindowsStarted::writeFilesData(QFile *archivo){
    for(int i=0;i<head.directoryCant;i++){
        QString value=this->directories.at(i);
        MetaData meta;
        meta.archivoDirectory=0;
        meta.setPath(const_cast<char*>(value.toStdString().c_str()));
        archivo->write(reinterpret_cast<char*>(&meta),sizeof(MetaData));
    }
    int pos=archivo->pos();
    int cantWrited=0;
    for(int i=0;i<this->files.count();i++){
        QFile tempFile(this->files.at(i));
        if(!tempFile.open(QIODevice::ReadOnly)){
            return;
        }
        QString value=this->files.at(i);
        MetaData meta;
        meta.archivoDirectory=1;
        qDebug()<<"FilePath"<<value;
        meta.setPath(const_cast<char*>(value.toStdString().c_str()));
        meta.startData=head.allHeaderSize+cantWrited;
        meta.sizeData=tempFile.size();
        archivo->seek(pos);
        qDebug()<<"escribir"<<archivo->pos()<<value;
        archivo->write(reinterpret_cast<char*>(&meta),sizeof(MetaData));
        pos=archivo->pos();
        archivo->seek(meta.startData);
        cantWrited+=archivo->write(tempFile.readAll());
    }
}

QString WindowsStarted::fixPath(QString p){
    QString path=this->destinyPath;
    path+="/";
    qDebug()<<"original"<<p;
    QString main(head.mainDirectory);
    int pos=p.indexOf(main);
    int tam=main.length()+1;
    p=p.mid(pos+tam);
    qDebug()<<"Mid"<<p;
    path+=p;
    qDebug()<<"Fin"<<path;
    return path;
}
