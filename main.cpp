#include <iostream>
#include <cstdlib>
#include<windows.h>
#include<conio.h>
#include<ctime>

#include "Snake .h"
#include "Food.h"

#define WIDTH 50
#define HEIGHT 25
using namespace std;

Snake Snake({WIDTH/2, HEIGHT/2}, 1);
Food food;

void board()
{
    COORD snake_pos = Snake.getPos();
    COORD food_pos= food.getPos();

    for(int i=0;i<HEIGHT;i++)
    {
        cout<<"\t\t#";
        for(int j=0;j<WIDTH-2;j++)
        {
            if(i==0 || i==HEIGHT-1)
                cout<<'#';
            else if(i==snake_pos.Y && j==snake_pos.X)
                cout<<'0';
            else if(i==food_pos.Y && j==food_pos.X)
                cout<<"*";
            else
                cout<<' ';
        }
        cout<<"#\n";
    }
}
int main()
{
    srand(time(NULL));
    while(true){
        board();

        if(kbhit()){
            switch(getch())
            {
                case 'w':Snake.changeDirection('u');break;
                case 'a':Snake.changeDirection('l');break;
                case 's':Snake.changeDirection('d');break;
                case 'd':Snake.changeDirection('r');break;
            }
        }
        Snake.moveSnake();

        if(Snake.foodEaten(food.getPos()))
        {
            food.generateFood();
            Snake.growSnake();
        }

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0, 0});
        //system("cls");
    }
}
