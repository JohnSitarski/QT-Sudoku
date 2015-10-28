#ifndef SUDOKUCELLWIDGET_H
#define SUDOKUCELLWIDGET_H
#include <QLabel>
#include "SudokuGrid.h"
#include <QWidget>
class SudokuCellWidget : public QLabel{

Q_OBJECT

private:
    SudokuGrid *gridPointer;

public:
     ~SudokuCellWidget();

    SudokuCellWidget(SudokuGrid *gridPointer);
    void setBackgroundColor(std::string colorname) ;
    void setBold(bool bold);
};

#endif
