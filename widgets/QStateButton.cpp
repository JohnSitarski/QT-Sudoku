#include "QStateButton.h"

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
