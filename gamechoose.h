#ifndef GAMECHOOSE_H
#define GAMECHOOSE_H

#include <QMainWindow>

namespace Ui {
class GameChoose;
}

class GameChoose : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameChoose(QWidget *parent = nullptr);
    ~GameChoose();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GameChoose *ui;
};

#endif // GAMECHOOSE_H
