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

#include <QFont>
#include <QFileDialog>
#include "widgets/GameScreen.h"
#include <QTextStream>
#include "widgets/QStateButton.h"
#include <ostream>
class SudokuBoard : public QWidget
{
    Q_OBJECT
private:
    std::map<int,std::string> borderMap;
    QVBoxLayout layout;

    QPushButton* saveButton =  new QPushButton("Save Puzzle");
    QPushButton* undoButton =  new QPushButton("Undo Last Move");
    QPushButton* importPuzzleButton =  new QPushButton("Import Puzzle");
    QStateButton* hintButton = new QStateButton("Show hints");

    QString fileFilter = "Text file (*.txt)";

public:
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
    void undo();


};

#endif // SUDOKUBOARD_H
