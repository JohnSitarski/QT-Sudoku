#include <iostream>
#include "sudoku/SudokuCell.h"
#include "sudoku/SudokuGrid.h"
#include "sudoku/utils/Tokenizer.h"
using namespace std;

int main() {
    SudokuCell cell = SudokuCell(2);
    SudokuGrid grid;
    grid.setCell(80,&cell);
    grid.importGrid("1 2 3 4 5F 6 7 8 0 0 0 0 0 0 0 0 0 8 0 0 0 0 0 0 0 0 0 0 7 0 0 0 0 0 0 6 0 0 0 0 0 0 0 0 5 0 0 0 0 0 0 0 0 4 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 0 1");
    cout << grid.getGridString() << endl;
    std:: vector<int> vector = grid.getPossibleValues(15);
    for (auto c: vector){
        cout << "Possible result: " << c<< endl;

    }


    return 0;
}