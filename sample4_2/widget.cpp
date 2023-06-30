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


void Widget::on_btnFrontBack_clicked()
{
    ui->plainTextEdit->appendPlainText("front()及back()函数测试:");
    QString str1 = ui->comboBoxStr1->currentText();
    ui->plainTextEdit->appendPlainText(str1);
    ui->plainTextEdit->appendPlainText("front = "+QString(str1.front()));
    ui->plainTextEdit->appendPlainText("back = "+QString(str1.back()));
}


void Widget::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_btnLeftRight_clicked()
{
    ui->plainTextEdit->appendPlainText("right()及left()函数测试:");
    QString str1 = ui->comboBoxStr1->currentText();
    ui->plainTextEdit->appendPlainText(str1);
    ui->plainTextEdit->appendPlainText("right = "+QString(str1.right(9)));
    ui->plainTextEdit->appendPlainText("left = "+QString(str1.left(2)));
}


void Widget::on_btnFirstLast_clicked()
{
    ui->plainTextEdit->appendPlainText("first()及last()函数测试:");
    QString str1 = ui->comboBoxStr1->currentText();
    QString str2 = ui->comboBoxStr2->currentText();
    int n = str1.lastIndexOf(str2);
    QString strFirst = str1.first(n+1);//包含斜杠
    QString strLast = str1.last(str1.size()-n-1);

    ui->plainTextEdit->appendPlainText(str1);
    ui->plainTextEdit->appendPlainText("路径名称 = "+strFirst);
    ui->plainTextEdit->appendPlainText("文件名称 = "+strLast);
}


void Widget::on_btnSection_clicked()
{
    ui->plainTextEdit->appendPlainText("section()函数测试:");
    QString str1 = ui->comboBoxStr1->currentText();
    QString str2 = ui->comboBoxStr2->currentText();
    int n = ui->spinBox->value();
    QString strSection = str1.section(str2,n,n);


    ui->plainTextEdit->appendPlainText(strSection);
}


void Widget::on_btnIsNullIsEmpty_clicked()
{
    ui->plainTextEdit->appendPlainText("isNull()及isEmpty()函数测试:");
    QString str1,str2="";//str1未初始胡，str2为空字符串
    ui->plainTextEdit->appendPlainText("QString str1,str2="";//str1未初始胡，str2为空字符串");

    QString str="str1.isNull()= ";
    ui->plainTextEdit->appendPlainText((str1.isNull())?str+="true":str+="false");
    str="str1.isEmpty()= ";
    ui->plainTextEdit->appendPlainText((str1.isEmpty())?str+="true":str+="false");

    str="str2.isNull()= ";
    ui->plainTextEdit->appendPlainText((str2.isNull())?str+="true":str+="false");
    str="str2.isEmpty()= ";
    ui->plainTextEdit->appendPlainText((str2.isEmpty())?str+="true":str+="false");

}


void Widget::on_btnResize_clicked()
{
    ui->plainTextEdit->appendPlainText("resize()函数测试:");
    QString str;
    str.resize(5,'0');
    ui->plainTextEdit->appendPlainText(str);
    str.resize(10,QString("哈")[0].unicode());
    ui->plainTextEdit->appendPlainText(str);
}


void Widget::on_btnSizeLength_clicked()
{
    ui->plainTextEdit->appendPlainText("size()/count()/length()函数测试:");
    QString str1 = ui->comboBoxStr1->currentText();
    ui->plainTextEdit->appendPlainText("str1="+str1);
    ui->plainTextEdit->appendPlainText(QString::asprintf("size=%lld",str1.size()));
    ui->plainTextEdit->appendPlainText(QString::asprintf("count=%lld",str1.count()));
    ui->plainTextEdit->appendPlainText(QString::asprintf("length=%lld",str1.length()));
}


void Widget::on_btnFill_clicked()
{
    ui->plainTextEdit->appendPlainText("fill()函数测试:");
    QString str="Hello";
    str.fill('X',5);
    ui->plainTextEdit->appendPlainText(str);
    str.fill('A',2);
    ui->plainTextEdit->appendPlainText(str);
    str.fill(QChar(0x54c8),3);
    ui->plainTextEdit->appendPlainText(str);
}


void Widget::on_btnTrimmedSimplified_clicked()
{
    ui->plainTextEdit->appendPlainText("trimmed()/simplified()函数测试:");
    QString str1 = ui->comboBoxStr1->currentText();
    ui->plainTextEdit->appendPlainText("str1 = " + str1);
    ui->plainTextEdit->appendPlainText("str1.trimmed() = "+str1.trimmed());
    ui->plainTextEdit->appendPlainText("str1.simplified() = "+str1.simplified());
}


