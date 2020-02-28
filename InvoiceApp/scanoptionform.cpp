#include "scanoptionform.h"
#include "ui_scanoptionform.h"
#include <qdir.h>

#pragma execution_character_set("utf-8")
scanoptionForm::scanoptionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scanoptionForm)
{
    ui->setupUi(this);
    _scanverticaldlg = new ScanVerticalForm();
    connect(_scanverticaldlg,SIGNAL(signal_modify_label(INVOICETYPE)),this,SLOT(setText(INVOICETYPE)));
    connect(_scanverticaldlg,SIGNAL(signal_modify_label(INVOICETYPE)),this,SIGNAL(siganl_set_invoice_type(INVOICETYPE)));

     _scanverticaldlg->setVisible(false);
      _scantype = "招待";
      ui->pushButton->setVisible(false);
}

scanoptionForm::~scanoptionForm()
{
    delete ui;
}

QString scanoptionForm::getscantype()
{
    return _scantype;
}

void scanoptionForm::on_pushButton_clicked() //上传识别发票
{

    emit signal_check_invoice();
}

void scanoptionForm::on_toolButton_3_clicked()
{
    _scanverticaldlg->setVisible(true);
    _scanverticaldlg->setGeometry(ui->toolButton_3->mapToGlobal(QPoint(0,0)).x()+ui->toolButton_3->width()/20,ui->toolButton_3->mapToGlobal(QPoint(0,0)).y()+ui->toolButton_3->rect().height()+10,_scanverticaldlg->width(),_scanverticaldlg->height());
}

void scanoptionForm::setText(INVOICETYPE type)
{
    switch (type) {
    case RECIPTION:
    {
        ui->label->setText("正在扫描发票类:招待餐费住宿类");
        _scantype = "招待";
        QPixmap pmap(":/imag/saomiaoreciptionnormal.png");
        ui->toolButton_3->setIcon(pmap);
        ui->toolButton_3->setIconSize(pmap.size());
        ui->toolButton_3->setText("招待餐费住宿类");
    }
      //  emit siganl_set_invoice_type(RECIPTION);
        break;
    case TEAMWORK:
    {
        ui->label->setText("正在扫描发票类:误餐费(团建)类");
        _scantype = "误餐";
        QPixmap pmap(":/imag/saomiaoteamworknormal.png");
        ui->toolButton_3->setIcon(pmap);
        ui->toolButton_3->setIconSize(pmap.size());
        ui->toolButton_3->setText("误餐费(团建)类");
    }

      //  emit siganl_set_invoice_type(TEAMWORK);
        break;
    case ADDWORK:
    {
        ui->label->setText("正在扫描发票类:无需识别验真类");
        _scantype = "误餐";
        QPixmap pmap(":/imag/saomiaoaddworknormal.png");
        ui->toolButton_3->setIcon(pmap);
        ui->toolButton_3->setIconSize(pmap.size());
        ui->toolButton_3->setText("无需识别验真类");
    }

       //   emit siganl_set_invoice_type(ADDWORK);
        break;
    case TRAVEL:
    {
        ui->label->setText("正在扫描发票类:合同类");
         _scantype = "合同";
        QPixmap pmap(":/imag/saomiaotravelnormal.png");
        ui->toolButton_3->setIcon(pmap);
        ui->toolButton_3->setIconSize(pmap.size());
        ui->toolButton_3->setText("合同类");
    }

       //  emit siganl_set_invoice_type(TRAVEL);
        break;
    case OTHERS:
    {
        ui->label->setText("正在扫描发票类:其他类");
         _scantype = "其他";
        QPixmap pmap(":/imag/saomiaoothernormal.png");
        ui->toolButton_3->setIcon(pmap);
        ui->toolButton_3->setIconSize(pmap.size());
        ui->toolButton_3->setText("   其他类");

      }
        break;
    default:
        break;
    }
}

void scanoptionForm::setpushbutton(bool visbale)
{
    ui->pushButton->setVisible(visbale);
}


void scanoptionForm::on_toolButton_2_clicked()
{
    emit signal_continue_scan(1);//剪切板
}

void scanoptionForm::on_toolButton_clicked()
{
    emit signal_auto_scan(0);
}


void scanoptionForm::on_toolButton_4_clicked()
{
     emit signal_auto_scan(2);//本地文件
}
