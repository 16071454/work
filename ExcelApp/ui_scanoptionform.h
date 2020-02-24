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
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QToolButton *toolButton_reset;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QWidget *scanoptionForm)
    {
        if (scanoptionForm->objectName().isEmpty())
            scanoptionForm->setObjectName(QStringLiteral("scanoptionForm"));
        scanoptionForm->resize(995, 127);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scanoptionForm->sizePolicy().hasHeightForWidth());
        scanoptionForm->setSizePolicy(sizePolicy);
        scanoptionForm->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        horizontalLayout = new QHBoxLayout(scanoptionForm);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton_3 = new QToolButton(scanoptionForm);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(120, 105));
        toolButton_3->setMaximumSize(QSize(120, 105));
        toolButton_3->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/autoscan.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon);
        toolButton_3->setIconSize(QSize(70, 70));
        toolButton_3->setPopupMode(QToolButton::DelayedPopup);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_3->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_3);

        toolButton_2 = new QToolButton(scanoptionForm);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(120, 105));
        toolButton_2->setMaximumSize(QSize(120, 105));
        toolButton_2->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imag/u312.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(70, 70));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_reset = new QToolButton(scanoptionForm);
        toolButton_reset->setObjectName(QStringLiteral("toolButton_reset"));
        toolButton_reset->setMinimumSize(QSize(120, 105));
        toolButton_reset->setMaximumSize(QSize(120, 105));
        toolButton_reset->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imag/lianxuscan.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_reset->setIcon(icon2);
        toolButton_reset->setIconSize(QSize(70, 70));
        toolButton_reset->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_reset->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_reset);

        label = new QLabel(scanoptionForm);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(466, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(scanoptionForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(0, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        pushButton->setFont(font);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(102, 204, 183);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius:5px;"));
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
        toolButton_3->setText(QApplication::translate("scanoptionForm", "\345\212\240\350\275\275\346\240\241\345\257\271\346\226\207\344\273\266", 0));
        toolButton_2->setText(QApplication::translate("scanoptionForm", "\346\211\253\346\217\217", 0));
        toolButton_reset->setText(QApplication::translate("scanoptionForm", "\351\207\215\347\275\256\346\225\260\346\215\256", 0));
        label->setText(QApplication::translate("scanoptionForm", "TextLabel", 0));
        pushButton->setText(QApplication::translate("scanoptionForm", "\350\277\224\345\233\236\346\265\217\350\247\210\347\225\214\351\235\242", 0));
    } // retranslateUi

};

namespace Ui {
    class scanoptionForm: public Ui_scanoptionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANOPTIONFORM_H
