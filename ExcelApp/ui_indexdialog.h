/********************************************************************************
** Form generated from reading UI file 'indexdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXDIALOG_H
#define UI_INDEXDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_IndexDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_head;
    QTableWidget *tableWidget;

    void setupUi(QDialog *IndexDialog)
    {
        if (IndexDialog->objectName().isEmpty())
            IndexDialog->setObjectName(QStringLiteral("IndexDialog"));
        IndexDialog->setWindowModality(Qt::ApplicationModal);
        IndexDialog->resize(963, 1055);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        IndexDialog->setWindowIcon(icon);
        IndexDialog->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        verticalLayout = new QVBoxLayout(IndexDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        horizontalLayout_head = new QHBoxLayout();
        horizontalLayout_head->setObjectName(QStringLiteral("horizontalLayout_head"));

        verticalLayout->addLayout(horizontalLayout_head);

        tableWidget = new QTableWidget(IndexDialog);
        if (tableWidget->columnCount() < 23)
            tableWidget->setColumnCount(23);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(20, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(21, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(22, __qtablewidgetitem22);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(IndexDialog);

        QMetaObject::connectSlotsByName(IndexDialog);
    } // setupUi

    void retranslateUi(QDialog *IndexDialog)
    {
        IndexDialog->setWindowTitle(QApplication::translate("IndexDialog", "\350\264\246e\346\215\267\347\224\265\345\255\220\346\212\245\351\224\200\347\263\273\347\273\237-\346\265\217\350\247\210", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("IndexDialog", "\350\256\242\347\245\250\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("IndexDialog", "\345\267\256\346\227\205\351\242\204\350\256\242\344\272\272", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("IndexDialog", "\346\210\220\346\234\254\344\270\255\345\277\203", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("IndexDialog", "\344\271\230\346\234\272\344\272\272", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("IndexDialog", "\344\271\230\346\234\272\344\272\272\350\257\201\344\273\266\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("IndexDialog", "\344\271\230\346\234\272\344\272\272\350\257\201\344\273\266\345\217\267\347\240\201", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("IndexDialog", "\350\210\252\347\217\255\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("IndexDialog", "\350\210\252\347\251\272\345\205\254\345\217\270", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("IndexDialog", "\350\210\252\347\217\255\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("IndexDialog", "\350\210\252\347\250\213", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("IndexDialog", "\350\210\261\344\275\215\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("IndexDialog", "\345\215\225\346\215\256\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("IndexDialog", "\351\224\200\345\224\256\344\273\267", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("IndexDialog", "\347\245\250\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("IndexDialog", "\345\233\275\345\206\205\345\233\275\351\231\205", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("IndexDialog", "\346\234\272\345\273\272", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("IndexDialog", "\350\264\255\347\245\250\345\272\224\346\224\266\351\207\221\351\242\235", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("IndexDialog", "\351\200\200\347\245\250\346\211\213\347\273\255\350\264\271", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("IndexDialog", "\351\200\200\347\245\250\345\272\224\351\200\200\351\207\221\351\242\235", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QApplication::translate("IndexDialog", "\346\224\271\347\255\276\345\220\216\347\245\250\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->horizontalHeaderItem(20);
        ___qtablewidgetitem20->setText(QApplication::translate("IndexDialog", "\346\224\271\347\255\276\345\220\216\350\210\252\347\217\255", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->horizontalHeaderItem(21);
        ___qtablewidgetitem21->setText(QApplication::translate("IndexDialog", "\346\224\271\347\255\276\345\220\216\350\265\267\351\243\236\346\227\266\351\227\264", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->horizontalHeaderItem(22);
        ___qtablewidgetitem22->setText(QApplication::translate("IndexDialog", "\346\224\271\347\255\276\346\211\213\347\273\255\350\264\271", 0));
    } // retranslateUi

};

namespace Ui {
    class IndexDialog: public Ui_IndexDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXDIALOG_H
