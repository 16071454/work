#include "scanoptionform.h"
#include "ui_scanoptionform.h"
#include <qdir.h>

#pragma execution_character_set("utf-8")
scanoptionForm::scanoptionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scanoptionForm)
{
    ui->setupUi(this);
    ui->toolButton_reset->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->toolButton_2->setStyleSheet("font: 12pt \"微软雅黑\";color:rgb(255,255,255)");
}

scanoptionForm::~scanoptionForm()
{
    delete ui;
}

void scanoptionForm::setindexButtonEnable(bool isvisible)
{
    ui->pushButton->setVisible(isvisible);
}

void scanoptionForm::setscanButtonEnable(bool isvisible)
{
    ui->toolButton_2->setVisible(isvisible);
}

void scanoptionForm::setLableText(QString str)
{
    ui->label->setText(str);
}



void scanoptionForm::on_pushButton_clicked() //上传识别发票
{

    emit signal_check_invoice();
}

void scanoptionForm::on_toolButton_3_clicked()
{
    emit signal_read_excel();

}

void scanoptionForm::on_toolButton_2_clicked()
{
    emit signal_continue_scan();
   ui->toolButton_reset->setVisible(true);
}


void scanoptionForm::on_toolButton_reset_clicked()
{
    emit signal_reset_data();
    ui->toolButton_reset->setVisible(false);
}
