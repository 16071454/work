/********************************************************************************
** Form generated from reading UI file 'scandlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANDLG_H
#define UI_SCANDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_scandlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_head;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_fan;
    QHBoxLayout *horizontalLayout_3;

    void setupUi(QDialog *scandlg)
    {
        if (scandlg->objectName().isEmpty())
            scandlg->setObjectName(QStringLiteral("scandlg"));
        scandlg->resize(841, 528);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        scandlg->setWindowIcon(icon);
        scandlg->setStyleSheet(QLatin1String("QDialog#scandlg{background-color: rgb(128, 128, 128);}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(scandlg);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_head = new QHBoxLayout();
        horizontalLayout_head->setObjectName(QStringLiteral("horizontalLayout_head"));
        horizontalLayout_head->setContentsMargins(-1, -1, -1, 0);

        verticalLayout->addLayout(horizontalLayout_head);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        label = new QLabel(scandlg);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        label_fan = new QLabel(scandlg);
        label_fan->setObjectName(QStringLiteral("label_fan"));
        sizePolicy.setHeightForWidth(label_fan->sizePolicy().hasHeightForWidth());
        label_fan->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_fan);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(scandlg);

        QMetaObject::connectSlotsByName(scandlg);
    } // setupUi

    void retranslateUi(QDialog *scandlg)
    {
        scandlg->setWindowTitle(QApplication::translate("scandlg", "\346\211\253\346\217\217\347\225\214\351\235\242", 0));
        label->setText(QString());
        label_fan->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class scandlg: public Ui_scandlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANDLG_H
