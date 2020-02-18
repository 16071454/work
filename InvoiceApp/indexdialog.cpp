#include "indexdialog.h"
#include "ui_indexdialog.h"
#include <QDesktopWidget>
#include <QSpacerItem>
#include <QTimer>
#include <QMessageBox>
#include <QLabel>
#include <QDir>
#include <LoginDlg.h>
#include <QDesktopServices>

extern QString _Uploadname;


#pragma execution_character_set("utf-8")

#define STORTPATH "E:/newjob/invoice"

IndexDialog::IndexDialog(QWidget *parent) :
    QDialog(parent),
    _successTable(NULL),
    _failTable(NULL),
    _problemTable(NULL),
    _faildWidget(NULL),
    _sucesaddworkWidget(NULL),
    _sucestravelWidget(NULL),
    _sucesrectionsWidget(NULL),
    _sucesothersWidget(NULL),
    _sucesworkteamWidget(NULL),
    _problemaddworkWidget(NULL),
    _problemrectionsWidget(NULL),
    _problemothersWidget(NULL),
    _problemworkteamWidget(NULL),
    _problemtravelWidget(NULL),
    problemlabel(NULL),
    faildlabel(NULL),
    _scandlg(NULL),
    _movedlg(NULL),
    successlabel(NULL),
    _updownform(NULL),
    //_processbar(NULL),
    ui(new Ui::IndexDialog)
{
    ui->setupUi(this);

    qRegisterMetaType<QMap<QString,QString> > ("QMap<QString,QString>>");
    setWindowFlags(Qt::CustomizeWindowHint);
    ui->pushButton_sumbit->setVisible(false);
   // ui->pushButton_cancel->setVisible(false);
    if(_updownform ==NULL)
    {
        _updownform = new UploadingInfoForm();
        connect(_updownform,SIGNAL(signal_setbutton(bool)),this,SLOT(slot_setbaoxiao(bool)));

    }

    // this->setAttribute(Qt::WA_DeleteOnClose, true);
    _head = new HeadDialog(this);
    connect(_head,&HeadDialog::signal_quite,this,[=](){
        this->close();
        _sumsuccpic.clear();
        _sucesspicTypeList.clear();
        Dialog::instanceLogin()->show();
        _updownform->clearalltext();
    });

    ui->horizontalLayout_head->addWidget(_head);



    ui->horizontalLayout->addWidget(_updownform);
    ui->horizontalLayout->addSpacerItem(new QSpacerItem(100,5,QSizePolicy::Expanding));
    _extendform = new extengroupForm(this);
    connect(_extendform,SIGNAL(signal_scan_show(INVOICETYPE)),this,SLOT(slot_show_scan(INVOICETYPE)));


    this->setFixedSize(QApplication::desktop()->size()*8/9);

    _webpage = new webDialog(this);

    ui->scrollArea->setWidgetResizable(true);
    _extendform->setGeometry(this->width()-_extendform->getframwidth()+70,_head->height()+7, _extendform->width(),_extendform->height());
    connect(this,SIGNAL(signal_cleardata()),this,SLOT(slot_cleardata()));

    connect(ui->pushButton_cancel,&MyButton::clicked, [=](){
        ui->pushButton_cancel->zoom1();
        ui->pushButton_cancel->zoom2();
        QTimer::singleShot(500,this,[=](){
            emit signal_cleardata();
        });

    });

    _vlayout = new QVBoxLayout (ui->scrollArea->widget());
    /////////song
    // _vlayout = new QVBoxLayout (ui->widget);
    _vlayout->setSpacing(20);

    successrelabel = NULL;
    successaddworklabel= NULL;
    successteamworklabel= NULL;
    successotherslabel= NULL;
    successtravellabel= NULL;

    problemrelabel= NULL;
    problemaddworklabel= NULL;
    problemteamworklabel= NULL;
    problemotherslabel= NULL;
    problemtravellabel= NULL;

    _width = this->width();


    _scandlg = new scandlg();
    connect(_scandlg,SIGNAL(signal_scan_end(QMap<QString,QString>)),this,SLOT(slot_setSumpic(QMap<QString,QString>)));//这里应该成
    connect(_scandlg,SIGNAL(siganl_set_invoice_type(INVOICETYPE)),this,SLOT(slot_setinvoice_type(INVOICETYPE)));
    connect(_scandlg,&scandlg::signal_back_index,this,[=](){this->show();});//
    connect(_scandlg,SIGNAL(signal_show_index()),this,SLOT(slot_show_dlg()));

    QThread *thread1 = new QThread(this);
    _uploainvoicethread = new upLoadInvoiceThread();
    _uploainvoicethread->moveToThread(thread1);
    connect(this,SIGNAL(signal_start_thread()),_uploainvoicethread,SLOT(slot_dosomthing()));
    connect(_uploainvoicethread,SIGNAL(signal_finished(QString)),this,SLOT(slot_finishupload(QString)));
    thread1->start();

    QThread *thread = new QThread(this);
    _cleaninitObject = new cleanInitFile;
    _cleaninitObject->moveToThread(thread);
    connect(this,SIGNAL(signal_startcleanfile_thread()),_cleaninitObject,SLOT(slot_dosomething()));
    thread->start();
}

IndexDialog::~IndexDialog()
{
    delete ui;
}

void IndexDialog::setusername(QString name,QString password)
{
    _head->setUsername(name);
    // _updownform->setName(name);
    _scandlg->setusername(name);
    _webpage->setusername(name);
    _username = name;
    _password = password;
}

void IndexDialog::deleteAllitemsOfLayout(QLayout* layout){

    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr)

    {
        ///setParent为NULL，防止删除之后界面不消失

        if(child->widget())

        {

            child->widget()->setParent(NULL);

        }else if(child->layout()){

            deleteAllitemsOfLayout(child->layout());

        }

        delete child;
    }
    successrelabel = NULL;
    successaddworklabel= NULL;
    successteamworklabel= NULL;
    successotherslabel= NULL;
    successtravellabel= NULL;

    problemrelabel= NULL;
    problemaddworklabel= NULL;
    problemteamworklabel= NULL;
    problemotherslabel= NULL;
    problemtravellabel= NULL;

    _successTable= NULL;
    _failTable= NULL;
    _problemTable= NULL;
    _faildWidget= NULL;
    _sucesaddworkWidget= NULL;
    _sucestravelWidget= NULL;
    _sucesrectionsWidget= NULL;
    _sucesothersWidget= NULL;
    _sucesworkteamWidget= NULL;
    _problemaddworkWidget= NULL;
    _problemrectionsWidget= NULL;
    _problemothersWidget= NULL;
    _problemworkteamWidget= NULL;
    _problemtravelWidget= NULL;
    problemlabel= NULL;
    faildlabel= NULL;
    successlabel= NULL;

}


