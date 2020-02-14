#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include <QThread>
#include "indexdialog.h"

#include <QEventLoop>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    static Dialog*instanceLogin()
    {
        if(_logindlg==NULL)
        {
            _logindlg = new Dialog();
        }
        return _logindlg;
    }

   // void slotgetEmployer();
    QList<QStringList> getemployer();

//public slots:
    //    void replyFinished1();
public slots:
    void replyFinished1();
private slots:
    void mybuttonAction();
    void checkCode(QString code);
    void slot_showscan();


    void on_pushButton_denglu_clicked();

signals:
    void signal_start_thread();
    void signal_mainshow();
    void start_thread(QString,QString,QString,QString,QString);

private:
    Ui::Dialog *ui;
    cleanInitFile *_cleaninitObject;

    bool rightCode;
    IndexDialog *_indexdlg;
    static Dialog* _logindlg;
    QNetworkAccessManager* m_pNetWorkManager;

    // QNetworkReply* reply1 ;

};

#endif // LOGINDLG_H
