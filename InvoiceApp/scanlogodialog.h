#ifndef SCANLOGODIALOG_H
#define SCANLOGODIALOG_H

#include <QDialog>

namespace Ui {
class ScanLogoDialog;
}

class ScanLogoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScanLogoDialog(QWidget *parent = 0);
    ~ScanLogoDialog();

private:
    Ui::ScanLogoDialog *ui;
};

#endif // SCANLOGODIALOG_H
