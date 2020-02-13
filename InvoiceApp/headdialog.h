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
    void setUsername(QString name);

private slots:
    void on_pushButton_clicked();
signals:
    void signal_quite();

private:
    Ui::HeadDialog *ui;
    QWidget *_parent;
};

#endif // HEADDIALOG_H
