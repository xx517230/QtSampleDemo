#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actListInit_triggered();

    void on_actListClear_triggered();

    void on_actListInset_triggered();

    void on_actListAppend_triggered();

    void on_actListDelete_triggered();


    void on_actSelAll_triggered();

    void on_actSelectNotAll_triggered();

    void on_actSelectInserve_triggered();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_chkSortEnable_clicked(bool checked);

    void on_tbtnAsc_clicked();

    void on_tbtnDes_clicked();

    void on_tbtnClearText_clicked();

    void on_tbtnAddLine_clicked();

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
