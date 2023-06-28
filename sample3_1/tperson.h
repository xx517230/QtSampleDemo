#ifndef TPERSON_H
#define TPERSON_H

#include <QObject>

class TPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author","Wang")
    Q_CLASSINFO("company","UPC")
    Q_CLASSINFO("version","2.0.0")
public:
    explicit TPerson(QString name,QObject *parent = nullptr);
    ~TPerson();
    int age();
    void setAge(int ageValue);
    void incAge();
signals:
    void ageChange(int ageValue);
private:
    QString m_name;
    int m_age=10;
    int m_sroce=79;
};

#endif // TPERSON_H
