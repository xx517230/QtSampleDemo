#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->radioButton_Black, SIGNAL(clicked()), this, SLOT(do_FontColor()));
    QObject::connect(ui->radioButton_Red, SIGNAL(clicked()), this, SLOT(do_FontColor()));
    QObject::connect(ui->radioButton_Blue, SIGNAL(clicked()), this, SLOT(do_FontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_Clear_clicked()
{
    ui->plainTextEdit->clear();
}


void Dialog::on_checkBox_underline_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_italic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBox_bold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::do_FontColor()
{
    QPalette plet = ui->plainTextEdit->palette();
    if(ui->radioButton_Black->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    if(ui->radioButton_Blue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    if(ui->radioButton_Red->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    ui->plainTextEdit->setPalette(plet);
}

