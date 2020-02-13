#ifndef XUANFUOPTIONFORM_H
#define XUANFUOPTIONFORM_H

#include <QWidget>
#include <QPropertyAnimation>
#include <invoiceable.h>

namespace Ui {
class xuanfuoptionForm;
}

class xuanfuoptionForm : public QWidget
{
    Q_OBJECT

public:
    explicit xuanfuoptionForm(INVOICEOPERATION type, QWidget *parent = 0);
    ~xuanfuoptionForm();
    void seticon(INVOICEOPERATION type);
public slots:
    void slot_show();
    void slot_hide();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

signals:
    void signal_show_pic();
    void signal_delete_pic();
    void signal_jiangji_pic();


private:
    Ui::xuanfuoptionForm *ui;
    QWidget *_parent;
};

#endif // XUANFUOPTIONFORM_H
