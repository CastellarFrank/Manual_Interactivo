#ifndef EDITORHIGHLIGHTER_H
#define EDITORHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QDebug>

class EditorHighLighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit EditorHighLighter(QTextDocument *parent = 0);

protected:
     void highlightBlock(const QString &text);

private:
     struct HighlightingRule
     {
         QRegExp pattern;
         QTextCharFormat format;
     };
     QVector<HighlightingRule> highlightingRules;

     QRegExp commentStartExpression;
     QRegExp commentEndExpression;

     QTextCharFormat numberFormat;
     QTextCharFormat keywordFormat;
     QTextCharFormat classFormat;
     QTextCharFormat singleLineCommentFormat;
     QTextCharFormat multiLineCommentFormat;
     QTextCharFormat quotationFormat;
     QTextCharFormat functionFormat;
     QTextCharFormat importClassFormat;
     QTextCharFormat numeralWord;

};

#endif // EDITORHIGHLIGHTER_H
