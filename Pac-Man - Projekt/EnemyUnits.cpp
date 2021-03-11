
#include "EnemyUnits.h"
#include <cstdlib>
#include<ctime>
EnemyUnits::EnemyUnits(PacManBoard &b, Player &p):board(b),p1(p) {
    srand(time(NULL));
    ghostCords.push_back(std::make_pair(8,9));
    dir=UP;
}


void EnemyUnits::moveGhost() {
    killUnit();
    int x=ghostCords[0].first;
    int y=ghostCords[0].second;



        if (dir == UP) {

            if (board.getFieldInfo(x, y - 1) != 'W') {
                ghostCords.pop_front();
                ghostCords.push_back(std::make_pair(x, y - 1));

            } else
                dir = randDirection();
        }
        if (dir == RIGHT) {

            if (board.getFieldInfo(x + 1, y) != 'W') {
                ghostCords.pop_front();
                ghostCords.push_back(std::make_pair(x + 1, y));
            } else
                dir = randDirection();
        }
        if (dir == LEFT) {

            if (board.getFieldInfo(x - 1, y) != 'W') {
                ghostCords.pop_front();
                ghostCords.push_back(std::make_pair(x - 1, y));

            } else
                dir = randDirection();
        }
        if (dir == DOWN) {

            if (board.getFieldInfo(x, y + 1) != 'W') {
                ghostCords.pop_front();
                ghostCords.push_back(std::make_pair(x, y + 1));

            } else
                dir = randDirection();
        }



}

int EnemyUnits::getFirstGhostCords(int x) const {
    return ghostCords[x].first;
}

int EnemyUnits::getSecondGhostCords(int y) const {
    return ghostCords[y].second;
}

enum direction EnemyUnits::randDirection() {

    int dirRand=0;
    dirRand=std::rand()%4;
    if(dirRand==0)
        return UP;
    if(dirRand==1)
        return RIGHT;
    if(dirRand==2)
        return LEFT;
    if(dirRand==3)
        return DOWN;
return STOP;
}

void EnemyUnits::moveGhost2() {
    killUnit();
    int x=ghostCords[0].first;
    int y=ghostCords[0].second;

    if(x==p1.getPacManFirstCords(0) && y<p1.getPacManSecondCords(0))
        dir=DOWN;
    else if(x==p1.getPacManFirstCords(0) && y>p1.getPacManSecondCords(0))
        dir=UP;
    else if(y==p1.getPacManSecondCords(0) && x<p1.getPacManFirstCords(0))
        dir=RIGHT;
    else if(y==p1.getPacManSecondCords(0) && x>p1.getPacManFirstCords(0))
        dir=LEFT;

        if (dir == UP) {

            if (board.getFieldInfo(x, y - 1) != 'W') {

                ghostCords.push_back(std::make_pair(x, y - 1));
                ghostCords.pop_front();
            } else
                dir = randDirection();
        } else if (dir == RIGHT) {

            if (board.getFieldInfo(x + 1, y) != 'W') {

                ghostCords.push_back(std::make_pair(x + 1, y));
                ghostCords.pop_front();
            } else
                dir = randDirection();
        } else if (dir == LEFT) {
            if (board.getFieldInfo(x - 1, y) != 'W') {
                ghostCords.push_back(std::make_pair(x - 1, y));
                ghostCords.pop_front();
            } else
                dir = randDirection();
        } else if (dir == DOWN) {

            if (board.getFieldInfo(x, y + 1) != 'W') {
                ghostCords.push_back(std::make_pair(x, y + 1));
                ghostCords.pop_front();
            } else
                dir = randDirection();
        }

    killUnit();
}

bool EnemyUnits::isPlayerHere(){
    return ghostCords[0].first == p1.getPacManFirstCords(0) && ghostCords[0].second == p1.getPacManSecondCords(0);
}

void EnemyUnits::killUnit() {
    if(p1.getCharge()>=1)
    {
        if(getFirstGhostCords(0)==p1.getPacManFirstCords(0) && getSecondGhostCords(0)==p1.getPacManSecondCords(0)) {
            ghostCords.pop_front();
            ghostCords.push_back(std::make_pair(8,9));
            p1.updateCharge(1);

        }
    }
}

enum direction EnemyUnits::getDirection() const {
    return dir;
}