void IndexDialog::setsucessrectiontable()
{
    QList<picForm*>succrectionlist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==RECIPTION && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==SUCCEED)
        {
            succrectionlist.append(_sumsuccpic.at(i));
        }
    }
    // _successTable->cleartable();

    for(int i=0;i<succrectionlist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(succrectionlist.at(i)->structpicinfo.receipttype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(succrectionlist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(succrectionlist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
        _successTable->setDataView(datalist);
    }
}

void IndexDialog::setsucessteamworktable()
{
    QList<picForm*>succteamworklist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {

        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==TEAMWORK&& _sumsuccpic.at(i)->structpicinfo.invoiceoperation==SUCCEED)
        {
            succteamworklist.append(_sumsuccpic.at(i));
        }
    }
    //_successTable->cleartable();

    for(int i=0;i<succteamworklist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(succteamworklist.at(i)->structpicinfo.receipttype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(succteamworklist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(succteamworklist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
        _successTable->setDataView(datalist);
    }
}

void IndexDialog::setsucessaddworktable()
{
    QList<picForm*>succaddworklist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==ADDWORK&& _sumsuccpic.at(i)->structpicinfo.invoiceoperation==SUCCEED)
        {
            succaddworklist.append(_sumsuccpic.at(i));
        }
    }
    //_successTable->cleartable();

    for(int i=0;i<succaddworklist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(succaddworklist.at(i)->structpicinfo.receipttype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(succaddworklist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(succaddworklist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
      //  _successTable->setDataView(datalist);
    }
}

void IndexDialog::setsucesstraveltable()
{
    QList<picForm*>succtravellist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==TRAVEL && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==SUCCEED)
        {
            succtravellist.append(_sumsuccpic.at(i));
        }
    }
    //_successTable->cleartable();

    for(int i=0;i<succtravellist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(succtravellist.at(i)->structpicinfo.receipttype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(succtravellist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(succtravellist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
        //_successTable->setDataView(datalist);
    }
}

void IndexDialog::setsucessotherltable()
{
    QList<picForm*>succotherlist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==OTHERS && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==SUCCEED)
        {
            succotherlist.append(_sumsuccpic.at(i));
        }
    }
    //_successTable->cleartable();

    for(int i=0;i<succotherlist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(succotherlist.at(i)->structpicinfo.receipttype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(succotherlist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(succotherlist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
        _successTable->setDataView(datalist);
    }
}

void IndexDialog::setsucessrectionwidget()
{
    QList<picForm*>succrectionlist;

    //招待
    if(_sucesrectionsWidget==NULL)
    {
        _sucesrectionsWidget = new QTableWidget();
        _sucesrectionsWidget->verticalHeader()->hide();
        _sucesrectionsWidget->horizontalHeader()->hide();
        _sucesrectionsWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _sucesrectionsWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _sucesrectionsWidget->setSelectionMode(QAbstractItemView::NoSelection);
        _sucesrectionsWidget->setColumnCount(3);


    }
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==RECIPTION && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==SUCCEED)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = _sumsuccpic.at(i)->structpicinfo.invoiceoperation;
            _pic->structpicinfo.invoicetype = _sumsuccpic.at(i)->structpicinfo.invoicetype;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            succrectionlist.append(_pic);

        }
    }


    _sucesrectionsWidget->setRowCount(0);
    _sucesrectionsWidget->setFixedSize(_width,0);



    if(successrelabel==NULL)
    {
        successrelabel = new QLabel("招待餐费住宿类");
        successrelabel->setStyleSheet("color:black;font: 75 12pt \"微软雅黑\";");
        _vlayout->addWidget(successrelabel);
    }
    if(!succrectionlist.isEmpty())
    {
        setpicwidget(succrectionlist,_sucesrectionsWidget);
    }


}

void IndexDialog::setsucessteamworkwidget()
{
    //团建类
    if(_sucesworkteamWidget==NULL)
    {
        _sucesworkteamWidget = new QTableWidget();
        _sucesworkteamWidget->verticalHeader()->hide();
        _sucesworkteamWidget->horizontalHeader()->hide();
        _sucesworkteamWidget->setColumnCount(3);
        _sucesworkteamWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //_sucessWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _sucesworkteamWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _sucesworkteamWidget->setSelectionMode(QAbstractItemView::NoSelection);

    }
    QList<picForm*>succteamworklist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==TEAMWORK && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==SUCCEED)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = _sumsuccpic.at(i)->structpicinfo.invoiceoperation;
            _pic->structpicinfo.invoicetype = _sumsuccpic.at(i)->structpicinfo.invoicetype;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            succteamworklist.append(_pic);
        }
    }
    _sucesworkteamWidget->setRowCount(0);
    _sucesworkteamWidget->setFixedSize(_width,0);

    if(successteamworklabel==NULL)
    {
        successteamworklabel = new QLabel("误餐费(团建)类");
        successteamworklabel->setStyleSheet("color:black;font: 75 12pt \"微软雅黑\";");
        _vlayout->addWidget(successteamworklabel);
    }
    if(!succteamworklist.isEmpty())
    {
        setpicwidget(succteamworklist,_sucesworkteamWidget);
    }


}

void IndexDialog::setsucessaddworkwidget()
{
    //加班类
    if(_sucesaddworkWidget==NULL)
    {
        _sucesaddworkWidget = new QTableWidget();
        _sucesaddworkWidget->verticalHeader()->hide();
        _sucesaddworkWidget->horizontalHeader()->hide();
        _sucesaddworkWidget->setColumnCount(3);
        _sucesaddworkWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _sucesaddworkWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _sucesaddworkWidget->setSelectionMode(QAbstractItemView::NoSelection);

    }


    QList<picForm*>succaddworklist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==ADDWORK && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==SUCCEED)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = SUCCEED;
            _pic->structpicinfo.invoicetype =ADDWORK;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            succaddworklist.append(_pic);
        }
    }
    _sucesaddworkWidget->setRowCount(0);
    _sucesaddworkWidget->setFixedSize(_width,0);


    if(successaddworklabel==NULL)
    {
        successaddworklabel = new QLabel("加班餐费住宿类");
        successaddworklabel->setStyleSheet("color:black;font: 75 12pt \"微软雅黑\";");
        _vlayout->addWidget(successaddworklabel);
    }
    if(!succaddworklist.isEmpty())
    {
        setpicwidget(succaddworklist,_sucesaddworkWidget);
    }


}

