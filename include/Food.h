#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdlib>
class Food
{
    public:
        void generateFood();
        COORD getPos();

     private:
        COORD pos;

};

#endif // FOOD_H
