#ifndef PROCESSBARDIALOG_H
#define PROCESSBARDIALOG_H

#include <QDialog>

namespace Ui {
class processBarDialog;
}

class processBarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit processBarDialog(QWidget *parent = 0);
    ~processBarDialog();
    void setvalue(int value);

    void setMaxvalue(int maxvalue);
    void setlabelText(QString text);
public slots:
    void slot_setvalue(int value);
private:
    Ui::processBarDialog *ui;
};

#endif // PROCESSBARDIALOG_H
