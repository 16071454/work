#include "scanlogodialog.h"
#include "ui_scanlogodialog.h"

ScanLogoDialog::ScanLogoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScanLogoDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);


    ui->label->setFixedSize(this->width(),this->height());

    QPixmap *pixmap = new QPixmap(":/imag/scanlogopng.png");
    pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(*pixmap);
}

ScanLogoDialog::~ScanLogoDialog()
{
    delete ui;
}
