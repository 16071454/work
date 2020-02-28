#include "uploadinvoicethread.h"
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QDebug>
#include <QHttpPart>
#include <QHttpMultiPart>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QTextCodec>
#include <QMessageBox>
#include <QEventLoop>
#include <QDir>
#include <QFile>
#include <QTextStream>

#pragma execution_character_set("utf-8")

static int updowncount=0;

upLoadInvoiceThread::upLoadInvoiceThread(QObject *parent) : QObject(parent)
{
    m_pNetWorkManager = NULL;
}

upLoadInvoiceThread::~upLoadInvoiceThread()
{
    delete m_pNetWorkManager;
}

void upLoadInvoiceThread::replyFinished1()
{
    QNetworkReply* reply = (QNetworkReply*)sender();
    QString repl =reply->readAll();

    QByteArray ba = repl.toUtf8();
    if(repl.compare("0")!=0)
    {
        emit signal_finished(repl);

    }
    reply->deleteLater();

    QDir* dir = new QDir();
    if(!dir->exists("D:/new1job")){
        dir->mkpath("D:/new1job");
    }


    QFile file("D:/new1job/log.txt");

    if(!file.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
    {
        return ;
    }

    QTextStream stream(&file);
    QString tt = QString("%1:%2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(repl);
    stream<<"repl sumbit information to web:upLoadInvoiceThread::replyFinished1*****"+tt<<"\n";
    file.close();
}

void upLoadInvoiceThread::setsumsucee(QList<picForm*> sumsuccpic)
{
    _sumsuccpic = sumsuccpic;
}

void upLoadInvoiceThread::clearalldata()
{
    _sumsuccpic.clear();
    login_name="";
    four_code="";
    type="";
    total="";
    username="";
    password="";
}

void upLoadInvoiceThread::slot_dosomthing()
{
    if(m_pNetWorkManager == NULL)
    {
        m_pNetWorkManager = new QNetworkAccessManager();
    }
    QString m_strServerAddr = "http://139.129.103.28/index.php/finances/post_intface";
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QNetworkRequest request;
    request.setUrl(QUrl(m_strServerAddr));

    QJsonObject jsonObject;

    QJsonArray jsonArray;

    for(int i=0;i<_sumsuccpic.count();i++)
    {
        QJsonObject pageObject;
        if(_sumsuccpic.at(i)->structpicinfo.invoiceoperation != FAILD )
        {
            pageObject.insert("id",_sumsuccpic.at(i)->structpicinfo.id);
            pageObject.insert("total",QString("%1").arg(_sumsuccpic.at(i)->structpicinfo.price));
            pageObject.insert("checkRs",_sumsuccpic.at(i)->structpicinfo.checkRs);
            pageObject.insert("checkRsDesc",_sumsuccpic.at(i)->structpicinfo.problem);
            pageObject.insert("orientation",_sumsuccpic.at(i)->structpicinfo.roation);
            pageObject.insert("truthRs",_sumsuccpic.at(i)->structpicinfo.truthRs);
            pageObject.insert("identification",_sumsuccpic.at(i)->structpicinfo.identification);
            pageObject.insert("iscontract",_sumsuccpic.at(i)->structpicinfo.iscontract);
            pageObject.insert("ChailvDetails",_sumsuccpic.at(i)->structpicinfo.ChailvDetails);
             pageObject.insert("fapiao_type",_sumsuccpic.at(i)->structpicinfo.fapiao_type);
             pageObject.insert("isChailv",_sumsuccpic.at(i)->structpicinfo.isChailv);

            QJsonDocument jsonDocument = QJsonDocument::fromJson(_sumsuccpic.at(i)->structpicinfo.details.toUtf8());

            QJsonObject jsonObject = jsonDocument.object();

            pageObject.insert("details",jsonObject);

        }
        jsonArray.append(pageObject);
    }

    jsonObject.insert("login_name", login_name);
    jsonObject.insert("four_code", four_code);
    jsonObject.insert("type", type);

    jsonObject.insert("users", password);
    jsonObject.insert("password", username);

    jsonObject.insert("total", total);
    jsonObject.insert("count", QString("%1").arg(_sumsuccpic.count()));
    //jsonObject.insert("identification", total);
    jsonObject.insert("count", QString("%1").arg(_sumsuccpic.count()));
    jsonObject.insert("invoice", jsonArray);

    QJsonDocument document;

    document.setObject(jsonObject);

    QByteArray byteArray =document.toJson(QJsonDocument::Compact);

  //  QByteArray byteArray =("{\"count\":\"1\",\"four_code\":\"1010\",\"invoice\":[],,\"iscontract\":"1",\"login_name\":\"晁岱全\",\"total\":\"90\",\"type\":\"支出凭单\"}");//QString(byteArray);

    QHttpPart imagePart1;
    imagePart1.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("text/plain"));
    imagePart1.setHeader(QNetworkRequest::ContentDispositionHeader, QString("form-data; name=%1").arg("aaa"));
    imagePart1.setBody(byteArray);

    multiPart->append(imagePart1);

    QNetworkReply*reply =m_pNetWorkManager->post(request,multiPart);
    multiPart->setParent(reply);
    connect(reply, SIGNAL(finished()), this, SLOT(replyFinished1()));

    QDir* dir = new QDir();
    if(!dir->exists("D:/new1job")){
        dir->mkpath("D:/new1job");
    }


    QFile file("D:/new1job/log.txt");

    if(!file.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
    {
        return ;
    }

    QTextStream stream(&file);
    QString tt = QString("%1:%2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(QString(byteArray));
    stream<<"sumbit all invoice information to web:upLoadInvoiceThread::slot_dosomthing*****"+tt<<"\n";
    file.close();

}

