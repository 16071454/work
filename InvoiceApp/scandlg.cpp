#include "scandlg.h"
#include "ui_scandlg.h"
#include <QDesktopWidget>
#include <QMessageBox>
#include <QDir>
#include "qtwain.h"
#include "dib.h"
#include <LoginDlg.h>

#include "opencvobject.h"

static int scanlistindex=0;
static int insertcount =0 ;

#define STORTPATH "E:\\newjob\\invoice\\"

#pragma execution_character_set("utf-8")

extern QString _Uploadname;

scandlg::scandlg(QWidget *parent) :
    QDialog(parent),
    bardlg(NULL),
    m_pTwain(NULL),
    sumcount(0),
    ui(new Ui::scandlg)
{
    ui->setupUi(this);
    qRegisterMetaType<QMap<QString,QString> > ("QMap<QString,QString>>");

    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(QApplication::desktop()->size()*8/9);
    QDesktopWidget *pDesk = QApplication::desktop();
    move((pDesk->width() - this->width()) / 2, (pDesk->height() - this->height()) / 2);
    _head = new HeadDialog(this);
    connect(_head,&HeadDialog::signal_quite,this,[=](){
        this->close();
        ui->label->clear();
        ui->label_fan->clear();
        mylist.clear();
        scanlistindex=0;
        insertcount=0;
        Dialog::instanceLogin()->show();

    });
    connect(this,SIGNAL(signal_get_localPhoto(int)),this,SLOT(slot_get_localphoto(int)));

    sde = new opencvObject();


    ui->horizontalLayout_head->addWidget(_head);
    tishiwidget = new QWidget(this);
    tishiwidget->setWindowFlags(Qt::FramelessWindowHint);
    tishiwidget->setFixedSize(800,200);
    _scanform = new scanoptionForm(this);
    ui->horizontalLayout->addWidget(_scanform);
    connect(_scanform,SIGNAL(signal_continue_scan(int)),this,SLOT(onSelectButton(int)));
    connect(_scanform,SIGNAL(signal_auto_scan(int)),this,SLOT(onSelectButton(int)));

    connect(_scanform,SIGNAL(signal_check_invoice()),this,SLOT(slot_upload_invoice()));
    connect(_scanform,SIGNAL(siganl_set_invoice_type(INVOICETYPE)),this,SIGNAL(siganl_set_invoice_type(INVOICETYPE)));

    _scanlog = new ScanLogoDialog();
    _scanlog->move ((QApplication::desktop()->width() - _scanlog->width())/2,(QApplication::desktop()->height() - _scanlog->height())/1.5);
    _scanlog->setVisible(false);

    QThread *thread = new QThread(this);
    _scanthread = new scanThread;
    _scanthread->moveToThread(thread);
    connect(this,SIGNAL(signal_start_thread(QString,QString,QString,QString,QString,QString,QString)),_scanthread,SLOT(slot_dosomething(QString,QString,QString,QString,QString,QString,QString)));
    connect(_scanthread,SIGNAL(signal_vertify_finish(QMap<QString,QString>)),this,SLOT(slot_product_pic(QMap<QString,QString>)));
    thread->start();

}

scandlg::~scandlg()
{
    delete m_pTwain;
    delete ui;
}

void scandlg::setText(INVOICETYPE type)
{

    _scanform->setText(type);
    //无需识别//合同类
    if(type == ADDWORK || type == TRAVEL)
    {
        identification = "0";
        if(type == TRAVEL)
        {
            iscontract = "1";
        }
    }
    else
    {
        identification ="1";
        iscontract ="0";
    }
}

void scandlg::setusername(QString name)
{
    _username = name;
    _head->setUsername(name);
}

void scandlg::showEvent(QShowEvent *thisEvent)
{

    // m_pTwain->setParent(this);
}

void scandlg::setlabelclear()
{
    ui->label->clear();
    ui->label_fan->clear();
}

void scandlg::initamount()
{
    ui->label->clear();
    ui->label_fan->clear();
    mylist.clear();
    scanlistindex=0;
    insertcount=0;
}

void scandlg::setShibiecanshu(QString name, QString company, QString certify)
{
    _baxiaoren = name;
    _gongsi = company;
    _danjupingzheng = certify;
}

bool scandlg::winEvent(MSG *pMsg, long *result)
{
    m_pTwain->processMessage(*pMsg);
    return false;
}

