/********************************************************************************
** Form generated from reading UI file 'moveinvoicedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVEINVOICEDIALOG_H
#define UI_MOVEINVOICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MoveInvoiceDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_charcount;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_confirm;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *MoveInvoiceDialog)
    {
        if (MoveInvoiceDialog->objectName().isEmpty())
            MoveInvoiceDialog->setObjectName(QStringLiteral("MoveInvoiceDialog"));
        MoveInvoiceDialog->setWindowModality(Qt::ApplicationModal);
        MoveInvoiceDialog->resize(593, 278);
        MoveInvoiceDialog->setStyleSheet(QLatin1String("QDialog#MoveInvoiceDialog{background-color: rgb(255, 255, 255);}\n"
"\n"
""));
        verticalLayout_3 = new QVBoxLayout(MoveInvoiceDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        line = new QFrame(MoveInvoiceDialog);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(MoveInvoiceDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Arial\";"));

        horizontalLayout_2->addWidget(label_2);

        comboBox = new QComboBox(MoveInvoiceDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setAutoFillBackground(false);
        comboBox->setStyleSheet(QStringLiteral(""));
        comboBox->setInsertPolicy(QComboBox::InsertAfterCurrent);
        comboBox->setFrame(true);

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(MoveInvoiceDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Arial\";"));

        verticalLayout->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout);

        textEdit = new QTextEdit(MoveInvoiceDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);"));

        horizontalLayout_3->addWidget(textEdit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_charcount = new QLabel(MoveInvoiceDialog);
        label_charcount->setObjectName(QStringLiteral("label_charcount"));
        label_charcount->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"Arial\";"));

        verticalLayout_2->addWidget(label_charcount);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_cancel = new QPushButton(MoveInvoiceDialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setMinimumSize(QSize(100, 36));
        pushButton_cancel->setMaximumSize(QSize(100, 36));
        pushButton_cancel->setStyleSheet(QLatin1String("width:120px;\n"
"height:40px;\n"
"background:rgba(229,229,229,1);\n"
"border-radius:3px;\n"
"color: #666666;"));

        horizontalLayout_4->addWidget(pushButton_cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton_confirm = new QPushButton(MoveInvoiceDialog);
        pushButton_confirm->setObjectName(QStringLiteral("pushButton_confirm"));
        pushButton_confirm->setMinimumSize(QSize(100, 36));
        pushButton_confirm->setMaximumSize(QSize(100, 36));
        pushButton_confirm->setStyleSheet(QLatin1String("width:120px;\n"
"height:40px;\n"
"background:rgba(64,197,173,1);\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(pushButton_confirm);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_3->addLayout(horizontalLayout_4);


        retranslateUi(MoveInvoiceDialog);

        QMetaObject::connectSlotsByName(MoveInvoiceDialog);
    } // setupUi

    void retranslateUi(QDialog *MoveInvoiceDialog)
    {
        MoveInvoiceDialog->setWindowTitle(QApplication::translate("MoveInvoiceDialog", "\347\247\273\345\212\250\345\217\221\347\245\250", 0));
        label_2->setText(QApplication::translate("MoveInvoiceDialog", "\347\247\273\345\212\250\350\207\263\357\274\232", 0));
        comboBox->setCurrentText(QString());
        label_3->setText(QApplication::translate("MoveInvoiceDialog", "\345\216\237\345\233\240\357\274\232", 0));
        label_charcount->setText(QApplication::translate("MoveInvoiceDialog", "TextLabel", 0));
        pushButton_cancel->setText(QApplication::translate("MoveInvoiceDialog", "\345\217\226\346\266\210", 0));
        pushButton_confirm->setText(QApplication::translate("MoveInvoiceDialog", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class MoveInvoiceDialog: public Ui_MoveInvoiceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVEINVOICEDIALOG_H
