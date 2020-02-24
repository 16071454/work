#include "dialog.h"
#include "ui_dialog.h"
#include <QDesktopWidget>
#include <QFileDialog>
#include <QMessageBox>

#pragma execution_character_set("utf-8")

#define STORTPATH "D:/newjob/invoice"
extern int scanlistindex;
static int insertcount=0;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    bardlg(NULL),
    sumcount(0),
    m_pTwain(NULL),
    _indexdlg(NULL),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(QApplication::desktop()->size()*8/9);
    QDesktopWidget *pDesk = QApplication::desktop();
    move((pDesk->width() - this->width()) / 2, (pDesk->height() - this->height()) / 2);
    _head = new HeadDialog(this);
    _head->setbuttonvisible(false);
    connect(_head,&HeadDialog::signal_quite,this,[=](){
        this->close();
        ui->label->clear();

    });

    ui->horizontalLayout_head->addWidget(_head);


    _indexdlg = new IndexDialog();
    connect(this,SIGNAL(signal_scan_end(QVariantList)),_indexdlg,SLOT(slot_setSumpic(QVariantList)));
    connect(this,SIGNAL(signal_only_insert_code(QString)),_indexdlg,SLOT(slot_only_insert_table(QString)));
    connect(this,SIGNAL(signal_clear_tablewidget()),_indexdlg,SLOT(slot_clear_tablewidget()));


    connect(_indexdlg,&IndexDialog::signal_show_scanlog,this,[=](){
        this->show();

    });


    _scanform = new scanoptionForm(this);
    _scanform->setscanButtonEnable(false);
    _scanform->setLableText("请首先加载校验文档");
    ui->horizontalLayout_2->addWidget(_scanform);
    connect(_scanform,SIGNAL(signal_continue_scan()),this,SLOT(onSelectButton()));
    connect(_scanform,SIGNAL(signal_read_excel()),this,SLOT(slot_read_excel()));
    connect(_scanform,SIGNAL(signal_reset_data()),this,SLOT(slot_reset_alldata()));
    connect(_scanform,SIGNAL(signal_check_invoice()),this,SLOT(slot_back_index()));
//    connect(this,&Dialog::signal_change_label_text,[=](){

//    });


    QThread *thread = new QThread(this);
    _scanthread = new scanThread;
    _scanthread->moveToThread(thread);
    connect(this,SIGNAL(signal_start_thread(QString)),_scanthread,SLOT(slot_dosomething(QString)));
    connect(_scanthread,SIGNAL(signal_vertify_finish(QString)),this,SLOT(slot_addcompare_excldata(QString)));
    connect(this,SIGNAL(signal_clear_tablewidget()),_scanthread,SLOT(slot_clear_tablewidget()));
    thread->start();


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onSelectButton()
{

    if(m_pTwain ==NULL)
    {
        m_pTwain = new QTwain();
        m_pTwain->setParent(this);
        connect(m_pTwain, &QTwainInterface::dibAcquired,this, &Dialog::onDibAcquired);
        connect(m_pTwain, &QTwainInterface::ScanEnd,this, &Dialog::onEndScan);
    }
    if(!m_pTwain->selectSource())
    {
        return;
    }

    if (!m_pTwain->acquire())
    {
        QMessageBox::information(NULL,"提示","扫描失败");

    }

}

void Dialog::slot_addcompare_excldata(QString str)
{
    //make picform

    //scanlistindex ++;
    // QMessageBox::information(NULL,"slot_addcompare_excldata1",str);
    if(scanlistindex > list.count()-1)
    {
        bardlg->hide();
        sumcount += list.count()-1;
        for(int i=0;i<manumberkey.count();i++)
        {

            _indexdlg->slot_setSumpic(excelContent.value(manumberkey.at(i)));
        }
        _scanform->setindexButtonEnable(true);

        return;
    }
    bardlg->setvalue(scanlistindex);

    if(QString::compare(str,"empty",Qt::CaseInsensitive)!=0 && QString::compare(str,"have",Qt::CaseInsensitive)!=0)
    {

        if(excelContent.value(str).count()==0)
        {
            //QMessageBox::information(NULL,"slot_addcompare_excldata2","null");
            emit signal_only_insert_code(str);
        }
        else
        {
          emit signal_scan_end(excelContent.value(str));
        }


    }
    emit signal_start_thread(list.at(scanlistindex));


}

void Dialog::slot_back_index()
{

    this->close();
    _indexdlg->show();
}


void Dialog::onEndScan()
{
    delete m_pTwain;
    m_pTwain = NULL;
    if(bardlg == NULL)
    {
        bardlg = new processBarDialog();
        ui->horizontalLayout_3->addWidget(bardlg);
        bardlg->setvalue(0);

    }

    bardlg->setMaxvalue(sumcount);
    bardlg->show();
    emit signal_start_thread(list.at(0));//先上传第一个

}


