
#ifndef SNAKE2_SCORE_H
#define SNAKE2_SCORE_H
#include <fstream>
#include "Snake.h"
class Score {
    Snake &snake;
    int cache;
    int elements=10;
    int actualScore;
    int tab[10]={};
public:
    void sort(int tab[]);
    Score(Snake &s);
    void saveScore();


};


#endif //SNAKE2_SCORE_H
