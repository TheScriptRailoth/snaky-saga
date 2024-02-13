#ifndef SNAKE _H
#define SNAKE _H
#include <windows.h>
#include<vector>
//position
//length
//direction
//velocity(no. of character/pixels)
using namespace std;
class Snake
{
    private:
        COORD pos;
        int len;
        int speed;
        char direction;
        vector<COORD>body;

    public:
        Snake(COORD pos, int speed);

        void changeDirection(char dir);
        void moveSnake();
        COORD getPos();
        vector<COORD> getBody();
        bool foodEaten(COORD foodPos);
        void growSnake();
        bool snakeCollision();
};

#endif // SNAKE _H