void IndexDialog::setsucesstravelwidget()
{

    QList<picForm*>succtravellist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==TRAVEL && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==SUCCEED)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = _sumsuccpic.at(i)->structpicinfo.invoiceoperation;
            _pic->structpicinfo.invoicetype = _sumsuccpic.at(i)->structpicinfo.invoicetype;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            succtravellist.append(_pic);
        }
    }


    //差旅
    if(_sucestravelWidget==NULL)
    {
        _sucestravelWidget = new QTableWidget();
        _sucestravelWidget->verticalHeader()->hide();
        _sucestravelWidget->horizontalHeader()->hide();
        _sucestravelWidget->setColumnCount(3);
        _sucestravelWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //_sucessWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _sucestravelWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _sucestravelWidget->setSelectionMode(QAbstractItemView::NoSelection);

    }
    _sucestravelWidget->setRowCount(0);
    _sucestravelWidget->setFixedSize(_width,0);



    if(successtravellabel==NULL)
    {
        successtravellabel = new QLabel("合同类");
        successtravellabel->setStyleSheet("color:black;font: 75 12pt \"微软雅黑\";");
        _vlayout->addWidget(successtravellabel);
    }
    if(!succtravellist.isEmpty())
    {
        setpicwidget(succtravellist,_sucestravelWidget);
    }

}

void IndexDialog::setsucessotherlwidget()
{
    QList<picForm*>succotherlist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==OTHERS && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==SUCCEED)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = _sumsuccpic.at(i)->structpicinfo.invoiceoperation;
            _pic->structpicinfo.invoicetype = _sumsuccpic.at(i)->structpicinfo.invoicetype;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            succotherlist.append(_pic);
        }
    }


    //其他类
    if(_sucesothersWidget==NULL)
    {
        _sucesothersWidget = new QTableWidget();
        _sucesothersWidget->verticalHeader()->hide();
        _sucesothersWidget->horizontalHeader()->hide();
        _sucesothersWidget->setColumnCount(3);
        _sucesothersWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //_sucessWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _sucesothersWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _sucesothersWidget->setSelectionMode(QAbstractItemView::NoSelection);

    }
    _sucesothersWidget->setRowCount(0);
    _sucesothersWidget->setFixedSize(_width,0);


    if(successotherslabel==NULL)
    {
        successotherslabel = new QLabel("其他类");
        successotherslabel->setStyleSheet("color:black;font: 75 12pt \"微软雅黑\";");
        _vlayout->addWidget(successotherslabel);
    }
    if(!succotherlist.isEmpty())
    {
        setpicwidget(succotherlist,_sucesothersWidget);
    }
}

