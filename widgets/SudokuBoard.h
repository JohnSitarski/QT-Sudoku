#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <QWidget>
#include <map>
#include <QGridLayout>
#include "SudokuGrid.h"
#include "SudokuCell.h"
#include "widgets/SudokuCellWidget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
class SudokuBoard : public QWidget
{
    Q_OBJECT
private:
      std::map<int,std::string> borderMap;
      QVBoxLayout layout;
      SudokuGrid grid;
      QPushButton* saveButton =  new QPushButton("Save Puzzle");
      QPushButton* undoButton =  new QPushButton("Undo Last Move");

public:
    explicit SudokuBoard(QWidget *parent = 0);
      void importGame(std::string gameString);
signals:


public slots:

};

#endif // SUDOKUBOARD_H
