#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QAxObject>
#include "headdialog.h"
#include "scanthread.h"
#include "scanoptionform.h"
#include "qtwain.h"
#include "dib.h"
#include <QThread>
#include "processbardialog.h"
#include "qtwaininterface.h"
#include <QAbstractNativeEventFilter>
#include <indexdialog.h>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void openExcel(QString fileName);
    QVariant readAll(QAxObject *sheet);
    void castVariant2ListListVariant(const QVariant &var);
public slots:
    void slot_read_excel();
     void onDibAcquired(QPixmap pixmap);
    void slot_reset_alldata();
    void onSelectButton();
    void onEndScan();
    void slot_addcompare_excldata(QString str);
    void slot_back_index();
signals:
     void signal_start_thread(QString path);
     void signal_scan_end(QVariantList str);
     void signal_show_index();
     void signal_clear_tablewidget();
     void signal_only_insert_code(QString);
     void signal_change_label_text();
private:
    Ui::Dialog *ui;
    HeadDialog *_head;
    scanThread *_scanthread;
    scanoptionForm *_scanform;
    QMap<QString,QVariantList>excelContent;
    QList<QVariantList>compareexcelContent;
    QTwainInterface* m_pTwain;
    QPixmap* m_pPixmap;
    QList<QString> list;
    processBarDialog *bardlg;
    int sumcount;
    IndexDialog *_indexdlg;
    QStringList manumberkey;
};

#endif // DIALOG_H
