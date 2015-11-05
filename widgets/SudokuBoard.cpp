#include "SudokuBoard.h"
#include <QStringList>
#include "utils/Tokenizer.h"
SudokuBoard::SudokuBoard(QWidget *parent) :
    QWidget(parent)
{
    this->importPuzzleButton->connect(importPuzzleButton,SIGNAL(clicked()),this,SLOT(importGame()));
    this->saveButton->connect(saveButton,SIGNAL(clicked()),this,SLOT(saveGame()));
    this->hintButton->connect(hintButton,SIGNAL(clicked()),this,SLOT(showSinglePossibleValues()));
    this->undoButton->connect(undoButton,SIGNAL(clicked()),this,SLOT(undo()));
    std::string LEFT  = "border-left : 2px solid black; ",RIGHT = "border-right : 2px solid black; ",

            BOTTOM="border-bottom : 2px solid black; ",TOP="border-top : 2px solid black; ";

    int topBorders[18] = {27,28,29,30,31,32,33,34,35,54,55,56,57,58,59,60,61,62};


    for (int index = 0;index<18;index++){
        std::map<int,std::string>::const_iterator it = borderMap.find(topBorders[index]);
        if (it == borderMap.end()){
            borderMap.insert(std::pair<int,std::string>(topBorders[index],TOP));
        }
    }

    int rightBorders[18] = {2,11,20,5,14,23,29,38,47,56,
                            65,74,32,41,50,59,68,77};

    for (int index = 0;index<18;index++){
        std::map<int,std::string>::const_iterator it = borderMap.find(rightBorders[index]);
        if (it == borderMap.end()){
            borderMap.insert(std::pair<int,std::string>(rightBorders[index],RIGHT));
        }else{
            std::string border = it->second+RIGHT;
            borderMap.at(rightBorders[index]) = border;
        }
    }


    int bottomBorders[18] = {18,19,20,21,22,23,24,25,26,45,46,47,48,49,50,51,52,53};

    for (int index = 0;index<18;index++){
        std::map<int,std::string>::const_iterator it = borderMap.find(bottomBorders[index]);
        if (it == borderMap.end()){
            borderMap.insert(std::pair<int,std::string>(bottomBorders[index],BOTTOM));
        }else{
            std::string border = it->second+BOTTOM;
            borderMap.at(bottomBorders[index]) = border;
        }
    }


    int leftBorders[18] = {3,12,21,30,39,48,57,66,75,6,15,24,33,42,51,60,69,78};

    for (int index = 0;index<18;index++){
        std::map<int,std::string>::const_iterator it = borderMap.find(leftBorders[index]);
        if (it == borderMap.end()){
            borderMap.insert(std::pair<int,std::string>(leftBorders[index],LEFT));
        }else{
            std::string border = it->second+LEFT;
            borderMap.at(leftBorders[index]) = border;
        }
    }

    boardLayout->setHorizontalSpacing(1);
    boardLayout->setVerticalSpacing(1);

    addCells();
    QHBoxLayout*  hlayout = new QHBoxLayout();
    hlayout->addWidget(this->importPuzzleButton);
    hlayout->addWidget(saveButton);

    hlayout->addWidget(undoButton);
    hlayout->addWidget(hintButton);
    layout.addLayout(hlayout);
    layout.addLayout(boardLayout);
    this->setLayout(&layout);
}
void SudokuBoard::importGame(){

    QString filePath = QFileDialog::getOpenFileName(this,tr("Select Saved Game"),QDir::homePath(),fileFilter);
    if (filePath.length()>0){
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream cout(stdout);
        QTextStream in(&file);
        std::string readIn ;

        QString line =  in.readAll();
        readIn += line.toUtf8().constData();
        QStringList  list = line.split("\n");
        grid.moveVector.clear();
        if (list.length()>9){
            QString moveLine = list.at(9);
            QStringList moveList = moveLine.split(" ");
            for (int i = 0 ;i<moveList.size();i++){
                QStringList moveListOrder = moveList.at(i).split(",");
                if (moveListOrder.size()>3){
                    int index = moveListOrder.at(0).toInt();
                    int newValue = moveListOrder.at(1).toInt();
                    int oldValueint = moveListOrder.at(2).toInt();
                    bool newBool = moveListOrder.at(3).toInt() >0 ? true : false;
                    bool oldBool  =  moveListOrder.at(4).toInt()>0 ? true : false;
                    cout <<  newBool << endl;
                    grid.addSudokuMove(new SudokuMove(index,oldValueint,newValue,oldBool,newBool));
                }

            }
        }

        grid.importGrid(readIn);
        refreshCells();

    }

}


