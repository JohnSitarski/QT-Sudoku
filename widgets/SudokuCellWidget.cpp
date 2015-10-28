#include "SudokuCellWidget.h"


SudokuCellWidget::SudokuCellWidget(SudokuGrid *gridPointer){
    this->gridPointer = gridPointer;
}


void SudokuCellWidget::setBackgroundColor(std::string colorname) {
    this->setStyleSheet("QLabel { background-color : "+QString::fromStdString(colorname)+";}");
}
SudokuCellWidget::~SudokuCellWidget(){

}
