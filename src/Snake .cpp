#include "Snake .h"

#define WIDTH 50
#define HEIGHT 25
Snake::Snake (COORD pos, int speed)
{
    this->pos=pos;
    this->speed=speed;
    len=1;
    direction='n';
}
void Snake::changeDirection(char dir){
    direction=dir;
}

void Snake::moveSnake()
{
    switch(direction)
    {
        case 'u': pos.Y = pos.Y - speed; break;
        case 'd': pos.Y = pos.Y + speed; break;
        case 'l': pos.X = pos.X - speed; break;
        case 'r': pos.X = pos.X + speed; break;
    }
}

COORD Snake::getPos(){
    return pos;
}

bool Snake::foodEaten(COORD foodPos)
{
    if(foodPos.X==pos.X && foodPos.Y==pos.Y){
        return true;
    }
    return false;
}

void Snake::growSnake(){
    len++;
}

bool Snake::snakeCollision(){
    if(pos.X<1 || pos.X > WIDTH-1 || pos.Y<1 || pos.Y>HEIGHT-1){
        return true;
    }
    return false;
}
