#include "dialog.h"

#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

void Dialog::do_checkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void Dialog::do_checkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void Dialog::do_checkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void Dialog::do_setFontColor()
{
    QPalette plet = txtEdit->palette();
    if(radioBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    if(radioRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    if(radioBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    txtEdit->setPalette(plet);
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    checkBoxUnder = new QCheckBox("下划线");
    checkBoxItalic = new QCheckBox("斜体");
    checkBoxBold= new QCheckBox("加粗");

    QHBoxLayout *HLay = new QHBoxLayout();
    HLay->addWidget(checkBoxUnder);
    HLay->addWidget(checkBoxItalic);
    HLay->addWidget(checkBoxBold);

    radioBlack = new QRadioButton("黑色");
    radioRed = new QRadioButton("红色");
    radioBlue = new QRadioButton("蓝色");
    //setLayout(HLayl);

    QHBoxLayout *HLay2 = new QHBoxLayout();
    HLay2->addWidget(radioBlack);
    HLay2->addWidget(radioRed);
    HLay2->addWidget(radioBlue);

    txtEdit = new QPlainTextEdit();
    txtEdit->setPlainText("Qt 6 \nC++ 指南");
    QFont font = txtEdit->font();
    font.setPointSize(12);
    txtEdit->setFont(font);
    txtEdit->setPlainText("Qt 6 \nC++ 指南");


    btnOK = new QPushButton("确定");
    btnCancel = new QPushButton("取消");
    btnClose = new QPushButton("退出");
    QHBoxLayout *HLay3 = new QHBoxLayout();
    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addStretch();
    HLay3->addWidget(btnCancel);
    HLay3->addWidget(btnClose);

    QVBoxLayout *Vlay = new QVBoxLayout();
    Vlay->addLayout(HLay);
    Vlay->addLayout(HLay2);
    Vlay->addWidget(txtEdit);
    Vlay->addLayout(HLay3);

    setLayout(Vlay);
    setWindowTitle("手动打造UI");
    connect(checkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(do_checkBoxUnder(bool)));
    connect(checkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(do_checkBoxItalic(bool)));
    connect(checkBoxBold,SIGNAL(clicked(bool)),this,SLOT(do_checkBoxBold(bool)));

    connect(radioBlack,SIGNAL(clicked(bool)),this,SLOT(do_setFontColor()));
    connect(radioBlue,SIGNAL(clicked(bool)),this,SLOT(do_setFontColor()));
    connect(radioRed,SIGNAL(clicked(bool)),this,SLOT(do_setFontColor()));

    connect(btnOK,SIGNAL(clicked(bool)),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked(bool)),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked(bool)),this,SLOT(close()));
}

Dialog::~Dialog()
{
}

