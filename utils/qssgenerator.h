#ifndef QSSGENERATOR_H
#define QSSGENERATOR_H

#include <QString>
/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/
class QSSGenerator
{
private:
    QString componentName = "";
    QString backgroundColor = "";
    QString borderComponent = "";
    QString foreground = "";

public:
    QSSGenerator(QString componentName);

    QString generateStyleSheet();

    void setBackgroundColor(QString color);
    void setForeground(QString color);
    void setBorderComponent(QString border);
    QString getBorderComponent();
};

#endif // QSSGENERATOR_H
