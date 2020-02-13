/********************************************************************************
** Form generated from reading UI file 'processbardialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSBARDIALOG_H
#define UI_PROCESSBARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_processBarDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QDialog *processBarDialog)
    {
        if (processBarDialog->objectName().isEmpty())
            processBarDialog->setObjectName(QStringLiteral("processBarDialog"));
        processBarDialog->setWindowModality(Qt::ApplicationModal);
        processBarDialog->resize(463, 40);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(processBarDialog->sizePolicy().hasHeightForWidth());
        processBarDialog->setSizePolicy(sizePolicy);
        processBarDialog->setStyleSheet(QLatin1String("QDialog#processBarDialog{\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(85, 85, 255);}"));
        verticalLayout = new QVBoxLayout(processBarDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(processBarDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(processBarDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        progressBar->setAutoFillBackground(false);
        progressBar->setStyleSheet(QLatin1String("QProgressBar{ \n"
"text-align:center;\n"
"color: rgb(170, 85, 0);}\n"
"\n"
"\n"
"\n"
""));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);


        retranslateUi(processBarDialog);

        QMetaObject::connectSlotsByName(processBarDialog);
    } // setupUi

    void retranslateUi(QDialog *processBarDialog)
    {
        processBarDialog->setWindowTitle(QApplication::translate("processBarDialog", "\350\277\233\345\272\246", 0));
        label->setText(QApplication::translate("processBarDialog", "\346\255\243\345\234\250\346\240\241\351\252\214\345\217\221\347\245\250\357\274\214\350\257\267\347\250\215\345\220\216", 0));
    } // retranslateUi

};

namespace Ui {
    class processBarDialog: public Ui_processBarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSBARDIALOG_H