////problrm
void IndexDialog::setproblemrectiontable()
{
    QList<picForm*>problemrectionlist;

    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==RECIPTION && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==PROBLEM)
        {
            problemrectionlist.append(_sumsuccpic.at(i));
        }
    }
    // _problemTable->cleartable();
    //problem
    for(int i=0;i<problemrectionlist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(problemrectionlist.at(i)->structpicinfo.receipttype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(problemrectionlist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(problemrectionlist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
        _problemTable->setDataView(datalist);
    }
}

void IndexDialog::setproblemteamworktable()
{
    QList<picForm*>problemteamworklist;

    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==TEAMWORK && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==PROBLEM)
        {
            problemteamworklist.append(_sumsuccpic.at(i));
        }
    }
    //  _problemTable->cleartable();
    //problem
    for(int i=0;i<problemteamworklist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(problemteamworklist.at(i)->structpicinfo.receipttype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(problemteamworklist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(problemteamworklist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
        _problemTable->setDataView(datalist);
    }
}

void IndexDialog::setproblemaddworktable()
{

    QList<picForm*>problemaddworklist;

    for(int i=0;i<_sumsuccpic.count();i++)
    {

        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==ADDWORK && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==PROBLEM)
        {
            problemaddworklist.append(_sumsuccpic.at(i));
        }
    }
    // _problemTable->cleartable();
    //problem
    for(int i=0;i<problemaddworklist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(problemaddworklist.at(i)->structpicinfo.receipttype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(problemaddworklist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(problemaddworklist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
        _problemTable->setDataView(datalist);
    }
}

void IndexDialog::setproblemtraveltable()
{

    QList<picForm*>problemtravellist;

    for(int i=0;i<_sumsuccpic.count();i++)
    {

        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==TRAVEL && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==PROBLEM)
        {
            problemtravellist.append(_sumsuccpic.at(i));
        }
    }
    // _problemTable->cleartable();
    //problem
    for(int i=0;i<problemtravellist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(problemtravellist.at(i)->structpicinfo.receipttype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(problemtravellist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(problemtravellist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
        _problemTable->setDataView(datalist);
    }
}

void IndexDialog::setproblemotherltable()
{
    QList<picForm*>problemotherlist;

    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==OTHERS && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==PROBLEM)
        {
            problemotherlist.append(_sumsuccpic.at(i));
        }
    }
    // _problemTable->cleartable();
    //problem
    for(int i=0;i<problemotherlist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(problemotherlist.at(i)->structpicinfo.receipttype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(problemotherlist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(problemotherlist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
        _problemTable->setDataView(datalist);
    }
}

void IndexDialog::setproblemrectionwidget()
{

    QList<picForm*>problemrectionlist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==RECIPTION && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==PROBLEM)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = _sumsuccpic.at(i)->structpicinfo.invoiceoperation;
            _pic->structpicinfo.invoicetype = _sumsuccpic.at(i)->structpicinfo.invoicetype;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            problemrectionlist.append(_pic);
        }
    }

    if(_problemrectionsWidget==NULL)
    {
        _problemrectionsWidget = new QTableWidget();
        _problemrectionsWidget->verticalHeader()->hide();
        _problemrectionsWidget->horizontalHeader()->hide();
        _problemrectionsWidget->setColumnCount(3);
        _problemrectionsWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _problemrectionsWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _problemrectionsWidget->setSelectionMode(QAbstractItemView::NoSelection);

    }
    _problemrectionsWidget->setRowCount(0);
    _problemrectionsWidget->setFixedSize(_width,0);

    if(problemrelabel==NULL)
    {
        problemrelabel = new QLabel("招待餐费住宿类");
        //problemrelabel->setFixedSize(120,60);
        problemrelabel->setStyleSheet("color:black;font: 75 12pt \"微软雅黑\";");
        _vlayout->addWidget(problemrelabel);
    }
    if(!problemrectionlist.isEmpty())
    {

        setpicwidget(problemrectionlist,_problemrectionsWidget);
    }

}

void IndexDialog::setproblemteamworkwidget()
{
    QList<picForm*>problemteamworklist;

    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==TEAMWORK && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==PROBLEM)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = _sumsuccpic.at(i)->structpicinfo.invoiceoperation;
            _pic->structpicinfo.invoicetype = _sumsuccpic.at(i)->structpicinfo.invoicetype;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            problemteamworklist.append(_pic);
        }
    }


    //团建类
    if(_problemworkteamWidget==NULL)
    {
        _problemworkteamWidget = new QTableWidget();
        _problemworkteamWidget->verticalHeader()->hide();
        _problemworkteamWidget->horizontalHeader()->hide();
        _problemworkteamWidget->setColumnCount(3);
        _problemworkteamWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //_sucessWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _problemworkteamWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _problemworkteamWidget->setSelectionMode(QAbstractItemView::NoSelection);

    }
    _problemworkteamWidget->setRowCount(0);
    _problemworkteamWidget->setFixedSize(_width,0);


    if(problemteamworklabel==NULL)
    {
        problemteamworklabel = new QLabel("误餐费(团建)类");
        problemteamworklabel->setStyleSheet("color:black;font: 75 12pt \"微软雅黑\";");
        _vlayout->addWidget(problemteamworklabel);
    }
    if(!problemteamworklist.isEmpty())
    {
        setpicwidget(problemteamworklist,_problemworkteamWidget);
    }

}

void IndexDialog::setproblemaddworkwidget()
{
    QList<picForm*>problemaddworklist;


    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==ADDWORK && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==PROBLEM)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = _sumsuccpic.at(i)->structpicinfo.invoiceoperation;
            _pic->structpicinfo.invoicetype = _sumsuccpic.at(i)->structpicinfo.invoicetype;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            problemaddworklist.append(_pic);
        }
    }

    //加班类
    if(_problemaddworkWidget==NULL)
    {
        _problemaddworkWidget = new QTableWidget();
        _problemaddworkWidget->verticalHeader()->hide();
        _problemaddworkWidget->horizontalHeader()->hide();
        _problemaddworkWidget->setColumnCount(3);
        _problemaddworkWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //_sucessWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _problemaddworkWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _problemaddworkWidget->setSelectionMode(QAbstractItemView::NoSelection);

    }
    _problemaddworkWidget->setRowCount(0);
    _problemaddworkWidget->setFixedSize(_width,0);

    if(problemaddworklabel==NULL)
    {
        problemaddworklabel = new QLabel("加班餐费住宿类");
        problemaddworklabel->setStyleSheet("color:black;font: 75 12pt \"微软雅黑\";");
        _vlayout->addWidget(problemaddworklabel);
    }
    if(!problemaddworklist.isEmpty())
    {
        setpicwidget(problemaddworklist,_problemaddworkWidget);
    }
}

void IndexDialog::setproblemtravelwidget()
{
    QList<picForm*>problemtravellist;

    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==TRAVEL && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==PROBLEM)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = _sumsuccpic.at(i)->structpicinfo.invoiceoperation;
            _pic->structpicinfo.invoicetype = _sumsuccpic.at(i)->structpicinfo.invoicetype;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            problemtravellist.append(_pic);
        }
    }



    //差旅
    if(_problemtravelWidget==NULL)
    {
        _problemtravelWidget = new QTableWidget();
        _problemtravelWidget->verticalHeader()->hide();
        _problemtravelWidget->horizontalHeader()->hide();
        _problemtravelWidget->setColumnCount(3);
        _problemtravelWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //_sucessWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _problemtravelWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _problemtravelWidget->setSelectionMode(QAbstractItemView::NoSelection);

    }
    _problemtravelWidget->setRowCount(0);
    _problemtravelWidget->setFixedSize(_width,0);


    if(problemtravellabel==NULL)
    {
        problemtravellabel = new QLabel("合同类");
        problemtravellabel->setStyleSheet("color:black;font: 75 12pt \"微软雅黑\";");
        _vlayout->addWidget(problemtravellabel);
    }
    if(!problemtravellist.isEmpty())
    {
        setpicwidget(problemtravellist,_problemtravelWidget);
    }
}

void IndexDialog::setproblemotherlwidget()
{
    QList<picForm*>problemotherlist;

    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if(_sumsuccpic.at(i)->structpicinfo.invoicetype==OTHERS && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==PROBLEM)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = _sumsuccpic.at(i)->structpicinfo.invoiceoperation;
            _pic->structpicinfo.invoicetype = _sumsuccpic.at(i)->structpicinfo.invoicetype;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            problemotherlist.append(_pic);
        }
    }


    //其他类
    if(_problemothersWidget==NULL)
    {
        _problemothersWidget = new QTableWidget();
        _problemothersWidget->verticalHeader()->hide();
        _problemothersWidget->horizontalHeader()->hide();
        _problemothersWidget->setColumnCount(3);
        _problemothersWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //_sucessWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _problemothersWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _problemothersWidget->setSelectionMode(QAbstractItemView::NoSelection);

    }
    _problemothersWidget->setRowCount(0);
    _problemothersWidget->setFixedSize(_width,0);

    if(problemotherslabel==NULL)
    {
        problemotherslabel = new QLabel("其他类");
        problemotherslabel->setStyleSheet("color:black;font: 75 12pt \"微软雅黑\";");
        _vlayout->addWidget(problemotherslabel);
    }
    if(!problemotherlist.isEmpty())
    {
        setpicwidget(problemotherlist,_problemothersWidget);
    }
}