void SudokuBoard::saveGame(){
    QString saveFile =  QFileDialog::getSaveFileName(this,"Save File",QDir::homePath(),fileFilter);
    if (saveFile.length() >0 && !saveFile.endsWith(".txt")){
        saveFile.append(".txt");
    }
    QTextStream cout(stdout);
    if (saveFile.length()>0){
        QFile file (saveFile);
        if (file.open(QIODevice::ReadWrite)){
            QTextStream stream(&file);
            stream << this->grid.getQtGridString() << "\n";
            stream << this->grid.getQtMoveString() << endl;
        }
        file.close();
    }
}
void SudokuBoard::addCells(){
    for (int i  = 0;i<81;i++){
        std::vector<int>  location = grid.getCellLocation(i);
        SudokuCellWidget *label = new SudokuCellWidget(i,&grid);
        if (grid.getCell(i).getValue() !=0){
            label->setNum(grid.getCell(i).getValue());
        }
        label->setBackgroundColor("white");
        boardLayout->addWidget(label,location[0],location[1]);
        std::map<int,std::string>::iterator it;
        it = borderMap.find(i);
        if (it != borderMap.end()){
            label->setBorder(borderMap.at(i));
        }
    }

}

void SudokuBoard::refreshCells(){
    for (int i  = 0;i<81;i++){
        bool bo = grid.getCell(i).isFinal();
        const   int value = grid.getCell(i).getValue();
        SudokuCellWidget* pointer =  dynamic_cast<SudokuCellWidget*>(boardLayout->itemAt(i)->widget());
        if (value == 0){
            pointer->setText("");
        }else{
            pointer->setNum(value);
        }
        pointer->setBold(bo);
        pointer->updateGeometry();

        pointer->setBackgroundColor("white");
    }
}

void SudokuBoard::showSinglePossibleValues(){
    QStateButton* pointer = dynamic_cast<QStateButton*> (sender());
    if (pointer->isSwitchedOn() == false){
        for (int i = 0;i<81;i++){
            SudokuCellWidget* pointer1 =  dynamic_cast<SudokuCellWidget*>(boardLayout->itemAt(i)->widget());
            pointer1->font.setPixelSize(12);
            pointer1->setFont(pointer1->font);
            if (grid.getCell(i).getValue() == 0){
                pointer1->setBackgroundColor("white");
                pointer1->setText("");
            }

        }
    }else{
        updateHint();
    }
}
void SudokuBoard::updateHint(){
    for (int i = 0;i<81;i++){
        std::vector<int> vector = grid.getPossibleValues(i);
        if (grid.getCell(i).getValue() == 0){
            SudokuCellWidget* pointer1 =  dynamic_cast<SudokuCellWidget*>(boardLayout->itemAt(i)->widget());
            if (vector.size() == 1 ){
                pointer1->setBackgroundColor("green");
            }else if (vector.size()>1){
                std::stringstream  ss;
                for (int j = 0;j<vector.size();j++){

                    ss << vector.at(j);
                    if (j != (vector.size()-1)){
                        ss << ",";
                    }
                    if (j %3 == 0){
                        ss << "\n";
                    }
                }
                pointer1->font.setPixelSize(12);
                pointer1->setFont(pointer1->font);
                pointer1->setText(QString::fromStdString(ss.str()));
                pointer1->setBackgroundColor("grey");
            }
        }
    }
}

    void SudokuBoard::undo(){
    if (grid.moveVector.size()>0){
        SudokuMove* move = grid.popMove();

        QTextStream cout(stdout);
        cout << QString::fromStdString(move->toString()) << endl;
        grid.getCell(move->getIndex()).setFinal(move->getOldFinalValue());
        grid.getCell(move->getIndex()).setValue(move->getOldValue());
        if (this->hintButton->isSwitchedOn() == false){
            this->refreshCells();
        }else{
            updateHint();
        }
    }

}


