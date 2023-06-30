#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->connect(ui->spinBoxNum,&QSpinBox::valueChanged,this,&Widget::on_btnCal_clicked);
    this->connect(ui->dSpinBoxPrice,&QDoubleSpinBox::valueChanged,this,&Widget::on_btnCal_clicked);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnCal_clicked()
{
    int num = ui->spinBoxNum->value();
    double price =  ui->dSpinBoxPrice->value();
    double total = num * price;
    ui->dSpinBoxTotal->setValue(total);
}

void Widget::on_spinBoxDec_valueChanged(int arg1)
{
    ui->spinBoxBin->setValue(arg1);
    ui->spinBoxHex->setValue(arg1);
}


void Widget::on_spinBoxBin_valueChanged(int arg1)
{
    ui->spinBoxDec->setValue(arg1);
    ui->spinBoxHex->setValue(arg1);
}


void Widget::on_spinBoxHex_valueChanged(int arg1)
{
    ui->spinBoxBin->setValue(arg1);
    ui->spinBoxDec->setValue(arg1);
}
