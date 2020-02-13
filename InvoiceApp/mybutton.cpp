#include "mybutton.h"
#include <QPropertyAnimation>
#include <qlabel.h>
#include <QHBoxLayout>
#include <qicon.h>

MyButton::MyButton(QObject *parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
}

void MyButton::setProperty(QString picPath, QString text)
{

    this->setIcon(QPixmap(picPath));
    this->setText(text);

   // this->setFixedSize(100,45);


}

void MyButton::zoom1()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");

    animation->setDuration(1000);

    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}

void MyButton::zoom2()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");

    animation->setDuration(1000);

    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}

