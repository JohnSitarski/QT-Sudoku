#include "SudokuGrid.h"
#include "utils/Tokenizer.h"
#include "ostream"



std::vector<int> SudokuGrid::getPossibleValues(int index) {
    std::vector<int> vector;
    for (int i = 1; i < 10; i++) {
        vector.push_back(i);
    }
    std::vector<int> point  = getCellLocation(index);
    std::vector<SudokuCell *> sectionCells = getSudokuSection(getSection(index));
    for (int i = 0; i < sectionCells.size(); i++) {
        if (std::find(vector.begin(), vector.end(), sectionCells.at(i)->getValue()) != vector.end()) {
            vector.erase(std::remove(vector.begin(),vector.end(),sectionCells.at(i)->getValue()),vector.end());
        }
    }

    for (int x = 0; x < 9; x++) {

        int value = getCell(getIndex(x, point[0])).getValue();
        if (std::find(vector.begin(), vector.end(), value) != vector.end()) {
            vector.erase(std::remove(vector.begin(),vector.end(),value),vector.end());
        }
    }

    for (int y = 0; y < 9; y++) {
        int value = getCell(getIndex(point[1], y)).getValue();
        if (std::find(vector.begin(), vector.end(), value) != vector.end()) {
            vector.erase(std::remove(vector.begin(),vector.end(),value),vector.end());
        }
    }
    return vector;
}

int SudokuGrid::getIndex(int x, int y) const {
    return y * 9 + x;
}


int SudokuGrid::getSection(int index) const {
    std::vector<int> location = getCellLocation(index);
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

std::vector<int> SudokuGrid::getCellLocation(int index) const {
    std::vector<int> point;
    point.push_back(index / 9); // x
    point.push_back( index % 9); // y


    return point;
}

void SudokuGrid::importGrid(std::string grid) {
    Tokenizer tokenizer(grid, ' ');
    std::vector<std::string> vector = tokenizer.getTokens();
    for (int i = 0; i < 81; i++) {
        const std::string element = vector[i];
        bool final = element.length() > 1;
        const int j = (element.at(0));
        int number = j >= 48 ? j - 48 : j;
        if (number >9){
            number = 0;
            final =  false;
        }
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


QString SudokuGrid::getQtGridString() const {
    return QString::fromStdString(getGridString());
}

QString SudokuGrid::getQtMoveString() const {
    std::stringstream stream;
    for (int i = moveVector.size()-1 ; i>-1 ; i--){
       SudokuMove* move = moveVector.at(i);

        stream << move->toString() << " ";
    }
    return QString::fromStdString(stream.str());
}

void SudokuGrid::setCell(int index, SudokuCell *cell) {
    cellArray[index] = cell;
}

SudokuMove *SudokuGrid::popMove() {
    SudokuMove *m = this->moveVector.back();
    moveVector.pop_back();
    return m;

}

void SudokuGrid::addSudokuMove( SudokuMove* move) {
    moveVector.push_back(move);
}
