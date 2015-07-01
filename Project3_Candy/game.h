#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "square.h"
#include <cTime>
#include <QTime>
#include "result.h"
#include <QKeyEvent>

namespace Ui {
class game;
}

class game : public QWidget
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = 0);
    ~game();

    void Check_Candy();
    bool operator== (Square &squa);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void Candy_Click(int square_num, bool candy_clicked);
    void set_score();
    void Quit_game();

signals:
    void quit(int star, int score);
private:
    Ui::game *ui;

    Square *gameSquare[8][8];
    QWidget *mainWindow;
    int first_click, second_click;
    void Change_Candy(int first, int second);
    bool Check_Same(int square_num, int Candy_num);
    void Candy_Fall();
    int first_Squa, second_Squa;
    int first_Candy, second_Candy;
    int Check_Speical(int length, int row, int col, int which);
//    void Set_Special(int row, int col, int candy_num, int which);
    void Special_func(int row, int col);
    int score, last_move, star;
    Result *resDialog;


};

#endif // GAME_H
