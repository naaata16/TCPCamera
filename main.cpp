#include "mainwindow.h"
#include <QApplication>
#include "client.h"
#include <QtWidgets>
/*!
    \author Gatanyuk N.S.
    \version 1.0.1
    \date December 2018 year
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClient client("169.254.69.224", 80);


    QPalette pal;
    pal.setBrush(client.backgroundRole(),QBrush(QPixmap("C:\\Users\\Nata\\Desktop\\camera2.jpg")));
    QCursor cur = QCursor(QPixmap("C:\\Users\\Nata\\Desktop\\c3.png"));
    client.setCursor(cur);
    client.setPalette(pal);
    client.setAutoFillBackground(true);

    client.show();

    return a.exec();

}
