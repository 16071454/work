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

};

#endif // UPLOADINVOICETHREAD_H

