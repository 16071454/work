/********************************************************************************
** Form generated from reading UI file 'extengroupform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTENGROUPFORM_H
#define UI_EXTENGROUPFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_extengroupForm
{
public:
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_4;
    QToolButton *toolButton_6;
    QToolButton *toolButton_3;

    void setupUi(QWidget *extengroupForm)
    {
        if (extengroupForm->objectName().isEmpty())
            extengroupForm->setObjectName(QStringLiteral("extengroupForm"));
        extengroupForm->resize(784, 143);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(extengroupForm->sizePolicy().hasHeightForWidth());
        extengroupForm->setSizePolicy(sizePolicy);
        extengroupForm->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalLayout_2 = new QHBoxLayout(extengroupForm);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_5 = new QToolButton(extengroupForm);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy1);
        toolButton_5->setMinimumSize(QSize(30, 105));
        toolButton_5->setMaximumSize(QSize(30, 16777215));
        toolButton_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/tubiao_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon);
        toolButton_5->setIconSize(QSize(40, 105));
        toolButton_5->setAutoRaise(true);
        toolButton_5->setArrowType(Qt::LeftArrow);

        horizontalLayout_2->addWidget(toolButton_5);

        frame = new QFrame(extengroupForm);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 10, 0);
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(102, 204, 183);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imag/u316.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(72, 72));
        toolButton->setPopupMode(QToolButton::InstantPopup);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton->setAutoRaise(true);
        toolButton->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton);

        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(136, 105));
        toolButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(102, 204, 183);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imag/teamwork.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(72, 72));
        toolButton_2->setCheckable(false);
        toolButton_2->setAutoRepeat(false);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        toolButton_4 = new QToolButton(frame);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(136, 105));
        toolButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(102, 204, 183);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/imag/other.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon3);
        toolButton_4->setIconSize(QSize(72, 72));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_4->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_4);

        toolButton_6 = new QToolButton(frame);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setMinimumSize(QSize(136, 105));
        toolButton_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(102, 204, 183);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/imag/travel.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon4);
        toolButton_6->setIconSize(QSize(72, 72));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_6->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_6);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(136, 105));
        toolButton_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(102, 204, 183);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/imag/addwork.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon5);
        toolButton_3->setIconSize(QSize(72, 72));
        toolButton_3->setCheckable(false);
        toolButton_3->setAutoRepeat(false);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButton_3->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_3);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(extengroupForm);

        QMetaObject::connectSlotsByName(extengroupForm);
    } // setupUi

    void retranslateUi(QWidget *extengroupForm)
    {
        extengroupForm->setWindowTitle(QApplication::translate("extengroupForm", "Form", 0));
        toolButton_5->setText(QApplication::translate("extengroupForm", "...", 0));
        toolButton->setText(QApplication::translate("extengroupForm", "\346\213\233\345\276\205\351\244\220\350\264\271\344\275\217\345\256\277\347\261\273", 0));
        toolButton_2->setText(QApplication::translate("extengroupForm", "\350\257\257\351\244\220\350\264\271(\345\233\242\345\273\272\347\261\273)", 0));
        toolButton_4->setText(QApplication::translate("extengroupForm", "\345\205\266\344\273\226\347\261\273", 0));
        toolButton_6->setText(QApplication::translate("extengroupForm", "\345\220\210\345\220\214\347\261\273", 0));
        toolButton_3->setText(QApplication::translate("extengroupForm", "\346\227\240\351\234\200\350\257\206\345\210\253\351\252\214\347\234\237\347\261\273", 0));
    } // retranslateUi

};

namespace Ui {
    class extengroupForm: public Ui_extengroupForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTENGROUPFORM_H
