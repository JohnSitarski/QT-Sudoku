#include "SudokuCellWidget.h"



SudokuCellWidget::SudokuCellWidget(int index, SudokuGrid *gridPointer){
    //this->board = board;
    this->gridPointer = gridPointer;
    this->setAlignment(Qt::AlignCenter);
    font = this->font;
    font.setPointSize(12);
    this->setFont(font);
    this->index = index;
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(showRightClickMenu(const QPoint &)));
    menuGenerator.setForeground("white");
}



SudokuCellWidget::SudokuCellWidget(SudokuBoard *board,int index, SudokuGrid *gridPointer){
    this->board = board;
    this->gridPointer = gridPointer;
    this->setAlignment(Qt::AlignCenter);
    font = this->font;
    font.setPointSize(12);
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

/**
 * This method shows the right click menu.
 * This method  generators a right click menu every time the label is object is clicked on.
 */
void SudokuCellWidget::showRightClickMenu(const QPoint &pos){
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
    if (!board->hintButton->isSwitchedOn()){
        QAction* hintAction = new QAction("Show hint",this);
        hintAction->connect(hintAction,SIGNAL(triggered()),this,SLOT(showHint()));
        rightMenu.addAction(hintAction);
    }

    for (int i = 0;i<vector.size();i++){
        std::stringstream  ss;
        ss << "Possible Value " << vector.at(i) << std::endl;
        std::string string =  ss.str();
        QAction* action = new QAction(QString::fromStdString(string), this);
        action->connect(action,SIGNAL(triggered()),this,SLOT(setValue()));
        valueMenu.addAction(action);
    }
    rightMenu.addMenu(&valueMenu);
    rightMenu.exec(mapToGlobal(pos));
}



/**
 * This method sets the value for a sudokucell in the logic and also updates the ui component relating to it.
 */
void SudokuCellWidget::setValue( ){
    QAction *pAction = qobject_cast<QAction*>(sender());
    QString text  = pAction->text();
    int value =    text.split(" ")[2].toInt();
    int oldValue = gridPointer->getCell(index).getValue();
    bool b = gridPointer->getCell(index).isFinal();
    gridPointer->addSudokuMove(new SudokuMove(index,oldValue,value,b,b));
    this->gridPointer->getCell(index).setValue(value);
    this->setNum(this->gridPointer->getCell(index).getValue());
    clearCellBackground();
    if (this->board->hintButton->isSwitchedOn()){
        this->board->updateHint();
    }else{
        this->board->refreshCells();
    }
}

/**
 * Sets the back end logic of the cell to a final value and also updates the ui component.
 */
void SudokuCellWidget::setFinal(){

    SudokuCell sc =  this->gridPointer->getCell(index);
    bool change = !sc.isFinal();
    gridPointer->addSudokuMove(new SudokuMove(index,sc.getValue(),sc.getValue(),!change,change));
    this->gridPointer->getCell(index).setFinal(change);
    setBold(change);
    clearCellBackground();

}

/**
 * Clears the cell back to it's back end state with a white background thus removing hints etc.
 */
void SudokuCellWidget::clearCell(){
    setBold(false);
    this->setText("");
    this->gridPointer->getCell(index).setFinal(false);
    this->gridPointer->getCell(index).setValue(0);
    clearCellBackground();
    if (this->board->hintButton->isSwitchedOn()){
        this->board->updateHint();
    }else{
        this->board->refreshCells();
    }
}

/**
 * @brief SudokuCellWidget::clearCellBackground
 * Sets the cell's background color to white thus the inital state of a cell
 */
void SudokuCellWidget::clearCellBackground(){
    this->updateGeometry();
    this->setBackgroundColor("white");
}
/**
 * @brief SudokuCellWidget::showHint
 *  Shows the invidual hint for the cell.
 */
void SudokuCellWidget::showHint(){

    board->showSingleHint(index);
}
