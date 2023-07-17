#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
class QStringListModel;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QStringList strlist;
    QStringListModel *model;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_tbtnFileSwitch_clicked();

    void on_tbtnOutput_clicked();

    void on_btnClear_clicked();

    void on_btnOutputFile_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
