#ifndef QSTATEBUTTON_H
#define QSTATEBUTTON_H
#include <QPushButton>
#include "utils/qssgenerator.h"
/**
* QT Sudoku
* Written By John Sitarski & Sinan Kocadag
* Email Address John Sitarski - sitjy001@mymail.unisa.edu.au / Sinan Kocagag - kocsy006@mymail.unisa.edu.au
*/
class QStateButton : public QPushButton
{

    Q_OBJECT
private:
    bool isSwitchOn = false;
    QSSGenerator generator = QSSGenerator("QPushButton");
public:
    QStateButton(const QString &text);
    ~QStateButton(){
    };
    bool isSwitchedOn(){
        return isSwitchOn;
    }

public slots:
    void  changeState();

};

#endif // QSTATEBUTTON_H
