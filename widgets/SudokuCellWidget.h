#ifndef SUDOKUCELLWIDGET_H
#define SUDOKUCELLWIDGET_H
#include <QLabel>
#include "SudokuGrid.h"
#include "utils/qssgenerator.h"
#include <QWidget>
#include <QFont>
class SudokuCellWidget : public QLabel{

Q_OBJECT

private:
    SudokuGrid *gridPointer;
    QFont font;
    QSSGenerator generator =  QSSGenerator("QLabel");


public:
     ~SudokuCellWidget();

    SudokuCellWidget(SudokuGrid *gridPointer);
    void setBackgroundColor(std::string colorname) ;
    void setBorder(std::string colorname);
    void setBold(bool bold);


};

#endif
