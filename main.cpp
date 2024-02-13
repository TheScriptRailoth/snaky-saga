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
int score;

void board()
{
    COORD snake_pos = Snake.getPos();
    COORD food_pos= food.getPos();

    vector<COORD> snakeBody= Snake.getBody();

    cout<<"YOUR SCORE : "<<score<<"\n\n";

    for(int i=0;i<HEIGHT;i++)
    {
        cout<<"\t\t#";
        for(int j=0;j<WIDTH-2;j++)
        {
            if(i==0 || i==HEIGHT-1)
                cout<<'#';
            else if(i==snake_pos.Y && j+1==snake_pos.X)
                cout<<'0';
            else if(i==food_pos.Y && j+1==food_pos.X)
                cout<<"*";
            else{
                bool isBodyPart = false;
                for(int k=0;k<snakeBody.size()-1;k++)
                {
                    if(i==snakeBody[k].Y && j+1==snakeBody[k].X)
                    {
                        cout<<"0";
                        isBodyPart=true;
                        break;
                    }
                }
                if(!isBodyPart)cout<<" ";
            }
        }
        cout<<"#\n";
    }
}
int main()
{
    score=0;
    srand(time(NULL));
    food.generateFood();
    bool isGameOver=false;
    while(!isGameOver)
    {
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

        if(Snake.foodEaten(food.getPos()))
        {
            food.generateFood();
            Snake.growSnake();
            score++;
        }
        if(Snake.snakeCollision()){
            isGameOver=true;
        }

        Snake.moveSnake();

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0, 0});
        //system("cls");
    }
}
