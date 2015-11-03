#include "myaction.h"
class MyAction : public QAction
{
  Q_OBJECT
  public:
    MyAction(QString someActionInfo)
      : someActionInfo_(someActionInfo)
    {
      connect(this, SIGNAL(triggered()),
              this, SLOT(onTriggered()));
    }
  signals:
    void triggered(QString someActionInfo);
  private slots:
    void onTriggered() {
      emit triggered(someActionInfo_);
    }
  private:
    QString someActionInfo_;
};
