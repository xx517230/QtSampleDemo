#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QStringListModel>
#include <QMessageBox>
#include <QStandardPaths>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStringListModel(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tbtnFileSwitch_clicked()
{
    //打开文件对话框
    //函数返回打开的路径
    strlist = QFileDialog::getOpenFileNames(
        this,//指定父窗口
        "请选择33xxATE的log相关文件",//打开文件对话框的标题
        QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),//打开桌面目录
//        "txt files(*.txt);;"

        "wmpTDO.txt files(*wmpTDO.txt);;"
        "sumryTDO.txt files(*sumryTDO.txt);;"
        "TIME.txt files(*TIME.txt);;"
        "txt files(*.txt);;"
        "csv files(*.csv);;"
        "all files(*.*)"//设置文件过滤器，有多个条件时中间以两个;;隔开
    );
    model->setStringList(strlist);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
}


void MainWindow::on_tbtnOutput_clicked()
{
    if(strlist.isEmpty())
    {
        QMessageBox::critical(
            this,//父窗体
            "错误",//标题
            "未选择文件!\n请先选择文件！"//显示内容
            );
        return;
    };

    static QString timeFormat33xxATE = "ddd MMM dd hh:mm:ss yyyy";
    static QRegularExpression re_timeStart(R"(^Test Start Date         :\s(.*))");
    static QRegularExpression re_timeEnd(R"(^Test End Date           :\s(.*))");
    static QRegularExpression re_waferid(R"(^Wafer ID                :\s(.*))");
    static QRegularExpression re_number(R"(^Fail Retest Rate        :\s([0-9.]+)\s\%\s[(]Gross:(\d+),\sSample:(\d+)[)])");

    QString timeStartStr;
    QString timeEndStr;
    QString waferidStr;
    QString rateRetestStr;
    QString testedNumStr;
    QString retestedNumStr;
    QString lineStr;

    foreach (auto &fileName, strlist)
    {
        QFile file(fileName); // fileName文件的路径
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text))  // 以读的方式打开文件
        {
            return;
        }
        QTextStream txtInput(&file);
        while(!txtInput.atEnd()) // 判断文件是否结束
        {
            lineStr = txtInput.readLine();
            if(re_timeStart.match(lineStr).hasMatch())
            {
                timeStartStr = re_timeStart.match(lineStr).captured(1);
            }
            if(re_timeEnd.match(lineStr).hasMatch())
            {
                timeEndStr = re_timeEnd.match(lineStr).captured(1);
            }
            if(re_waferid.match(lineStr).hasMatch())
            {
                waferidStr = re_waferid.match(lineStr).captured(1);
            }
            if(re_number.match(lineStr).hasMatch())
            {
                rateRetestStr = re_number.match(lineStr).captured(1);
                testedNumStr = re_number.match(lineStr).captured(2);
                retestedNumStr = re_number.match(lineStr).captured(3);
                break;
            }

        }
        file.close();

        QDateTime t1 = QDateTime::fromString(timeStartStr,timeFormat33xxATE);
        QDateTime t2 = QDateTime::fromString(timeEndStr,timeFormat33xxATE);
        qint64 timeMs1 = t1.toMSecsSinceEpoch();
        qint64 timeMs2 = t2.toMSecsSinceEpoch();
        double timeSub = (timeMs2-timeMs1)/1000.0/60;
        int retestNum = retestedNumStr.toInt() - testedNumStr.toInt();
        QString strRate = QString::number(rateRetestStr.toDouble(),'f',2);
        ui->plainTextEdit->appendPlainText(waferidStr+", 时间 ,"+QString::number(timeSub,'f', 2)+" , min, 回收良率 ,"+strRate+",%, 测试总数 ,"+ testedNumStr + ", 回收总数 , "+QString::number(retestNum));
    }

}


void MainWindow::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}


void MainWindow::on_btnOutputFile_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open Config"),"", tr("csv files(*.csv)"));
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        return;
    }
    QTextStream in(&file);
    in.setEncoding (QStringConverter::System);

    in  << ui->plainTextEdit->toPlainText();
    //关闭文件
    file.close();
    ui->plainTextEdit->appendPlainText("已导完成出,路径:"+fileName);
}

