#ifndef SIGNALWINDOW_H
#define SIGNALWINDOW_H

#include <QMainWindow>
#include "signaldialog.h"

// Change "game" to your main window's name
#include "game.h"
#define MY_CLASS game

namespace Ui {
class SignalWindow;
}

class SignalWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SignalWindow(QWidget *parent = 0);
    ~SignalWindow();

public slots:
    void quitGame(int star,int score);

private:
    Ui::SignalWindow *ui;
    MY_CLASS *myClass;
};

#endif // SIGNALWINDOW_H
