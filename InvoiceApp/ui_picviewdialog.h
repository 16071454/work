/********************************************************************************
** Form generated from reading UI file 'picviewdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICVIEWDIALOG_H
#define UI_PICVIEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PicViewDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QDialog *PicViewDialog)
    {
        if (PicViewDialog->objectName().isEmpty())
            PicViewDialog->setObjectName(QStringLiteral("PicViewDialog"));
        PicViewDialog->setWindowModality(Qt::ApplicationModal);
        PicViewDialog->resize(675, 466);
        PicViewDialog->setLayoutDirection(Qt::LeftToRight);
        PicViewDialog->setStyleSheet(QStringLiteral("background-color: rgb(128, 128, 128);"));
        horizontalLayout = new QHBoxLayout(PicViewDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        label = new QLabel(PicViewDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        retranslateUi(PicViewDialog);

        QMetaObject::connectSlotsByName(PicViewDialog);
    } // setupUi

    void retranslateUi(QDialog *PicViewDialog)
    {
        PicViewDialog->setWindowTitle(QApplication::translate("PicViewDialog", "Dialog", 0));
        label->setText(QApplication::translate("PicViewDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class PicViewDialog: public Ui_PicViewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICVIEWDIALOG_H