void IndexDialog::setfaildtable()
{
    QList<picForm*>faildlist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if( _sumsuccpic.at(i)->structpicinfo.invoiceoperation==FAILD)
        {
            faildlist.append(_sumsuccpic.at(i));
        }
    }

    //  _failTable->cleartable();

    for(int i=0;i<faildlist.count();i++)
    {
        QStringList datalist;
        QString invoiceoperationtype = QString("%1").arg(faildlist.at(i)->structpicinfo.invoicetype);
        datalist.append(invoiceoperationtype);
        QString price = QString("%1").arg(faildlist.at(i)->structpicinfo.price);
        datalist.append(price);
        QString prostr = QString("%1").arg(faildlist.at(i)->structpicinfo.problem);
        datalist.append(prostr);
        _failTable->setDataView(datalist);
    }
}

void IndexDialog::setfaildwidget()
{
    QList<picForm*>faildlist;
    for(int i=0;i<_sumsuccpic.count();i++)
    {
        if( _sumsuccpic.at(i)->structpicinfo.invoiceoperation==FAILD)
        {
            picForm *_pic =  new picForm(_sumsuccpic.at(i)->structpicinfo.invoiceoperation,_sumsuccpic.at(i)->structpicinfo.id,(_width-30)/3,_sumsuccpic.at(i)->structpicinfo.roation.toInt());

            _pic->structpicinfo.invoiceoperation = _sumsuccpic.at(i)->structpicinfo.invoiceoperation;
            _pic->structpicinfo.invoicetype = _sumsuccpic.at(i)->structpicinfo.invoicetype;
            _pic->structpicinfo.identification = _sumsuccpic.at(i)->structpicinfo.identification;
            faildlist.append(_pic);
        }
    }

    if(_faildWidget==NULL)
    {
        _faildWidget = new QTableWidget();
        _faildWidget->verticalHeader()->hide();
        _faildWidget->horizontalHeader()->hide();
        _faildWidget->setColumnCount(3);
        _faildWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        _faildWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        _faildWidget->setSelectionMode(QAbstractItemView::NoSelection);

    }
    _faildWidget->setRowCount(0);

    _faildWidget->setFixedSize(_width,0);
    if(!faildlist.isEmpty())
    {
        setpicwidget(faildlist,_faildWidget);
    }
}

void IndexDialog::setSuccessScorllArea(/*QList<picForm *> picInfo*/)
{
    ///////table
    ///
    QMessageBox::information(NULL,QString("pic count"),QString("%1").arg(_sumsuccpic.count()));

    deleteAllitemsOfLayout(_vlayout);
    if(_successTable==NULL)
    {
        _successTable = new Invoiceable(SUCCEED);

        connect(_successTable,SIGNAL(signal_jisuan(int,float)),this,SLOT(slot_setupload(int,float)));

    }

    setsucessaddworktable();
    setsucessotherltable();
    setsucessrectiontable();
    setsucessteamworktable();
    setsucesstraveltable();
    _vlayout->addWidget(_successTable);



    if(_problemTable==NULL)
    {
        _problemTable = new Invoiceable(PROBLEM);
        //connect(_failTable,SIGNAL(signal_jisuan(int,float)),this,SLOT(slot_setupload(int,float)));

    }

    setproblemaddworktable();
    setproblemotherltable();
    setproblemrectiontable();
    setproblemteamworktable();
    setproblemtraveltable();
    _vlayout->addWidget(_problemTable);

    //faild
    if(_failTable==NULL)
    {
        _failTable = new Invoiceable(FAILD);
        //connect(_failTable,SIGNAL(signal_jisuan(int,float)),this,SLOT(slot_setupload(int,float)));
    }
    setfaildtable();
    _vlayout->addWidget(_failTable);

    /////////////////////////////////////////////////////////////picWidget
    ///
    /// //sucess
    if(successlabel == NULL)
    {
        //QMessageBox::information(NULL,"NULL","NULL");
        successlabel = new QLabel("成功发票");
        successlabel->setStyleSheet("color:black;font: 87 14pt \"微软雅黑\";");
        _vlayout->addWidget(successlabel);
    }



    setsucessrectionwidget();
    //if(_sucesrectionsWidget->rowCount()>0)
    //{
    _vlayout->addWidget(_sucesrectionsWidget);

    //}

    setsucessaddworkwidget();
    // if(_sucesaddworkWidget->rowCount()>0)
    {
        _vlayout->addWidget(_sucesaddworkWidget);
    }
    setsucessteamworkwidget();
    // if(_sucesworkteamWidget->rowCount()>0)
    {
        _vlayout->addWidget(_sucesworkteamWidget);
    }

    setsucesstravelwidget();
    // if(_sucestravelWidget->rowCount()>0)
    {
        _vlayout->addWidget(_sucestravelWidget);
    }

    setsucessotherlwidget();
    // if(_sucesothersWidget->rowCount()>0)
    {
        _vlayout->addWidget(_sucesothersWidget);
    }


    //problem
    //招待
    if(problemlabel==NULL)
    {
        problemlabel = new QLabel("问题发票");
        problemlabel->setStyleSheet("color:black;font: 87 14pt \"微软雅黑\";");

        _vlayout->addWidget(problemlabel);
    }


    setproblemrectionwidget();
    // if(_problemrectionsWidget->rowCount()>0)
    {
        _vlayout->addWidget(_problemrectionsWidget);
    }

    setproblemaddworkwidget();
    // if(_problemaddworkWidget->rowCount()>0)
    {
        _vlayout->addWidget(_problemaddworkWidget);
    }


    setproblemteamworkwidget();
    //  if(_problemworkteamWidget->rowCount()>0)
    {
        _vlayout->addWidget(_problemworkteamWidget);
    }

    setproblemtravelwidget();
    // if(_problemtravelWidget->rowCount()>0)
    {
        _vlayout->addWidget(_problemtravelWidget);
    }

    setproblemotherlwidget();
    //  if(_problemothersWidget->rowCount()>0)
    {
        _vlayout->addWidget(_problemothersWidget);
    }


    //faild
    if(faildlabel==NULL)
    {
        faildlabel = new QLabel("不可报销发票");
        faildlabel->setStyleSheet("color:black;font: 87 14pt \"微软雅黑\";");
        _vlayout->addWidget(faildlabel);
    }

    setfaildwidget();
    //if(_faildWidget->rowCount()>0)
    {
        _vlayout->addWidget(_faildWidget);
    }


    _vlayout->addSpacerItem(new QSpacerItem(30,30,QSizePolicy::Minimum,QSizePolicy::Expanding));
    /////////song
    ui->scrollArea->widget()->setLayout(_vlayout);
    //ui->widget->setLayout(_vlayout);
}

