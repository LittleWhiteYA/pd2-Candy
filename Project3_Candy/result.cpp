#include "result.h"
#include "ui_result.h"

Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
}

Result::~Result()
{
    delete ui;
}

void Result::Show_Star(int star)
{
    QTime t;
    t.start();
    while(t.elapsed() < 500)
        QCoreApplication::processEvents();
    if(star == 0)
    {
        ui->label_2->setPixmap(QPixmap(":/icon/x.png"));
    }
    else if(star == 1)
    {
        ui->label->setPixmap(QPixmap(":/icon/star.jpg"));
    }
    else if(star == 2)
    {
        ui->label->setPixmap(QPixmap(":/icon/star.jpg"));
        t.start();
        while(t.elapsed() < 500)
            QCoreApplication::processEvents();
        ui->label_2->setPixmap(QPixmap(":/icon/star.jpg"));
    }
    else if(star == 3)
    {
        ui->label->setPixmap(QPixmap(":/icon/star.jpg"));
        t.start();
        while(t.elapsed() < 500)
            QCoreApplication::processEvents();
        ui->label_2->setPixmap(QPixmap(":/icon/star.jpg"));
        t.start();
        while(t.elapsed() < 500)
            QCoreApplication::processEvents();
        ui->label_3->setPixmap(QPixmap(":/icon/star.jpg"));

    }
}

void Result::on_pushButton_clicked()
{
    emit quit_game();
    this->close();
}
