#include "Food.h"
#define WIDTH 50
#define HEIGHT 25
void Food::generateFood(){
    pos.X = (rand()% WIDTH -3)+3;
    pos.Y = (rand()% HEIGHT -3)+3;
}

COORD Food::getPos(){
    return pos;
}
