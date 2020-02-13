#ifndef MYTOOLBUTTON_H
#define MYTOOLBUTTON_H
#include <QToolButton>
#include <QEvent>
#include <QMouseEvent>
#include "invoiceable.h"

class MyToolButton : public QToolButton
{
public:
    MyToolButton(QObject *parent = 0);
public:
    void setType(INVOICETYPE type);
private:
    INVOICETYPE _type;

protected:
    void enterEvent(QEvent *e); //鼠标进入事件
    void leaveEvent(QEvent *e);//鼠标离开事件
};

#endif // MYTOOLBUTTON_H
