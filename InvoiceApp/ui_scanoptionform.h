/********************************************************************************
** Form generated from reading UI file 'scanoptionform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANOPTIONFORM_H
#define UI_SCANOPTIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scanoptionForm
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *scanoptionForm)
    {
        if (scanoptionForm->objectName().isEmpty())
            scanoptionForm->setObjectName(QStringLiteral("scanoptionForm"));
        scanoptionForm->resize(1016, 82);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scanoptionForm->sizePolicy().hasHeightForWidth());
        scanoptionForm->setSizePolicy(sizePolicy);
        scanoptionForm->setStyleSheet(QLatin1String("QWidget#scanoptionForm{background-color: rgb(128, 128, 128);\n"
"}"));
        horizontalLayout = new QHBoxLayout(scanoptionForm);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton = new QToolButton(scanoptionForm);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy1);
        toolButton->setMinimumSize(QSize(140, 40));
        toolButton->setMaximumSize(QSize(120, 40));
        toolButton->setLayoutDirection(Qt::LeftToRight);
        toolButton->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background:rgba(64,197,173,1);\n"
"border-radius:20px;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/autoscan.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(16, 16));
        toolButton->setPopupMode(QToolButton::DelayedPopup);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(scanoptionForm);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        sizePolicy1.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy1);
        toolButton_2->setMinimumSize(QSize(140, 0));
        toolButton_2->setMaximumSize(QSize(140, 40));
        toolButton_2->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:#CCCCCC;\n"
"\n"
"background:rgba(255,255,255,1);\n"
"border-radius:20px;\n"
"border:1px solid rgba(204,204,204,1);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imag/lianxuscan.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(32, 32));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(scanoptionForm);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        sizePolicy1.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy1);
        toolButton_3->setMinimumSize(QSize(155, 0));
        toolButton_3->setMaximumSize(QSize(155, 40));
        toolButton_3->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: #CCCCCC;\n"
"\n"
"background:rgba(255,255,255,1);\n"
"border-radius:20px;\n"
"border:1px solid rgba(204,204,204,1);"));
        toolButton_3->setIconSize(QSize(0, 0));
        toolButton_3->setPopupMode(QToolButton::DelayedPopup);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_3->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_3);

        label = new QLabel(scanoptionForm);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(466, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(scanoptionForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pushButton->setFont(font);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("width:120px;\n"
"height:40px;\n"
"background:rgba(83,187,235,1);\n"
"border-radius:3px;\n"
"color: rgb(255, 255, 255);\n"
"font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButton->setAutoDefault(true);
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);


        retranslateUi(scanoptionForm);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(scanoptionForm);
    } // setupUi

    void retranslateUi(QWidget *scanoptionForm)
    {
        scanoptionForm->setWindowTitle(QApplication::translate("scanoptionForm", "Form", 0));
        toolButton->setText(QApplication::translate("scanoptionForm", "\350\207\252\345\212\250\346\211\253\346\217\217\345\217\221\347\245\250", 0));
        toolButton_2->setText(QApplication::translate("scanoptionForm", "\350\277\236\347\273\255\346\211\253\346\217\217\345\217\221\347\245\250", 0));
        toolButton_3->setText(QApplication::translate("scanoptionForm", "\345\210\207\346\215\242\345\217\221\347\245\250\347\261\273\345\236\213", 0));
        label->setText(QApplication::translate("scanoptionForm", "TextLabel", 0));
        pushButton->setText(QApplication::translate("scanoptionForm", "\350\277\224\345\233\236\346\265\217\350\247\210\347\225\214\351\241\265", 0));
    } // retranslateUi

};

namespace Ui {
    class scanoptionForm: public Ui_scanoptionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANOPTIONFORM_H
