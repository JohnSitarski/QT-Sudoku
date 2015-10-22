//
// Created by John on 10/8/2015.
//Jo

#include "SudokuGrid.h"
#include "utils/Tokenizer.h"

#include <iostream>


std::vector<int> SudokuGrid::getPossibleValues(int index) {
    std::vector<int> vector;
    for (int i = 1; i < 10; i++) {
        vector.push_back(i);
    }
    int *point = getCellLocation(index);
    std::vector<SudokuCell *> sectionCells = getSudokuSection(getSection(index));
    for (int i = 0; i < sectionCells.size(); i++) {
        if (std::find(vector.begin(), vector.end(), sectionCells.at(i)->getValue()) != vector.end()) {
            int index = std::find(vector.begin(), vector.end(), sectionCells.at(i)->getValue()) - vector.begin();
            std::swap(vector[index], vector.back());
            vector.pop_back();
        }
    }

    for (int x = 0; x < 9; x++) {
        int value = getCell(getIndex(x, point[1])).getValue();
        if (std::find(vector.begin(), vector.end(), value) != vector.end()) {
            int index = std::find(vector.begin(), vector.end(), value) - vector.begin();
            std::swap(vector[index], vector.back());
            vector.pop_back();
        }
    }

    for (int x = 0; x < 9; x++) {
        int value = getCell(getIndex(point[0], x)).getValue();
        //std:: cout << getIndex(point[0],x) << " value:"<< value << std::endl;
        if (std::find(vector.begin(), vector.end(), value) != vector.end()) {
            int index = std::find(vector.begin(), vector.end(), value) - vector.begin();
            std::swap(vector[index], vector.back());
            vector.pop_back();
        }
    }
    return vector;
}

int SudokuGrid::getIndex(int x, int y) const {
    return y * 9 + x;
}


int SudokuGrid::getSection(int index) const {
    int *location = getCellLocation(index);
    int subdivX = location[0] / 3;
    int subdivY = location[1] / 3;
    int sectionIndex = subdivY * 3 + subdivX;
    return sectionIndex;

}

SudokuGrid::SudokuGrid() {
    for (int index = 0; index < 81; index++) {
        setCell(index, new SudokuCell(0));
    }
}

SudokuGrid::~SudokuGrid() {
    for (int i = 0; i < 81; i++) {
        delete cellArray[i];
    }
    // delete cellArray;
}

void SudokuGrid::exportGrid() {

}

SudokuCell &SudokuGrid::getCell(int index) const {
    SudokuCell *point = cellArray[index];
    return *point;
}

int *SudokuGrid::getCellLocation(int index) const {
    static int point[2];
    point[0] = index % 9;
    point[1] = index / 9;
    return point;
}

void SudokuGrid::importGrid(std::string grid) {
    Tokenizer tokenizer(grid, ' ');
    std::vector<std::string> vector = tokenizer.getTokens();
    for (int i = 0; i < 81; i++) {
        const std::string element = vector[i];
        const bool final = element.length() > 1;
        const int j = (element.at(0));
        const int number = j >= 48 ? j - 48 : j;
        setCell(i, new SudokuCell(number, final));
    }


}

std::vector<SudokuCell *> SudokuGrid::getSudokuSection(int sectionNumber) {
    std::vector<SudokuCell *> vector;
    for (int i = 0; i < 81; i++) {
        int sectionIndex = getSection(i);
        if (sectionIndex == sectionNumber) {
            vector.push_back(&getCell(i));
        }
    }
    return vector;
}


std::string SudokuGrid::getGridString() const {
    std::stringstream ss;
    int oldColumn = 0;
    for (int index = 0; index < 81; index++) {
        if (index / 9 != oldColumn) {
            oldColumn = index / 9;
            ss << std::endl;
        }
        ss << getCell(index) << " ";
    }
    return ss.str();
}

void SudokuGrid::setCell(int index, SudokuCell *cell) {
    cellArray[index] = cell;
}

SudokuMove &SudokuGrid::popMove() {
    SudokuMove *m = this->moveVector.top();
    moveVector.pop();
    return *m;

}

void SudokuGrid::addSudokuMove(const SudokuMove &move) {
//    moveVector.push(&move);

}




