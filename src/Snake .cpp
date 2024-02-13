#include "Snake .h"

#define WIDTH 50
#define HEIGHT 25
Snake::Snake (COORD pos, int speed)
{
    this->pos=pos;
    this->speed=speed;
    len=1;
    direction='n';

    body.push_back(pos);
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

    if(pos.X>WIDTH-2) pos.X=0;
    if(pos.X<1) pos.X = WIDTH-2;
    body.push_back(pos);
    if(body.size()>len) body.erase(body.begin());
}

COORD Snake::getPos(){
    return pos;
}

vector<COORD> Snake::getBody(){return body;}

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
    if(pos.X<1 || pos.X >=WIDTH-2 || pos.Y < 1 || pos.Y > HEIGHT-2){
        return true;
    }
    //afor(int i=0;i<len-1;i++)
    //{
    //    if(pos.X==body[i].X && pos.Y == body[i].Y) return true;
    //}
    return false;
}
