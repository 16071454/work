#ifndef SCANVERTICALFORM_H
#define SCANVERTICALFORM_H

#include <QWidget>
#include "invoiceable.h"

namespace Ui {
class ScanVerticalForm;
}

class ScanVerticalForm : public QWidget
{
    Q_OBJECT

public:
    explicit ScanVerticalForm(QWidget *parent = 0);
    ~ScanVerticalForm();

signals:
    void signal_modify_label(INVOICETYPE);

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

private:
    Ui::ScanVerticalForm *ui;
};

#endif // SCANVERTICALFORM_H
