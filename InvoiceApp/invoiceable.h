#ifndef INVOICEABLE_H
#define INVOICEABLE_H

#include <QWidget>
#include <QStandardItemModel>
#include <QList>

enum INVOICETYPE
{
    RECIPTION,
    TEAMWORK,
    ADDWORK,
    OTHERS,
    TRAVEL
};

enum INVOICEOPERATION
{
    SUCCEED=1,
    PROBLEM,
    FAILD
};

namespace Ui {
class Invoiceable;
}

class Invoiceable : public QWidget
{
    Q_OBJECT

public:
    explicit Invoiceable(INVOICEOPERATION type,QWidget *parent = 0);
    ~Invoiceable();
    void setDataView(QStringList piclist);
    void cleartable();

private:

    void initDataView();
signals:
    void signal_jisuan(int amount,float sumprice);

private:
    Ui::Invoiceable *ui;
    QStandardItemModel* _myModel;
    QString _title;
    QList<QString>_tabTypeList;
    INVOICEOPERATION _type;
    int _amount;
    float _sumprice;
};

#endif // INVOICEABLE_H
