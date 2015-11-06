#ifndef SUDOKUCELL_H
#define SUDOKUCELL_H

#include <string>
#include <sstream>
#include <QString>
#include <iostream>
#include <QTextStream>

/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/
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

    QString toQTString()const;

    friend std::ostream &operator<<(std::ostream&, const SudokuCell&) ;

    friend QTextStream &operator<<(QTextStream&, const SudokuCell&) ;

    SudokuCell(const SudokuCell&);

    SudokuCell &operator=(const SudokuCell &cell);

};
#endif // SUDOKUCELL_H
