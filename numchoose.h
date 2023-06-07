#ifndef NUMCHOOSE_H
#define NUMCHOOSE_H

#include <QMainWindow>

namespace Ui {
class NumChoose;
}

class NumChoose : public QMainWindow
{
    Q_OBJECT

public:
    explicit NumChoose(QWidget *parent = nullptr);
    ~NumChoose();

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_6_clicked();
private:
    Ui::NumChoose *ui;
};

#endif // NUMCHOOSE_H
