#include "xuanfuoptionform.h"
#include "ui_xuanfuoptionform.h"

xuanfuoptionForm::xuanfuoptionForm(INVOICEOPERATION type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xuanfuoptionForm)
{
    ui->setupUi(this);
    _parent= parent;
    this->setWindowOpacity(0.5);
   seticon(type);
}

xuanfuoptionForm::~xuanfuoptionForm()
{
    delete ui;
}

void xuanfuoptionForm::seticon(INVOICEOPERATION type)
{
    if(type != FAILD)
    {
        ui->pushButton_2->hide();
    }
    else
    {
     ui->pushButton_2->setVisible(true);
    }
}

void xuanfuoptionForm::slot_show()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");


    animation->setDuration(500);

    animation->setStartValue(QRect(_parent->width(),this->y(),this->width(),this->height()));

    animation->setEndValue(QRect(_parent->width()-this->width(),this->y(),this->width(),this->height()));

    animation->start();
   // this->setGeometry(this->width(),this->y(),_xuanfuform->width(),_xuanfuform->height());
   // this->setVisible(true);

}

void xuanfuoptionForm::slot_hide()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");

    animation->setDuration(500);

    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    animation->setEndValue(QRect(this->x()+this->width(),this->y(),this->width(),this->height()));


    animation->start();
   // this->setVisible(false);
}

void xuanfuoptionForm::on_pushButton_clicked()
{
    emit signal_show_pic();
}

void xuanfuoptionForm::on_pushButton_2_clicked()
{
    emit signal_delete_pic();

}

void xuanfuoptionForm::on_pushButton_3_clicked()
{
    emit signal_jiangji_pic();
}
