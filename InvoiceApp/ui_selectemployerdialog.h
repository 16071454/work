/********************************************************************************
** Form generated from reading UI file 'selectemployerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTEMPLOYERDIALOG_H
#define UI_SELECTEMPLOYERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_selectemployerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer_4;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtoncancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *selectemployerDialog)
    {
        if (selectemployerDialog->objectName().isEmpty())
            selectemployerDialog->setObjectName(QStringLiteral("selectemployerDialog"));
        selectemployerDialog->setWindowModality(Qt::ApplicationModal);
        selectemployerDialog->resize(729, 381);
        selectemployerDialog->setStyleSheet(QLatin1String("Dialog#selectemployerDialog{background-color: rgb(255, 255, 255);}\n"
""));
        verticalLayout = new QVBoxLayout(selectemployerDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, -1, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        lineEdit = new QLineEdit(selectemployerDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(lineEdit);

        toolButton = new QToolButton(selectemployerDialog);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setStyleSheet(QLatin1String("width:16px;\n"
"height:16px;\n"
"background-color:rgba(229,229,229,1);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/serch.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(20, 20));
        toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton->setAutoRaise(false);

        horizontalLayout_3->addWidget(toolButton);


        horizontalLayout_2->addLayout(horizontalLayout_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(selectemployerDialog);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setSortingEnabled(false);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButtoncancel = new QPushButton(selectemployerDialog);
        pushButtoncancel->setObjectName(QStringLiteral("pushButtoncancel"));
        pushButtoncancel->setMinimumSize(QSize(100, 36));
        pushButtoncancel->setStyleSheet(QStringLiteral("border-image: url(:/imag/anniu_01.png);"));
        pushButtoncancel->setFlat(false);

        horizontalLayout->addWidget(pushButtoncancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(selectemployerDialog);

        QMetaObject::connectSlotsByName(selectemployerDialog);
    } // setupUi

    void retranslateUi(QDialog *selectemployerDialog)
    {
        selectemployerDialog->setWindowTitle(QApplication::translate("selectemployerDialog", "\351\200\211\346\213\251\346\212\245\351\224\200\344\272\272", 0));
        toolButton->setText(QApplication::translate("selectemployerDialog", "\346\243\200\347\264\242\345\221\230\345\267\245", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("selectemployerDialog", "\345\221\230\345\267\245\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("selectemployerDialog", "\345\221\230\345\267\245\345\247\223\345\220\215", 0));
        pushButtoncancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class selectemployerDialog: public Ui_selectemployerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTEMPLOYERDIALOG_H
