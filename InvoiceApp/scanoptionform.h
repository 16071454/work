#ifndef SCANOPTIONFORM_H
#define SCANOPTIONFORM_H

#include <QWidget>
#include "scanverticalform.h"
namespace Ui {
class scanoptionForm;
}

class scanoptionForm : public QWidget
{
    Q_OBJECT

public:
    explicit scanoptionForm(QWidget *parent = 0);
    ~scanoptionForm();
    QString getscantype();

    void setpushbutton(bool visbale);
signals:
     void signal_continue_scan(int type);
     void signal_auto_scan(int type);
     void signal_check_invoice();
     void siganl_set_invoice_type(INVOICETYPE type);

public slots:
    void setText(INVOICETYPE type);
private slots:
    void on_pushButton_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_2_clicked();


    void on_toolButton_clicked();

    void on_toolButton_4_clicked();

private:
    Ui::scanoptionForm *ui;
    ScanVerticalForm *_scanverticaldlg;
    QString _scantype;
};

#endif // SCANOPTIONFORM_H