void scandlg::onSelectButton(int type)
{
    if(type==0)
    {
        _scanlog->setVisible(true);

        if(m_pTwain ==NULL)
        {
            m_pTwain = new QTwain();
            m_pTwain->setParent(this);
            connect(m_pTwain, &QTwainInterface::dibAcquired,this, &scandlg::onDibAcquired);
            connect(m_pTwain, &QTwainInterface::ScanEnd,this, &scandlg::onEndScan);
        }
        if(!m_pTwain->selectSource())
        {
            return;
        }

        if (!m_pTwain->acquire())
        {
            QMessageBox::information(NULL,"提示","扫描失败");
            _scanlog->hide();
        }
    }
    if(type==1)//剪切板
    {
        emit signal_get_localPhoto(1);
    }
    if(type == 2)
    {
        emit signal_get_localPhoto(2);
    }

}

void scandlg::slot_upload_invoice()
{
    _scanlog->hide();
    emit signal_back_index();
    this->close();
}

void scandlg::slot_product_pic(QMap<QString,QString> str)
{
    //make picform

    emit signal_scan_end(str);
    bardlg->setvalue(scanlistindex);
    scanlistindex ++;
    if(scanlistindex > mylist.count()-1)
    {
        bardlg->hide();
        //this->close();
        sumcount += mylist.count()-1;//song
        emit signal_show_index();
        _scanform->setpushbutton(true);
        return;
    }
    // if((scanlistindex%2)==0)
    //{

    emit signal_start_thread(mylist.at(scanlistindex),_baxiaoren,_gongsi,_danjupingzheng,_scanform->getscantype(),identification,iscontract);

    // }

}

void scandlg::slot_get_localphoto(int type)
{
    if(type==1)//剪切板
    {

        if(!clipboard)
        {
            clipboard = QApplication::clipboard();   //获取系统剪贴板指针
        }


        QPixmap originalmap  = clipboard->pixmap();
        if(originalmap.isNull())
        {
            return;
        }


        //图片自动适应labedl
        ui->label->setFixedSize(800,600);
        ui->label_fan->setFixedSize(800,600);
        ui->label->setScaledContents(true);
        ui->label_fan->setScaledContents(true);
        dir_str = QString("%1%2").arg(STORTPATH).arg(_Uploadname);
        // 检查目录是否存在，若不存在则新建
        QDir dir;
        if (!dir.exists(dir_str))
        {
            dir.mkpath(dir_str);
        }

        QDateTime currentdt = QDateTime::currentDateTime();
        QString currenttime=currentdt.toString("sshhddMMyyyy");
        QString  spath = QString("%1\\%2pix%3.jpg").arg(dir_str).arg(currenttime).arg(insertcount++);

        //QMessageBox::information(NULL,"insertcount",QString("%1").arg(insertcount));

        mylist.append(spath);

        sumcount = mylist.count()-1;
        originalmap.save(spath);


        QPixmap pixmap1(spath);
        int sum = insertcount;

        if(sum%2==0)
        {
            ui->label->setPixmap(pixmap1);
            ui->label->resize(QSize(pixmap1.width(),pixmap1.height()));

        }
        else
        {
            ui->label_fan->setPixmap(pixmap1);
            ui->label_fan->resize(QSize(pixmap1.width(),pixmap1.height()));
        }

        _scanlog->hide();
        if(mylist.count()==0)
        {
            return;
        }


        if(bardlg == NULL)
        {
            bardlg = new processBarDialog();
            ui->horizontalLayout_3->addWidget(bardlg);
            bardlg->setvalue(0);

        }

        bardlg->setMaxvalue(sumcount);
        bardlg->show();
        if(QString::compare(identification,"1")==0)//new modify 28/2
        {
            sde->photoProcess(dir_str);
        }
        emit signal_start_thread(mylist.at(scanlistindex),_baxiaoren,_gongsi,_danjupingzheng,_scanform->getscantype(),identification,iscontract);//先上传第一个

    }
    if(type==2)
    {
        QStringList FileName;
        //        QString fileName = QFileDialog::getOpenFileName(this, tr("选择文件"),
        //                                                        "D:/",
        //                                                        tr("上传图片文件(*.png *.jpg)"));


        QFileDialog* fileDialog = new QFileDialog(this,tr("选择文件"),"D:/");
        fileDialog->setFileMode(QFileDialog::ExistingFiles);
        fileDialog->setWindowTitle( tr("上传图片文件"));
        fileDialog->setNameFilter("*.png *.jpg");

        if ( fileDialog->exec() == QDialog::Accepted )
        {


            FileName=fileDialog->selectedFiles();


        }
        for(int i=0;i<FileName.size();i++)
        {
            QPixmap pixmap(FileName.at(i));

            //图片自动适应labedl
            ui->label->setFixedSize(800,600);
            ui->label_fan->setFixedSize(800,600);
            ui->label->setScaledContents(true);
            ui->label_fan->setScaledContents(true);
            dir_str = QString("%1%2").arg(STORTPATH).arg(_Uploadname);
            // 检查目录是否存在，若不存在则新建
            QDir dir;
            if (!dir.exists(dir_str))
            {
                dir.mkpath(dir_str);
            }

            QDateTime currentdt = QDateTime::currentDateTime();
            QString currenttime=currentdt.toString("sshhddMMyyyy");
            QString  spath = QString("%1\\%2pix%3.jpg").arg(dir_str).arg(currenttime).arg(insertcount++);

            //QMessageBox::information(NULL,"insertcount",QString("%1").arg(insertcount));

            mylist.append(spath);

            sumcount = mylist.count()-1;
            pixmap.save(spath);


            QPixmap pixmap1(spath);
            int sum = insertcount;

            if(sum%2==0)
            {
                ui->label->setPixmap(pixmap1);
                ui->label->resize(QSize(pixmap1.width(),pixmap1.height()));

            }
            else
            {
                ui->label_fan->setPixmap(pixmap1);
                ui->label_fan->resize(QSize(pixmap1.width(),pixmap1.height()));
            }

        }
        _scanlog->hide();
        if(mylist.count()==0)
        {
            return;
        }


        if(bardlg == NULL)
        {
            bardlg = new processBarDialog();
            ui->horizontalLayout_3->addWidget(bardlg);
            bardlg->setvalue(0);

        }

        bardlg->setMaxvalue(sumcount);
        bardlg->show();
        if(QString::compare(identification,"1")==0)//new modify 28/2
        {
            sde->photoProcess(dir_str);
        }
        emit signal_start_thread(mylist.at(scanlistindex),_baxiaoren,_gongsi,_danjupingzheng,_scanform->getscantype(),identification,iscontract);//先上传第一个


    }
}

