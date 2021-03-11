#ifndef PACMAN2_TEXTDISPLAY_H
#define PACMAN2_TEXTDISPLAY_H
#include <deque>
#include "PacManBoard.h"
#include "Player.h"
#include "EnemyUnits.h"
class TextDisplay {
    PacManBoard &board;
    Player &p1;
    EnemyUnits &e1;
    char pom;
    EnemyUnits &e2;
    std::deque<char> temp;
    int wys;
    int szer;
    char temp_b[17][15];
public:
    TextDisplay(PacManBoard &b, Player &p, EnemyUnits &e, EnemyUnits &enemy2);
    void display();


};


#endif //PACMAN2_TEXTDISPLAY_H
