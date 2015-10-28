#ifndef SUDOKUMOVE_H
#define SUDOKUMOVE_H
#include "SudokuCell.h"

class SudokuMove{

private:
    int index;
    int oldValue;
    int newValue;
    bool oldFinalValue;
    bool newFinalValue;



public:
    SudokuMove(const int index,const int oldValue,const int newValue,const bool oldFinalValue,const bool newFinalValue );

    int getIndex() const;

    int getOldValue() const;

    int getNewValue() const;

    bool getOldFinalValue() const;

    bool getNewFinalValue() const;


    std::string toString() const;


};

#endif // SUDOKUMOVE_H
