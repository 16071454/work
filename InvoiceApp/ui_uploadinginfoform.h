/********************************************************************************
** Form generated from reading UI file 'uploadinginfoform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADINGINFOFORM_H
#define UI_UPLOADINGINFOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadingInfoForm
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QLineEdit *lineEdit_project;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QLineEdit *lineEdit_company;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QLineEdit *lineEdit_wbs;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QLineEdit *lineEdit_name;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLineEdit *lineEdit_fourcode;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QComboBox *comboBox;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_amount;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_sumprice;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_date;
    QFrame *line;

    void setupUi(QWidget *UploadingInfoForm)
    {
        if (UploadingInfoForm->objectName().isEmpty())
            UploadingInfoForm->setObjectName(QStringLiteral("UploadingInfoForm"));
        UploadingInfoForm->resize(831, 239);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UploadingInfoForm->sizePolicy().hasHeightForWidth());
        UploadingInfoForm->setSizePolicy(sizePolicy);
        UploadingInfoForm->setStyleSheet(QLatin1String("QWidget#UploadingInfoForm{background-color: rgb(240, 243, 247);}\n"
""));
        verticalLayout = new QVBoxLayout(UploadingInfoForm);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_5 = new QLabel(UploadingInfoForm);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(116, 0));
        label_5->setMaximumSize(QSize(116, 16777215));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_11->addWidget(label_5);

        lineEdit_project = new QLineEdit(UploadingInfoForm);
        lineEdit_project->setObjectName(QStringLiteral("lineEdit_project"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_project->sizePolicy().hasHeightForWidth());
        lineEdit_project->setSizePolicy(sizePolicy2);
        lineEdit_project->setMinimumSize(QSize(200, 0));
        lineEdit_project->setMaximumSize(QSize(200, 16777215));
        lineEdit_project->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(200, 200, 200);"));
        lineEdit_project->setReadOnly(true);

        horizontalLayout_11->addWidget(lineEdit_project);


        gridLayout->addLayout(horizontalLayout_11, 2, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_4 = new QLabel(UploadingInfoForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMinimumSize(QSize(116, 0));
        label_4->setMaximumSize(QSize(116, 16777215));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_10->addWidget(label_4);

        lineEdit_company = new QLineEdit(UploadingInfoForm);
        lineEdit_company->setObjectName(QStringLiteral("lineEdit_company"));
        sizePolicy2.setHeightForWidth(lineEdit_company->sizePolicy().hasHeightForWidth());
        lineEdit_company->setSizePolicy(sizePolicy2);
        lineEdit_company->setMinimumSize(QSize(350, 0));
        lineEdit_company->setMaximumSize(QSize(350, 16777215));
        lineEdit_company->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(200, 200, 200);"));
        lineEdit_company->setReadOnly(true);

        horizontalLayout_10->addWidget(lineEdit_company);


        gridLayout->addLayout(horizontalLayout_10, 1, 1, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_6 = new QLabel(UploadingInfoForm);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(116, 0));
        label_6->setMaximumSize(QSize(116, 16777215));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_12->addWidget(label_6);

        lineEdit_wbs = new QLineEdit(UploadingInfoForm);
        lineEdit_wbs->setObjectName(QStringLiteral("lineEdit_wbs"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_wbs->sizePolicy().hasHeightForWidth());
        lineEdit_wbs->setSizePolicy(sizePolicy3);
        lineEdit_wbs->setMinimumSize(QSize(350, 0));
        lineEdit_wbs->setMaximumSize(QSize(350, 16777215));
        lineEdit_wbs->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(200, 200, 200);"));
        lineEdit_wbs->setReadOnly(true);

        horizontalLayout_12->addWidget(lineEdit_wbs);


        gridLayout->addLayout(horizontalLayout_12, 2, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_3 = new QLabel(UploadingInfoForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(116, 0));
        label_3->setMaximumSize(QSize(116, 16777215));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_9->addWidget(label_3);

        lineEdit_name = new QLineEdit(UploadingInfoForm);
        lineEdit_name->setObjectName(QStringLiteral("lineEdit_name"));
        sizePolicy2.setHeightForWidth(lineEdit_name->sizePolicy().hasHeightForWidth());
        lineEdit_name->setSizePolicy(sizePolicy2);
        lineEdit_name->setMinimumSize(QSize(200, 0));
        lineEdit_name->setMaximumSize(QSize(200, 16777215));
        lineEdit_name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(200, 200, 200);"));
        lineEdit_name->setReadOnly(true);

        horizontalLayout_9->addWidget(lineEdit_name);


        gridLayout->addLayout(horizontalLayout_9, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label = new QLabel(UploadingInfoForm);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(116, 0));
        label->setMaximumSize(QSize(116, 16777215));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_6->addWidget(label);

        lineEdit_fourcode = new QLineEdit(UploadingInfoForm);
        lineEdit_fourcode->setObjectName(QStringLiteral("lineEdit_fourcode"));
        sizePolicy2.setHeightForWidth(lineEdit_fourcode->sizePolicy().hasHeightForWidth());
        lineEdit_fourcode->setSizePolicy(sizePolicy2);
        lineEdit_fourcode->setMinimumSize(QSize(200, 0));
        lineEdit_fourcode->setMaximumSize(QSize(200, 16777215));
        lineEdit_fourcode->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        lineEdit_fourcode->setMaxLength(4);

        horizontalLayout_6->addWidget(lineEdit_fourcode);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_2 = new QLabel(UploadingInfoForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(116, 0));
        label_2->setMaximumSize(QSize(116, 16777215));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_7->addWidget(label_2);

        comboBox = new QComboBox(UploadingInfoForm);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy3.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy3);
        comboBox->setMinimumSize(QSize(350, 0));
        comboBox->setMaximumSize(QSize(350, 16777215));
        comboBox->setLayoutDirection(Qt::LeftToRight);
        comboBox->setStyleSheet(QStringLiteral(""));

        horizontalLayout_7->addWidget(comboBox);


        gridLayout->addLayout(horizontalLayout_7, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line_2 = new QFrame(UploadingInfoForm);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_amount = new QLabel(UploadingInfoForm);
        label_amount->setObjectName(QStringLiteral("label_amount"));
        sizePolicy.setHeightForWidth(label_amount->sizePolicy().hasHeightForWidth());
        label_amount->setSizePolicy(sizePolicy);
        label_amount->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_3->addWidget(label_amount);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_sumprice = new QLabel(UploadingInfoForm);
        label_sumprice->setObjectName(QStringLiteral("label_sumprice"));
        sizePolicy.setHeightForWidth(label_sumprice->sizePolicy().hasHeightForWidth());
        label_sumprice->setSizePolicy(sizePolicy);
        label_sumprice->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_2->addWidget(label_sumprice);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_13->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);

        label_date = new QLabel(UploadingInfoForm);
        label_date->setObjectName(QStringLiteral("label_date"));
        sizePolicy.setHeightForWidth(label_date->sizePolicy().hasHeightForWidth());
        label_date->setSizePolicy(sizePolicy);
        label_date->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));

        horizontalLayout_13->addWidget(label_date);


        verticalLayout->addLayout(horizontalLayout_13);

        line = new QFrame(UploadingInfoForm);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        line->raise();
        line_2->raise();

        retranslateUi(UploadingInfoForm);

        QMetaObject::connectSlotsByName(UploadingInfoForm);
    } // setupUi

    void retranslateUi(QWidget *UploadingInfoForm)
    {
        UploadingInfoForm->setWindowTitle(QApplication::translate("UploadingInfoForm", "Form", 0));
        label_5->setText(QApplication::translate("UploadingInfoForm", "\351\241\271 \347\233\256 \344\277\241 \346\201\257\357\274\232", 0));
        label_4->setText(QApplication::translate("UploadingInfoForm", "\346\212\245 \351\224\200 \345\205\254 \345\217\270\357\274\232", 0));
        label_6->setText(QApplication::translate("UploadingInfoForm", "WBS \351\230\266 \346\256\265\357\274\232", 0));
        label_3->setText(QApplication::translate("UploadingInfoForm", "\346\212\245   \351\224\200   \344\272\272\357\274\232", 0));
        label->setText(QApplication::translate("UploadingInfoForm", "\345\233\233 \344\275\215 \347\274\226 \345\217\267:", 0));
        label_2->setText(QApplication::translate("UploadingInfoForm", "\345\215\225 \346\215\256 \347\261\273 \345\236\213\357\274\232", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("UploadingInfoForm", "\346\224\257\345\207\272\345\207\255\345\215\225", 0)
         << QApplication::translate("UploadingInfoForm", "\345\267\256\346\227\205\346\212\245\351\224\200\345\215\225", 0)
         << QApplication::translate("UploadingInfoForm", "\346\224\257\347\245\250\351\242\206\347\224\250\345\215\225", 0)
         << QApplication::translate("UploadingInfoForm", "\347\205\247\346\230\216\346\211\200-\346\224\257\345\207\272\345\207\255\345\215\225", 0)
         << QApplication::translate("UploadingInfoForm", "\347\205\247\346\230\216\346\211\200-\345\267\256\346\227\205\346\212\245\351\224\200\345\215\225", 0)
         << QApplication::translate("UploadingInfoForm", "\347\205\247\346\230\216\346\211\200-\346\224\257\347\245\250\351\242\206\347\224\250\345\215\225", 0)
        );
        label_amount->setText(QApplication::translate("UploadingInfoForm", "TextLabel", 0));
        label_sumprice->setText(QApplication::translate("UploadingInfoForm", "TextLabel", 0));
        label_date->setText(QApplication::translate("UploadingInfoForm", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class UploadingInfoForm: public Ui_UploadingInfoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADINGINFOFORM_H
