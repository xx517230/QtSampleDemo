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


    void on_btnClear_clicked();

    void on_btnClearList_clicked();

    void on_btnInit_clicked();

    void on_checkBox_clicked(bool checked);

    void on_combCitys_currentTextChanged(const QString &arg1);

    void on_btnInitCityCode_clicked();

    void on_combCityCode_currentIndexChanged(int index);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
