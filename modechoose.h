#ifndef MODECHOOSE_H
#define MODECHOOSE_H

#include <QMainWindow>

namespace Ui {
class ModeChoose;
}

class ModeChoose : public QMainWindow
{
    Q_OBJECT

public:
    explicit ModeChoose(QWidget *parent = nullptr);
    ~ModeChoose();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ModeChoose *ui;
};

#endif // MODECHOOSE_H
