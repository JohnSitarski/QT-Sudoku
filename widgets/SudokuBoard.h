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

#include <QVBoxLayout>
#include <QTextEdit>


#include <QStringList>
#include "utils/Tokenizer.h"

#include <QFont>
#include <QFileDialog>
#include "widgets/GameScreen.h"
#include <QTextStream>
#include "widgets/QStateButton.h"
#include <ostream>

/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/
class SudokuBoard : public QWidget
{
    Q_OBJECT
private:
    std::map<int,std::string> borderMap;
    QVBoxLayout layout;

    QPushButton* saveButton =  new QPushButton("Save Puzzle");
    QPushButton* undoButton =  new QPushButton("Undo Last Move");
    QPushButton* importPuzzleButton =  new QPushButton("Import Puzzle");


    QString fileFilter = "Text file (*.txt)";

public:
    QStateButton* hintButton = new QStateButton("Show hints");
    QGridLayout* boardLayout = new QGridLayout();
    SudokuGrid grid;
    explicit SudokuBoard(QWidget *parent = 0);
    void refreshCells();
    void addCells();
    void updateHint();

signals:


public slots:
    void importGame();
    void saveGame();
    void showSinglePossibleValues();
    void showSingleHint(int index);
    void undo();


};

#endif // SUDOKUBOARD_H
