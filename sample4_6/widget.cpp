#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider,&QAbstractSlider::valueChanged,this,&Widget::do_valueChanged);
    connect(ui->horizontalScrollBar,&QAbstractSlider::valueChanged,this,&Widget::do_valueChanged);
    connect(ui->dial,&QAbstractSlider::valueChanged,this,&Widget::do_valueChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::do_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}


void Widget::on_chkTextVisible_clicked(bool checked)
{
    ui->progressBar->setTextVisible(checked);
}


void Widget::on_chkInvertedAppearance_clicked(bool checked)
{
    ui->progressBar->setInvertedAppearance(checked);
}


void Widget::on_radioPercent_clicked()
{
    ui->progressBar->setFormat("%p%");
}


void Widget::on_radioValue_clicked()
{
    ui->progressBar->setFormat("%v");
}

