
#ifndef PACMAN2_SCORE_H
#define PACMAN2_SCORE_H
#include "Player.h"

class Score {
    Player &p1;
    int cache;
    int elements=5;
    int actualScore;
    int temp[5]={};
public:
    Score(Player &p);
    void saveScore();
};


#endif //PACMAN2_SCORE_H
