#ifndef PICVIEWDIALOG_H
#define PICVIEWDIALOG_H

#include <QDialog>


namespace Ui {
class PicViewDialog;
}

class PicViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PicViewDialog(QWidget *parent = 0);
    ~PicViewDialog();

    void setpicPath(QString picpath, int roation);

private:
    Ui::PicViewDialog *ui;
};

#endif // PICVIEWDIALOG_H
