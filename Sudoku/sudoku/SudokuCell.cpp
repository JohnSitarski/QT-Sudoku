//
// Created by John on 10/8/2015.
//

#include "SudokuCell.h"
#include <iostream>

SudokuCell::SudokuCell() {
    this->value = 0;
    this->final = false;
}

SudokuCell::SudokuCell(const SudokuCell &cell) {
    this->value = cell.value;
    this->final = cell.final;
}

SudokuCell::SudokuCell(int value) {
    this->value = value;
    this->final = false;
}

SudokuCell::SudokuCell(int value, bool b) {
    this->value = value;
    this->final = b;
}

SudokuCell &SudokuCell::operator=(const SudokuCell &cell) {
    if (this != &cell) {
        this->value = cell.value;
        this->final = cell.final;
    }
    return *this;
}


int SudokuCell::getValue() const {
    return this->value;
}

void SudokuCell::setValue(int value) {
    this->value = value;
}


bool SudokuCell::isFinal() const {
    return final;
}

void SudokuCell::setFinal(const bool b) {
    this->final = b;
}

std::string SudokuCell::toString() const {
    std::stringstream ss;
    ss << value;
    if (isFinal())
        ss << "F";
    return ss.str();
}

std::ostream &operator<<(std::ostream &ostream, const SudokuCell &cell) {
    ostream << cell.toString();
    return ostream;
}