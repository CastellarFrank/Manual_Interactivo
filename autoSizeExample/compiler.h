#ifndef COMPILER_H
#define COMPILER_H

#include "codeeditor.h"
#include "editorhighlighter.h"
#include <QSplitter>
#include <QMainWindow>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QMessageBox>
#include <QMap>
#include <clasesform.h>
#include <QProcess>
#include <QFileDialog>
#include <QScrollBar>


namespace Ui {
    class Compiler;
}

class Compiler : public QMainWindow
{
    Q_OBJECT

public:
    explicit Compiler(QWidget *parent = 0);
    ~Compiler();
    void resizeEvent ( QResizeEvent * event );

private:
    Ui::Compiler *ui;
    QList<CodeEditor *> editors;
    int decrementX;
    int decrementY;
    int classCant;
    QSplitter *splitter;
    QString destinyPath;
    void createMainWindowStyle();
    int sizeFontEdit;
    int sizeFontOutput;
    void addNewClass(QString name);
    void setDefaultFont();
    void updateAllEditorsFont();
    void updateOutPutFont();
    QList<QString> clases;
    bool checkClassName(QString name);
    ClasesForm *adminClases;
    void newClass(QWidget *parent);
    void setToolBarIcons();
    QProcess *myProcess;
    void startProcess();
    QString checkOutputChannel(bool &err, bool &esp);
    QString sendCommand(QString comm,bool &err,bool &esp);
    int bytesWrited;
    void createAllFiles(bool request=false);
    QString filesDirectory;
    void checkFilesCode();
    QStringList pathFiles;

private slots:
    void on_textEdit_textChanged();
    void on_lineEdit_returnPressed();
    void on_actionEjecutar_C_digo_triggered();
    void on_actionBorrar_Clase_triggered();
    void on_actionNueva_Clase_triggered();
    void on_lblOutputMinusZoom_clicked();
    void on_lblOutputPlusZoom_clicked();
    void on_lblTextEditMinusZoom_clicked();
    void on_lblTextEditPlusZoom_clicked();
    void splitterMoveAction(int x,int y);
    void newClassReciever(QWidget*parent);
    void removeClass(QString name);
    void saveClassCode(QString name);

signals:
    void adminClasesNewClass(QString);
    void adminClasesRemoveClass(int);
};

#endif // COMPILER_H