void IndexDialog::setProblemScorllArea()
{

}

void IndexDialog::setFaildScorllArea()
{

}

void IndexDialog::setpicwidget(QList<picForm*>piclist,QTableWidget *widget)
{

    if(!widget)
    {
        return;
    }
    int count = piclist.count();
    int row;
    int yushu=count%3;

    if(count<3)
    {
        row=0;

        widget->setFixedSize(_width,400*1);
    }
    else
    {
        row =count/3;
        if(yushu>0)
        {
            widget->setFixedSize(_width,400*(row+1));
        }
        else
            widget->setFixedSize(_width,400*row);
    }


    for(int i=0;i<row;i++)
    {

        widget->insertRow(widget->rowCount());
        for(int column=0;column<3;column++)
        {
            picForm *_picform = piclist.at((3*i)+column);//new picForm("E:/newjob/invoice/2.jpg",(_width-30)/3,this);//
            connect(_picform,SIGNAL(signal_operation_pic(picForm *)),this,SLOT(slot_delete_jiangji_oper(picForm *)));
            connect(_picform,SIGNAL(signal_jiangji_pic(picForm *)),this,SLOT( slot_jiangji_pic(picForm *)));
            //_picform->setxuanfuicon( piclist.at((3*i)+column)->structpicinfo.invoiceoperation);
            widget->setRowHeight(widget->rowCount()-1,400);
            widget->setCellWidget(widget->rowCount()-1,column,_picform);

            piclist.at((3*i)+column)->structpicinfo.row=widget->rowCount()-1;
            piclist.at((3*i)+column)->structpicinfo.column=column;
        }

    }

    if(yushu>0)
    {
        widget->insertRow(widget->rowCount());
        for(int column=0;column<yushu;column++)
        {
            picForm *_picform =  piclist.at(3*(row)+column);
            connect(_picform,SIGNAL(signal_operation_pic(picForm *)),this,SLOT(slot_delete_jiangji_oper(picForm *)));
            connect(_picform,SIGNAL(signal_jiangji_pic(picForm *)),this,SLOT( slot_jiangji_pic(picForm *)));
            widget->setRowHeight(widget->rowCount()-1,400);
            widget->setCellWidget(widget->rowCount()-1,column,_picform);
            // _picform->setxuanfuicon( _picform->structpicinfo.invoiceoperation);
            _picform->structpicinfo.row=widget->rowCount()-1;
            _picform->structpicinfo.column=column;
        }

    }

}

