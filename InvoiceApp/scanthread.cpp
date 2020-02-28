#include "scanthread.h"
#include <QWidget>
#include <windows.h>
#include <WinUser.h>
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
#include <QDir>
#include <QDate>

#pragma execution_character_set("utf-8")

QString _Uploadname;

scanThread::scanThread(QObject *parent) : QObject(parent)
{
    m_pNetWorkManager = NULL;
    qRegisterMetaType<QMap<QString,QString> > ("QMap<QString,QString>>");
}

scanThread::~scanThread()
{
    delete m_pNetWorkManager;
}


void scanThread::replyFinished1()
{
    QNetworkReply* reply1 = (QNetworkReply*)sender();

    QMap<QString,QString> strlist;
    QString repl =reply1->readAll();

    QByteArray ba = repl.toUtf8();
    QJsonParseError jsonpe;
    QJsonDocument doucment = QJsonDocument::fromJson(ba, &jsonpe);


    if ((!doucment.isNull() && (jsonpe.error == QJsonParseError::NoError)) && QString::compare( repl,"{}")!=0 && !repl.contains("500")|| !repl.contains("Error"))
    {
        if (doucment.isObject())
        {
            QJsonObject obj = doucment.object();


            if (obj.contains("id"))
            {
                QString id = obj["id"].toString();
                strlist.insert("id",id);
            }
            if (obj.contains("identification"))
            {
                QString identification = obj["identification"].toString();
                strlist.insert("identification",identification);
                //无需识别，直接就是成功发票
                if(QString::compare( identification,"0", Qt::CaseInsensitive)==0)
                {
                    strlist.insert("invoicetype","success");
                }
            }

            if (obj.contains("iscontract"))
            {
                QString iscontract = obj["iscontract"].toString();
                strlist.insert("iscontract",iscontract);
                //无需识别，直接就是成功发票
                if(QString::compare( iscontract,"1", Qt::CaseInsensitive)==0)
                {
                    strlist.insert("invoicetype","success");
                }
            }

            //strlist.insert("id",_picpath);
            if (obj.contains("orientation"))
            {
                QString orientation = obj["orientation"].toString();
                strlist.insert("orientation",orientation);
            }
            if (obj.contains("total"))
            {
                QString price = obj["total"].toString();
                strlist.insert("total",price);
            }

            if (obj.contains("checkRsDesc"))
            {
                QString type = obj["checkRsDesc"].toString();
                strlist.insert("checkRsDesc",type);
            }
            if (obj.contains("checkRs"))
            {
                QString kind = obj["checkRs"].toString();
                strlist.insert("checkRs",kind);
                if(QString::compare( kind,"True", Qt::CaseInsensitive)==0)
                {
                    strlist.insert("invoicetype","success");
                }
               if(QString::compare( kind,"false", Qt::CaseInsensitive)==0)
                {
                    strlist.insert("invoicetype","problem");
                }
            }
            if (obj.contains("total"))
            {
                QString price = obj["total"].toString();
                strlist.insert("total",price);
            }
            if(obj.contains("details"))
            {

                    QJsonObject detajson = obj["details"].toObject();
                    QString details = QString(QJsonDocument(detajson).toJson());
                    strlist.insert("details",details);
                    QString splistring = detajson.keys().first();
                    QString receipttype = splistring.split("-").last();
                    strlist.insert("receipttype",receipttype);

            }
            if(obj.contains("fapiao_type"))
            {

                QString fapiao_type = obj["fapiao_type"].toString();
                strlist.insert("fapiao_type",fapiao_type);

            }
            if(obj.contains("isChailv"))
            {
                QString isChailv = obj["isChailv"].toString();
                strlist.insert("isChailv",isChailv);

            }
            if(obj.contains("ChailvDetails"))
            {

                    QJsonObject ChailvDetails = obj["ChailvDetails"].toObject();
                    QString details = QString(QJsonDocument(ChailvDetails).toJson());
                    strlist.insert("ChailvDetails",details);

            }

        }
    }
    else
    {
        strlist.insert("invoicetype","fail");

        strlist.insert("id",_picpath);
        strlist.insert("price","0");

    }
    emit signal_vertify_finish(strlist);

    reply1->deleteLater();


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
    QString tt = QString("%1:%2:%3").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(_picpath).arg(QString(ba));
    stream<<"recognized return:scanThread::replyFinished1*****"+tt<<"\n";
    file.close();
}


