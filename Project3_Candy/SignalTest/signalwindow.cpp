#include "signalwindow.h"
#include "ui_signalwindow.h"

SignalWindow::SignalWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SignalWindow)
{
    ui->setupUi(this);
    myClass=new MY_CLASS(this);
    connect(myClass,SIGNAL(quit(int,int)),this,SLOT(quitGame(int,int)));
    setFixedSize(myClass->width(),myClass->height());
    setCentralWidget(myClass);
    myClass->show();
}

SignalWindow::~SignalWindow()
{
    delete ui;
}

void SignalWindow::quitGame(int star, int score)
{
    SignalDialog *QuitDialog=new SignalDialog(star,score);
    QuitDialog->setModal(true);
    QuitDialog->show();
    QuitDialog->exec();
    QApplication::exit(star);
}
