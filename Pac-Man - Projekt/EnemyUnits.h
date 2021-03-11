
#ifndef PACMAN2_ENEMYUNITS_H
#define PACMAN2_ENEMYUNITS_H
#include "PacManBoard.h"
#include "Player.h"
#include <string>
#include <deque>

class EnemyUnits {
    PacManBoard &board;
    Player &p1;
    enum direction dir;
    std::deque<std::pair<int,int>> ghostCords;
public:
    EnemyUnits(PacManBoard &b, Player &p);
    void moveGhost();
    void moveGhost2();
    int getFirstGhostCords(int x) const;
    int getSecondGhostCords(int y) const;
    enum direction randDirection();
    bool isPlayerHere();
    void killUnit();
    enum direction getDirection() const;


};


#endif //PACMAN2_ENEMYUNITS_H
