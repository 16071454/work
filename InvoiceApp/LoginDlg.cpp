#include "LoginDlg.h"
#include "ui_LoginDlg.h"
#include "mybutton.h"
#include "verificationcodelabel.h"
#include "QDebug"
#include <qtimer.h>
#include <QMessageBox>
#include <QPixmap>
#include "picform.h"
#include "picviewdialog.h"

#pragma execution_character_set("utf-8")

Dialog* Dialog::_logindlg = NULL;
bool isdhow;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    rightCode(false),
    _indexdlg(NULL),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    qRegisterMetaType<QList<QStringList> > ("QList<QStringList>");

    this->setWindowFlags(Qt::Dialog |Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    ui->lineEdit_user_name->setPlaceholderText("请输入用户名");


    QAction *searchAction_name = new QAction(ui->lineEdit_user_name);
    searchAction_name->setIcon(QIcon(":/imag/u277.png"));
    ui->lineEdit_user_name->addAction(searchAction_name,QLineEdit::LeadingPosition);

    ui->lineEdit__pwd->setPlaceholderText("请输入密码");
    QAction *searchAction_pwd = new QAction(ui->lineEdit__pwd);
    searchAction_pwd->setIcon(QIcon(":/imag/u276.png"));
    ui->lineEdit__pwd->addAction(searchAction_pwd,QLineEdit::LeadingPosition);

    QPixmap *pixmap = new QPixmap(":/imag/logleft.png");
    pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(*pixmap);

    // ui->frame_right->setMinimumSize(500,400);
    connect(ui->lineEdit_vertify_code,SIGNAL(textChanged(QString)),this,SLOT(checkCode(QString)));
    connect(this,SIGNAL(signal_mainshow()),this,SLOT(slot_showscan()));

    ui->pushButton_denglu->setProperty(":/imag/u257.png","登录");


    connect(ui->pushButton_denglu,&MyButton::clicked, [=](){
        ui->pushButton_denglu->zoom1();
        ui->pushButton_denglu->zoom2();
        emit signal_mainshow();

    });
    // slotgetEmployer();

    ui->label_codepic->setFixedSize(32,32);
    QPixmap *pixmap1 = new QPixmap();

    pixmap1->load("");

    pixmap1->scaled(ui->label_codepic->size(), Qt::KeepAspectRatio);
    ui->label_codepic->setScaledContents(true);
    ui->label_codepic->setPixmap(*pixmap1);

    ui->label_username_tip->hide();
    ui->label_pwdtip->hide();
    QThread *thread = new QThread(this);
    _cleaninitObject = new cleanInitFile;
    _cleaninitObject->moveToThread(thread);
    connect(this,SIGNAL(signal_start_thread()),_cleaninitObject,SLOT(slot_dosomething()));
    thread->start();

}

Dialog::~Dialog()
{
    delete _cleaninitObject;
    delete ui;
}

void Dialog::mybuttonAction()
{

}

//void Dialog::replyFinished1()
//{
//    //QNetworkReply* reply1 = (QNetworkReply*)sender();

//    if (reply1->error() == QNetworkReply::NoError)

//    {

//        QByteArray ba = reply1->readAll();

//        QJsonParseError jsonpe;

//        QJsonDocument json = QJsonDocument::fromJson(ba, &jsonpe);

//        if (jsonpe.error == QJsonParseError::NoError)

//        {

//            if (json.isArray())
//            {
//                  QJsonArray array = json.array();
//                  for(int i=0;i< array.count();i++)
//                  {
//                      if(array.at(i).isObject())
//                      {
//                          QJsonObject obj = array.at(i).toObject();
//                         QString id =  obj["id"].toString();
//                         QString name =  obj["name"].toString();
//                         QStringList map;
//                         map<<id<<name;
//                         _employerlist.append(map);
//                      }
//                  }

//            }
//        }
//    }

//    if(_indexdlg == NULL)
//    {

//        _indexdlg = new IndexDialog();
//        ui->pushButton_denglu->setEnabled(true);
//    }

//    reply1->deleteLater();
//    isdhow=true;
//}

//void Dialog::slotgetEmployer()
//{
//    if(m_pNetWorkManager == NULL)
//    {
//        m_pNetWorkManager = new QNetworkAccessManager();
//    }
//    QString m_strServerAddr = "http://139.129.103.28/index.php/finances/people_intface";

//    QNetworkRequest request;
//    request.setUrl(QUrl(m_strServerAddr));
//    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

//    reply1 =m_pNetWorkManager->post(request,  QByteArray("[]"));
//   // QEventLoop ev;

//    connect(reply1, SIGNAL(finished()), this, SLOT(replyFinished1()));


//    //ev.exec(QEventLoop::ExcludeUserInputEvents);

//    //emit signal_putinto_employer(_employerlist);
//}


void Dialog::checkCode(QString code)
{
    QString codestr = ui->label_verfiycode->getVerificationCode();

    QPixmap *pixmap = new QPixmap();


    if(QString::compare(code,codestr,Qt::CaseInsensitive)==0)
    {
        pixmap->load(":/imag/u240.png");
        rightCode=true;
    }
    else
    {
        pixmap->load(":/imag/u241.png");
        rightCode=false;
    }

    pixmap->scaled(ui->label_codepic->size(), Qt::KeepAspectRatio);
    ui->label_codepic->setScaledContents(true);
    ui->label_codepic->setPixmap(*pixmap);

}

void Dialog::slot_showscan()
{
    if(_indexdlg ==NULL)
    {
        _indexdlg = new IndexDialog();
    }

//   if(ui->lineEdit_user_name->text()== "admin" && rightCode==true && ui->lineEdit__pwd->text()== "123456")
//    {
        _indexdlg->setusername(ui->lineEdit_user_name->text());
        ui->lineEdit_user_name->clear();
        ui->lineEdit__pwd->clear();
        ui->lineEdit_vertify_code->clear();
        Dialog::instanceLogin()->hide();
        _indexdlg->setSuccessScorllArea();
        _indexdlg->show();

//    }
//    else
//    {
//        QMessageBox::information(NULL,"提示","登录失败");
//        return;
//    }
}




void Dialog::on_pushButton_denglu_clicked()
{

}
