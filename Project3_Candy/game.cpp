#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::game),
    first_click(-1), second_click(-1),
    score(0), last_move(20), star(0)
{
    ui->setupUi(this);

    mainWindow=parent;
    srand(time(NULL));
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            gameSquare[i][j] = new Square(this,i,j);
            connect(gameSquare[i][j], SIGNAL(Click(int,bool)), this, SLOT(Candy_Click(int,bool)));
            connect(gameSquare[i][j], SIGNAL(add_score()), this, SLOT(set_score()));
            int rand_num = rand()%6;
            gameSquare[i][j]->Set_Candy(rand_num);
        }
    }


//    gameSquare[7][0]->Set_Candy(100);
//    gameSquare[6][1]->Set_Candy(100);
//    gameSquare[7][2]->Set_Candy(100);
//    gameSquare[7][3]->Set_Candy(100);
    ui->lcdNumber_score->display(0);
    ui->lcdNumber->display(last_move);
    resDialog = new Result;

//    gameSquare[0][0]->Set_Candy(0);
//    gameSquare[0][1]->Set_Candy(0);
//    if(gameSquare[0][0] == gameSquare[0][1])
//        ui->lcdNumber_score->display(100);
    connect(resDialog, SIGNAL(quit_game()), this, SLOT(Quit_game()));


}

game::~game()
{
    delete ui;

    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            delete gameSquare[i][j];
        }
    }
    delete mainWindow;
    delete resDialog;
}

void game::Candy_Click(int square_num, bool candy_clicked)
{
    //ui->label->setText(QString::number(gameSquare[square_num/8][square_num%8]->Get_Square_num()));
    if(first_click == -1 && candy_clicked == true)
        first_click = square_num;
    else if(first_click != -1 && candy_clicked == false)
        first_click = -1;
    else if(first_click != -1 && candy_clicked == true)
    {
        second_click = square_num;
        if(second_click == first_click+1 || second_click == first_click-1 ||
           second_click == first_click-8 || second_click == first_click+8 )
        {
            //ui->label->setText(QString::number(first_click));
            //ui->label_2->setText(QString::number(second_click));
            Change_Candy(first_click, second_click);
            gameSquare[first_click/8][first_click%8]->Set_Candy_State(false);
            gameSquare[second_click/8][second_click%8]->Set_Candy_State(false);
            first_click = -1;
            second_click = -1;

        }
        else
        {
            gameSquare[first_click/8][first_click%8]->Set_Candy_State(false);
            first_click = second_click;
            second_click = -1;
        }

    }
}

void game::Change_Candy(int first, int second)
{
    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j)
            gameSquare[i][j]->Set_Change(false);
    first_Squa = first;
    second_Squa = second;
    first_Candy = gameSquare[first_Squa/8][first_Squa%8]->Get_Candy();
    second_Candy = gameSquare[second_Squa/8][second_Squa%8]->Get_Candy();
    //ui->label->setText(QString::number(Candy1));
    //ui->label_2->setText(QString::number(Candy2));
    gameSquare[first_Squa/8][first_Squa%8]->Set_Candy(second_Candy);
    gameSquare[second_Squa/8][second_Squa%8]->Set_Candy(first_Candy);
    QTime t;
    t.start();
    while(t.elapsed() < 200)
        QCoreApplication::processEvents();

    bool Same1 = Check_Same(first_Squa, second_Candy);
    bool Same2 = Check_Same(second_Squa, first_Candy);
    if(first_Candy == 100 || second_Candy == 100)
    {
        --last_move;
        ui->lcdNumber->display(last_move);
        int num;
        if(first_Candy == 100)
            num = second_Candy;
        else if(second_Candy == 100)
            num = first_Candy;

        for(int i=0; i<8; ++i)
            for(int j=0; j<8; ++j)
                if(gameSquare[i][j]->Get_Candy()%6 == num && gameSquare[i][j]->Get_Candy() != 100)
                {
                    if(gameSquare[i][j]->Get_Candy() >= 12)
                        Special_func(i, j);
                    else
                        gameSquare[i][j]->Set_Candy(-1);
                }

        gameSquare[first_Squa/8][second_Squa%8]->Set_Candy(-1);
        gameSquare[second_Squa/8][second_Squa%8]->Set_Candy(-1);
        Candy_Fall();
        Check_Candy();
    }
    else if(Same1 || Same2)
    {
        --last_move;
        ui->lcdNumber->display(last_move);
        //ui->label->setText("True");
        Check_Candy();
    }
    else
    {
        //ui->label->setText("False");
        //ui->label_2->setText(QString::number(0));
        //ui->label_3->setText(QString::number(0));
        gameSquare[first_Squa/8][first_Squa%8]->Set_Candy(first_Candy);
        gameSquare[second_Squa/8][second_Squa%8]->Set_Candy(second_Candy);
    }

    if(last_move == 0)
    {
        if(score >= 500 && score < 1000)
            star = 1;
        else if(score >= 1000 && score < 2000)
            star = 2;
        else if(score >= 2000)
            star = 3;
        else
            star = 0;
        resDialog->show();
        resDialog->Show_Star(star);
    }

}

