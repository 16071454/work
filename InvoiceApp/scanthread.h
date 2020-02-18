#ifndef SCANTHREAD_H
#define SCANTHREAD_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QMetaType>

class scanThread : public QObject
{
    Q_OBJECT
public:
    explicit scanThread(QObject *parent = 0);
    void setlist(QList<QString> list){_list = list;}

    ~scanThread();
signals:
    void signal_vertify_finish(QMap<QString,QString> _strlist);
public slots:
    void slot_dosomething(QString path, QString baoxiaoren, QString company, QString certify, QString scantype, QString _identification, QString _iscontract);
    void replyFinished1();
private:
    QNetworkAccessManager * m_pNetWorkManager;
    QString _picpath;
    QList<QString> _list;
};

#endif // SCANTHREAD_H
