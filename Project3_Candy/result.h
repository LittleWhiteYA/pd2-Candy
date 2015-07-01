#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <QTime>

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = 0);
    ~Result();
    void Show_Star(int star);

public slots:
    void on_pushButton_clicked();
signals:
    void quit_game();

private:
    Ui::Result *ui;
};

#endif // RESULT_H