void IndexDialog::slot_jiangji_pic(picForm *picform)
{
    if(picform->structpicinfo.invoiceoperation == SUCCEED)
    {

        if(_movedlg==NULL)
        {
            _movedlg = new MoveInvoiceDialog(this);
            connect(_movedlg,SIGNAL(signal_move_where(int,QString)),this,SLOT(slot_move_invoice(int,QString )));
        }
        _movedlg->setOperationType(SUCCEED);

        if( _movedlg->exec()==QDialog::Rejected)
        {
            return;
        }

        if(moveType == PROBLEM)
        {

            for(int i=0;i<_sumsuccpic.count();i++)
            {

                if((picform->structpicinfo.id == _sumsuccpic.at(i)->structpicinfo.id) && picform->structpicinfo.invoiceoperation == _sumsuccpic.at(i)->structpicinfo.invoiceoperation)
                {

                    _sumsuccpic.at(i)->structpicinfo.invoiceoperation=PROBLEM;
                    _sumsuccpic.at(i)->structpicinfo.problem = _cause;
                    _sumsuccpic.at(i)->setxuanfuicon(PROBLEM);
                    break;
                }
            }

            _problemTable->cleartable();
            setproblemrectiontable();
            setproblemaddworktable();
            setproblemteamworktable();
            setproblemtraveltable();
            setproblemotherltable();
            if(picform->structpicinfo.invoicetype == OTHERS)
            {

                setproblemotherlwidget();
            }
            if(picform->structpicinfo.invoicetype == TRAVEL)
            {

                setproblemtravelwidget();
            }
            if(picform->structpicinfo.invoicetype == ADDWORK)
            {

                setproblemaddworkwidget();
            }
            if(picform->structpicinfo.invoicetype == TEAMWORK)
            {

                setproblemteamworkwidget();
            }
            if(picform->structpicinfo.invoicetype == RECIPTION)
            {
                setproblemrectionwidget();
            }
        }
        else
        {
            for(int i=0;i<_sumsuccpic.count();i++)
            {
                if(picform->structpicinfo.id == _sumsuccpic.at(i)->structpicinfo.id && picform->structpicinfo.invoiceoperation == _sumsuccpic.at(i)->structpicinfo.invoiceoperation)
                {
                    _sumsuccpic.at(i)->structpicinfo.invoiceoperation=FAILD;
                    _sumsuccpic.at(i)->structpicinfo.problem = _cause;
                    _sumsuccpic.at(i)->setxuanfuicon(FAILD);
                    break;
                }
            }
            _failTable->cleartable();
            setfaildtable();
            setfaildwidget();

        }

        _successTable->cleartable();
        setsucessrectiontable();
        setsucessaddworktable();
        setsucessteamworktable();
        setsucesstraveltable();
        setsucessotherltable();

        if(picform->structpicinfo.invoicetype == OTHERS)
        {
            setsucessotherlwidget();

        }
        if(picform->structpicinfo.invoicetype == TRAVEL)
        {
            setsucesstravelwidget();

        }
        if(picform->structpicinfo.invoicetype == ADDWORK)
        {
            setsucessaddworkwidget();

        }
        if(picform->structpicinfo.invoicetype == TEAMWORK)
        {
            setsucessteamworkwidget();

        }
        if(picform->structpicinfo.invoicetype == RECIPTION)
        {
            setsucessrectionwidget();

        }

    }

    if(picform->structpicinfo.invoiceoperation == PROBLEM)
    {
        if(_movedlg==NULL)
        {
            _movedlg = new MoveInvoiceDialog(this);
            connect(_movedlg,SIGNAL(signal_move_where(int,QString)),this,SLOT(slot_move_invoice(int,QString)));
        }
        _movedlg->setOperationType(PROBLEM);
        for(int i=0;i<_sumsuccpic.count();i++)
        {
            if(picform->structpicinfo.id == _sumsuccpic.at(i)->structpicinfo.id && picform->structpicinfo.invoiceoperation == _sumsuccpic.at(i)->structpicinfo.invoiceoperation)
            {
                _movedlg->setproblemdec(_sumsuccpic.at(i)->structpicinfo.problem);
                break;
            }
        }

        if( _movedlg->exec()==QDialog::Rejected)
        {
            return;
        }

        if(moveType == SUCCEED)
        {
            for(int i=0;i<_sumsuccpic.count();i++)
            {
                if(picform->structpicinfo.id == _sumsuccpic.at(i)->structpicinfo.id && picform->structpicinfo.invoiceoperation == _sumsuccpic.at(i)->structpicinfo.invoiceoperation)
                {
                    _sumsuccpic.at(i)->structpicinfo.invoiceoperation=SUCCEED;
                    _sumsuccpic.at(i)->structpicinfo.problem="";
                    _sumsuccpic.at(i)->setxuanfuicon(SUCCEED);

                    break;
                }
            }

            _successTable->cleartable();
            setsucessrectiontable();
            setsucessaddworktable();
            setsucessteamworktable();
            setsucesstraveltable();
            setsucessotherltable();
            if(picform->structpicinfo.invoicetype == OTHERS)
            {

                setsucessotherlwidget();
            }
            if(picform->structpicinfo.invoicetype == TRAVEL)
            {

                setsucesstravelwidget();
            }
            if(picform->structpicinfo.invoicetype == ADDWORK)
            {

                setsucessaddworkwidget();
            }
            if(picform->structpicinfo.invoicetype == TEAMWORK)
            {

                setsucessteamworkwidget();
            }
            if(picform->structpicinfo.invoicetype == RECIPTION)
            {
                setsucessrectionwidget();
            }
        }
        else
        {
            for(int i=0;i<_sumsuccpic.count();i++)
            {
                if(picform->structpicinfo.id == _sumsuccpic.at(i)->structpicinfo.id && picform->structpicinfo.invoiceoperation == _sumsuccpic.at(i)->structpicinfo.invoiceoperation)
                {
                    _sumsuccpic.at(i)->structpicinfo.invoiceoperation=FAILD;
                    _sumsuccpic.at(i)->structpicinfo.problem = _cause;
                    _sumsuccpic.at(i)->setxuanfuicon(FAILD);
                    break;
                }
            }
            _failTable->cleartable();
            setfaildtable();
            setfaildwidget();

        }

        _problemTable->cleartable();
        setproblemaddworktable();
        setproblemotherltable();
        setproblemrectiontable();
        setproblemteamworktable();
        setproblemtraveltable();

        if(picform->structpicinfo.invoicetype == OTHERS)
        {
            setproblemotherlwidget();

        }
        if(picform->structpicinfo.invoicetype == TRAVEL)
        {
            setproblemtravelwidget();

        }
        if(picform->structpicinfo.invoicetype == ADDWORK)
        {
            setproblemaddworkwidget();

        }
        if(picform->structpicinfo.invoicetype == TEAMWORK)
        {
            setproblemteamworkwidget();

        }
        if(picform->structpicinfo.invoicetype == RECIPTION)
        {
            setproblemrectionwidget();

        }

    }

    if(picform->structpicinfo.invoiceoperation == FAILD)
    {
        if(_movedlg==NULL)
        {
            _movedlg = new MoveInvoiceDialog(this);
            connect(_movedlg,SIGNAL(signal_move_where(int,QString)),this,SLOT(slot_move_invoice(int,QString)));
        }
        _movedlg->setOperationType(FAILD);
        if( _movedlg->exec()==QDialog::Rejected)
        {
            return;
        }

        if(moveType == SUCCEED)
        {
            for(int i=0;i<_sumsuccpic.count();i++)
            {
                if(picform->structpicinfo.id == _sumsuccpic.at(i)->structpicinfo.id && picform->structpicinfo.invoiceoperation == _sumsuccpic.at(i)->structpicinfo.invoiceoperation)
                {
                    _sumsuccpic.at(i)->structpicinfo.invoiceoperation=SUCCEED;
                    _sumsuccpic.at(i)->setxuanfuicon(SUCCEED);
                    break;
                }
            }

            _successTable->cleartable();
            setsucessrectiontable();
            setsucessaddworktable();
            setsucessteamworktable();
            setsucesstraveltable();
            setsucessotherltable();
            if(picform->structpicinfo.invoicetype == OTHERS)
            {

                setsucessotherlwidget();
            }
            if(picform->structpicinfo.invoicetype == TRAVEL)
            {

                setsucesstravelwidget();
            }
            if(picform->structpicinfo.invoicetype == ADDWORK)
            {

                setsucessaddworkwidget();
            }
            if(picform->structpicinfo.invoicetype == TEAMWORK)
            {

                setsucessteamworkwidget();
            }
            if(picform->structpicinfo.invoicetype == RECIPTION)
            {
                setsucessrectionwidget();
            }
        }
        if(moveType == PROBLEM)
        {
            for(int i=0;i<_sumsuccpic.count();i++)
            {
                if(picform->structpicinfo.id == _sumsuccpic.at(i)->structpicinfo.id && picform->structpicinfo.invoiceoperation == _sumsuccpic.at(i)->structpicinfo.invoiceoperation)
                {
                    _sumsuccpic.at(i)->structpicinfo.invoiceoperation=PROBLEM;
                    _sumsuccpic.at(i)->structpicinfo.problem = _cause;
                    _sumsuccpic.at(i)->setxuanfuicon(PROBLEM);
                    break;
                }
            }

            _problemTable->cleartable();
            setproblemrectiontable();
            setproblemaddworktable();
            setproblemteamworktable();
            setproblemtraveltable();
            setproblemotherltable();
            if(picform->structpicinfo.invoicetype == OTHERS)
            {

                setproblemotherlwidget();
            }
            if(picform->structpicinfo.invoicetype == TRAVEL)
            {

                setproblemtravelwidget();
            }
            if(picform->structpicinfo.invoicetype == ADDWORK)
            {

                setproblemaddworkwidget();
            }
            if(picform->structpicinfo.invoicetype == TEAMWORK)
            {

                setproblemteamworkwidget();
            }
            if(picform->structpicinfo.invoicetype == RECIPTION)
            {
                setproblemrectionwidget();
            }
        }
        _failTable->cleartable();
        setfaildtable();
        setfaildwidget();
    }

}

