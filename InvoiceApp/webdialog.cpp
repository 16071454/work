#include "webdialog.h"
#include "ui_webdialog.h"
#include "headdialog.h"
#include <QDesktopWidget>

webDialog::webDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::webDialog)
{
    ui->setupUi(this);
     this->setWindowFlags(Qt::Dialog |Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    _head = new HeadDialog(this);
    connect(_head,&HeadDialog::signal_quite,this,[=](){this->close();});
    ui->horizontalLayout->addWidget(_head);
    this->resize(QApplication::desktop()->size());
    this->setMinimumSize(QApplication::desktop()->size());
    //this->setMaximumSize(QSize(982, 652));


}

webDialog::~webDialog()
{
    delete ui;
}

void webDialog::setusername(QString name)
{
    _head->setUsername(name);
    ui->webView->load(QUrl("http://www.sohu.com"));

}
