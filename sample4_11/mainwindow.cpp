#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tbtnListInit->setDefaultAction(ui->actListInit);
    ui->tbtnListClear->setDefaultAction(ui->actListClear);
    ui->tbtnListInsert->setDefaultAction(ui->actListInset);
    ui->tbtnListAppend->setDefaultAction(ui->actListAppend);
    ui->tbtnListDelete->setDefaultAction(ui->actListDelete);

    ui->tbtnSelectAll->setDefaultAction(ui->actSelAll);
    ui->tbtnSelectInVerse->setDefaultAction(ui->actSelectInserve);
    ui->tbtnSelectNotAll->setDefaultAction(ui->actSelectNotAll);

    //为什么加this,因为QMenu是属于MainWindow的，当MainWindow对象删掉时会先删掉QMenu,所以需要加this,挂在MainWindow对象上。
    QMenu *menu = new QMenu(this);
    menu->addAction(ui->actSelAll);
    menu->addAction(ui->actSelectInserve);
    menu->addAction(ui->actSelectNotAll);

    ui->tbtnSelectAll->setPopupMode(QToolButton::MenuButtonPopup);
    ui->tbtnSelectItem->setMenu(menu);

    QToolButton *tBtn = new QToolButton(this);
    tBtn->setIcon(QIcon(":/image/icons/412.bmp"));
    tBtn->setPopupMode(QToolButton::InstantPopup);
    tBtn->setText("选择选项");
    tBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tBtn->setMenu(menu);
    ui->toolBar->addWidget(tBtn);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actQuit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//对QListItem初始化
void MainWindow::on_actListInit_triggered()
{
    //清除已有的Item
    ui->listWidget->clear();
    //循环添加Item
    QIcon icon(":/image/icons/check2.ico");
    /*
        为什么用指针，如果在函数中使用QListWidgetItem item,那么变量就是栈中，函数退出后内存释放。
        使用new创建就是分配在堆中，只有在对象树被解析时自动调用析构函数，不会在函数退出后释放。
    */
    QListWidgetItem *item ;
    bool chk = ui->chkItemEnchanged->isChecked();
    for(int i =0; i<10;i++)
    {
        item = new QListWidgetItem();
        item->setIcon(icon);
        item->setText("Item"+QString::number(i));
        item->setCheckState(Qt::Checked);
        if(chk)
        {
            item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
        }else
        {
            item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
        }
        ui->listWidget->addItem(item);
    }
}


void MainWindow::on_actListClear_triggered()
{
     ui->listWidget->clear();
}


void MainWindow::on_actListInset_triggered()
{
    QIcon icon(":/image/icons/check2.ico");
    QListWidgetItem *item ;
    bool chk = ui->chkItemEnchanged->isChecked();

    item = new QListWidgetItem();
    item->setIcon(icon);
    item->setText("InsertItem");
    item->setCheckState(Qt::Checked);
    if(chk)
    {
        item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }else
    {
        item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }
    ui->listWidget->insertItem(ui->listWidget->currentRow(),item);
}


void MainWindow::on_actListAppend_triggered()
{
    QIcon icon(":/image/icons/check2.ico");
    QListWidgetItem *item ;
    bool chk = ui->chkItemEnchanged->isChecked();

    item = new QListWidgetItem();
    item->setIcon(icon);
    item->setText("AddtItem");
    item->setCheckState(Qt::Checked);
    if(chk)
    {
        item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }else
    {
        item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsSelectable);
    }
    ui->listWidget->addItem(item);
}


void MainWindow::on_actListDelete_triggered()
{
    delete ui->listWidget->currentItem();
}


void MainWindow::on_actSelAll_triggered()
{
    const int cnt = ui->listWidget->count();
    QListWidgetItem *item;
    for(int i = 0; i<cnt;i++)
    {
        item = ui->listWidget->item(i);
        item->setCheckState(Qt::Checked);
    }
}


void MainWindow::on_actSelectNotAll_triggered()
{
    const int cnt = ui->listWidget->count();
    QListWidgetItem *item;
    for(int i = 0; i<cnt;i++)
    {
        item = ui->listWidget->item(i);
        item->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_actSelectInserve_triggered()
{
    const int cnt = ui->listWidget->count();
    QListWidgetItem *item;
    for(int i = 0; i<cnt;i++)
    {
        item = ui->listWidget->item(i);
        if(item->checkState() == Qt::Checked)
        {
            item->setCheckState(Qt::Unchecked);
        }
        else
        {
            item->setCheckState(Qt::Checked);
        }
    }
}


void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(NULL != current )
    {
        if(NULL !=previous)
            ui->editCurItemText->setText("前一项:"+previous->text()+" 当前项："+current->text());
        else
            ui->editCurItemText->setText("当前项："+current->text());
    ui->plainTextEdit->appendPlainText("currentItemChanged()信号被发射");
    }

}

