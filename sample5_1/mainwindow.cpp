#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_strList<<"北京"<<"上海"<<"南昌"<<"南京"<<"成都";
    m_model = new QStringListModel(this);
    m_model->setStringList(m_strList);
    ui->listView->setModel(m_model);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    m_model->setStringList(m_strList);
}


void MainWindow::on_pushButton_2_clicked()
{
    m_model->removeRows(0,m_model->rowCount());
}


void MainWindow::on_checkBox_clicked(bool checked)
{
    if(checked)
        ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
    else
         ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

