#ifndef SCANOPTIONFORM_H
#define SCANOPTIONFORM_H

#include <QWidget>

namespace Ui {
class scanoptionForm;
}

class scanoptionForm : public QWidget
{
    Q_OBJECT

public:
    explicit scanoptionForm(QWidget *parent = 0);
    ~scanoptionForm();
    void setscanButtonEnable(bool isvisible);

    void setLableText(QString str);
    void setindexButtonEnable(bool isvisible);
signals:
     void signal_continue_scan();
     void signal_reset_data();
     void signal_check_invoice();
     void signal_read_excel();

//public slots:
//    void setText(INVOICETYPE type);
private slots:
    void on_pushButton_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_reset_clicked();

private:
    Ui::scanoptionForm *ui;
};

#endif // SCANOPTIONFORM_H
