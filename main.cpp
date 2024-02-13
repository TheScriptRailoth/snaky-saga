#include <iostream>
#include <cstdlib>
#include<windows.h>
#include<conio.h>

#include "Snake .h"
#define WIDTH 50
#define HEIGHT 25
using namespace std;

Snake Snake({WIDTH/2, HEIGHT/2}, 1);
void board()
{
    COORD snake_pos = Snake.getPos();

    for(int i=0;i<HEIGHT;i++)
    {
        cout<<"\t\t#";
        for(int j=0;j<WIDTH-2;j++)
        {
            if(i==0 || i==HEIGHT-1)
                cout<<'#';
            else if(i==snake_pos.Y && j==snake_pos.X)
                cout<<'0';
            else
                cout<<' ';
        }
        cout<<"#\n";
    }
}
int main()
{
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

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0, 0});
        //system("cls");
    }
}