bool game::Check_Same(int square_num, int Candy_num)
{
    int row_start = square_num/8;
    int col = square_num%8;
    while(row_start > 0 && Candy_num%6 == gameSquare[row_start-1][col]->Get_Candy()%6)
    {
        --row_start;
    }
    int row_length = 1;
    int row_end;
    for(row_end=row_start+1; row_end<8 && Candy_num%6 == gameSquare[row_end][col]->Get_Candy()%6; ++row_end)
    {
        ++row_length;
    }
    --row_end;


    int row = square_num/8;
    int col_start = square_num%8;
    while(col_start > 0 && Candy_num%6 == gameSquare[row][col_start-1]->Get_Candy()%6)
    {
        --col_start;
    }
    int col_length = 1;
    int col_end;
    for(col_end=col_start+1; col_end<8 && Candy_num%6 == gameSquare[row][col_end]->Get_Candy()%6; ++col_end)
    {
        ++col_length;
    }
    --col_end;

    if(row_length >=3 || col_length >= 3)
        return true;
    else
        return false;
}

void game::Check_Candy()
{

    bool Same1 = false;
    for(int i=7; i>=0 && !Same1; --i)
    {
        for(int j=0; j<6 && !Same1; ++j)
        {
            int length = 1;
            for(int k=j; gameSquare[i][k+1]->Get_Candy()%6 == gameSquare[i][k]->Get_Candy()%6; ++k)
            {
                ++length;
                if(k == 6)
                    break;
            }

            if(length >= 3)
            {
//                ui->label->setText(QString::number(length));
//                ui->label_2->setText(QString::number(i));
//                ui->label_3->setText(QString::number(j));
//                ui->label_4->setText("True");
                int candy_num = Check_Speical(length, i, j, 1);
                int row_set = i;
                int col_set = j;
                int k, count;
                for(k=j, count=0; count<length; ++count, ++k)
                {
                    if(gameSquare[i][k]->Get_Change() == true)
                    {
                        row_set = i;
                        col_set = k;
                    }
                }

                if(candy_num != -1)
                {
                    gameSquare[row_set][col_set]->Set_Candy(candy_num);
                }

                for(k=j, count=0; count<length; ++count, ++k)
                {
                    if(gameSquare[i][k]->Get_Candy() >=12 && (gameSquare[i][k]->Get_Change() == false ||
                       (i == row_set && k == col_set && candy_num == -1)))
                    {
//                        ui->label_2->setText("2");
                        QTime t;
                        t.start();
                        while(t.elapsed() < 200)
                            QCoreApplication::processEvents();
                        Special_func(i, k);
                    }
                    else if(gameSquare[i][k]->Get_Candy() < 6)
                        gameSquare[i][k]->Set_Candy(-1);
                }


                Candy_Fall();
                Same1 = true;
            }

        }
    }

    bool Same2 = false;
    for(int y=7; y>=0 && !Same2; --y)
    {
        for(int x=0; x<6 && !Same2; ++x)
        {
            int length = 1;
            for(int k=x; gameSquare[k+1][y]->Get_Candy()%6 == gameSquare[k][y]->Get_Candy()%6; ++k)
            {
                ++length;
                if(k == 6)
                    break;
            }

            if(length >= 3)
            {
//                ui->label_2->setText(QString::number(length));
                int candy_num = Check_Speical(length, x, y, 2);
                int row_set = x;
                int col_set = y;
                int k, count;
                for(k=x, count=0; count<length; ++count, ++k)
                {
                    if(gameSquare[k][y]->Get_Change() == true)
                    {
                        row_set = k;
                        col_set = y;
                    }
                }
                if(candy_num != -1)
                {
                    gameSquare[row_set][col_set]->Set_Candy(candy_num);
                }

                for(k=x, count=0; count<length; ++count, ++k)
                {
                    if(gameSquare[k][y]->Get_Candy() >= 12 && (gameSquare[k][y]->Get_Change() == false ||
                       (k == row_set && y == col_set && candy_num == -1)))
                    {
//                        ui->label->setText("1");
                        QTime t;
                        t.start();
                        while(t.elapsed() < 200)
                            QCoreApplication::processEvents();
                        Special_func(k, y);
                    }
                    else if(gameSquare[k][y]->Get_Candy() < 6)
                        gameSquare[k][y]->Set_Candy(-1);
                }
                Candy_Fall();
                Same2 = true;
            }
        }
    }

    if(Same1 || Same2)
        Check_Candy();



}

