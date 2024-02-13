#include "Food.h"
#define WIDTH 50
#define HEIGHT 25
Food::Food()
{
    generateFood();
}
void Food::generateFood(){
    pos.X = rand()%(WIDTH+1);
    pos.Y = rand()% HEIGHT+1;
}

COORD Food::getPos(){
    return pos;
}
