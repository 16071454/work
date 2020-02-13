#ifndef WEBDIALOG_H
#define WEBDIALOG_H

#include <QDialog>
#include <QWebView>

class  HeadDialog;
namespace Ui {
class webDialog;
}

class webDialog : public QDialog
{
    Q_OBJECT

public:
    explicit webDialog(QWidget *parent = 0);
    ~webDialog();

    void setusername(QString name);
private:
    Ui::webDialog *ui;
     HeadDialog *_head;
};

#endif // WEBDIALOG_H