void game::Candy_Fall()
{
    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j)
            gameSquare[i][j]->Set_Change(false);
    QTime t;
    t.start();
    while(t.elapsed() < 200)
        QCoreApplication::processEvents();

    bool Full = false;
    while(Full == false)
    {
        int count = 0;
        for(int i=0; i<8; ++i)
        {
            for(int j=0; j<8; ++j)
            {
                if(gameSquare[i][j]->Get_Candy() == -1)
                {
                    if(i == 0)
                    {
                        int num = rand()%6;
                        gameSquare[i][j]->Set_Candy(num);
                    }
                    else
                    {
                        int up_candy = gameSquare[i-1][j]->Get_Candy();
                        gameSquare[i][j]->Set_Candy(up_candy);
                        gameSquare[i-1][j]->Set_Candy(-1);

                    }
                }
                else
                {
                    ++count;
                    if(count == 63)
                        Full = true;
                }
            }
        }
        t.start();
        while(t.elapsed() < 100)
            QCoreApplication::processEvents();
    }
}

int game::Check_Speical(int length, int row, int col, int which)
{
    int candy_num = 0;
    bool Special = false;
    if(which == 1)
    {
        if(length == 5)
        {
            candy_num = 100;
            Special = true;
        }
        else if(length == 3)
        {
            if(row < 6 && (gameSquare[row][col]->Get_Candy()%6 == gameSquare[row+1][col]->Get_Candy()%6) &&
               (gameSquare[row][col]->Get_Candy()%6 == gameSquare[row+2][col]->Get_Candy()%6))
            {
               // ui->label->setText("1");
                if(gameSquare[row+1][col]->Get_Candy() >= 12)
                    Special_func(row+1, col);
                else
                    gameSquare[row+1][col]->Set_Candy(-1);
                if(gameSquare[row+2][col]->Get_Candy() >= 12)
                    Special_func(row+2, col);
                else
                    gameSquare[row+2][col]->Set_Candy(-1);
                Special = true;
            }
            else if(row >= 2 && (gameSquare[row][col]->Get_Candy()%6 == gameSquare[row-1][col]->Get_Candy()%6) &&
                    (gameSquare[row][col]->Get_Candy()%6 == gameSquare[row-2][col]->Get_Candy()%6))
            {
                //ui->label_2->setText("2");
                if(gameSquare[row-1][col]->Get_Candy() >= 12)
                    Special_func(row-1, col);
                else
                    gameSquare[row-1][col]->Set_Candy(-1);
                if(gameSquare[row-2][col]->Get_Candy() >= 12)
                    Special_func(row-2, col);
                else
                    gameSquare[row-2][col]->Set_Candy(-1);
                Special = true;
            }
            else if(row < 6 && (gameSquare[row][col+2]->Get_Candy()%6 == gameSquare[row+1][col+2]->Get_Candy()%6) &&
                    (gameSquare[row][col+2]->Get_Candy()%6 == gameSquare[row+2][col+2]->Get_Candy()%6))
            {
                //ui->label_3->setText("3");
                if(gameSquare[row+1][col+2]->Get_Candy() >= 12)
                    Special_func(row+1, col+2);
                else
                    gameSquare[row+1][col+2]->Set_Candy(-1);
                if(gameSquare[row+2][col+2]->Get_Candy() >= 12)
                    Special_func(row+2, col+2);
                else
                    gameSquare[row+2][col+2]->Set_Candy(-1);
                Special = true;
            }
            else if(row >= 2 && (gameSquare[row][col+2]->Get_Candy()%6 == gameSquare[row-1][col+2]->Get_Candy()%6) &&
                    (gameSquare[row][col+2]->Get_Candy()%6 == gameSquare[row-2][col+2]->Get_Candy()%6))
            {
                //ui->label_4->setText("4");
                if(gameSquare[row-1][col+2]->Get_Candy() >= 12)
                    Special_func(row-1, col+2);
                else
                    gameSquare[row-1][col+2]->Set_Candy(-1);
                if(gameSquare[row-2][col+2]->Get_Candy() >= 12)
                    Special_func(row-2, col+2);
                else
                    gameSquare[row-2][col+2]->Set_Candy(-1);

                Special = true;
            }

            if(Special)
                candy_num = gameSquare[row][col]->Get_Candy()%6+24;


        }
        else if(length == 4)
        {
            candy_num = gameSquare[row][col]->Get_Candy()%6+12;
            Special = true;
        }

        if(Special)
            return candy_num;

    }
    else if(which == 2)
    {
        if(length == 5)
        {
            candy_num = 100;
            Special = true;
        }
        else if(length == 3)
        {
            if(col < 6 && (gameSquare[row][col]->Get_Candy()%6 == gameSquare[row][col+1]->Get_Candy()%6) &&
               (gameSquare[row][col]->Get_Candy()%6 == gameSquare[row][col+2]->Get_Candy()%6))
            {
               // ui->label->setText("1");
                gameSquare[row][col+1]->Set_Candy(-1);
                gameSquare[row][col+2]->Set_Candy(-1);
                Special = true;
            }
            else if(col >= 2 && (gameSquare[row][col]->Get_Candy()%6 == gameSquare[row][col-1]->Get_Candy()%6) &&
                    (gameSquare[row][col]->Get_Candy()%6 == gameSquare[row][col-2]->Get_Candy()%6))
            {
                //ui->label_2->setText("2");
                gameSquare[row][col-1]->Set_Candy(-1);
                gameSquare[row][col-2]->Set_Candy(-1);
                Special = true;
            }
            else if(col < 6 && (gameSquare[row+2][col]->Get_Candy()%6 == gameSquare[row+2][col+1]->Get_Candy()%6) &&
                    (gameSquare[row+2][col]->Get_Candy()%6 == gameSquare[row+2][col+2]->Get_Candy()%6))
            {
                //ui->label_3->setText("3");
                gameSquare[row+2][col+1]->Set_Candy(-1);
                gameSquare[row+2][col+2]->Set_Candy(-1);
                Special = true;
            }
            else if(col >= 2 && (gameSquare[row+2][col]->Get_Candy()%6 == gameSquare[row+2][col-1]->Get_Candy()%6) &&
                    (gameSquare[row+2][col]->Get_Candy()%6 == gameSquare[row+2][col-2]->Get_Candy()%6))
            {
                //ui->label_4->setText("4");
                gameSquare[row+2][col-1]->Set_Candy(-1);
                gameSquare[row+2][col-2]->Set_Candy(-1);
                Special = true;
            }

            if(Special)
            {
                candy_num = gameSquare[row][col]->Get_Candy()%6+24;
            }
        }
        else if(length == 4)
        {
            candy_num = gameSquare[row][col]->Get_Candy()%6+12;
            Special = true;
        }

        if(Special)
        {
            return candy_num;
        }
    }

    return -1;
}

