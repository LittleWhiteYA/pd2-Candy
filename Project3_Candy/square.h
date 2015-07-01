#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QPushButton>
#include <QString>

class Square : public QObject
{
    Q_OBJECT
public:
    explicit Square(QWidget *parent, int row, int col);
    ~Square();

    int Get_Square_num();
    int Get_Candy();
    void Set_Candy_State(bool state);
    void Set_Change(bool move);
    bool Get_Change();


signals:
    void Click(int square_num, bool candy_clicked);
    void add_score();

public slots:
    void Clicked();
    void Set_Candy(int);

private:
    QPushButton *button;
    int Row, Col;
    int square_num;
    int Candy_num;
    bool candy_clicked;
    bool Change;
};

#endif // SQUARE_H
