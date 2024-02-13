#ifndef SNAKE _H
#define SNAKE _H
#include <windows.h>
//position
//length
//direction
//velocity(no. of character/pixels)
class Snake
{
    private:
        COORD pos;
        int len;
        int speed;
        char direction;

    public:
        Snake(COORD pos, int speed);

        void changeDirection(char dir);
        void moveSnake();
        COORD getPos();
};

#endif // SNAKE _H
