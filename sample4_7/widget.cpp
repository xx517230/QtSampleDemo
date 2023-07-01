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




void Widget::on_btnCurDateTime_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->timeEdit->setTime(curDateTime.time());
    ui->lineEditTime->setText(curDateTime.toString("hh:mm:ss"));

    ui->dateEdit->setDate(curDateTime.date());
    ui->lineEditDate->setText(curDateTime.toString("yyyy-MM-dd"));

    ui->dateTimeEdit->setDateTime(curDateTime);
    ui->lineEditDateTime->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));
}


void Widget::on_btnQDebugTime_clicked()
{
    QTime TM1(13,24,5);
    QString str=TM1.toString("HH:mm:ss");
    qDebug("original time = %s",str.toLocal8Bit().data());

    QTime TM2 =TM1.addSecs(150);
    str=TM2.toString("HH:mm:ss");
    qDebug("150s later, time=%s",str.toLocal8Bit().data());

    TM2=QTime::currentTime();
    str=TM2.toString("HH:mm:ss zzz");
    qDebug("Current Time = %s",str.toLocal8Bit().data());
    qDebug("Hour = %d",TM2.hour());
    qDebug("Minute = %d",TM2.minute());
    qDebug("Second = %d",TM2.second());
    qDebug("MSecond = %d",TM2.msec());

}


void Widget::on_btnQDebugDate_clicked()
{
    QDate DT1(2021,7,5);
    QString str=DT1.toString("yyyy-MM-dd");
    qDebug("DT1 = %s",str.toLocal8Bit().data());

    QDate DT2;
    DT2.setDate(2021,8,5);
    str=DT2.toString("yyyy-MM-dd");
    qDebug("DT2 = %s",str.toLocal8Bit().data());
    qDebug("Day between DT2 and DT1=%lld",DT2.daysTo(DT1));

    DT2=QDate::currentDate();
    str=DT2.toString("yyyy-MM-dd");
    qDebug("Current date = %s",str.toLocal8Bit().data());
    qDebug("Year = %d",DT2.year());
    qDebug("Month = %d",DT2.month());
    qDebug("Day = %d",DT2.day());
    qDebug("Day of week = %d",DT2.dayOfWeek());
}


void Widget::on_btnQDebugDateTime_clicked()
{
    QDateTime DT1 = QDateTime::currentDateTime();
    QString str = DT1.toString("yyyy-MM-dd HH:mm:ss");
    qDebug("DT1 = %s",str.toLocal8Bit().data());

    QDate dt = DT1.date();
    str = dt.toString("yyyy-MM-dd");
    qDebug("DT1.date() = %s",str.toLocal8Bit().data());

    QTime tm = DT1.time();
    str = tm.toString("HH:mm:ss zzz");
    qDebug("DT1.time() = %s",str.toLocal8Bit().data());

    qint64 MS= DT1.toSecsSinceEpoch();
    qDebug("DT1.toSecsSinceEpoch()=%lld",MS);

    MS += 120;
    DT1.setSecsSinceEpoch(MS);
    str=DT1.toString("yyyy-MM-dd HH:mm:ss");
    qDebug("DT1+120S = %s",str.toLocal8Bit().data());

}


void Widget::on_btnTimeString_clicked()
{
    QString str = ui->lineEditTime->text();
    str = str.trimmed();
    if(!str.isEmpty())
    {
        QTime tm= QTime::fromString(str,"HH:mm:ss");
        ui->timeEdit->setTime(tm);
    }
}


void Widget::on_btnDateString_clicked()
{
    QString str = ui->lineEditDate->text();
    str = str.trimmed();
    if(!str.isEmpty())
    {
        QDate dt = QDate::fromString(str,"yyyy-MM-dd");
        ui->dateEdit->setDate(dt);
    }
}


void Widget::on_btnDateTimeString_clicked()
{
    QString str = ui->lineEditDateTime->text();
    str = str.trimmed();
    if(!str.isEmpty())
    {
        QDateTime dt = QDateTime::fromString(str,"yyyy-MM-dd HH:mm:ss");
        ui->dateTimeEdit->setDateTime(dt);
    }
}


void Widget::on_calendarWidget_selectionChanged()
{
    QString str = ui->calendarWidget->selectedDate().toString("yyyy年MM月dd日");
    ui->lineEditChooseData->setText(str);
}

