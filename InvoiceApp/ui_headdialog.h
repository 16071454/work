/********************************************************************************
** Form generated from reading UI file 'headdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEADDIALOG_H
#define UI_HEADDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_HeadDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_logo;
    QLabel *label_wenzi;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QFrame *line_2;
    QPushButton *pushButton;

    void setupUi(QDialog *HeadDialog)
    {
        if (HeadDialog->objectName().isEmpty())
            HeadDialog->setObjectName(QStringLiteral("HeadDialog"));
        HeadDialog->resize(1106, 72);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HeadDialog->sizePolicy().hasHeightForWidth());
        HeadDialog->setSizePolicy(sizePolicy);
        HeadDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(102, 204, 183);\n"
"font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"\n"
""));
        horizontalLayout_3 = new QHBoxLayout(HeadDialog);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_logo = new QLabel(HeadDialog);
        label_logo->setObjectName(QStringLiteral("label_logo"));

        horizontalLayout->addWidget(label_logo);

        label_wenzi = new QLabel(HeadDialog);
        label_wenzi->setObjectName(QStringLiteral("label_wenzi"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_wenzi->sizePolicy().hasHeightForWidth());
        label_wenzi->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_wenzi);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 7, -1);
        label = new QLabel(HeadDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(200, 0));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        line = new QFrame(HeadDialog);
        line->setObjectName(QStringLiteral("line"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        line->setFont(font);
        line->setStyleSheet(QStringLiteral(""));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        label_2 = new QLabel(HeadDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(56, 0));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        line_2 = new QFrame(HeadDialog);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        pushButton = new QPushButton(HeadDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(56, 0));
        pushButton->setMaximumSize(QSize(48, 48));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(true);

        horizontalLayout_2->addWidget(pushButton);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(HeadDialog);

        QMetaObject::connectSlotsByName(HeadDialog);
    } // setupUi

    void retranslateUi(QDialog *HeadDialog)
    {
        HeadDialog->setWindowTitle(QApplication::translate("HeadDialog", "Dialog", 0));
        label_logo->setText(QApplication::translate("HeadDialog", "TextLabel", 0));
        label_wenzi->setText(QApplication::translate("HeadDialog", "TextLabel", 0));
        label->setText(QApplication::translate("HeadDialog", "TextLabel", 0));
        label_2->setText(QApplication::translate("HeadDialog", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        pushButton->setText(QApplication::translate("HeadDialog", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class HeadDialog: public Ui_HeadDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEADDIALOG_H
