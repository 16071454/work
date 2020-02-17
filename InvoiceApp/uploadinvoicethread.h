#ifndef UPLOADINVOICETHREAD_H
#define UPLOADINVOICETHREAD_H

#include <QObject>
#include "picform.h"
#include <QNetworkAccessManager>

class upLoadInvoiceThread : public QObject
{
    Q_OBJECT
public:
    explicit upLoadInvoiceThread(QObject *parent = 0);

    ~upLoadInvoiceThread();
    void setsumsucee(QList<picForm *> sumsuccpic);

    void setlogname(QString name){login_name =name; }
    void setcodee(QString name){four_code =name; }
    void settype(QString name){type =name; }
    void settotal(QString name){total =name; }
    void clearalldata();
    void setusername(QString name){username = name;}
    void setpassword(QString name){password = name;}
signals:
    void signal_finished(QString fivecode);

public slots:
    void slot_dosomthing();
    void replyFinished1();
private:
    QNetworkAccessManager *m_pNetWorkManager;
    QList<picForm*> _sumsuccpic;
    QString login_name;
    QString four_code;
    QString type;
    QString total;
    QString username;
    QString password;

};

#endif // UPLOADINVOICETHREAD_H

