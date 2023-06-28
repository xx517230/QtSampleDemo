/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_underline;
    QCheckBox *checkBox_italic;
    QCheckBox *checkBox_bold;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_Black;
    QRadioButton *radioButton_Red;
    QRadioButton *radioButton_Blue;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Clear;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Ok;
    QPushButton *pushButton_Close;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(451, 449);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/20.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_underline = new QCheckBox(groupBox);
        checkBox_underline->setObjectName(QString::fromUtf8("checkBox_underline"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/UNDRLN.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox_underline->setIcon(icon1);

        horizontalLayout->addWidget(checkBox_underline);

        checkBox_italic = new QCheckBox(groupBox);
        checkBox_italic->setObjectName(QString::fromUtf8("checkBox_italic"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/images/ITL.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox_italic->setIcon(icon2);

        horizontalLayout->addWidget(checkBox_italic);

        checkBox_bold = new QCheckBox(groupBox);
        checkBox_bold->setObjectName(QString::fromUtf8("checkBox_bold"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/images/BLD.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        checkBox_bold->setIcon(icon3);

        horizontalLayout->addWidget(checkBox_bold);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        radioButton_Black = new QRadioButton(groupBox_2);
        radioButton_Black->setObjectName(QString::fromUtf8("radioButton_Black"));

        horizontalLayout_3->addWidget(radioButton_Black);

        radioButton_Red = new QRadioButton(groupBox_2);
        radioButton_Red->setObjectName(QString::fromUtf8("radioButton_Red"));

        horizontalLayout_3->addWidget(radioButton_Red);

        radioButton_Blue = new QRadioButton(groupBox_2);
        radioButton_Blue->setObjectName(QString::fromUtf8("radioButton_Blue"));

        horizontalLayout_3->addWidget(radioButton_Blue);


        verticalLayout->addWidget(groupBox_2);

        plainTextEdit = new QPlainTextEdit(Dialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(12);
        plainTextEdit->setFont(font);

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_Clear = new QPushButton(Dialog);
        pushButton_Clear->setObjectName(QString::fromUtf8("pushButton_Clear"));

        horizontalLayout_2->addWidget(pushButton_Clear);

        horizontalSpacer_2 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_Ok = new QPushButton(Dialog);
        pushButton_Ok->setObjectName(QString::fromUtf8("pushButton_Ok"));

        horizontalLayout_2->addWidget(pushButton_Ok);

        pushButton_Close = new QPushButton(Dialog);
        pushButton_Close->setObjectName(QString::fromUtf8("pushButton_Close"));

        horizontalLayout_2->addWidget(pushButton_Close);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Dialog);
        QObject::connect(pushButton_Close, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::close));
        QObject::connect(pushButton_Ok, &QPushButton::clicked, Dialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\345\255\227\344\275\223", nullptr));
        checkBox_underline->setText(QCoreApplication::translate("Dialog", "\344\270\213\345\210\222\347\272\277", nullptr));
        checkBox_italic->setText(QCoreApplication::translate("Dialog", "\346\226\234\344\275\223", nullptr));
        checkBox_bold->setText(QCoreApplication::translate("Dialog", "\345\212\240\347\262\227", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog", "\351\242\234\350\211\262", nullptr));
        radioButton_Black->setText(QCoreApplication::translate("Dialog", "\351\273\221\350\211\262", nullptr));
        radioButton_Red->setText(QCoreApplication::translate("Dialog", "\347\272\242\350\211\262", nullptr));
        radioButton_Blue->setText(QCoreApplication::translate("Dialog", "\350\223\235\350\211\262", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("Dialog", "Qt 6 C++ \n"
"\345\274\200\345\217\221\346\214\207\345\215\227", nullptr));
        pushButton_Clear->setText(QCoreApplication::translate("Dialog", "\346\270\205\347\251\272", nullptr));
        pushButton_Ok->setText(QCoreApplication::translate("Dialog", "\347\241\256\350\256\244", nullptr));
        pushButton_Close->setText(QCoreApplication::translate("Dialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
