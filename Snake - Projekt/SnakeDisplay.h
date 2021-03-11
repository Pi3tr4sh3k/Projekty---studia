

#ifndef SNAKE2_SNAKEDISPLAY_H
#define SNAKE2_SNAKEDISPLAY_H
#include "Snake.h"
#include "SBoard.h"



class SnakeDisplay {
    Snake &snake;
    SBoard &board;

    int wys;
    int szer;
    int len;

public:
    SnakeDisplay(SBoard &b, Snake &s);
    void display();
    bool checkCollide() const;
};


#endif //SNAKE2_SNAKEDISPLAY_H
