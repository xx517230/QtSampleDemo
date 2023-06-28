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


void Widget::on_btnGetChars_clicked()
{
    QString str = ui->editStr->text();
    if(str.isEmpty()) return;
    for(qint16  i=0;i<str.size();i++)
    {
        QChar ch=str.at(i);
        char16_t uniCode = ch.unicode();

        QString chStr(ch);
        QString info = chStr+QString::asprintf("\t,UniCode编码=0x%X",uniCode);
        ui->plainTextEdit->appendPlainText(info);
    }
}


void Widget::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_btnCharJudge_clicked()
{
    QString str = ui->editChar->text();
    if(str.isEmpty()) return;

    QChar ch=str.at(0);
    char16_t uniCode = ch.unicode();

    QString info = ch+QString::asprintf("\t,UniCode编码=0x%X",uniCode);
    ui->plainTextEdit->appendPlainText(info);

    ui->chkDigit->setChecked(ch.isDigit());
    ui->chkLetter->setChecked(ch.isLetter());
    ui->chkLetterOrNumber->setChecked(ch.isLetterOrNumber());
    ui->chkUpper->setChecked(ch.isUpper());
    ui->chkLower->setChecked(ch.isLower());
    ui->chkMark->setChecked(ch.isMark());
    ui->chkSpace->setChecked(ch.isSpace());  //是否是空白符
    ui->chkSymbol->setChecked(ch.isSymbol());//是否是符号
    ui->chkPunct->setChecked(ch.isPunct()); //是否是标点符号
}


void Widget::on_btnConvLatin1_clicked()
{
    QString str="Dimple";
    ui->plainTextEdit->appendPlainText(str);
    //QChar chp=QChar::fromLatin1('P');
    str[0]='P';
    ui->plainTextEdit->appendPlainText("\n"+str);

}


void Widget::on_btnConvUTF16_clicked()
{
    QString str="Hello,北京";
    ui->plainTextEdit->appendPlainText(str);
    QString qd="青岛";
    str[6]=qd.at(0);
    str[7]=qd.at(1);
//    str[6]=QChar(0x9752);
//    str[7]=QChar(0x5c9B);
    ui->plainTextEdit->appendPlainText("\n"+str);
}


void Widget::on_btnCompare_clicked()
{
    QString HuStr="河to湖";
    QChar He=QChar::fromUcs2(HuStr[0].unicode());
    QChar Hu=QChar::fromUcs2(HuStr[3].unicode());
    QString str="我们来自河南或河北";
    ui->plainTextEdit->appendPlainText(str);

    for(int i = 0;i<str.size();i++)
    {
        if(str.at(i)==He)
        {
            str[i]=Hu;
        }
    }
    ui->plainTextEdit->appendPlainText(str);
}

