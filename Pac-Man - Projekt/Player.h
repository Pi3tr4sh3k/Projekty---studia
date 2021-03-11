
#ifndef PACMAN2_PLAYER_H
#define PACMAN2_PLAYER_H
#include <deque>
#include "PacManBoard.h"
#include <vector>
#include <SFML/Graphics.hpp>
enum direction {UP,RIGHT,DOWN,LEFT,STOP};
class Player {
    PacManBoard &board;
    std::deque<std::pair<int,int>>PacMan;
    std::deque<std::pair<int,int>>PointsCords;
    int score=0;
    enum direction dir;
    enum direction pastDir;
    bool closeJapa=false;
    int charge;

public:
    Player(PacManBoard &b);
    int getPacManFirstCords(int x) const;
    int getScore() const;
    int getPacManSecondCords(int y) const;
    void movePlayer();
    enum direction getDirection()const;
    void changeDirection(int x);
    bool isBoost();
    void isTurnPossible();
    int getFirstPointsCords(int index)const;
    int getSecondPointsCords(int index)const;
    int countPoints() const;
    bool isJapaOpen() const;
    int getCharge() const;
    void updateCharge(int value);




};


#endif //PACMAN2_PLAYER_H
