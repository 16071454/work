/********************************************************************************
** Form generated from reading UI file 'invoiceable.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVOICEABLE_H
#define UI_INVOICEABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Invoiceable
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;

    void setupUi(QWidget *Invoiceable)
    {
        if (Invoiceable->objectName().isEmpty())
            Invoiceable->setObjectName(QStringLiteral("Invoiceable"));
        Invoiceable->resize(833, 224);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Invoiceable->sizePolicy().hasHeightForWidth());
        Invoiceable->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Invoiceable);
        verticalLayout->setSpacing(7);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Invoiceable);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(Invoiceable);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy2);
        tableView->setFocusPolicy(Qt::NoFocus);
        tableView->setStyleSheet(QStringLiteral(""));
        tableView->setFrameShape(QFrame::Panel);
        tableView->setFrameShadow(QFrame::Plain);
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(tableView);


        retranslateUi(Invoiceable);

        QMetaObject::connectSlotsByName(Invoiceable);
    } // setupUi

    void retranslateUi(QWidget *Invoiceable)
    {
        Invoiceable->setWindowTitle(QApplication::translate("Invoiceable", "Form", 0));
        label->setText(QApplication::translate("Invoiceable", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Invoiceable: public Ui_Invoiceable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVOICEABLE_H
