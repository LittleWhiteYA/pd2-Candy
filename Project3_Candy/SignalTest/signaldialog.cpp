#include "signaldialog.h"
#include "ui_signaldialog.h"

SignalDialog::SignalDialog(int star, int score, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignalDialog)
{
    ui->setupUi(this);
    ui->StarLabel->setText("Star:"+QString::number(star));
    ui->ScoreLabel->setText("Score:"+QString::number(score));
}

SignalDialog::~SignalDialog()
{
    delete ui;
}

void SignalDialog::on_pushButton_clicked()
{
    delete this;
}
