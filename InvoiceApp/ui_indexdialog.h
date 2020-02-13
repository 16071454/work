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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mybutton.h>

QT_BEGIN_NAMESPACE

class Ui_IndexDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_head;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    MyButton *pushButton_cancel;
    MyButton *pushButton_sumbit;
    QPushButton *pushButton_webpage;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *IndexDialog)
    {
        if (IndexDialog->objectName().isEmpty())
            IndexDialog->setObjectName(QStringLiteral("IndexDialog"));
        IndexDialog->setWindowModality(Qt::ApplicationModal);
        IndexDialog->resize(963, 1055);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        IndexDialog->setWindowIcon(icon);
        IndexDialog->setStyleSheet(QLatin1String("color: rgb(51, 51, 51);\n"
""));
        verticalLayout = new QVBoxLayout(IndexDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 20);
        horizontalLayout_head = new QHBoxLayout();
        horizontalLayout_head->setObjectName(QStringLiteral("horizontalLayout_head"));

        verticalLayout->addLayout(horizontalLayout_head);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(-1, 0, 0, -1);

        verticalLayout->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(IndexDialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 963, 968));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(51);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_cancel = new MyButton(IndexDialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy1);
        pushButton_cancel->setMinimumSize(QSize(100, 36));
        pushButton_cancel->setFocusPolicy(Qt::NoFocus);
        pushButton_cancel->setStyleSheet(QString::fromUtf8("width:120px;\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"height:40px;\n"
"background:rgba(229,229,229,1);\n"
"border-radius:3px;\n"
"color: rgb(102, 102, 102);"));
        pushButton_cancel->setIconSize(QSize(20, 20));
        pushButton_cancel->setAutoRepeat(false);
        pushButton_cancel->setAutoDefault(true);
        pushButton_cancel->setFlat(false);

        horizontalLayout_2->addWidget(pushButton_cancel);

        pushButton_sumbit = new MyButton(IndexDialog);
        pushButton_sumbit->setObjectName(QStringLiteral("pushButton_sumbit"));
        pushButton_sumbit->setMinimumSize(QSize(100, 36));
        pushButton_sumbit->setFocusPolicy(Qt::NoFocus);
        pushButton_sumbit->setStyleSheet(QString::fromUtf8("width:180px;\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"height:40px;\n"
"background:rgba(64,197,173,1);\n"
"border-radius:3px;"));
        pushButton_sumbit->setIconSize(QSize(20, 20));
        pushButton_sumbit->setFlat(false);

        horizontalLayout_2->addWidget(pushButton_sumbit);

        pushButton_webpage = new QPushButton(IndexDialog);
        pushButton_webpage->setObjectName(QStringLiteral("pushButton_webpage"));
        pushButton_webpage->setMinimumSize(QSize(100, 36));
        pushButton_webpage->setFocusPolicy(Qt::NoFocus);
        pushButton_webpage->setStyleSheet(QString::fromUtf8("width:180px;\n"
"height:40px;\n"
"background:rgba(83,187,235,1);\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(pushButton_webpage);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(IndexDialog);

        pushButton_cancel->setDefault(false);


        QMetaObject::connectSlotsByName(IndexDialog);
    } // setupUi

    void retranslateUi(QDialog *IndexDialog)
    {
        IndexDialog->setWindowTitle(QApplication::translate("IndexDialog", "\350\264\246e\346\215\267\347\224\265\345\255\220\346\212\245\351\224\200\347\263\273\347\273\237-\346\265\217\350\247\210", 0));
        pushButton_cancel->setText(QApplication::translate("IndexDialog", "\346\270\205\347\251\272\346\225\260\346\215\256", 0));
        pushButton_sumbit->setText(QApplication::translate("IndexDialog", "\346\217\220\344\272\244", 0));
        pushButton_webpage->setText(QApplication::translate("IndexDialog", "\345\217\221\347\245\250\345\244\271", 0));
    } // retranslateUi

};

namespace Ui {
    class IndexDialog: public Ui_IndexDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXDIALOG_H
