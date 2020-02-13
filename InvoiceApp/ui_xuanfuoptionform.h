/********************************************************************************
** Form generated from reading UI file 'xuanfuoptionform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XUANFUOPTIONFORM_H
#define UI_XUANFUOPTIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_xuanfuoptionForm
{
public:
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *xuanfuoptionForm)
    {
        if (xuanfuoptionForm->objectName().isEmpty())
            xuanfuoptionForm->setObjectName(QStringLiteral("xuanfuoptionForm"));
        xuanfuoptionForm->resize(117, 36);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(xuanfuoptionForm->sizePolicy().hasHeightForWidth());
        xuanfuoptionForm->setSizePolicy(sizePolicy);
        xuanfuoptionForm->setMinimumSize(QSize(117, 36));
        xuanfuoptionForm->setMaximumSize(QSize(117, 36));
        xuanfuoptionForm->setAutoFillBackground(false);
        xuanfuoptionForm->setStyleSheet(QStringLiteral("background-color: rgb(128, 128, 128);"));
        horizontalLayout_2 = new QHBoxLayout(xuanfuoptionForm);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(xuanfuoptionForm);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(128, 128, 128);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 0, 5, 0);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setAutoFillBackground(false);
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(128, 128, 128);"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/eye.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(32, 32));
        pushButton->setAutoDefault(true);
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/imag/jiangji.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(32, 32));
        pushButton_3->setAutoDefault(true);
        pushButton_3->setFlat(true);

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(32, 32));
        pushButton_2->setMaximumSize(QSize(32, 32));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_2->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/imag/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(32, 32));
        pushButton_2->setAutoDefault(true);
        pushButton_2->setFlat(true);

        horizontalLayout->addWidget(pushButton_2);


        horizontalLayout_2->addWidget(frame);


        retranslateUi(xuanfuoptionForm);

        QMetaObject::connectSlotsByName(xuanfuoptionForm);
    } // setupUi

    void retranslateUi(QWidget *xuanfuoptionForm)
    {
        xuanfuoptionForm->setWindowTitle(QApplication::translate("xuanfuoptionForm", "Form", 0));
        pushButton->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class xuanfuoptionForm: public Ui_xuanfuoptionForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XUANFUOPTIONFORM_H
