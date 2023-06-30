#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnCal_clicked()
{
    float num = ui->editNum->text().toFloat();
    float price = ui->editPrice->text().toFloat();

    float total =price*num;
    QString str=QString::number(total,'f',2);
    //str=str.setNum(total,'f',2);
    ui->editTotal->setText(str);
}


void Widget::on_btnDec_clicked()
{
    int value = ui->editDec->text().toInt();
    ui->editBin->setText(QString::number(value,2));
    ui->editHex->setText(QString::number(value,16));
}


void Widget::on_btnBin_clicked()
{
    bool ok;
    int value = ui->editBin->text().toInt(&ok,2);
    if(!ok) return;
    ui->editDec->setText(QString::number(value,10));
    ui->editHex->setText(QString::number(value,16));
}


void Widget::on_btnHex_clicked()
{
    bool ok;
    int value = ui->editHex->text().toInt(&ok,16);
    if(!ok) return;
    ui->editBin->setText(QString::number(value,2));
    ui->editDec->setText(QString::number(value,10));
}


void Widget::on_btnDebug_clicked()
{
    qDebug("PI=%f",3.14159);
    QString str = QString::number(3.15149,10,10);
    qDebug("PI=%s",str.toLocal8Bit().data());
}

