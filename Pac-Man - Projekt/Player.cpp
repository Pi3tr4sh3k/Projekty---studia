

#include <algorithm>
#include "Player.h"
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <iostream>
Player::Player(PacManBoard &b):board(b) {
    PacMan.push_back(std::make_pair(8,11));
    charge=0;
    dir=RIGHT;
    pastDir=RIGHT;

    PointsCords.push_back(std::make_pair(1,1));
    PointsCords.push_back(std::make_pair(15,13));
    PointsCords.push_back(std::make_pair(1,13));
    PointsCords.push_back(std::make_pair(15,1));


}
int Player::getPacManFirstCords(int x) const {
    return PacMan[x].first;

}
int Player::getPacManSecondCords(int y) const {
    return PacMan[y].second;
}

void Player::movePlayer() {
    int x=PacMan[0].first;
    int y=PacMan[0].second;
    isTurnPossible();
    if(dir==UP && board.getFieldInfo(x,y-1)!='W'){
        PacMan.push_front(std::make_pair(x,y-1));
        PacMan.pop_back();

        if(board.getFieldInfo(x,y-1)=='.')
            score++;
        if(board.getFieldInfo(x,y-1)=='*')
            score+=10;
        if(board.getFieldInfo(x,y)!='C')
            board.setFieldStatus(x, y, 'C');


    }

    if(dir==RIGHT && board.getFieldInfo(x+1,y)!='W' && board.getFieldInfo(x+1,y)!='S'){
        PacMan.push_front(std::make_pair(x+1,y));
        PacMan.pop_back();
        if(board.getFieldInfo(x+1,y)=='.')
            score++;
        if(board.getFieldInfo(x+1,y)=='*')
            score+=10;
        if(board.getFieldInfo(x+1,y)!='C')
            board.setFieldStatus(x, y, 'C');
    }

    if(dir==LEFT &&  board.getFieldInfo(x-1,y)!='W' &&  board.getFieldInfo(x-1,y)!='S'){
        PacMan.push_front(std::make_pair(x-1,y));
        PacMan.pop_back();
        if(board.getFieldInfo(x-1,y)=='.')
            score++;
        if(board.getFieldInfo(x-1,y)=='*')
            score+=10;
        if(board.getFieldInfo(x,y)!='C')
            board.setFieldStatus(x, y, 'C');

    }


    if(dir==DOWN &&  board.getFieldInfo(x,y+1)!='W' &&  board.getFieldInfo(x,y+1)!='S'){
        PacMan.push_front(std::make_pair(x,y+1));
        PacMan.pop_back();
        if(board.getFieldInfo(x,y+1)=='.')
            score++;
        if(board.getFieldInfo(x,y+1)=='*')
            score+=10;
        if(board.getFieldInfo(x,y)!='C')
            board.setFieldStatus(x, y, 'C');
    }

    if(closeJapa==false)

        closeJapa=true;
    else
        closeJapa=false;
    if(isBoost())
        ++charge;
}

enum direction Player::getDirection() const {
    return dir;
}

void Player::changeDirection(int x) {
    int posX=PacMan[0].first;
    int posY=PacMan[0].second;
    if(x==1) {
        pastDir = UP;
        if(board.getFieldInfo(posX,posY-1)!='W')
            dir = UP;
    }
    if(x==2) {
        pastDir = RIGHT;
        if(board.getFieldInfo(posX+1,posY)!='W')
            dir = RIGHT;
    }
    if(x==3) {
        pastDir = LEFT;
        if(board.getFieldInfo(posX-1,posY)!='W')
            dir = LEFT;
    }
    if(x==4){
        pastDir = DOWN;
        if(board.getFieldInfo(posX,posY+1)!='W' && board.getFieldInfo(posX,posY+1)!='S')
            dir = DOWN;
    }

}

int Player::getScore() const{
    return score;
}

bool Player::isBoost(){
    int len=PointsCords.size()-1;
    do{

        if(PointsCords[len].first==PacMan[0].first && PointsCords[len].second==PacMan[0].second) {
            PointsCords[len].first=0;
            PointsCords[len].second=0;
            return true;

        }
        --len;
    }while(len>=0);
    return false;
}

int Player::getFirstPointsCords(int index) const {
    return PointsCords[index].first;
}

int Player::getSecondPointsCords(int index) const {
    return PointsCords[index].second;
}

void Player::isTurnPossible(){
    int x=PacMan[0].first;
    int y=PacMan[0].second;
    if(pastDir==UP && board.getFieldInfo(x,y-1)!='W'){
        dir=pastDir;
    }
    else if(pastDir==RIGHT && board.getFieldInfo(x+1,y)!='W'){
        dir=pastDir;
    }
    else if(pastDir==LEFT && board.getFieldInfo(x-1,y)!='W'){
        dir=pastDir;
    }
    else if(pastDir==DOWN && board.getFieldInfo(x,y+1)!='W' && board.getFieldInfo(x,y+1)!='S'){
        dir=pastDir;
    }
}

bool Player::isJapaOpen() const {
    return closeJapa;
}

int Player::getCharge() const {
    return charge;
}

void Player::updateCharge(int value) {
    charge=charge-value;
}











