#ifndef CODEEDITOR_H
#define CODEEDITOR_H
#include <QPlainTextEdit>
#include <QObject>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QSize>
#include <QWidget>
class LineNumberArea;
class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
     CodeEditor(QWidget *parent = 0);
     void lineNumberAreaPaintEvent(QPaintEvent *event);
     int lineNumberAreaWidth();

 protected:
     void resizeEvent(QResizeEvent *event);

 private slots:
     void updateLineNumberAreaWidth(int newBlockCount);
     void highlightCurrentLine();
     void updateLineNumberArea(const QRect &, int);


 private:
     QWidget *lineNumberArea;
     void keyPressEvent(QKeyEvent *e);
 };


 class LineNumberArea : public QWidget
 {
 public:
     LineNumberArea(CodeEditor *editor) : QWidget(editor) {
         codeEditor = editor;
     }

     QSize sizeHint() const {
         return QSize(codeEditor->lineNumberAreaWidth(), 0);
     }

 protected:
     void paintEvent(QPaintEvent *event) {
         codeEditor->lineNumberAreaPaintEvent(event);
     }

 private:
     CodeEditor *codeEditor;
 };


 #endif
