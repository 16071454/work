#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QPropertyAnimation>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QObject *parent = 0);

    void setProperty(QString picPath, QString text);

    void zoom1();
    void zoom2();

};

#endif // MYBUTTON_H
