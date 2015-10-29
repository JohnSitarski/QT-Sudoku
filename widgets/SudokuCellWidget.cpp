#include "SudokuCellWidget.h"


SudokuCellWidget::SudokuCellWidget(SudokuGrid *gridPointer){
    this->gridPointer = gridPointer;
    this->setAlignment(Qt::AlignCenter);
    font = this->font;
    font.setPointSize(18);
    this->setFont(font);
}


void SudokuCellWidget::setBackgroundColor(std::string colorname) {
    this->setStyleSheet("QLabel { background-color : "+QString::fromStdString(colorname)+";border:2px solid grey;}");
}
SudokuCellWidget::~SudokuCellWidget(){

}

void SudokuCellWidget::setBold(bool bold){
   font.setBold(bold);
   this->setFont(font);
}
