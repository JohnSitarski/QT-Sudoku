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
class SudokuCellWidget : public QLabel{

    Q_OBJECT

private:
    SudokuGrid *gridPointer;

    QSSGenerator generator =  QSSGenerator("QLabel"),menuGenerator = QSSGenerator("QMenu");
    int index;


public:
    QFont font;

    ~SudokuCellWidget();
    SudokuCellWidget(int index,SudokuGrid *gridPointer);
    void setBackgroundColor(std::string colorname) ;
    void setBorder(std::string colorname);
    void setBold(bool bold);


public slots:
    void showRightClickMenu(const QPoint &pos );
    void setValue();
    void setFinal();
    void clearCell();
    void clearCellBackground();

};

#endif
