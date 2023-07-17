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
    QStringList m_strList;
    QStringListModel *m_model;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRestore_clicked();

    void on_btnClear_clicked();

    void on_chkEnableEdit_clicked(bool checked);

    void on_btnAddItem_clicked();

    void on_btnInsertItem_clicked();

    void on_btnMoveUp_clicked();

    void on_btnMoveDown_clicked();

    void on_btnSortItem_clicked(bool checked);

    void on_btnCLearPlain_clicked();

    void on_btnShow_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
