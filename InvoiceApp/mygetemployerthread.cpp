#include "mygetemployerthread.h"
#include "scanthread.h"


extern QString _Uploadname;

MygetemployerThread::MygetemployerThread(QObject *parent) : QObject(parent)
{
    m_pNetWorkManager = NULL;
}

void MygetemployerThread::slot_dosomething(QString code)
{

    if(m_pNetWorkManager == NULL)
    {
        m_pNetWorkManager = new QNetworkAccessManager();
    }
    QString m_strServerAddr = QString("http://139.129.103.28/index.php/finances/qt_intface?four_code=%1").arg(code);

    QNetworkRequest request;
    request.setUrl(QUrl(m_strServerAddr));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply1 =m_pNetWorkManager->get(request);

    connect(reply1, SIGNAL(finished()), this, SLOT(replyFinished1()));
}

void MygetemployerThread::replyFinished1()
{
    QNetworkReply* reply1 = (QNetworkReply*)sender();
    _employerlist.clear();

    if (reply1->error() == QNetworkReply::NoError)

    {

        QByteArray ba = reply1->readAll();

        QString result = ba;

        if(result =="0")
        {
            reply1->deleteLater();
            emit signal_repeat_fourcode();
            return;
        }


        if(ba.isEmpty() || ba.isNull())
        {
            reply1->deleteLater();
            emit signal_repeat_fourcode();
            return;
        }


        QJsonParseError jsonpe;


        QJsonDocument json = QJsonDocument::fromJson(ba, &jsonpe);

        if (jsonpe.error == QJsonParseError::NoError)
        {

            if (json.isObject())
            {
                QJsonObject obj = json.object();

                QString id =  obj["id"].toString();
                QString name =  obj["baoxiao_people"].toString();
                QString company =  obj["company"].toString();
                QString project_name =  obj["project_name"].toString();
                QString wbs_stage =  obj["wbs_stage"].toString();
                QString cost_department =  obj["cost_department"].toString();
                QString four_code =  obj["four_code"].toString();

                _Uploadname = four_code;
                _employerlist.append(id);
                _employerlist.append(name);
                _employerlist.append(company);
                _employerlist.append(project_name);
                _employerlist.append(wbs_stage);
                _employerlist.append(cost_department);
                _employerlist.append(four_code);


            }
        }
    }
    if(_employerlist.isEmpty())
    {
         reply1->deleteLater();
        return;
    }
    emit finish_get_employInfo(_employerlist);

    reply1->deleteLater();
}

