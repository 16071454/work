#include "selectemployerdialog.h"
#include "ui_selectemployerdialog.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QTextCodec>


#pragma execution_character_set("utf-8")

selectemployerDialog::selectemployerDialog(QWidget *parent) :
    QDialog(parent),
    _selectedRow(-1),
    ui(new Ui::selectemployerDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(800,QApplication::desktop()->size().height()*8/9);
    ui->tableWidget->verticalHeader()->setHidden(true);
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {"
                                                       "color: white;background-color:#66ccb7;}");
    ui->tableWidget->horizontalHeader()->setMinimumHeight(35);


   // ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);

    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(settingTableChanged(int, int)));
   connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(settingTableunChanged(int, int)));


    ui->tableWidget->sortItems(1,Qt::AscendingOrder);
    ui->toolButton->setVisible(false);

    ui->lineEdit->setPlaceholderText("搜索员工");

   // ui->lineEdit->setEnabled(false);

    connect( ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(onReturnPressed(QString)) );

}

selectemployerDialog::~selectemployerDialog()
{
    delete ui;
}

void selectemployerDialog::setDataView(QStringList piclist)
{

    if(piclist.isEmpty())
    {
        return;
    }
    //_texts.clear();
    TEXT t2;
    QString name = piclist.at(1);
    t2.hanzitext = QString::fromLocal8Bit(name.toLocal8Bit());

    t2._alphbat = firstPinyin( t2.hanzitext );

    _texts.append( t2 );
    int row=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    QTableWidgetItem *check=new QTableWidgetItem;
    check->setCheckState(Qt::Unchecked);

    ui->tableWidget->setItem(row,0,check);

    QTableWidgetItem *item1 = new QTableWidgetItem(piclist.at(0));
    item1->setFlags(item1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
    ui->tableWidget->setItem(row,1,item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(piclist.at(1));
    item2->setFlags(item2->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
    ui->tableWidget->setItem(row,2,item2);

    infomap.insert(piclist.at(0),piclist.at(1));

    //    QTableWidgetItem *item3 =new QTableWidgetItem(piclist.at(2));
    //    item3->setFlags(item3->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
    //     ui->tableWidget->setItem(row,3,item3);
}

void selectemployerDialog::on_pushButtoncancel_clicked()
{
    this->reject();
    this->close();
}

void selectemployerDialog::settingTableunChanged(int row, int col)
{
    if(ui->tableWidget->item (row,0)->checkState()==Qt::Checked)
    {
        employeeInfo.clear();
        if(_selectedRow != -1)
        {
            ui->tableWidget->item(_selectedRow,0)->setCheckState(Qt::Unchecked);
        }

        _selectedRow = row;

        employeeInfo<<ui->tableWidget->item(row,1)->data(Qt::DisplayRole).toString()<<ui->tableWidget->item(row,2)->data(Qt::DisplayRole).toString();//<<ui->tableWidget->item(row,1)->data(Qt::DisplayRole).toString();
        this->accept();
    }
    else
    {
        _selectedRow = -1;
        employeeInfo.clear();
    }

}

void selectemployerDialog::settingTableChanged(int row, int col)
{
    if(ui->tableWidget->item (row,0)->checkState()==Qt::Checked)
    {
        employeeInfo.clear();
        if(_selectedRow != -1)
        {
            ui->tableWidget->item(_selectedRow,0)->setCheckState(Qt::Unchecked);
        }

        _selectedRow = row;

        employeeInfo<<ui->tableWidget->item(row,1)->data(Qt::DisplayRole).toString()<<ui->tableWidget->item(row,2)->data(Qt::DisplayRole).toString();//<<ui->tableWidget->item(row,1)->data(Qt::DisplayRole).toString();
        this->accept();
    }
    else
    {
        _selectedRow = -1;
        employeeInfo.clear();
    }


}

void selectemployerDialog::onReturnPressed(QString linetext)

{

    QString text = ui->lineEdit->text();
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    if(text.isEmpty())
    {
        for(int i=0;i<infomap.size();i++)
        {
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        QTableWidgetItem *check=new QTableWidgetItem;

        check->setCheckState(Qt::Unchecked);

        ui->tableWidget->setItem(row,0,check);

        QTableWidgetItem *item1 = new QTableWidgetItem(infomap.keys().at(i));
        item1->setFlags(item1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        ui->tableWidget->setItem(row,1,item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(infomap.value(infomap.keys().at(i)));
        item2->setFlags(item2->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        ui->tableWidget->setItem(row,2,item2);
        }
        return;
    }

    int size = _texts.size();

    for( int i = 0; i < size; i ++ )

    {

    QString string = _texts.at(i)._alphbat;

    if( string.contains( text ) )

    {

            int row=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            QTableWidgetItem *check=new QTableWidgetItem;

            check->setCheckState(Qt::Unchecked);

            ui->tableWidget->setItem(row,0,check);

            QTableWidgetItem *item1 = new QTableWidgetItem(infomap.key( _texts.at(i).hanzitext));
            item1->setFlags(item1->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
            ui->tableWidget->setItem(row,1,item1);

            QTableWidgetItem *item2 = new QTableWidgetItem(_texts.at(i).hanzitext);
            item2->setFlags(item2->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
            ui->tableWidget->setItem(row,2,item2);
        }
        else
            continue;
    }

}


QString selectemployerDialog::firstPinyin(QString &string)

{

    QTextCodec *codec4gbk = QTextCodec::codecForName("GBK");    //获取qt提供的gbk的解码器

    QByteArray buf = codec4gbk->fromUnicode( string );        //qt用的unicode，专程gbk

    int size = buf.size();

    quint16 *array = new quint16[size+1];

    QString alphbats;

    for( int i = 0, j = 0; i < buf.size(); i++, j++ )

    {

        if( (quint8)buf[i] < 0x80 )                        //gbk的第一个字节都大于0x81，所以小于0x80的都是符号，字母，数字etc

            continue;

        array[j] = (((quint8)buf[i]) << 8) + (quint8)buf[i+1];    //计算gbk编码

        i++;

        alphbats.append( convert( array[j] ) );            //相当于查表，用gbk编码得到首拼音字母

    }
    delete [] array;
    return alphbats;

}

bool selectemployerDialog::In( wchar_t start, wchar_t end, wchar_t code)

{

    return (code>=start && code<=end) ? true : false;

}

char selectemployerDialog::convert(wchar_t n)

{

    if (In(0xB0A1,0xB0C4,n)) return 'a';

    if (In(0XB0C5,0XB2C0,n)) return 'b';

    if (In(0xB2C1,0xB4ED,n)) return 'c';

    if (In(0xB4EE,0xB6E9,n)) return 'd';

    if (In(0xB6EA,0xB7A1,n)) return 'e';

    if (In(0xB7A2,0xB8c0,n)) return 'f';

    if (In(0xB8C1,0xB9FD,n)) return 'g';

    if (In(0xB9FE,0xBBF6,n)) return 'h';

    if (In(0xBBF7,0xBFA5,n)) return 'j';

    if (In(0xBFA6,0xC0AB,n)) return 'k';

    if (In(0xC0AC,0xC2E7,n)) return 'l';

    if (In(0xC2E8,0xC4C2,n)) return 'm';

    if (In(0xC4C3,0xC5B5,n)) return 'n';

    if (In(0xC5B6,0xC5BD,n)) return 'o';

    if (In(0xC5BE,0xC6D9,n)) return 'p';

    if (In(0xC6DA,0xC8BA,n)) return 'q';

    if (In(0xC8BB,0xC8F5,n)) return 'r';

    if (In(0xC8F6,0xCBF0,n)) return 's';

    if (In(0xCBFA,0xCDD9,n)) return 't';

    if (In(0xCDDA,0xCEF3,n)) return 'w';

    if (In(0xCEF4,0xD188,n)) return 'x';

    if (In(0xD1B9,0xD4D0,n)) return 'y';

    if (In(0xD4D1,0xD7F9,n)) return 'z';

    return '\0';

}


