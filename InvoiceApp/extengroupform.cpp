#include "extengroupform.h"
#include "ui_extengroupform.h"

extengroupForm::extengroupForm(QWidget *parent) :
    QWidget(parent),
     isshow(false),
     cando(false),
    ui(new Ui::extengroupForm)
{
    ui->setupUi(this);
    this->setFixedSize(740,140);

}

extengroupForm::~extengroupForm()
{
    delete ui;
}

void extengroupForm::on_toolButton_5_clicked()
{
    if(cando==true)
    {

        if(isshow)//hide
        {
            QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");

            animation->setDuration(1000);

            animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

            animation->setEndValue(QRect(this->x()+ui->frame->width(),this->y(),this->width(),this->height()));

            isshow=false;
            ui->toolButton_5->setArrowType(Qt::LeftArrow);
            animation->start();
        }
        else//show
        {
            QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");

            animation->setDuration(1000);

            animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

            animation->setEndValue(QRect(this->x()-ui->frame->width(),this->y(),this->width(),this->height()));

            isshow=true;
            ui->toolButton_5->setArrowType(Qt::RightArrow);
            animation->start();
        }
    }
}

int extengroupForm::getframwidth()
{
    return ui->frame->width();
}

void extengroupForm::backwardForm()
{
    if(isshow)//hide
    {
        QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");

        animation->setDuration(1000);

        animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

        animation->setEndValue(QRect(this->x()+ui->frame->width(),this->y(),this->width(),this->height()));

        isshow=false;
        ui->toolButton_5->setArrowType(Qt::LeftArrow);
        animation->start();
    }
}

void extengroupForm::extendwardForm()
{
     if(!isshow)//show
    {
        QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");

        animation->setDuration(1000);

        animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

        animation->setEndValue(QRect(this->x()-ui->frame->width(),this->y(),this->width(),this->height()));

        isshow=true;
        ui->toolButton_5->setArrowType(Qt::RightArrow);
        animation->start();
    }
}

void extengroupForm::on_toolButton_clicked()
{
    emit signal_scan_show(RECIPTION);
}

void extengroupForm::on_toolButton_2_clicked()
{
     emit signal_scan_show(TEAMWORK);
}

void extengroupForm::on_toolButton_3_clicked()
{
     emit signal_scan_show(ADDWORK);
}

void extengroupForm::on_toolButton_6_clicked()
{
     emit signal_scan_show(TRAVEL);
}

void extengroupForm::on_toolButton_4_clicked()
{
     emit signal_scan_show(OTHERS);
}
