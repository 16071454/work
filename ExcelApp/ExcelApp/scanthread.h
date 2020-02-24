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
    void setlist(QMap<QString,QVariantList> list, QStringList &anumberkey);

    ~scanThread();
signals:
    void signal_vertify_finish(QString _strlist);
public slots:
    void slot_dosomething(QString path);
    void replyFinished1();
    void slot_clear_tablewidget();
private:
    QNetworkAccessManager * m_pNetWorkManager;
    QString _picpath;
    QMap<QString,QVariantList> _list;
    QStringList *_anumberkey;

};

#endif // SCANTHREAD_H
