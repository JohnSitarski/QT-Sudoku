#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

#include <string>
#include "SudokuCell.h"
#include "SudokuMove.h"
#include <math.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <QString>
#include <vector>
/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/
class SudokuGrid{
private:
    SudokuCell* cellArray[81] ;

    // list of cells





public:
    std::vector<SudokuMove*> moveVector;
    int getSection(int index) const;

    std::vector<int> getPossibleValues(int index) ;


    SudokuGrid();

    ~SudokuGrid();
    SudokuCell& getCell(int index) const;

    std::string getGridString() const;

    QString getQtGridString() const;
    QString getQtMoveString() const;

    std::vector<int> getCellLocation(int index) const;

    void setCell(int index, SudokuCell* cell);

    // TODO: Pass a file over or a string.
    void importGrid(const std::string gridString) ;

    void populateGrid();

    void exportGrid();

    int getIndex(int x, int y) const;

    SudokuMove* popMove();

    void addSudokuMove( SudokuMove* move);

    std::vector<SudokuCell*> getSudokuSection(int sectionNumber);


};







#endif // SUDOKUGRID_H