void scanThread::slot_dosomething(QString path,QString baoxiaoren,QString company,QString certify,QString scantype,QString _identification,QString _iscontract)
{
    _picpath = path;
    if(m_pNetWorkManager == NULL)
    {
        m_pNetWorkManager = new QNetworkAccessManager();
    }
    QString m_strServerAddr = "http://139.129.103.28:8080/uploader";

    QNetworkRequest request;
    request.setUrl(QUrl(m_strServerAddr));
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    //  baoxiaoren=\"%1\";suoshu_gongsi=\"%2\";danju_leixing=\"%3\";saomiao_leixing=\"%4\"; image=\"%5\"").arg(baoxiaoren).arg(company).arg(certify).arg(scantype).arg(path));
    // imagePart.setHeader(QNetworkRequest::ContentTypeHeader,  "text/html; charset=UTF-8");

    QHttpPart imagePart0;
    imagePart0.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("text/plain"));
    imagePart0.setHeader(QNetworkRequest::ContentDispositionHeader, QString("form-data;name=\"identification\""));
    imagePart0.setBody(_identification.toLocal8Bit());

    QHttpPart imagePart6;
    imagePart6.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("text/plain"));
    imagePart6.setHeader(QNetworkRequest::ContentDispositionHeader, QString("form-data;name=\"iscontract\""));
    imagePart6.setBody(_iscontract.toLocal8Bit());

    QHttpPart imagePart1;
    imagePart1.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("text/plain"));
    imagePart1.setHeader(QNetworkRequest::ContentDispositionHeader, QString("form-data;name=\"baoxiaoren\""));
    imagePart1.setBody(baoxiaoren.toLocal8Bit());

    QHttpPart imagePart2;
    imagePart2.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("text/plain"));
    imagePart2.setHeader(QNetworkRequest::ContentDispositionHeader, QString("form-data;name=\"suoshu_gongsi\""));
    imagePart2.setBody(company.toLocal8Bit());
    QHttpPart imagePart3;
    imagePart3.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("text/plain"));
    imagePart3.setHeader(QNetworkRequest::ContentDispositionHeader, QString("form-data;name=\"danju_leixing\""));
    imagePart3.setBody(certify.toLocal8Bit());
    QHttpPart imagePart4;
    imagePart4.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("text/plain"));
    imagePart4.setHeader(QNetworkRequest::ContentDispositionHeader, QString("form-data;name=\"saomiao_leixing\""));
    imagePart4.setBody(scantype.toLocal8Bit());
    QHttpPart imagePart5;
    imagePart5.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));//
    imagePart5.setHeader(QNetworkRequest::ContentDispositionHeader, QString("form-data;name=\"%1\"; filename=\"%2\"").arg("image").arg(path));

    QFile *file = new QFile(path);
    if (!file->open(QIODevice::ReadOnly)||file->size()==0)
    {
        file->close();
        return ;
    }
    imagePart5.setBodyDevice(file);
    file->setParent(multiPart);
    multiPart->append(imagePart0);
    multiPart->append(imagePart1);
    multiPart->append(imagePart2);
    multiPart->append(imagePart3);
    multiPart->append(imagePart4);
    multiPart->append(imagePart6);
    multiPart->append(imagePart5);


    QNetworkReply*reply1 =m_pNetWorkManager->post(request, multiPart);
    multiPart->setParent(reply1);

    connect(reply1, SIGNAL(finished()), this, SLOT(replyFinished1()));

    QDir* dir = new QDir();
    if(!dir->exists("D:/new1job")){
        dir->mkpath("D:/new1job");
    }


    QFile file1("D:/new1job/log.txt");

    if(!file1.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
    {
        return ;
    }

    QTextStream stream(&file1);
    QString tt1 = QString("%1:%2:%3").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg("identification").arg(_identification);
    QString tt2 = QString("iscontract:%2").arg(_iscontract);
    QString tt3 = QString("baoxiaoren:%2").arg(baoxiaoren);
    QString tt4 = QString("suoshu_gongsi:%2").arg(company);
    QString tt5 = QString("danju_leixing:%2").arg(certify);
    QString tt6 = QString("saomiao_leixing:%2").arg(scantype);
    QString tt7 = QString("image:%2").arg(path);


    stream<<"submit recognize invoice requiry *****"+tt7+tt2+tt3+tt4+tt5+tt6+tt1<<"\n";
    file1.close();

}


