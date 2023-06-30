#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnCal_clicked();

    void on_spinBoxDec_valueChanged(int arg1);

    void on_spinBoxBin_valueChanged(int arg1);

    void on_spinBoxHex_valueChanged(int arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H