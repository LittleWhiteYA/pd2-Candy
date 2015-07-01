#ifndef SIGNALDIALOG_H
#define SIGNALDIALOG_H

#include <QDialog>

namespace Ui {
class SignalDialog;
}

class SignalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignalDialog(int star,int score,QWidget *parent = 0);
    ~SignalDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SignalDialog *ui;
};

#endif // SIGNALDIALOG_H
