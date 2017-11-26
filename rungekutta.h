#ifndef RUNGEKUTTA_H
#define RUNGEKUTTA_H

#include <QMainWindow>

namespace Ui {
class RungeKutta;
}

class RungeKutta : public QMainWindow
{
    Q_OBJECT

public:
    explicit RungeKutta(QWidget *parent = 0);
    ~RungeKutta();

private:
    Ui::RungeKutta *ui;

public slots:
    void metodo(); //Slot that performs the gaussian elimination method
    void borrar(); //Slot that erases the contents of the spinbox and text
};

#endif // RUNGEKUTTA_H
