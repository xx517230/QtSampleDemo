#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class TPerson;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    TPerson* boy;
    TPerson* girl;
private slots:
    void do_ageChange(int value);
    void do_spinChange(int arg1);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
