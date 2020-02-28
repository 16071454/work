#ifndef UPLOADINGINFOFORM_H
#define UPLOADINGINFOFORM_H

#include <QWidget>
//#include "selectemployerdialog.h"
#include <mygetemployerthread.h>

namespace Ui {
class UploadingInfoForm;
}

class UploadingInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit UploadingInfoForm(QWidget *parent = 0);
    ~UploadingInfoForm();
    void setName(QString user);
    void setPages(int pagescount);
    void setPrice(float price);
    void clearalltext();
    QString getLabelname();
    QString getfourcode();
    QString gettotal();
    QString getcount();
    QString gettype();
    QString getcompany();
    QString getdanjuleixing();
    void setCombtypeenable(bool enab);
signals:
    void signal_set_refundname(QStringList info);
    void signal_start_thread(QString code);
    void signal_setbutton(bool);

public slots:
    //void slot_setemployerdata(QList<QStringList> list);
    void slot_getemployer(QStringList list);

    void slot_repeat_fourcode();
private slots:
    // void on_toolButton_clicked();

    void on_lineEdit_fourcode_returnPressed();


private:
    Ui::UploadingInfoForm *ui;
    //selectemployerDialog *_selectedemployee;
    MygetemployerThread *_mygetemployThread;
    QStringList _employerlist;
    float _count;
    int _price;
};

#endif // UPLOADINGINFOFORM_H
