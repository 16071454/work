#include "scanverticalform.h"
#include "ui_scanverticalform.h"

ScanVerticalForm::ScanVerticalForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScanVerticalForm)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);

    ui->toolButton->setType(RECIPTION);
    ui->toolButton_2->setType(TEAMWORK);
    ui->toolButton_3->setType(ADDWORK);
    ui->toolButton_4->setType(OTHERS);
    ui->toolButton_5->setType(TRAVEL);
}

ScanVerticalForm::~ScanVerticalForm()
{
    delete ui;
}

void ScanVerticalForm::on_toolButton_clicked()
{
    emit signal_modify_label(RECIPTION);
    this->hide();
}

void ScanVerticalForm::on_toolButton_2_clicked()
{
     emit signal_modify_label(TEAMWORK);
    this->hide();
}

void ScanVerticalForm::on_toolButton_3_clicked()
{
     emit signal_modify_label(ADDWORK);
    this->hide();
}

void ScanVerticalForm::on_toolButton_4_clicked()
{
     emit signal_modify_label(OTHERS);
    this->hide();
}

void ScanVerticalForm::on_toolButton_5_clicked()
{
    emit signal_modify_label(TRAVEL);
    this->hide();
}
