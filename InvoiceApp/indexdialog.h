#ifndef INDEXDIALOG_H
#define INDEXDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QTableWidget>
#include <QLabel>
#include "scandlg.h"
#include "extengroupform.h"
#include "uploadinginfoform.h"
#include "webdialog.h"
#include "moveinvoicedialog.h"
#include "uploadinvoicethread.h"
#include "cleaninitfile.h"



namespace Ui {
class IndexDialog;
}

class IndexDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IndexDialog(QWidget *parent = 0);
    ~IndexDialog();
    void setusername(QString name, QString password);
    void setSuccessScorllArea();
    void setProblemScorllArea();
    void setFaildScorllArea();
    void setpicwidget(QList<picForm*> piclist, QTableWidget *widget=NULL);
//suceess
    void setsucessrectiontable();
    void setsucessteamworktable();
    void setsucessaddworktable();
    void setsucesstraveltable();
    void setsucessotherltable();

    void setsucessrectionwidget();
    void setsucessteamworkwidget();
    void setsucessaddworkwidget();
    void setsucesstravelwidget();
    void setsucessotherlwidget();
 //problem
    void setproblemrectiontable();
    void setproblemteamworktable();
    void setproblemaddworktable();
    void setproblemtraveltable();
    void setproblemotherltable();

    void setproblemrectionwidget();
    void setproblemteamworkwidget();
    void setproblemaddworkwidget();
    void setproblemtravelwidget();
    void setproblemotherlwidget();
 //faild
    void setfaildtable();
    void setfaildwidget();

    void deleteAllitemsOfLayout(QLayout *layout);
public slots:
    void slot_delete_jiangji_oper(picForm* picform);
    void slot_setupload(int pages,float price);
    void slot_show_scan(INVOICETYPE type);
    void slot_jiangji_pic(picForm *picform);
    void slot_setSumpic(QMap<QString, QString> strlist);
    void slot_setinvoice_type(INVOICETYPE type);
    void slot_setbaoxiao(bool info);
    void slot_show_dlg();
    void slot_finishupload(QString five_code);
signals:
    void signal_cleardata();
    void signal_start_thread();
    void signal_startcleanfile_thread();
private slots:
    void on_pushButton_webpage_clicked();
    void slot_move_invoice(int index, QString cause);

    void on_pushButton_sumbit_clicked();
    void slot_cleardata();

private:
    Ui::IndexDialog *ui;
    HeadDialog *_head;
    extengroupForm *_extendform;
    UploadingInfoForm *_updownform;
    QVBoxLayout *_vlayout ;
    Invoiceable *_successTable;
    Invoiceable *_failTable;
    Invoiceable *_problemTable;
    QTableWidget *_faildWidget;

    QTableWidget *_sucesrectionsWidget;
    QTableWidget *_sucesworkteamWidget;
    QTableWidget *_sucesaddworkWidget;
    QTableWidget *_sucesothersWidget;
    QTableWidget *_sucestravelWidget;

    QTableWidget *_problemrectionsWidget;
    QTableWidget *_problemworkteamWidget;
    QTableWidget *_problemaddworkWidget;
    QTableWidget *_problemtravelWidget;
    QTableWidget *_problemothersWidget;

    QLabel *successrelabel;
    QLabel *successaddworklabel;
    QLabel *successteamworklabel;
    QLabel *successotherslabel;
    QLabel *successtravellabel;

    QLabel *problemrelabel;
    QLabel *problemaddworklabel;
    QLabel *problemteamworklabel;
    QLabel *problemotherslabel;
    QLabel *problemtravellabel;

     MoveInvoiceDialog* _movedlg;

    scandlg *_scandlg;

    QList<picForm*> _sumsuccpic;
    int _width;
    QList<QString>_sucesspicTypeList;
    webDialog *_webpage;
    int moveType;
    QString _cause;
    QString _username;
    QString _password;
    INVOICETYPE _scanType;
    QLabel *faildlabel;
    QLabel *problemlabel;
    QLabel *successlabel;
    //processBarDialog *_processbar;
    upLoadInvoiceThread *_uploainvoicethread;
    cleanInitFile *_cleaninitObject ;

};

#endif // INDEXDIALOG_H
