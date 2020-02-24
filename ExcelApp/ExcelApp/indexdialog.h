#ifndef INDEXDIALOG_H
#define INDEXDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QTableWidget>
#include <QLabel>
#include "headdialog.h"



namespace Ui {
class IndexDialog;
}

class IndexDialog : public QDialog
{
    Q_OBJECT

public:
    explicit IndexDialog(QWidget *parent = 0);
    ~IndexDialog();

public slots:
    void slot_clear_tablewidget();
    void slot_setSumpic(QVariantList strlist);
    void slot_only_insert_table(QString code);
signals:
    void signal_show_scanlog();
private:
    Ui::IndexDialog *ui;
    HeadDialog *_head;
    int _width;
    QList<QVariantList>comparedExcelData;
};

#endif // INDEXDIALOG_H
