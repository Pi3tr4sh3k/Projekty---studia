
#ifndef PACMAN2_PACMANBOARD_H
#define PACMAN2_PACMANBOARD_H

#include <string>
#include <deque>
class PacManBoard {
    int width=17;
    int height=15;
    char board[17][15];


public:
    PacManBoard();
    int getWidth() const;
    int getHeight() const;

    char getFieldInfo(int x, int y) const;
    void setFieldStatus(int x, int y, char k);




};




#endif //PACMAN2_PACMANBOARD_H
