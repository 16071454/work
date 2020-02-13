#ifndef SELECTEMPLOYERDIALOG_H
#define SELECTEMPLOYERDIALOG_H

#include <QDialog>
#include <QButtonGroup>
#include <QMap>

typedef struct _text

{

    QString hanzitext;

    QString _alphbat;

}TEXT;

namespace Ui {
class selectemployerDialog;
}

class selectemployerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit selectemployerDialog(QWidget *parent = 0);
    ~selectemployerDialog();
    QStringList getSelectedInfo(){return employeeInfo;}

    void setDataView(QStringList piclist);
    char convert(wchar_t n);
    bool In(wchar_t start, wchar_t end, wchar_t code);
    QString firstPinyin(QString &string);
public slots:
    void onReturnPressed(QString linetext);
    void settingTableunChanged(int row, int col);
private slots:
    void on_pushButtoncancel_clicked();
    void settingTableChanged(int row, int col);

   // void on_pushButton_confirm_clicked();

   // void on_toolButton_clicked();

private:
    Ui::selectemployerDialog *ui;
    int _selectedRow;
    QStringList employeeInfo;
    QMap<QString,QString> infomap;
    QList<TEXT> _texts;

};

#endif // SELECTEMPLOYERDIALOG_H
