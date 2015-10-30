#ifndef QSSGENERATOR_H
#define QSSGENERATOR_H

#include <QString>

class QSSGenerator
{
private:
    QString componentName = "";
    QString backgroundColor = "";
    QString borderComponent = "";

public:
    QSSGenerator(QString componentName);

    QString generateStyleSheet();

    void setBackgroundColor(QString color);

    void setBorderComponent(QString border);
    QString getBorderComponent();
};

#endif // QSSGENERATOR_H
