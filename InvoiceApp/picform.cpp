#include "picform.h"
#include "ui_picform.h"
#include <QMessageBox>

picForm::picForm(INVOICEOPERATION type,QString path,int width,int roatation,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::picForm)
{
    ui->setupUi(this);

    setFixedSize(width,380);
    structpicinfo.id = path;
    structpicinfo.roation = roatation;
    _xuanfuform = new xuanfuoptionForm(type,this);
    connect(this,SIGNAL(signal_show()),_xuanfuform,SLOT(slot_show()));
    connect(this,SIGNAL(signal_hide()),_xuanfuform,SLOT(slot_hide()));
    _xuanfuform->setGeometry(this->width(),this->y(),_xuanfuform->width(),_xuanfuform->height());
    connect(_xuanfuform,SIGNAL(signal_show_pic()),this,SLOT(slot_show_pic()));
    connect(_xuanfuform,SIGNAL(signal_delete_pic()),this,SLOT(slot_send_operation()));
    connect(_xuanfuform,SIGNAL(signal_jiangji_pic()),this,SLOT(slot_jiangji_operation()));
    QMatrix matrix;
    matrix.rotate(0-roatation);
    // QMessageBox::information(NULL,"replyFinished1",QString("%1").arg(roatation));
    ui->label->setFixedSize(width,380);
    //label->setScaledContents(true);
    QPixmap pixmaplogo (path);

    pixmaplogo = pixmaplogo.scaled(ui->label->size(), Qt::KeepAspectRatio);

    ui->label->setPixmap(pixmaplogo.transformed(matrix, Qt::SmoothTransformation));
    _picview = new PicViewDialog();
    _picview->setpicPath(structpicinfo.id,roatation);

}

void picForm::slot_send_operation()
{
   emit signal_operation_pic(this);
}

void picForm::slot_jiangji_operation()
{
   emit signal_jiangji_pic(this);
}

picForm::~picForm()
{
    delete ui;
}

void picForm::setxuanfuicon(INVOICEOPERATION type)
{
    _xuanfuform->seticon(type);
}

void picForm::slot_show_pic()
{
    _picview->show();
}

void picForm::enterEvent(QEvent *)
{
    emit signal_show();

}

void picForm::leaveEvent(QEvent *)
{
    emit signal_hide();

}
