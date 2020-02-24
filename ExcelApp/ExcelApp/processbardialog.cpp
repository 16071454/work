#include "processbardialog.h"
#include "ui_processbardialog.h"

processBarDialog::processBarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::processBarDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedHeight(40);

}

processBarDialog::~processBarDialog()
{
    delete ui;
}

void processBarDialog::setvalue(int value)
{
    ui->progressBar->setValue(value);
}
void processBarDialog::setMaxvalue(int maxvalue)
{
    ui->progressBar->setMaximum(maxvalue);
}

void processBarDialog::setlabelText(QString text)
{
    ui->label->setText(text);
}

void processBarDialog::slot_setvalue(int value)
{
     ui->progressBar->setValue(value);
}
