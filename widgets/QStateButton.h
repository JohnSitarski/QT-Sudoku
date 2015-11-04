#ifndef QSTATEBUTTON_H
#define QSTATEBUTTON_H
#include <QPushButton>
#include "utils/qssgenerator.h"
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
