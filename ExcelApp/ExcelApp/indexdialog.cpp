#include "indexdialog.h"
#include "ui_indexdialog.h"
#include <QDesktopWidget>
#include <QSpacerItem>
#include <QTimer>
#include <QMessageBox>
#include <QLabel>
#include <QDir>
#include <QDesktopWidget>


extern QString _Uploadname;


#pragma execution_character_set("utf-8")

IndexDialog::IndexDialog(QWidget *parent) :
    QDialog(parent),
    _width(0),
    ui(new Ui::IndexDialog)
{
    ui->setupUi(this);

    qRegisterMetaType<QMap<QString,QString> > ("QMap<QString,QString>>");
    setWindowFlags(Qt::CustomizeWindowHint);

    _head = new HeadDialog(this);
    connect(_head,&HeadDialog::signal_quite,this,[=](){
        this->close();
    });
    connect(_head,&HeadDialog::signal_show_dialog,this,[=](){
        this->hide();
        emit signal_show_scanlog();
    });
     this->setFixedSize(QApplication::desktop()->size()*8/9);
    _width = this->width();
    _head->setbuttonvisible(true);

    ui->horizontalLayout_head->addWidget(_head);

    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {"
                                                     "color: white;background-color:#66ccb7;}");
    ui->tableWidget->horizontalHeader()->setMinimumHeight(35);

    ui->tableWidget->setFixedWidth(_width);
    ui->tableWidget->verticalHeader()->hide();
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

IndexDialog::~IndexDialog()
{
    delete ui;
}

void IndexDialog::slot_clear_tablewidget()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setFixedSize(_width,0);
}

void IndexDialog::slot_setSumpic(QVariantList strlist)
{
 //   QMessageBox::information(NULL,"slot_setSumpic",strlist.at(14).toString());

  // comparedExcelData.append(strlist);

   int row=ui->tableWidget->rowCount();

   ui->tableWidget->insertRow(row);

   for(int i=1;i<25;i++)
   {
      if(strlist.at(i).isValid())
      {
       QTableWidgetItem *item1 = new QTableWidgetItem(strlist.at(i).toString());
       item1->setFlags(item1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
       ui->tableWidget->setItem(row,i-1,item1);
      }
      else
      {
          QTableWidgetItem *item1 = new QTableWidgetItem(" ");
          item1->setFlags(item1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
          ui->tableWidget->setItem(row,i-1,item1);
      }
   }
}

void IndexDialog::slot_only_insert_table(QString code)
{


    int row=ui->tableWidget->rowCount();
    for(int i =0;i<row;i++)
    {
        QString str = ui->tableWidget->item(i,13)->text();
        if(code==str)
        {
            return;
        }

    }
    ui->tableWidget->insertRow(row);

    QTableWidgetItem *item1 = new QTableWidgetItem(code);
    item1->setFlags(item1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
    ui->tableWidget->setItem(row,13,item1);

}































