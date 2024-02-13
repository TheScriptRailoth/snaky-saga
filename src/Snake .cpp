#include "Snake .h"

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
