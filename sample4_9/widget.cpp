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





void Widget::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_btnClearList_clicked()
{
    ui->combCitys->clear();
}


void Widget::on_btnInit_clicked()
{
    QIcon icons;
    icons.addFile(":/icons/icons/aim.ico");
    ui->combCitys->clear();
    for(int i=0;i<20;i++)
    {
        ui->combCitys->addItem(icons,QString("Iten%1").arg(i));
    }
}


void Widget::on_checkBox_clicked(bool checked)
{
    ui->combCitys->setEditable(checked);
}


void Widget::on_combCitys_currentTextChanged(const QString &arg1)
{
    ui->plainTextEdit->appendPlainText(arg1);
}


void Widget::on_btnInitCityCode_clicked()
{
    QMap<QString,int> city_Zone;
    city_Zone.insert("重庆",01);
    city_Zone.insert("北京",02);
    city_Zone.insert("上海",03);
    city_Zone.insert("东京",04);
    city_Zone.insert("南京",05);
    ui->combCityCode->clear();
    foreach(const QString &str,city_Zone.keys())
    {
        ui->combCityCode->addItem(str,city_Zone.value(str));
    }

}


void Widget::on_combCityCode_currentIndexChanged(int index)
{
    Q_UNUSED(index);

    ui->plainTextEdit->appendPlainText(ui->combCityCode->currentText()+ui->combCityCode->currentData().toString());
}

