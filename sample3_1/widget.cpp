#include "widget.h"
#include "ui_widget.h"
#include "tperson.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    boy = new TPerson("小明",this);
    girl = new TPerson("小丽",this);
    ui->spinBoy->setProperty("isBoy",true);
    ui->spinGirl->setProperty("isBoy",false);
    connect(boy,SIGNAL(ageChange(int)),this,SLOT(do_ageChange(int)));
    connect(girl,SIGNAL(ageChange(int)),this,SLOT(do_ageChange(int)));
    connect(ui->spinBoy,SIGNAL(valueChanged(int)),this,SLOT(do_spinChange(int)));
    connect(ui->spinGirl,SIGNAL(valueChanged(int)),this,SLOT(do_spinChange(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::do_ageChange(int value)
{
    TPerson *person=qobject_cast<TPerson*>(sender());
    QString str=QString("年龄=%1").arg(value);
    ui->plainTextEdit->appendPlainText(str);
}

void Widget::do_spinChange(int arg1)
{
    QSpinBox* spinBox = qobject_cast<QSpinBox*>(sender());
    if(spinBox->property("isBoy").toBool())
        boy->setAge(arg1);
    else
        girl->setAge(arg1);
}

