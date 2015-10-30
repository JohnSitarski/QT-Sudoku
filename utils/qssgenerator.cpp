#include "qssgenerator.h"



QSSGenerator::QSSGenerator(QString componentName){
    this->componentName = componentName;
}

QString QSSGenerator::generateStyleSheet(){
    return componentName+"{"+
            "background-color:"+backgroundColor+";"+

            (borderComponent != ""? borderComponent+";":"" )

            +"}";
}

void QSSGenerator::setBackgroundColor(QString color){
this->backgroundColor = color;
}

void QSSGenerator::setBorderComponent(QString border){
this->borderComponent= border;
}

QString QSSGenerator::getBorderComponent(){
    return borderComponent;
}