void IndexDialog::slot_setSumpic(QMap<QString,QString> strlist)
{

    //重置_sumsuccpic内容

    if(strlist.value("invoicetype")=="success" || strlist.value("invoicetype")=="problem")
    {
        QString picpath = QString("%1/%2/%3").arg(STORTPATH).arg(_Uploadname).arg(strlist.value("id"));

        picForm *_picform1;
        if(strlist.value("invoicetype")=="success")
        {
           _picform1 =  new picForm(SUCCEED,picpath,(_width-30)/3,strlist.value("orientation").toInt());
        }
        else
        {
             _picform1 =  new picForm(PROBLEM,picpath,(_width-30)/3,strlist.value("orientation").toInt());
        }

        _picform1->structpicinfo.invoiceoperation=SUCCEED;
        _picform1->structpicinfo.invoicetype=_scanType;
        _picform1->structpicinfo.price = strlist.value("total").toFloat();
        _picform1->structpicinfo.roation = strlist.value("orientation");
        _picform1->structpicinfo.identification = strlist.value("identification");

        _picform1->structpicinfo.checkRs = strlist.value("checkRs");
        _picform1->structpicinfo.checkRsDesc = strlist.value("checkRsDesc");

        _picform1->structpicinfo.details = strlist.value("details");
        _picform1->structpicinfo.truthRs = strlist.value("truthRs");
         _picform1->structpicinfo.receipttype = strlist.value("receipttype");
        _picform1->structpicinfo.problem = "";

        _sumsuccpic.append(_picform1);

    }
    else if(strlist.value("invoicetype")=="fail")
    {

        picForm *_picform1 = new picForm(FAILD,strlist.value("id"),(_width-30)/3,0);
        _picform1->structpicinfo.invoiceoperation=FAILD;
        _picform1->structpicinfo.invoicetype= _scanType;
        _picform1->structpicinfo.identification = strlist.value("identification");
        _picform1->structpicinfo.price = 0;
        _picform1->structpicinfo.problem = "无法识别";
        _sumsuccpic.append(_picform1);
    }

}

void IndexDialog::slot_show_dlg()
{
    setSuccessScorllArea();
    _uploainvoicethread->setsumsucee(_sumsuccpic);

    //this->show();
}

void IndexDialog::slot_finishupload(QString five_code)
{
    _sumsuccpic.clear();
    _scandlg->initamount();

    setSuccessScorllArea();
    emit signal_startcleanfile_thread();
    ui->pushButton_sumbit->setVisible(false);

    QDesktopServices::openUrl(QUrl(QString("http://139.129.103.28/index.php/finances/caiwu_index/%1").arg(five_code)));

}

void IndexDialog::slot_setinvoice_type(INVOICETYPE type)
{
    _scanType = type;
}

void IndexDialog::slot_setbaoxiao(bool info)
{
    _scandlg->initamount();
    _sumsuccpic.clear();
    _extendform->setcando(info);
    ui->pushButton_sumbit->setVisible(info);
     _extendform->extendwardForm();
}

void IndexDialog::slot_delete_jiangji_oper(picForm *picform)
{

    if(picform->structpicinfo.invoiceoperation == FAILD)
    {
        if(QMessageBox::information(this,"提示","确认要删除发票",QMessageBox::Yes,QMessageBox::Cancel)==QMessageBox::Yes)
        {
            for(int i=0;i<_sumsuccpic.count();i++)
            {
                if(picform->structpicinfo.id == _sumsuccpic.at(i)->structpicinfo.id && _sumsuccpic.at(i)->structpicinfo.invoiceoperation==FAILD)
                {
                    _sumsuccpic.removeAt(i);
                    break;
                }
            }
            setfaildwidget();
            _failTable->cleartable();
            setfaildtable();

        }
    }
}

void IndexDialog::slot_setupload(int pages, float price)
{
    _updownform->setPages(pages);
    _updownform->setPrice(price);
}

void IndexDialog::slot_show_scan(INVOICETYPE type)
{
    if(_updownform->getLabelname().isEmpty())
    {
        QMessageBox::information(NULL,"提示","请输入四位编码");
        return ;
    }
    _scandlg->setText(type);
    _scandlg->setlabelclear();
    _scandlg->setShibiecanshu(_updownform->getLabelname(),_updownform->getcompany(),_updownform->getdanjuleixing());

    _scandlg->show();
    _scanType = type;
    _updownform->setCombtypeenable(false);

    this->close();
}



void IndexDialog::on_pushButton_webpage_clicked()
{
    _webpage->show();
}

void IndexDialog::slot_move_invoice(int index,QString cause)
{
    moveType = index;
    _cause = cause;

}

void IndexDialog::on_pushButton_sumbit_clicked()//提交发票
{

    if(_updownform->getLabelname().isEmpty())
    {
        QMessageBox::information(NULL,"提示","请输入四位编码");
        return ;
    }
 _updownform->setCombtypeenable(true);
   _uploainvoicethread->setlogname(_updownform->getLabelname());
    _uploainvoicethread->setcodee(_updownform->getfourcode());
     _uploainvoicethread->settype(_updownform->gettype());
     _uploainvoicethread->settotal(_updownform->gettotal());
     _uploainvoicethread->setpassword(_username);
     _uploainvoicethread->setusername(_password);
    emit signal_start_thread();

}

void IndexDialog::slot_cleardata()
{
    _uploainvoicethread->clearalldata();
     //deleteAllitemsOfLayout(_vlayout);
    _updownform->setCombtypeenable(true);
     _sumsuccpic.clear();
     _sucesspicTypeList.clear();
     _updownform->clearalltext();
     _extendform->backwardForm();
     ui->pushButton_sumbit->setVisible(false);
     _scandlg->initamount();
     setSuccessScorllArea();
     emit signal_startcleanfile_thread();
}
