#ifndef HEADDIALOG_H
#define HEADDIALOG_H

#include <QDialog>

namespace Ui {
class HeadDialog;
}

class HeadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HeadDialog(QWidget *parent = 0);
    ~HeadDialog();

    void setbuttonvisible(bool isvisabe);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();


signals:
    void signal_quite();
    void signal_show_dialog();

private:
    Ui::HeadDialog *ui;
    QWidget *_parent;
};

#endif // HEADDIALOG_H
