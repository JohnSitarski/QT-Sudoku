//
// Created by John on 10/8/2015.
//

#ifndef SUDOKU_SUDOKUGRID_H
#define SUDOKU_SUDOKUGRID_H


#include <string>
#include "SudokuCell.h"
#include "SudokuMove.h"
#include <math.h>
#include <vector>
#include <stack>
#include <algorithm>
class SudokuGrid{
private:
    SudokuCell* cellArray[81] ;
    std::stack<SudokuMove*> moveVector;
    // list of cells





public:
    int getSection(int index) const;

    std::vector<int> getPossibleValues(int index) ;


    SudokuGrid();

    ~SudokuGrid();
    SudokuCell& getCell(int index) const;

    std::string getGridString() const;

    int* getCellLocation(int index) const;

    void setCell(int index, SudokuCell* cell);

    // TODO: Pass a file over or a string.
    void importGrid(const std::string gridString) ;

    void populateGrid();

    void exportGrid();

    int getIndex(int x, int y) const;

    SudokuMove& popMove();

    void addSudokuMove(const SudokuMove& move);

   std::vector<SudokuCell*> getSudokuSection(int sectionNumber);


};



#endif //SUDOKU_SUDOKUGRID_H
