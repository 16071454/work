/********************************************************************************
** Form generated from reading UI file 'webdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBDIALOG_H
#define UI_WEBDIALOG_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_webDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QWebView *webView;

    void setupUi(QDialog *webDialog)
    {
        if (webDialog->objectName().isEmpty())
            webDialog->setObjectName(QStringLiteral("webDialog"));
        webDialog->setWindowModality(Qt::ApplicationModal);
        webDialog->resize(961, 705);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        webDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(webDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        webView = new QWebView(webDialog);
        webView->setObjectName(QStringLiteral("webView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(webView->sizePolicy().hasHeightForWidth());
        webView->setSizePolicy(sizePolicy);
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        verticalLayout->addWidget(webView);


        retranslateUi(webDialog);

        QMetaObject::connectSlotsByName(webDialog);
    } // setupUi

    void retranslateUi(QDialog *webDialog)
    {
        webDialog->setWindowTitle(QApplication::translate("webDialog", "\345\217\221\347\245\250\345\244\271\351\242\204\350\247\210", 0));
    } // retranslateUi

};

namespace Ui {
    class webDialog: public Ui_webDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBDIALOG_H
