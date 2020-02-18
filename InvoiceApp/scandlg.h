#ifndef SCANDLG_H
#define SCANDLG_H

#include <QDialog>
#include "headdialog.h"
#include "scanoptionform.h"
#include "scanthread.h"
#include <QThread>
#include "qtwaininterface.h"
#include <QAbstractNativeEventFilter>
#include <QPrinter>
#include <QFile>
#include "processbardialog.h"
#include "scanlogodialog.h"
class opencvObject;

namespace Ui {
class scandlg;
}

class scandlg : public QDialog
{
    Q_OBJECT

public:
    explicit scandlg(QWidget *parent = 0);
    ~scandlg();
    void setText(INVOICETYPE type);
    void setusername(QString name);
    void showEvent(QShowEvent* thisEvent);
    void setlabelclear();
    void initamount();
    void setShibiecanshu(QString name, QString company,QString certify);
public slots:
    void onDibAcquired(QPixmap pixmap);
    void onSelectButton(int type);
    void onEndScan();
    void slot_upload_invoice();
    void slot_product_pic(QMap<QString, QString> str);
signals:
    void signal_start_thread(QString path,QString name,QString company,QString pingzheng,QString scantype,QString _identification,QString _iscontract);
    void signal_scan_end(QMap<QString,QString> str);
    void siganl_set_invoice_type(INVOICETYPE);
    void signal_back_index();
    void signal_show_index();
private:
    scanoptionForm *_scanform;
    Ui::scandlg *ui;
    HeadDialog *_head;
    scanThread *_scanthread;
    QTwainInterface* m_pTwain;
    QPixmap* m_pPixmap;
    QImage* m_pImage;
    QList<QString> mylist;
    ScanLogoDialog *_scanlog;
    QString _username;
    processBarDialog *bardlg;
    QWidget *tishiwidget;
    int sumcount;
    QString dir_str;
    QString identification;
    QString iscontract;
protected:
    //void paintEvent(QPaintEvent* thisEvent);
    //void resizeEvent(QResizeEvent* thisEvent);
    virtual bool winEvent(MSG* pMsg,long * result);
     opencvObject *sde;
     QString _baxiaoren;
     QString _gongsi;
     QString _danjupingzheng;

};

#endif // SCANDLG_H
