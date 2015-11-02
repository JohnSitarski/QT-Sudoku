#include "SudokuCellWidget.h"


SudokuCellWidget::SudokuCellWidget(int index, SudokuGrid *gridPointer){
    this->gridPointer = gridPointer;
    this->setAlignment(Qt::AlignCenter);
    font = this->font;
    font.setPointSize(18);
    this->setFont(font);
    this->index = index;
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(showRightClickMenu(const QPoint &)));
    menuGenerator.setForeground("white");
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

void SudokuCellWidget::showRightClickMenu(const QPoint &pos){
    QMenu rightMenu( this);

    QAction action("Possible Value: 1", this);
    connect(&action, SIGNAL(triggered()), this, SLOT(setValue(i)));
    rightMenu.addAction(&action);

    rightMenu.exec(mapToGlobal(pos));
}

void SudokuCellWidget::setValue(int value ){
    this->setNum(value);
    this->gridPointer->getCell(index).setValue(value);
}
void SudokuCellWidget::setFinal(bool b){

}
