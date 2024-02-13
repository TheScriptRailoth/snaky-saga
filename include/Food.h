#ifndef FOOD_H
#define FOOD_H

#include <windows.h>
#include <cstdlib>
class Food
{
    public:
        Food();
        void generateFood();
        COORD getPos();

    protected:

    private:
        COORD pos;

};

#endif // FOOD_H
