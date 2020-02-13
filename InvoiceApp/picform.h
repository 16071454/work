#ifndef PICFORM_H
#define PICFORM_H

#include <QWidget>
#include <xuanfuoptionform.h>
#include <QMouseEvent>
#include <QEvent>
#include "picviewdialog.h"
#include "invoiceable.h"


typedef struct InvoiceInfo
{
    QString id;
    INVOICETYPE invoicetype;
    INVOICEOPERATION invoiceoperation;
    int row;
    int column;
    float price;
    QString type;
    QString problem;
    QString roation;
    QString identification;
    QString receipttype;
//    QString number;
//    QString date;
//    QString  pretax_amount;
//    QString tax;
//    QString check_code;
//    QString seller;
//    QString  seller_tax_id;
//    QString buyer;
//    QString buyer_tax_id;
//    QString company_seal;
//    QString  form_type;
//    QString form_name;
//    QString ciphertext;
//    QString receiptor;
//    QString reviewer;
//    QString issuer;
//    QString item_names;
//    QString service_name;
//    QString province;

    QString checkRs;
    QString checkRsDesc;
    QString truthRs;
    QString details;

}INFO;


namespace Ui {
class picForm;
}

class picForm : public QWidget
{
    Q_OBJECT

public:
    explicit picForm(INVOICEOPERATION type, QString path, int width, int roatation, QWidget *parent = 0);
    ~picForm();
    INFO structpicinfo;
    void setxuanfuicon(INVOICEOPERATION type);
public slots:
    void slot_show_pic();
    void slot_send_operation();
    void slot_jiangji_operation();
signals:
    void signal_show();
    void signal_hide();
    void signal_operation_pic(picForm* picform);
    void signal_jiangji_pic(picForm* picform);
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
private:
    Ui::picForm *ui;
    xuanfuoptionForm *_xuanfuform;
    PicViewDialog *_picview;

};

#endif // PICFORM_H
