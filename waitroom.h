#ifndef WAITROOM_H
#define WAITROOM_H
#include <QThread>
#include <QMainWindow>
#include <QtNetwork/QUdpSocket>
#include <QDebug>

namespace Ui {
class waitroom;
}

class waitroom : public QMainWindow
{
    Q_OBJECT


public:
    explicit waitroom(QWidget *parent = nullptr);
    ~waitroom();
private slots:
    void on_pushButton_7_clicked();

private:
    Ui::waitroom *ui;

};

#endif // WAITROOM_H
