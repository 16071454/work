#include "invoiceable.h"
#include "ui_invoiceable.h"
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDate>

#pragma execution_character_set("utf-8")

Invoiceable::Invoiceable(INVOICEOPERATION type, QWidget *parent) :
    QWidget(parent),
    _type(type),
    _amount(0),
    _myModel(NULL),
    _sumprice(0.0),
    ui(new Ui::Invoiceable)
{
    ui->setupUi(this);
    ui->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {"
                                                     "color: white;background-color:#66ccb7;}");
    ui->tableView->horizontalHeader()->setMinimumHeight(35);

    ui->tableView->setFixedWidth(1000);
    initDataView();
    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

Invoiceable::~Invoiceable()
{
    delete ui;
}

void Invoiceable::setDataView(QStringList piclist)
{

    int row=_myModel->rowCount();
    QList<QStandardItem *>itemlist;
    if(!_tabTypeList.contains(piclist.at(0)))
    {
        _tabTypeList.append(piclist.at(0));
        QStandardItem *item = new QStandardItem(piclist.at(0));
        item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        itemlist.append(item);
        //        if(piclist.at(0) == "0")
        //        {
        //            QStandardItem *item = new QStandardItem("招待餐费住宿");
        //             item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        //            itemlist.append(item);


        //        }
        //        else if(piclist.at(0) == "1")
        //        {
        //            QStandardItem *item = new QStandardItem("误餐费(团建)");
        //             item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        //            itemlist.append(item);
        //        }
        //        else if(piclist.at(0) == "2")
        //        {
        //            QStandardItem *item = new QStandardItem("加班餐费住宿");
        //             item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        //            itemlist.append(item);
        //        }
        //        else if(piclist.at(0) == "3")
        //        {
        //            QStandardItem *item = new QStandardItem("其他");
        //             item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        //            itemlist.append(item);
        //        }
        //        else if(piclist.at(0) == "4")
        //        {
        //            QStandardItem *item = new QStandardItem("差旅招待住宿");
        //             item->setFlags(item->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        //            itemlist.append(item);
        //        }
        QStandardItem *item1 = new QStandardItem("1");
        item1->setFlags(item1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        itemlist.append(item1);
        QStandardItem *item2 = new QStandardItem(QString("%1").arg(piclist.at(1)));
        item2->setFlags(item2->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        itemlist.append(item2);
        //QMessageBox::information(NULL,"this",piclist.at(1));
        QStandardItem *item3 =new QStandardItem(QString("%1").arg(piclist.at(2)));
        item3->setFlags(item3->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        itemlist.append(item3);
        _myModel->insertRow(row,itemlist);
        ui->tableView->setFixedHeight(35*(_myModel->rowCount()+1));
        _sumprice+=QString(piclist.at(1)).toFloat();

    }
    else
    {
        int row = _tabTypeList.indexOf(piclist.at(0));
        QModelIndex index = _myModel->index(row,1);
        QModelIndex priceindex = _myModel->index(row,2);
        int amount = _myModel->data(index).toInt();
        _myModel->setData(index,amount+1);
        float price = _myModel->data(priceindex).toFloat() + QString(piclist.at(1)).toFloat();
        _myModel->setData(priceindex,price);
        // QMessageBox::information(NULL,"this",QString("%1").arg(price));
        _sumprice+= QString(piclist.at(1)).toFloat();
    }
    _amount+=1;

    emit signal_jisuan(_amount,_sumprice);

    QDir* dir = new QDir();
    if(!dir->exists("D:/new1job")){
        dir->mkpath("D:/new1job");
    }


    QFile file("D:/new1job/log.txt");

    if(!file.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
    {
        return ;
    }

    QTextStream stream(&file);
    QString tt = QString("%1:%2").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")).arg(piclist.at(0));
    stream<<"add pic information in table:Invoiceable::setDataView*****"+tt<<"\n";
    file.close();


}

void Invoiceable::cleartable()
{

    _myModel->setRowCount(0);
    _tabTypeList.clear();
    _amount=0;
    _sumprice=0;
}

void Invoiceable::initDataView()
{
    if(_myModel==NULL)
    {
        _myModel = new QStandardItemModel(ui->tableView);
        ui->tableView->setModel(_myModel);
    }
    _myModel->setColumnCount(4);
    _myModel->setHeaderData(0,Qt::Horizontal, "发票类型");
    _myModel->setHeaderData(1,Qt::Horizontal, "发票数量");
    _myModel->setHeaderData(2,Qt::Horizontal, "金额小计");
    _myModel->setHeaderData(3,Qt::Horizontal, "问题原因");
    //    if(_type == FAILD || _type == PROBLEM)
    //    {
    //        _myModel->setHeaderData(2,Qt::Horizontal, "问题原因");
    //    }
    //    else
    //    {
    //        _myModel->setHeaderData(2,Qt::Horizontal, "金额小计");
    //        _myModel->setHeaderData(3,Qt::Horizontal, "问题原因");
    //    }


    ui->label->setFixedWidth(200);
    QFont font ( "微软雅黑", 14, QFont::Black );
    ui->label->setFont(font);
    if(_type == SUCCEED)
    {
        ui->tableView->setColumnHidden(3,true);
        ui->tableView->setFixedWidth(750);
        ui->label->setText("|成功发票预览");

        // QPixmap *pixmap = new QPixmap(":/imag/images_01.png");
        // pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
        // ui->label->setScaledContents(true);
        // ui->label->setPixmap(*pixmap);
    }
    else if(_type == PROBLEM)
    {
        ui->label->setText("|问题发票预览");

        //        QPixmap *pixmap = new QPixmap(":/imag/images_02.png");
        //        pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
        //        ui->label->setScaledContents(true);
        //        ui->label->setPixmap(*pixmap);
    }
    else
    {
        ui->label->setText("|不可报销发票预览");
        //        QPixmap *pixmap = new QPixmap(":/imag/images_03.png");
        //        pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
        //        ui->label->setScaledContents(true);
        //        ui->label->setPixmap(*pixmap);
    }


}
