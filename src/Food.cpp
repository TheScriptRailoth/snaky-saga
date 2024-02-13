#include "Food.h"

Food::Food()
{
    generateFood();
}
void Food::generateFood(){
    pos.X = rand()%(WIDTH+1);
    pos.Y = rand()% HEIGHT+1;
}
