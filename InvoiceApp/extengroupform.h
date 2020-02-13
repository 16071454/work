#ifndef EXTENGROUPFORM_H
#define EXTENGROUPFORM_H

#include <QWidget>
#include <QPropertyAnimation>
#include "invoiceable.h"

namespace Ui {
class extengroupForm;
}

class extengroupForm : public QWidget
{
    Q_OBJECT

public:
    explicit extengroupForm(QWidget *parent = 0);
    ~extengroupForm();

    int getframwidth();
    void setcando(bool sd){cando =sd;}

    void backwardForm();
    void extendwardForm();
private slots:
    void on_toolButton_5_clicked();
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_4_clicked();

signals:
    void signal_isshow();
    void signal_scan_show(INVOICETYPE type);

private:
    Ui::extengroupForm *ui;
    bool isshow;
    bool cando;

};

#endif // EXTENGROUPFORM_H
