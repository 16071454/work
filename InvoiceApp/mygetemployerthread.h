#ifndef MYGETEMPLOYERTHREAD_H
#define MYGETEMPLOYERTHREAD_H

#include <QObject>
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
#include <QMetaType>

class MygetemployerThread : public QObject
{
    Q_OBJECT
public:
    explicit MygetemployerThread(QObject *parent = 0);

signals:
    void finish_get_employInfo(QStringList list);
    void signal_repeat_fourcode();

public slots:
    void slot_dosomething(QString code);
    void replyFinished1();
private:
    QStringList _employerlist;
    QNetworkAccessManager* m_pNetWorkManager;
};

#endif // MYGETEMPLOYERTHREAD_H
