#ifndef SUDOKUCELLWIDGET_H
#define SUDOKUCELLWIDGET_H
#include <QLabel>
#include "SudokuGrid.h"
#include "utils/qssgenerator.h"
#include <QWidget>
#include <QFont>
#include <QMenu>
#include <QAction>
#include <QContextMenuEvent>
#include <QMenu>
#include <sstream>
#include "widgets/SudokuBoard.h"

class SudokuBoard;
/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/
class SudokuCellWidget : public QLabel{

    Q_OBJECT

private:
    SudokuGrid *gridPointer;

    QSSGenerator generator =  QSSGenerator("QLabel"),menuGenerator = QSSGenerator("QMenu");
    int index;


public:
    QFont font;

    ~SudokuCellWidget();

    SudokuBoard* board;


    SudokuCellWidget( int index,SudokuGrid *gridPointer);

    SudokuCellWidget(SudokuBoard* board, int index,SudokuGrid *gridPointer);
    void setBackgroundColor(std::string colorname) ;
    void setBorder(std::string colorname);
    void setBold(bool bold);


public slots:
    void showRightClickMenu(const QPoint &pos );
    void setValue();
    void setFinal();
    void clearCell();
    void clearCellBackground();
    void showHint();

};

#endif
