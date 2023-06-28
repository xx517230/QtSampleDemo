/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *editNum;
    QLineEdit *editTotal;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *editPrice;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLineEdit *editDec;
    QPushButton *btnDec;
    QLabel *label_5;
    QLineEdit *editBin;
    QPushButton *btnBin;
    QLabel *label_6;
    QLineEdit *editHex;
    QPushButton *btnHex;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(429, 226);
        gridLayout_3 = new QGridLayout(Widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        editNum = new QLineEdit(Widget);
        editNum->setObjectName(QString::fromUtf8("editNum"));

        gridLayout->addWidget(editNum, 0, 1, 1, 1);

        editTotal = new QLineEdit(Widget);
        editTotal->setObjectName(QString::fromUtf8("editTotal"));

        gridLayout->addWidget(editTotal, 1, 3, 1, 1);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        editPrice = new QLineEdit(Widget);
        editPrice->setObjectName(QString::fromUtf8("editPrice"));

        gridLayout->addWidget(editPrice, 0, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        editDec = new QLineEdit(Widget);
        editDec->setObjectName(QString::fromUtf8("editDec"));

        gridLayout_2->addWidget(editDec, 0, 1, 1, 1);

        btnDec = new QPushButton(Widget);
        btnDec->setObjectName(QString::fromUtf8("btnDec"));

        gridLayout_2->addWidget(btnDec, 0, 2, 1, 1);

        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        editBin = new QLineEdit(Widget);
        editBin->setObjectName(QString::fromUtf8("editBin"));

        gridLayout_2->addWidget(editBin, 1, 1, 1, 1);

        btnBin = new QPushButton(Widget);
        btnBin->setObjectName(QString::fromUtf8("btnBin"));

        gridLayout_2->addWidget(btnBin, 1, 2, 1, 1);

        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        editHex = new QLineEdit(Widget);
        editHex->setObjectName(QString::fromUtf8("editHex"));

        gridLayout_2->addWidget(editHex, 2, 1, 1, 1);

        btnHex = new QPushButton(Widget);
        btnHex->setObjectName(QString::fromUtf8("btnHex"));

        gridLayout_2->addWidget(btnHex, 2, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 2, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\225\260\351\207\217:", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\200\273\344\273\267:", nullptr));
        editNum->setText(QCoreApplication::translate("Widget", "12", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\350\256\241\347\256\227", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\345\215\225\344\273\267:", nullptr));
        editPrice->setText(QCoreApplication::translate("Widget", "10", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\215\201\350\277\233\345\210\266:", nullptr));
        editDec->setText(QCoreApplication::translate("Widget", "15", nullptr));
        btnDec->setText(QCoreApplication::translate("Widget", "\350\275\254\346\215\242\346\210\220\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\344\272\214\350\277\233\345\210\266:", nullptr));
        btnBin->setText(QCoreApplication::translate("Widget", "\350\275\254\346\215\242\346\210\220\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\345\215\201\345\205\255\350\277\233\345\210\266:", nullptr));
        btnHex->setText(QCoreApplication::translate("Widget", "\350\275\254\346\215\242\346\210\220\345\205\266\344\273\226\350\277\233\345\210\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
