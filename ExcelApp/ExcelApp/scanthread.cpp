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
#include <QVariantList>


#pragma execution_character_set("utf-8")

QString _Uploadname;
int scanlistindex = 0;

scanThread::scanThread(QObject *parent) : QObject(parent)
{
    m_pNetWorkManager = NULL;
    qRegisterMetaType<QMap<QString,QString> > ("QMap<QString,QString>>");

}

void scanThread::setlist(QMap<QString, QVariantList> list, QStringList &anumberkey)
{
    _list = list;
    _anumberkey=&anumberkey;
}

scanThread::~scanThread()
{
    delete m_pNetWorkManager;
}


void scanThread::replyFinished1()
{

    QNetworkReply* reply1 = (QNetworkReply*)sender();

    QString repl =reply1->readAll();

    QByteArray ba = repl.toUtf8();
    QJsonParseError jsonpe;
    QJsonDocument doucment = QJsonDocument::fromJson(ba, &jsonpe);
    scanlistindex+=1;
    if ((!doucment.isNull() && (jsonpe.error == QJsonParseError::NoError)))
    {
        if (doucment.isObject())
        {
            QJsonObject obj = doucment.object();
            // QMessageBox::information(NULL,"replyFinished1","repl");
            if (obj.contains("number"))
            {
               // QMessageBox::information(NULL,"222222","number");
                QString number = obj["number"].toString();
                // QMessageBox::information(NULL,"333333333",number);
                if(number.isEmpty())
                {
                   // QMessageBox::information(NULL,"4",number);
                    emit signal_vertify_finish("empty");

                }
                else
                {
                    number.insert(3,QString("-"));
                   // QMessageBox::information(NULL,"insert",_anumberkey.at(0));

                    if(!_anumberkey->contains(number))
                    {
                       // QMessageBox::information(NULL,"no contains",number);
                        emit signal_vertify_finish(number);
                    }
                    else
                    {
                        _anumberkey->removeOne(number);
                        emit signal_vertify_finish("have");
                    }

                }

            }
//            else
//            {
//                QMessageBox::information(NULL,"this","this");
//            }
        }

    }
    reply1->deleteLater();
}

void scanThread::slot_clear_tablewidget()
{
    _list.clear();
    _anumberkey->clear();
}

void scanThread::slot_dosomething(QString path)
{
    _picpath = path;

    if(m_pNetWorkManager == NULL)
    {
        m_pNetWorkManager = new QNetworkAccessManager();
    }
    QString m_strServerAddr = "http://139.129.103.28/index.php/finances/post_intface";

    QNetworkRequest request;
    request.setUrl(QUrl(m_strServerAddr));
    QHttpMultiPart *multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart imagePart;
    imagePart.setHeader(QNetworkRequest::ContentTypeHeader, "text/html; charset=UTF-8");
    imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QString("form-data; name=\"%1\"; filename=\"%2\"").arg("aaa").arg(path));
    QFile *file = new QFile(path);
    if (!file->open(QIODevice::ReadOnly)||file->size()==0)
    {
        file->close();
        return ;
    }
    imagePart.setBodyDevice(file);
    file->setParent(multiPart);
    multiPart->append(imagePart);

    QNetworkReply*reply1 =m_pNetWorkManager->post(request, multiPart);
    multiPart->setParent(reply1);

    connect(reply1, SIGNAL(finished()), this, SLOT(replyFinished1()));

}


