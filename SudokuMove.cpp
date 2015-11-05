
#include "SudokuMove.h"
#include "ostream"
SudokuMove::SudokuMove(const int index, const int oldValue, const int newValue, const bool oldFinalValue,
                       const bool newFinalValue) {

    this->index = index;
    this->oldValue = oldValue;
    this->newValue = newValue;
    this->oldFinalValue = oldFinalValue;
    this->newFinalValue = newFinalValue;
}

int SudokuMove::getIndex() const {
    return this->index;
}

int SudokuMove::getNewValue() const {
    return this->newValue;
}

int SudokuMove::getOldValue() const {
    return this->oldValue;
}

bool SudokuMove::getNewFinalValue() const {
    return this->newFinalValue;
}

bool SudokuMove::getOldFinalValue() const {
    return this->oldFinalValue;
}

std::string SudokuMove::toString() const {
   std::stringstream stream;
   stream << index << "," << newValue << "," << oldValue << "," << newFinalValue << "," << oldFinalValue;
   return stream.str();
}
