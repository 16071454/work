/********************************************************************************
** Form generated from reading UI file 'LoginDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <mybutton.h>
#include <verificationcodelabel.h>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QFrame *frame_left;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *frame_right;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QFrame *line;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit_user_name;
    QLabel *label_username_tip;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEdit__pwd;
    QLabel *label_pwdtip;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_vertify_code;
    QLabel *label_codepic;
    verificationcodelabel *label_verfiycode;
    QHBoxLayout *horizontalLayout_3;
    MyButton *pushButton_denglu;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::ApplicationModal);
        Dialog->resize(1091, 649);
        QIcon icon;
        icon.addFile(QStringLiteral(":/imag/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        frame_left = new QFrame(Dialog);
        frame_left->setObjectName(QStringLiteral("frame_left"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_left->sizePolicy().hasHeightForWidth());
        frame_left->setSizePolicy(sizePolicy);
        frame_left->setMinimumSize(QSize(0, 0));
        frame_left->setFrameShape(QFrame::NoFrame);
        frame_left->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_left);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(frame_left);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        label->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(label);


        horizontalLayout_4->addWidget(frame_left);

        frame_right = new QFrame(Dialog);
        frame_right->setObjectName(QStringLiteral("frame_right"));
        sizePolicy1.setHeightForWidth(frame_right->sizePolicy().hasHeightForWidth());
        frame_right->setSizePolicy(sizePolicy1);
        frame_right->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        frame_right->setFrameShape(QFrame::NoFrame);
        frame_right->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_right);
        verticalLayout_4->setSpacing(30);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(100, 80, 100, 80);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(frame_right);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"font: 75 26px \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout);

        line = new QFrame(frame_right);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lineEdit_user_name = new QLineEdit(frame_right);
        lineEdit_user_name->setObjectName(QStringLiteral("lineEdit_user_name"));
        sizePolicy.setHeightForWidth(lineEdit_user_name->sizePolicy().hasHeightForWidth());
        lineEdit_user_name->setSizePolicy(sizePolicy);
        lineEdit_user_name->setMinimumSize(QSize(0, 44));
        lineEdit_user_name->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        verticalLayout_5->addWidget(lineEdit_user_name);

        label_username_tip = new QLabel(frame_right);
        label_username_tip->setObjectName(QStringLiteral("label_username_tip"));

        verticalLayout_5->addWidget(label_username_tip);


        verticalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        lineEdit__pwd = new QLineEdit(frame_right);
        lineEdit__pwd->setObjectName(QStringLiteral("lineEdit__pwd"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit__pwd->sizePolicy().hasHeightForWidth());
        lineEdit__pwd->setSizePolicy(sizePolicy2);
        lineEdit__pwd->setMinimumSize(QSize(0, 44));
        lineEdit__pwd->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit__pwd->setEchoMode(QLineEdit::Password);

        verticalLayout_6->addWidget(lineEdit__pwd);

        label_pwdtip = new QLabel(frame_right);
        label_pwdtip->setObjectName(QStringLiteral("label_pwdtip"));

        verticalLayout_6->addWidget(label_pwdtip);


        verticalLayout_3->addLayout(verticalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_vertify_code = new QLineEdit(frame_right);
        lineEdit_vertify_code->setObjectName(QStringLiteral("lineEdit_vertify_code"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_vertify_code->sizePolicy().hasHeightForWidth());
        lineEdit_vertify_code->setSizePolicy(sizePolicy3);
        lineEdit_vertify_code->setMinimumSize(QSize(0, 32));
        lineEdit_vertify_code->setStyleSheet(QString::fromUtf8("font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(lineEdit_vertify_code);

        label_codepic = new QLabel(frame_right);
        label_codepic->setObjectName(QStringLiteral("label_codepic"));

        horizontalLayout_2->addWidget(label_codepic);

        label_verfiycode = new verificationcodelabel(frame_right);
        label_verfiycode->setObjectName(QStringLiteral("label_verfiycode"));
        sizePolicy2.setHeightForWidth(label_verfiycode->sizePolicy().hasHeightForWidth());
        label_verfiycode->setSizePolicy(sizePolicy2);
        label_verfiycode->setMinimumSize(QSize(120, 40));
        label_verfiycode->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"width:100px;\n"
"height:40px;\n"
"background:rgba(83,187,235,1);\n"
"border-radius:2px;"));
        label_verfiycode->setFrameShape(QFrame::Panel);
        label_verfiycode->setTextFormat(Qt::AutoText);
        label_verfiycode->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_2->addWidget(label_verfiycode);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_denglu = new MyButton(frame_right);
        pushButton_denglu->setObjectName(QStringLiteral("pushButton_denglu"));
        sizePolicy2.setHeightForWidth(pushButton_denglu->sizePolicy().hasHeightForWidth());
        pushButton_denglu->setSizePolicy(sizePolicy2);
        pushButton_denglu->setStyleSheet(QString::fromUtf8("width:300px;\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"height:40px;\n"
"background:rgba(64,197,173,1);\n"
"border-radius:2px;\n"
"color: rgb(255, 255, 255);\n"
""));

        horizontalLayout_3->addWidget(pushButton_denglu);


        verticalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_4->addWidget(frame_right);


        gridLayout->addLayout(horizontalLayout_4, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\350\264\246e\346\215\267\347\224\265\345\255\220\346\212\245\351\224\200\347\263\273\347\273\237-\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("Dialog", "TextLabel", 0));
        label_3->setText(QApplication::translate("Dialog", "\350\264\246e\346\215\267", 0));
        label_username_tip->setText(QApplication::translate("Dialog", "TextLabel", 0));
        label_pwdtip->setText(QApplication::translate("Dialog", "TextLabel", 0));
        label_codepic->setText(QApplication::translate("Dialog", "TextLabel", 0));
        label_verfiycode->setText(QApplication::translate("Dialog", "TextLabel", 0));
        pushButton_denglu->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
