#pragma once
#include <QWidget>
#include <QTcpSocket>
#include <QLabel>
class QTextEdit;
class QLineEdit;
/**
*@class MyClient Класс в котором храняться все переменные и данные необходимые для работы с камерой
*
*Данный класс состоит из многих переменных и методов необходимых для подключения, получения и вывода на экран стрима.
*/
class MyClient : public QWidget
{
    Q_OBJECT
private:
    QTcpSocket* tcpSocket;///< Brief QTcpSocket Сокет для управления клиентом
    QTextEdit* txtInfo;///< Brief QTextEdit Виджет для вывода информации о состоянии процесса.
    QLabel *lb;///< Brief QLabel Виджет для вывода на экран стрима
    QLineEdit* txtIp;///< Brief QLineEdit Виджет для ввода адреса камеры
    QLineEdit* txtPort;///< Brief QLineEdit Виджет для ввода порта камеры
    quint16 nextBlockSize;///< Brief quint16 Размер блока
    QByteArray txt;
    int Size = 0;///< Brief int Размер полученых данных
    void getPicture(); ///<Функция получения изображения
public:
    MyClient(const QString & strHost,int nPort,QWidget* pwgt = 0); ///Конструктор

private slots:
    void slotReadyRead();///Слот для чтения данных
    void slotError(QAbstractSocket::SocketError);///слот соединен с сигналом отправляющем ощибку
    void slotSendToServer();///Слот для отправки сообщения камере
    void slotConnected(); ///Слот для подключения
    //void slotReadChannelFinished();
};
