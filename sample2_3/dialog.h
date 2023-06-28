#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>

class QCheckBox;
class QRadioButton;
class QPlainTextEdit;
class QPushButton;

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QCheckBox *checkBoxUnder;
    QCheckBox *checkBoxBold;
    QCheckBox *checkBoxItalic;

    QRadioButton *radioBlack;
    QRadioButton *radioBlue;
    QRadioButton *radioRed;

    QPlainTextEdit *txtEdit;

    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnClose;
private slots:
    void do_checkBoxUnder(bool checked);
    void do_checkBoxItalic(bool checked);
    void do_checkBoxBold(bool checked);
    void do_setFontColor();
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
