#include "mainwindow.h"

#include <QApplication>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    QString time1 = "Tue Jul 11 16:12:49 2023";
//    QString time2 = "Tue Jul 11 20:27:59 2023";
//    QString timeFormat33xxATE = "ddd MMM dd hh:mm:ss yyyy";

//    QDateTime t1 = QDateTime::fromString(time1,timeFormat33xxATE);
//    QDateTime t2 = QDateTime::fromString(time2,timeFormat33xxATE);

//    qint64 timeMs1 = t1.toMSecsSinceEpoch();
//    qint64 timeMs2 = t2.toMSecsSinceEpoch();
//    double timeSub = (timeMs2-timeMs1)/1000.0/60;
//    printf("time = %.2f\n",timeSub);
//    QString timee = t1.toString(timeFormat33xxATE);
//    printf("%s\n",timee.toLocal8Bit().data());
    return a.exec();
}
