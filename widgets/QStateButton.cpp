#include "QStateButton.h"
/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/
QStateButton::QStateButton( const QString &text)
{    if (!isSwitchOn){
        generator.setBackgroundColor("green");
    }else{
        generator.setBackgroundColor("red");
    }
     this->setStyleSheet(generator.generateStyleSheet());
     this->updateGeometry();
     this->setText(text);
     connect(this,SIGNAL(clicked()),SLOT(changeState()));

}

void QStateButton::changeState(){
    isSwitchOn = !isSwitchOn;
    if (!isSwitchOn){
        generator.setBackgroundColor("green");
    }else{
        generator.setBackgroundColor("red");
    }
    this->setStyleSheet(generator.generateStyleSheet());

}
