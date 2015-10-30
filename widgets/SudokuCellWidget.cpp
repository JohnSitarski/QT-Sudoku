#include "SudokuCellWidget.h"


SudokuCellWidget::SudokuCellWidget(int index, SudokuGrid *gridPointer){
    this->gridPointer = gridPointer;
    this->setAlignment(Qt::AlignCenter);
    font = this->font;
    font.setPointSize(18);
    this->setFont(font);
    this->index = index;
}



void SudokuCellWidget::setBackgroundColor(std::string colorname) {
    generator.setBackgroundColor(QString::fromStdString(colorname));
    this->setStyleSheet(generator.generateStyleSheet());
}



SudokuCellWidget::~SudokuCellWidget(){

}

void SudokuCellWidget::setBorder(std::string border){
    generator.setBorderComponent(QString::fromStdString(border));
    this->setStyleSheet(generator.generateStyleSheet());

}

void SudokuCellWidget::setBold(bool bold){
   font.setBold(bold);
   this->setFont(font);
}
