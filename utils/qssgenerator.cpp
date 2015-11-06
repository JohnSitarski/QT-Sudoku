#include "qssgenerator.h"
/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/


QSSGenerator::QSSGenerator(QString componentName){
    this->componentName = componentName;
}

QString QSSGenerator::generateStyleSheet(){
    return componentName+"{"+
            "background-color:"+backgroundColor+";"+

            (borderComponent != ""? borderComponent+";":"" )

            + (foreground.length()>0 ?"color:"+ foreground :"")+"}";
}

void QSSGenerator::setBackgroundColor(QString color){
this->backgroundColor = color;
}

void QSSGenerator::setBorderComponent(QString border){
this->borderComponent= border;
}

void QSSGenerator::setForeground(QString color){
   this->foreground= color;
}

QString QSSGenerator::getBorderComponent(){
    return borderComponent;
}

