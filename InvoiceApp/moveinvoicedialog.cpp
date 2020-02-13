#include "moveinvoicedialog.h"
#include "ui_moveinvoicedialog.h"
#define MAX_SIZE 120

#pragma execution_character_set("utf-8")

MoveInvoiceDialog::MoveInvoiceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoveInvoiceDialog)
{
    ui->setupUi(this);
    Qt::WindowFlags flags=Qt::Dialog;
      flags |=Qt::WindowCloseButtonHint;
      setWindowFlags(flags);
    ui->label_charcount->setText(QString("%1/%2").arg(0).arg(MAX_SIZE));
    ui->textEdit->setPlaceholderText("请输入原因");

}

MoveInvoiceDialog::~MoveInvoiceDialog()
{
    delete ui;
}

void MoveInvoiceDialog::setproblemdec(QString problem)
{
    ui->textEdit->setText(problem);
}

void MoveInvoiceDialog::setOperationType(INVOICEOPERATION type)
{
    ui->comboBox->clear();
    ui->comboBox->insertItem(0,"--请选择--",0);

    if(type==SUCCEED)
    {
        ui->comboBox->insertItem(1,"问题发票",2);
        ui->comboBox->insertItem(2,"不可报销发票",3);
    }
    else if(type==PROBLEM)
    {
        ui->comboBox->insertItem(1,"成功发票",1);
        ui->comboBox->insertItem(2,"不可报销发票",3);
    }
    else if(type==FAILD)
    {
        ui->comboBox->insertItem(1,"成功发票",1);
        ui->comboBox->insertItem(2,"问题发票",2);
    }
    ui->comboBox->setCurrentIndex(0);
}


//void MoveInvoiceDialog::on_pushButton_closed_clicked()
//{
//    ui->comboBox->setCurrentIndex(0);
//    ui->textEdit->clear();
//    ui->label_charcount->setText(QString("%1/%2").arg(0).arg(MAX_SIZE));
//    this->hide();
//}

void MoveInvoiceDialog::on_textEdit_textChanged()
{

    QString textContent = ui->textEdit->toPlainText();

    int length = textContent.count();

    int maxLength = MAX_SIZE;

    if(length > maxLength) {
        int position = ui->textEdit->textCursor().position();
        QTextCursor textCursor = ui->textEdit->textCursor();
        textContent.remove(position - (length - maxLength), length - maxLength);
        ui->textEdit->setText(textContent);
        textCursor.setPosition(position - (length - maxLength));
        ui->textEdit->setTextCursor(textCursor);
    }

    length = textContent.count();

    ui->label_charcount->setText(QString("%1/%2").arg(MAX_SIZE-length).arg(MAX_SIZE));


}


void MoveInvoiceDialog::on_pushButton_cancel_clicked()
{
        ui->comboBox->setCurrentIndex(0);
        ui->textEdit->clear();
        ui->label_charcount->setText(QString("%1/%2").arg(0).arg(MAX_SIZE));
        this->reject();
}

void MoveInvoiceDialog::closeEvent(QCloseEvent *event)
{
    ui->comboBox->setCurrentIndex(0);
    ui->textEdit->clear();
    ui->label_charcount->setText(QString("%1/%2").arg(0).arg(MAX_SIZE));
    event->accept();
}

void MoveInvoiceDialog::on_pushButton_confirm_clicked()
{
    if(ui->comboBox->currentIndex()==0)
        return;
    emit signal_move_where(ui->comboBox->currentData().toInt(),ui->textEdit->toPlainText());
    this->accept();
    //this->close();
}
