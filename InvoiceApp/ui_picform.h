/********************************************************************************
** Form generated from reading UI file 'picform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICFORM_H
#define UI_PICFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_picForm
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QWidget *picForm)
    {
        if (picForm->objectName().isEmpty())
            picForm->setObjectName(QStringLiteral("picForm"));
        picForm->resize(645, 353);
        picForm->setStyleSheet(QStringLiteral("QWidget#picForm{background-color: rgb(255, 255, 255);}"));
        horizontalLayout = new QHBoxLayout(picForm);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, 20);
        label = new QLabel(picForm);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        retranslateUi(picForm);

        QMetaObject::connectSlotsByName(picForm);
    } // setupUi

    void retranslateUi(QWidget *picForm)
    {
        picForm->setWindowTitle(QApplication::translate("picForm", "Form", 0));
        label->setText(QApplication::translate("picForm", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class picForm: public Ui_picForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICFORM_H
