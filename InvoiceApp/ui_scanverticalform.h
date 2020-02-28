/********************************************************************************
** Form generated from reading UI file 'scanverticalform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANVERTICALFORM_H
#define UI_SCANVERTICALFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mytoolbutton.h>

QT_BEGIN_NAMESPACE

class Ui_ScanVerticalForm
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    MyToolButton *toolButton;
    MyToolButton *toolButton_2;
    MyToolButton *toolButton_3;
    MyToolButton *toolButton_5;
    MyToolButton *toolButton_4;

    void setupUi(QWidget *ScanVerticalForm)
    {
        if (ScanVerticalForm->objectName().isEmpty())
            ScanVerticalForm->setObjectName(QStringLiteral("ScanVerticalForm"));
        ScanVerticalForm->setWindowModality(Qt::ApplicationModal);
        ScanVerticalForm->resize(145, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ScanVerticalForm->sizePolicy().hasHeightForWidth());
        ScanVerticalForm->setSizePolicy(sizePolicy);
        ScanVerticalForm->setMinimumSize(QSize(140, 0));
        ScanVerticalForm->setMaximumSize(QSize(155, 16777215));
        ScanVerticalForm->setStyleSheet(QLatin1String("QWidget#ScanVerticalForm{background:rgba(255,255,255,1);\n"
"border-radius:10px;\n"
"border:1px solid rgba(204,204,204,1);}"));
        verticalLayout = new QVBoxLayout(ScanVerticalForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        frame = new QFrame(ScanVerticalForm);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(155, 0));
        frame->setMaximumSize(QSize(155, 16777215));
        frame->setStyleSheet(QStringLiteral(""));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton = new MyToolButton(frame);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(155, 40));
        toolButton->setMaximumSize(QSize(155, 40));
        toolButton->setStyleSheet(QLatin1String("QToolButton{  \n"
"color:rgb(0, 0, 0);  \n"
"\n"
"}  \n"
"QToolButton:hover{\n"
"background:rgba(64,197,173,1);\n"
"color:rgb(255, 255, 255);  \n"
" \n"
"}  \n"
"QToolButton:pressed{ \n"
"background:rgba(64,197,173,1);\n"
"color:rgb(255, 255, 255); \n"
"}  "));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/saomiaoreciptionnormal.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(16, 16));
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);

        verticalLayout_2->addWidget(toolButton);

        toolButton_2 = new MyToolButton(frame);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(155, 40));
        toolButton_2->setMaximumSize(QSize(155, 40));
        toolButton_2->setStyleSheet(QLatin1String("QToolButton{  \n"
"color:rgb(0, 0, 0);  \n"
"\n"
"}  \n"
"QToolButton:hover{\n"
"background:rgba(64,197,173,1);\n"
"color:rgb(255, 255, 255);  \n"
" \n"
"}  \n"
"QToolButton:pressed{ \n"
"background:rgba(64,197,173,1);\n"
"color:rgb(255, 255, 255); \n"
"}  "));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imag/saomiaoteamworknormal.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(60, 60));
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_2->setAutoRaise(true);
        toolButton_2->setArrowType(Qt::NoArrow);

        verticalLayout_2->addWidget(toolButton_2);

        toolButton_3 = new MyToolButton(frame);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(155, 40));
        toolButton_3->setMaximumSize(QSize(155, 40));
        toolButton_3->setStyleSheet(QLatin1String("QToolButton{  \n"
"color:rgb(0, 0, 0);  \n"
"\n"
"}  \n"
"QToolButton:hover{\n"
"background:rgba(64,197,173,1);\n"
"color:rgb(255, 255, 255);  \n"
" \n"
"}  \n"
"QToolButton:pressed{ \n"
"background:rgba(64,197,173,1);\n"
"color:rgb(255, 255, 255); \n"
"}  "));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imag/saomiaoaddworknormal.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(60, 60));
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_3->setAutoRaise(true);

        verticalLayout_2->addWidget(toolButton_3);

        toolButton_5 = new MyToolButton(frame);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setMinimumSize(QSize(155, 40));
        toolButton_5->setMaximumSize(QSize(155, 40));
        toolButton_5->setStyleSheet(QLatin1String("QToolButton{  \n"
"color:rgb(0, 0, 0);  \n"
"\n"
"}  \n"
"QToolButton:hover{\n"
"background:rgba(64,197,173,1);\n"
"color:rgb(255, 255, 255);  \n"
" \n"
"}  \n"
"QToolButton:pressed{ \n"
"background:rgba(64,197,173,1);\n"
"color:rgb(255, 255, 255); \n"
"}  "));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/imag/saomiaotravelnormal.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon3);
        toolButton_5->setIconSize(QSize(60, 60));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_5->setAutoRaise(true);

        verticalLayout_2->addWidget(toolButton_5);

        toolButton_4 = new MyToolButton(frame);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(155, 40));
        toolButton_4->setMaximumSize(QSize(155, 40));
        toolButton_4->setStyleSheet(QLatin1String("QToolButton{  \n"
"color:rgb(0, 0, 0);  \n"
"\n"
"}  \n"
"QToolButton:hover{\n"
"background:rgba(64,197,173,1);\n"
"color:rgb(255, 255, 255);  \n"
" \n"
"}  \n"
"QToolButton:pressed{ \n"
"background:rgba(64,197,173,1);\n"
"color:rgb(255, 255, 255); \n"
"}  "));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/imag/saomiaoothernormal.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setIconSize(QSize(60, 60));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_4->setAutoRaise(true);

        verticalLayout_2->addWidget(toolButton_4);


        verticalLayout->addWidget(frame);


        retranslateUi(ScanVerticalForm);

        QMetaObject::connectSlotsByName(ScanVerticalForm);
    } // setupUi

    void retranslateUi(QWidget *ScanVerticalForm)
    {
        ScanVerticalForm->setWindowTitle(QApplication::translate("ScanVerticalForm", "Form", 0));
        toolButton->setText(QApplication::translate("ScanVerticalForm", "\346\213\233\345\276\205\351\244\220\350\264\271\344\275\217\345\256\277\347\261\273", 0));
        toolButton_2->setText(QApplication::translate("ScanVerticalForm", "\350\257\257\351\244\220\350\264\271(\345\233\242\345\273\272)\347\261\273", 0));
        toolButton_3->setText(QApplication::translate("ScanVerticalForm", "\346\227\240\351\234\200\350\257\206\345\210\253\351\252\214\347\234\237\347\261\273", 0));
        toolButton_5->setText(QApplication::translate("ScanVerticalForm", "   \345\220\210\345\220\214\347\261\273", 0));
        toolButton_4->setText(QApplication::translate("ScanVerticalForm", "   \345\205\266\344\273\226\347\261\273", 0));
    } // retranslateUi

};

namespace Ui {
    class ScanVerticalForm: public Ui_ScanVerticalForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANVERTICALFORM_H
