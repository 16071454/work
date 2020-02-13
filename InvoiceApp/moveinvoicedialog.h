#ifndef MOVEINVOICEDIALOG_H
#define MOVEINVOICEDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include "invoiceable.h"

namespace Ui {
class MoveInvoiceDialog;
}

class MoveInvoiceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MoveInvoiceDialog(QWidget *parent = 0);
    ~MoveInvoiceDialog();
    void setOperationType(INVOICEOPERATION type);
    void setproblemdec(QString problem);
signals:
    void signal_move_where(int index,QString cause);

private slots:
//    void on_pushButton_closed_clicked();

    void on_textEdit_textChanged();

    void on_pushButton_cancel_clicked();
    void on_pushButton_confirm_clicked();

protected:
    void closeEvent(QCloseEvent *event);


private:
    Ui::MoveInvoiceDialog *ui;
};

#endif // MOVEINVOICEDIALOG_H
