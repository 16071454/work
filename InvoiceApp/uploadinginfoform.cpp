#include "uploadinginfoform.h"
#include "ui_uploadinginfoform.h"
#include "QDateTime"
#include "QTimer"
#include "LoginDlg.h"
#include <QMessageBox>

#pragma execution_character_set("utf-8")

UploadingInfoForm::UploadingInfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UploadingInfoForm)
{
    ui->setupUi(this);
    //this->setFixedSize(700,140);
    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [=](){

        QString tim = QDateTime::currentDateTime().toString(QString("yyyy-MM-dd HH:mm:ss"));
        ui->label_date->setText(QString(" %1  %2").arg("上传日期：").arg(tim));
    });
    ui->comboBox->setStyleSheet("color: rgb(0, 0, 0);background-color: rgb(255, 255, 255);font: 75 10pt \"微软雅黑\";");
    ui->label_amount->setText(QString("总张数: %1").arg(0));
    ui->label_sumprice->setText(QString("总金额: %1元").arg(0));
    // ui->label_name->setText(QString("报销人: %1").arg(""));
    ui->lineEdit_fourcode->setFocus();

    //    _selectedemployee = new selectemployerDialog();
    //    QList<QStringList> _list= Dialog::instanceLogin()->getemployer();
    //    for(int i=0;i<_list.count();i++)
    //    {
    //        _selectedemployee->setDataView(_list.at(i));
    //    }


    timer->start(1000);
    QThread *thread1 = new QThread(this);
    _mygetemployThread = new MygetemployerThread;
    _mygetemployThread->moveToThread(thread1);
    connect(this,SIGNAL(signal_start_thread(QString)),_mygetemployThread,SLOT(slot_dosomething(QString)));
    connect(_mygetemployThread,SIGNAL(finish_get_employInfo(QStringList)),this,SLOT(slot_getemployer(QStringList)));
    connect(_mygetemployThread,SIGNAL(signal_repeat_fourcode()),this,SLOT(slot_repeat_fourcode()));

    thread1->start();

}

UploadingInfoForm::~UploadingInfoForm()
{
    delete ui;
}

void UploadingInfoForm::setName(QString user)
{
    //ui->label_name->setText(QString("报销人: %1").arg(user));
}

void UploadingInfoForm::setPages(int pagescount)
{
    _count = pagescount;
    ui->label_amount->setText(QString("总张数: %1").arg(pagescount));
}

void UploadingInfoForm::setPrice(float price)
{
    _price = price;
    ui->label_sumprice->setText(QString("总金额: %1元").arg(price));
}

//void UploadingInfoForm::on_toolButton_clicked()
//{

//    if(_selectedemployee->exec()==QDialog::Accepted)
//    {
//        emit signal_set_refundname(_selectedemployee->getSelectedInfo());
//        setName(_selectedemployee->getSelectedInfo().at(1));
//    }

//}
void UploadingInfoForm::clearalltext()
{
    ui->label_amount->setText(QString("总张数: %1").arg(0));
    ui->label_sumprice->setText(QString("总金额: %1元").arg(0));
    ui->lineEdit_name->setText("");
    ui->lineEdit_company->setText("");
    ui->lineEdit_fourcode->setText("");
    ui->lineEdit_project->clear();
    ui->lineEdit_wbs->clear();
}

//void UploadingInfoForm::slot_setemployerdata(QList<QStringList> list)
//{
//    for(int i=0;i<list.count();i++)
//    {
//        QStringList strlist = list.at(i);

//        _selectedemployee->setDataView(strlist);
//    }
//}

QString UploadingInfoForm::getLabelname()
{
    return ui->lineEdit_name->text();
}

QString UploadingInfoForm::getcompany()
{
    return ui->lineEdit_company->text();
}

QString UploadingInfoForm::getdanjuleixing()
{
    return ui->comboBox->currentText();
}

QString UploadingInfoForm::getfourcode()
{
    return ui->lineEdit_fourcode->text();
}

QString UploadingInfoForm::gettotal()
{
    return QString("%1").arg(_price);
}

QString UploadingInfoForm::gettype()
{
    return ui->comboBox->currentText();
}

QString UploadingInfoForm::getcount()
{
    return  QString("%1").arg(_count);
}

void UploadingInfoForm::slot_getemployer(QStringList list)
{
    _employerlist = list;
    ui->lineEdit_name->setText(_employerlist.at(1));
    ui->lineEdit_company->setText( _employerlist.at(2));
    ui->lineEdit_project->setText( _employerlist.at(3));
    ui->lineEdit_wbs->setText( _employerlist.at(4));
    emit signal_setbutton(true);
}


void UploadingInfoForm::slot_repeat_fourcode()
{

    _employerlist.clear();
    ui->lineEdit_name->setText("");
    ui->lineEdit_company->setText("");
    ui->lineEdit_project->setText("");
    ui->lineEdit_wbs->setText("");

    emit signal_setbutton(false);
    QMessageBox::information(this,"提示","编号错误，请重新输入");
    return;
}

void UploadingInfoForm::on_lineEdit_fourcode_returnPressed()
{
    emit signal_start_thread(ui->lineEdit_fourcode->text());
}

void UploadingInfoForm::setCombtypeenable(bool enab)
{
   ui->comboBox->setEnabled(enab);
}

