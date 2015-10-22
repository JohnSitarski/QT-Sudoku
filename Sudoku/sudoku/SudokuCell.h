//
// Created by John on 10/8/2015.
//

#ifndef SUDOKU_SUDOKUCELL_H
#define SUDOKU_SUDOKUCELL_H

#include <string>
#include <sstream>

class SudokuCell {
private:
    int value = 0;
    bool final = false;

public:
    SudokuCell();

    SudokuCell(int value);

    SudokuCell(int value,bool b);

    int getValue() const;

    void setValue(int value);

    bool isFinal() const;

    void setFinal(const bool b);

    std::string toString() const;

    friend std::ostream &operator<<(std::ostream&, const SudokuCell&) ;

    SudokuCell(const SudokuCell&);

    SudokuCell &operator=(const SudokuCell &cell);

};

#endif //SUDOKU_SUDOKUCELL_H
