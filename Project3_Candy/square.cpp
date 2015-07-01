#include "square.h"

Square::Square(QWidget *parent, int row, int col) : QObject(parent),
    candy_clicked(false)
{
    Row=row;
    Col=col;
    button = new QPushButton(parent);
    button->setGeometry(55*col+50,55*row+85, 55, 55);
    //button->setStyleSheet("border:1px solid;");
    square_num = 8*row+col;
    //button->setText(QString::number(square_num));
    button->setCursor(Qt::PointingHandCursor);
    connect(button, SIGNAL(clicked()), this, SLOT(Clicked()));
}

Square::~Square()
{
    delete button;
}

int Square::Get_Square_num()
{
    return square_num;
}

void Square::Set_Candy(int num)
{
//    if(num == 0)
//    {
//        Candy_num = 0;
//        QIcon nothing;
//        button->setIcon(nothing);
//        button->setIconSize(QSize(button->width(), button->height()));
//    }

        QString icon;
        if(num == -1)
        {
            icon = ":/icon/nothing.png";
            emit add_score();
        }
        else if(num == 0)
        {
            icon = ":/icon/red.png";
        }
        else if(num == 1)
        {
            icon = ":/icon/orange.png";
        }
        else if(num == 2)
        {
            icon = ":/icon/yellow.png";
        }
        else if(num == 3)
        {
            icon = ":/icon/green.png";
        }
        else if(num == 4)
        {
            icon = ":/icon/blue.png";
        }
        else if(num == 5)
        {
            icon = ":/icon/purple.png";
        }
        else if(num == 6)
        {
            icon = ":/icon/red_click.png";
        }
        else if(num == 7)
        {
            icon = ":/icon/orange_click.png";
        }
        else if(num == 8)
        {
            icon = ":/icon/yellow_click.png";
        }
        else if(num == 9)
        {
            icon = ":/icon/green_click.png";
        }
        else if(num == 10)
        {
            icon = ":/icon/blue_click.png";
        }
        else if(num == 11)
        {
            icon = ":/icon/purple_click.png";
        }
        else if(num == 12)
            icon = ":/icon/red_2.png";
        else if(num == 13)
            icon = ":/icon/orange_2.png";
        else if(num == 14)
            icon = ":/icon/yellow_2.png";
        else if(num == 15)
            icon = ":/icon/green_2.png";
        else if(num == 16)
            icon = ":/icon/blue_2.png";
        else if(num == 17)
            icon = ":/icon/purple_2.png";
        else if(num == 18)
            icon = ":/icon/red_2_click.png";
        else if(num == 19)
            icon = ":/icon/orange_2_click.png";
        else if(num == 20)
            icon = ":/icon/yellow_2_click.png";
        else if(num == 21)
            icon = ":/icon/green_2_click.png";
        else if(num == 22)
            icon = ":/icon/blue_2_click.png";
        else if(num == 23)
            icon = ":/icon/purple_2_click.png";
        else if(num == 24)
            icon = ":/icon/red_3.png";
        else if(num == 25)
            icon = ":/icon/orange_3.png";
        else if(num == 26)
            icon = ":/icon/yellow_3.png";
        else if(num == 27)
            icon = ":/icon/green_3.png";
        else if(num == 28)
            icon = ":/icon/blue_3.png";
        else if(num == 29)
            icon = ":/icon/purple_3.png";
        else if(num == 30)
            icon = ":/icon/red_3_click.png";
        else if(num == 31)
            icon = ":/icon/orange_3_click.png";
        else if(num == 32)
            icon = ":/icon/yellow_3_click.png";
        else if(num == 33)
            icon = ":/icon/green_3_click.png";
        else if(num == 34)
            icon = ":/icon/blue_3_click.png";
        else if(num == 35)
            icon = ":/icon/purple_3_click.png";
        else if(num == 100)
            icon = ":/icon/Choco.png";
        else if(num == 106)
            icon = ":/icon/Choco_click.png";

        if(num == 100)
            Candy_num = num;
        else if(num < 12)
            Candy_num = num%6;
        else if(num < 24)
            Candy_num = num%6+12;
        else if(num < 36)
            Candy_num = num%6+24;
        button->setIcon(QIcon(icon));
        button->setIconSize(QSize(button->width(), button->height()));
        button->setDefault(true);
        if(num != -1)
            Set_Change(true);
}

void Square::Clicked()
{
    if(candy_clicked == false)
    {
        candy_clicked = true;
        Set_Candy(Candy_num+6);
        emit Click(square_num, candy_clicked);
    }
    else if(candy_clicked == true)
    {
        candy_clicked = false;
        if(Candy_num == 106)
            Set_Candy(100);
        else
            Set_Candy(Candy_num);
        emit Click(square_num, candy_clicked);
    }
}

int Square::Get_Candy()
{
    return Candy_num;
}

void Square::Set_Candy_State(bool state)
{
    candy_clicked = state;
    Set_Candy(Candy_num);
}


void Square::Set_Change(bool move)
{
    Change = move;
}

bool Square::Get_Change()
{
    return Change;
}