void Widget::on_btnInsert_clicked()
{
    ui->plainTextEdit->appendPlainText("insert()函数测试:");
    QString str1 = "It is great!";
    ui->plainTextEdit->appendPlainText(str1);
    int n = str1.lastIndexOf(" ");
    ui->plainTextEdit->appendPlainText(str1.insert(n,"n't"));
}


void Widget::on_btnRemove_clicked()
{
    ui->plainTextEdit->appendPlainText("remove()函数测试:移除特定字符");
    QString str1="你们，我们，他们";
    ui->plainTextEdit->appendPlainText("str1 = "+ str1);

    QString DeStr = "们";
    QChar DeChar = QChar(DeStr[0].unicode());
    str1.remove(DeChar);
    ui->plainTextEdit->appendPlainText("str1 = "+ str1);

    ui->plainTextEdit->appendPlainText("remove()函数测试:移除右侧N个字符");
    QString str= ui->comboBoxStr1->currentText();
    ui->plainTextEdit->appendPlainText("str = "+ str);

    int n = str.lastIndexOf("\\");
    ui->plainTextEdit->appendPlainText("str = "+ str.remove(n+1,20));
}


void Widget::on_btnReplace_clicked()
{
    ui->plainTextEdit->appendPlainText("replace()函数测试:替换特定字符");
    QString str1="Gooooogle";
    ui->plainTextEdit->appendPlainText("str1 = "+ str1);

    str1.replace('o','e');
    ui->plainTextEdit->appendPlainText("str1 = "+ str1);

    ui->plainTextEdit->appendPlainText("replace()函数测试:替换字符串");
    str1="It is great!";
    ui->plainTextEdit->appendPlainText("str1 = "+ str1);

    int n = str1.lastIndexOf(" ");
    QString subStr = "wonderful";
    ui->plainTextEdit->appendPlainText("str1 = "+ str1.replace(n+1,subStr.size(),QString("wonderful!")));
    ui->plainTextEdit->appendPlainText("str1 = "+ str1.replace(n+1,subStr.size(),QString("OK!")));
}

void Widget::on_btnIndexOfLastIndexOf_clicked()
{
        //indexOf()函数
        QString str1,str2;
        str1=ui->comboBoxStr1->currentText();
        str2=ui->comboBoxStr2->currentText();
        ui->plainTextEdit->appendPlainText("indexOf()/lastIndexOf()函数测试:");
        ui->plainTextEdit->appendPlainText("str1="+str1);
        ui->plainTextEdit->appendPlainText("str2="+str2);

        int i;
        //i=str1.indexOf(str2[0].unicode());
        i=str1.indexOf(str2);
        ui->plainTextEdit->appendPlainText(QString::asprintf("str1.indexOf(str2): %d",i));

        //i=str1.lastIndexOf(str2[0].unicode());
        i=str1.lastIndexOf(str2);
        ui->plainTextEdit->appendPlainText(QString::asprintf("str1.lastIndexOf(str2): %d",i));
}


void Widget::on_btnEndsWithStatsWith_clicked()
{
        QString str1,str2;
        str1=ui->comboBoxStr1->currentText();
        str2=ui->comboBoxStr2->currentText();
        ui->plainTextEdit->appendPlainText("startsWith()/endsWith()函数测试:");
        ui->plainTextEdit->appendPlainText("str1="+str1);
        ui->plainTextEdit->appendPlainText("str2="+str2);
        //startsWith()函数
        ui->plainTextEdit->appendPlainText("str1.startsWith(st2)="+(str1.startsWith(str2)?QString("true"):QString("false")));
        //endsWith()函数
        ui->plainTextEdit->appendPlainText("str1.endsWith(st2)="+(str1.endsWith(str2)?QString("true"):QString("false")));
}


void Widget::on_btnContains_clicked()
{
        //contains()函数
        QString str1,str2;
        str1=ui->comboBoxStr1->currentText();
        str2=ui->comboBoxStr2->currentText();
        ui->plainTextEdit->appendPlainText("contains()函数测试:");
        ui->plainTextEdit->appendPlainText("str1="+str1);
        ui->plainTextEdit->appendPlainText("str2="+str2);

        ui->plainTextEdit->appendPlainText("str1.contains(st2)="+(str1.contains(str2)?QString("true"):QString("false")));
}


void Widget::on_btnCount_clicked()
{
    ui->plainTextEdit->appendPlainText("size()/count()/length()函数测试:");
    QString str1 = ui->comboBoxStr1->currentText();
    ui->plainTextEdit->appendPlainText("str1="+str1);
    ui->plainTextEdit->appendPlainText(QString::asprintf("size=%lld",str1.size()));
    ui->plainTextEdit->appendPlainText(QString::asprintf("count=%lld",str1.count()));
    ui->plainTextEdit->appendPlainText(QString::asprintf("length=%lld",str1.length()));
}

