/********************************************************************************
** Form generated from reading UI file 'scanlogodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANLOGODIALOG_H
#define UI_SCANLOGODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ScanLogoDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *ScanLogoDialog)
    {
        if (ScanLogoDialog->objectName().isEmpty())
            ScanLogoDialog->setObjectName(QStringLiteral("ScanLogoDialog"));
        ScanLogoDialog->setWindowModality(Qt::ApplicationModal);
        ScanLogoDialog->resize(248, 195);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScanLogoDialog->sizePolicy().hasHeightForWidth());
        ScanLogoDialog->setSizePolicy(sizePolicy);
        ScanLogoDialog->setWindowOpacity(0.9);
        ScanLogoDialog->setStyleSheet(QStringLiteral("QDialog#ScanLogoDialog{background-color: rgb(128, 128, 128);}"));
        gridLayout = new QGridLayout(ScanLogoDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(ScanLogoDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(ScanLogoDialog);

        QMetaObject::connectSlotsByName(ScanLogoDialog);
    } // setupUi

    void retranslateUi(QDialog *ScanLogoDialog)
    {
        ScanLogoDialog->setWindowTitle(QApplication::translate("ScanLogoDialog", "Dialog", 0));
        label->setText(QApplication::translate("ScanLogoDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ScanLogoDialog: public Ui_ScanLogoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANLOGODIALOG_H