void scandlg::onEndScan()
{
    delete m_pTwain;
    m_pTwain = NULL;
    _scanlog->hide();
    if(mylist.count()==0)
    {
        return;
    }


    if(bardlg == NULL)
    {
        bardlg = new processBarDialog();
        ui->horizontalLayout_3->addWidget(bardlg);
        bardlg->setvalue(0);

    }

    bardlg->setMaxvalue(sumcount);
    bardlg->show();
    if(QString::compare(identification,"1")==0)//new modify 28/2
    {
        sde->photoProcess(dir_str);
    }


    emit signal_start_thread(mylist.at(scanlistindex),_baxiaoren,_gongsi,_danjupingzheng,_scanform->getscantype(),identification,iscontract);//先上传第一个
}

void scandlg::onDibAcquired(QPixmap pixmap)
{
    if(pixmap.isNull())
    {
        return;
    }

    //图片自动适应labedl
    ui->label->setFixedSize(800,600);
    ui->label_fan->setFixedSize(800,600);
    ui->label->setScaledContents(true);
    ui->label_fan->setScaledContents(true);
    dir_str = QString("%1%2").arg(STORTPATH).arg(_Uploadname);
    // 检查目录是否存在，若不存在则新建
    QDir dir;
    if (!dir.exists(dir_str))
    {
        dir.mkpath(dir_str);
    }

    QDateTime currentdt = QDateTime::currentDateTime();
    QString currenttime=currentdt.toString("sshhddMMyyyy");
    QString  spath = QString("%1\\%2pix%3.jpg").arg(dir_str).arg(currenttime).arg(insertcount++);

    //QMessageBox::information(NULL,"insertcount",QString("%1").arg(insertcount));

    mylist.append(spath);

    sumcount = mylist.count()-1;
    pixmap.save(spath);


    QPixmap pixmap1(spath);
    int sum = insertcount;

    if(sum%2==0)
    {
        ui->label->setPixmap(pixmap1);
        ui->label->resize(QSize(pixmap1.width(),pixmap1.height()));

    }
    else
    {
        ui->label_fan->setPixmap(pixmap1);
        ui->label_fan->resize(QSize(pixmap1.width(),pixmap1.height()));
    }
}
