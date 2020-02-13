#include "headdialog.h"
#include "ui_headdialog.h"
//#include "LoginDlg.h"

#pragma execution_character_set("utf-8")

HeadDialog::HeadDialog(QWidget *parent) :
    QDialog(parent),
    _parent(parent),
    ui(new Ui::HeadDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->label_logo->setFixedSize(52,52);
    QPixmap *pixmaplogo = new QPixmap(":/imag/logo.png");
    pixmaplogo->scaled(ui->label_logo->size(), Qt::KeepAspectRatio);
    ui->label_logo->setScaledContents(true);
    ui->label_logo->setPixmap(*pixmaplogo);

    ui->label_wenzi->setFixedSize(120,32);
    QPixmap *pixmap = new QPixmap(":/imag/mingcheng.png");
    pixmap->scaled(ui->label_wenzi->size(), Qt::KeepAspectRatio);
    ui->label_wenzi->setScaledContents(true);
    ui->label_wenzi->setPixmap(*pixmap);
}

HeadDialog::~HeadDialog()
{
    delete ui;
}

void HeadDialog::setUsername(QString name)
{
    ui->label->setText(name);
}

void HeadDialog::on_pushButton_clicked()
{
//    _parent->hide();
//    Dialog::instanceLogin()->show();
    emit signal_quite();
}