void game::Special_func(int row, int col)
{
    int candy_num = gameSquare[row][col]->Get_Candy();
    gameSquare[row][col]->Set_Candy(-1);
    if(candy_num >=12 && candy_num <= 17)
    {
        int rand_num = rand()%2;
        if(rand_num == 0)
        {
            for(int h=0; h<8; ++h)
            {
                if(gameSquare[row][h]->Get_Candy() >= 12)
                    Special_func(row, h);
                else if(gameSquare[row][h]->Get_Candy() < 6)
                    gameSquare[row][h]->Set_Candy(-1);
            }
        }
        else if(rand_num == 1)
            for(int h=0; h<8; ++h)
            {
                if(gameSquare[h][col]->Get_Candy() >= 12)
                    Special_func(h, col);
                else if(gameSquare[h][col]->Get_Candy() < 6)
                    gameSquare[h][col]->Set_Candy(-1);
            }
    }
    else if(candy_num >=24 && candy_num <= 29)
    {
        int i = row-1;
        do
        {
            int j = col-1;
            if(i<0)
                ++i;
            do
            {
                if(j<0)
                    ++j;
                if(gameSquare[i][j]->Get_Candy() >= 12)
                {
                    Special_func(i, j);
                }
                else if(gameSquare[i][j]->Get_Candy() < 6)
                    gameSquare[i][j]->Set_Candy(-1);
                ++j;

            }while( j >= col-1 && j <= col+1 && j>=0 && j<8);
            ++i;

        }while(i >= row-1 && i <= row+1 && i>=0 && i<8);

    }

}

void game::set_score()
{
    ++score;
    ui->lcdNumber_score->display(score);
}

bool game::operator== (Square &squa)
{
    ui->Test->setText(QString::number(0));
    ui->Test->setText(QString::number(this->last_move));
    if(this->gameSquare[0][0]->Get_Candy() == squa.Get_Candy())
        return true;
    else
        return false;


}

void game::Quit_game()
{
    emit quit(star, score);
    this->close();
}

void game::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        for(int i=0; i<8; ++i)
        {
            gameSquare[1][i]->Set_Candy(-1);
        }
        Candy_Fall();
    }
    else if(event->key() == Qt::Key_C)
    {
        for(int i=0; i<4; ++i)
        {
            for(int j=0; j<8; ++j)
            {
                int candy1 = gameSquare[i][j]->Get_Candy();
                int candy2 = gameSquare[7-i][j]->Get_Candy();
                gameSquare[i][j]->Set_Candy(candy2);
                gameSquare[7-i][j]->Set_Candy(candy1);
            }
        }
    }









}