void Dialog::openExcel(QString fileName)
{

    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false);
    QAxObject *work_books = excel.querySubObject("WorkBooks");
    work_books->dynamicCall("Open(const QString&)", fileName);

    QAxObject *work_book = excel.querySubObject("ActiveWorkBook");
    QAxObject *work_sheets = work_book->querySubObject("Sheets");  //Sheets也可换用WorkSheets

    int sheet_count = work_sheets->property("Count").toInt();  //获取工作表数目
    if(sheet_count<1)
    {
        QMessageBox::information(this,"提示","读取文件失败");
        return;
    }

    if (sheet_count > 0)
    {
        QAxObject *work_sheet = work_book->querySubObject("Sheets(int)", 1);


        QVariant var = readAll(work_sheet);
        castVariant2ListListVariant(var);
    }
    _scanform->setLableText("文件数据读取完成");
    _scanform->setscanButtonEnable(true);
    work_book->dynamicCall("Close(Boolean)", false);  //关闭文件
    excel.dynamicCall("Quit(void)");  //退出
}

QVariant Dialog::readAll(QAxObject *sheet)
{
    QVariant var;
    if (sheet != NULL && !sheet->isNull())
    {
        QAxObject *usedRange = sheet->querySubObject("UsedRange");
        if (NULL == usedRange || usedRange->isNull())
        {
            return var;
        }
        var = usedRange->dynamicCall("Value");
        delete usedRange;
    }
    return var;
}


void Dialog::castVariant2ListListVariant(const QVariant &var)
{
    QVariantList varRows = var.toList();
    if (varRows.isEmpty())
    {
        return;
    }
    const int rowCount = varRows.size();
    QVariantList rowData;
    for (int i = 1; i < rowCount; ++i)
    {
        rowData = varRows[i].toList();
        if(rowData.count() <25)
        {
            QMessageBox::information(this,"提示","读取文件失败");
            return;
        }
        if(rowData.at(0).toString().isEmpty() && rowData.at(1).toString().isEmpty())
        {
            continue;
        }
        excelContent.insert(rowData.at(14).toString(), rowData);
        manumberkey.append(rowData.at(14).toString());
    }
    _scanthread->setlist(excelContent,manumberkey);
}


void Dialog::slot_read_excel()
{

    excelContent.clear();
    manumberkey.clear();
    _scanform->setLableText("文件数据读取中...");
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择文件"),
                                                    "D:/",
                                                    tr("Excel文件(*.xls)"));


    if(!fileName.isEmpty())
    {


        openExcel(fileName);

    }
    else
    {
         _scanform->setLableText("请首先加载校验文档");
    }


//    QFileDialog* fileDialog = new QFileDialog(this);
//    fileDialog->setWindowTitle( tr("选择文件"));
//    fileDialog->setNameFilter("*.xls");

//    if ( fileDialog->exec() == QDialog::Accepted )
//    {

//
//        QStringList FileName=fileDialog->selectedFiles();

//
//    }

}

void Dialog::onDibAcquired(QPixmap pixmap)
{
    //图片自动适应label
    ui->label->setFixedSize(800,600);
    ui->label->setScaledContents(true);
    ui->label_2->setFixedSize(800,600);
    ui->label_2->setScaledContents(true);
    QString dir_str = QString("%1").arg(STORTPATH);
    // 检查目录是否存在，若不存在则新建
    QDir dir;
    if (!dir.exists(dir_str))
    {
        dir.mkpath(dir_str);
    }

    QDateTime currentdt = QDateTime::currentDateTime();
    QString currenttime=currentdt.toString("sshhddMMyyyy");
    QString  spath = QString("%1/%2pix%3.jpg").arg(dir_str).arg(currenttime).arg(insertcount++);
    //  QMessageBox::information(NULL,"onDibAcquired",spath);

    list.append(spath);
    sumcount = list.count()-1;
    if(insertcount%2==0)
    {
        pixmap.scaled(ui->label->size(), Qt::KeepAspectRatio);
        pixmap.save(spath);
        ui->label->setPixmap(pixmap);
    }
    else
    {
        pixmap.scaled(ui->label_2->size(), Qt::KeepAspectRatio);
        pixmap.save(spath);
        ui->label_2->setPixmap(pixmap);
    }


}

void Dialog::slot_reset_alldata()
{
    list.clear();
    excelContent.clear();
    compareexcelContent.clear();
    _scanform->setscanButtonEnable(false);
    bardlg->setMaxvalue(0);
    bardlg->setvalue(0);
    ui->label->clear();
    ui->label_2->clear();
    sumcount=0;
    list.clear();
    scanlistindex=0;
    insertcount=0;
    emit signal_clear_tablewidget();
    manumberkey.clear();
    QMessageBox::information(this,"提示","所有数据已重置");

}
