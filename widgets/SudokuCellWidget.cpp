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
    // generate dynamic menu
    QMenu rightMenu( this);
    SudokuCell sc = gridPointer->getCell(index);
    if (sc.getValue() !=0){
        QAction* finalAction  = new QAction(sc.isFinal() ?"Make unfinal" :"Make final",this);
        finalAction->connect(finalAction,SIGNAL(triggered()),this,SLOT(setFinal()));
        rightMenu.addAction(finalAction);
        QAction* clearAction = new QAction("Clear",this);
        clearAction->connect(clearAction,SIGNAL(triggered()),this,SLOT(clearCell()));
        rightMenu.addAction(clearAction);
        rightMenu.addSeparator();

    }
    QMenu valueMenu("Possible Moves",this);
    std::vector<int>  vector =  gridPointer->getPossibleValues(index);
    for (int i = 0;i<vector.size();i++){
        std::string string =  "Possible Value "+vector.at(i);
        QAction* action = new QAction(QString::fromStdString(string), this);
        action->connect(action,SIGNAL(triggered()),this,SLOT(setValue()));
        valueMenu.addAction(action);
    }
    rightMenu.addMenu(&valueMenu);

    rightMenu.exec(mapToGlobal(pos));
}

void SudokuCellWidget::setValue( ){

    this->setNum(1);
    this->gridPointer->getCell(index).setValue(1);
}
void SudokuCellWidget::setFinal(){
    SudokuCell sc =  this->gridPointer->getCell(index);
    bool change = !sc.isFinal();
    this->gridPointer->getCell(index).setFinal(change);
    setBold(change);
}
void SudokuCellWidget::clearCell(){
    setBold(false);
    this->setText("");
    this->gridPointer->getCell(index).setFinal(false);
    this->gridPointer->getCell(index).setValue(0);
}
