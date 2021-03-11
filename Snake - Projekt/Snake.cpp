
#include <cstdlib>
#include "Snake.h"
#include <ctime>
#include <deque>
Snake::Snake(SBoard &b): board(b) {
    state=RUNNING;
    int randX,randY;
    srand(time(0));
    randX=rand()%5;
    randY=rand()%5;
    SnakeBody.push_back(std::make_pair(0,1));
    SnakeBody.push_front(std::make_pair(0,0));
    direction=2;
    pastDirection=3;

}

int Snake::getSnakeSize() const {
    return SnakeBody.size();
}

int Snake::getFirstSnakeCords(int index) const {
    return SnakeBody[index].first;
}

int Snake::getSecondSnakeCords(int index) const {
    return SnakeBody[index].second;
}

void Snake::moveSneakRight() {
    int length = SnakeBody.size()-1;
    tempX=SnakeBody[length].first;
    tempY=SnakeBody[length].second;
    if(tempX==FoodCords[0].first && tempY==FoodCords[0].second){
        FoodCords.clear();
        SnakeBody.push_back(std::make_pair(tempX, tempY + 1));
        randFoodCords();
        score+=100;
    }
    else{
        SnakeBody.pop_front();
        SnakeBody.push_back(std::make_pair(tempX, tempY + 1));
    }
    direction=2;
}

void Snake::moveSneakLeft() {
    int length = SnakeBody.size()-1;
    tempX = SnakeBody[length].first;
    tempY = SnakeBody[length].second;
    if(tempX==FoodCords[0].first && tempY==FoodCords[0].second){
        FoodCords.clear();
        SnakeBody.push_back(std::make_pair(tempX, tempY - 1));
        randFoodCords();
        score+=100;
    }

    else{
        SnakeBody.pop_front();
        SnakeBody.push_back(std::make_pair(tempX, tempY - 1));
    }
    direction=3;

}

void Snake::moveSneakDown(){
    int length = SnakeBody.size()-1;
    tempX=SnakeBody[length].first;
    tempY=SnakeBody[length].second;
    if(tempX==FoodCords[0].first && tempY==FoodCords[0].second) {
        FoodCords.clear();
        SnakeBody.push_back(std::make_pair(tempX + 1, tempY));
        randFoodCords();
        score+=100;
    }
    else{
        SnakeBody.pop_front();
        SnakeBody.push_back(std::make_pair(tempX+1,tempY));
    }
    direction=4;

}

void Snake::moveSneakUp() {
    int length = SnakeBody.size()-1;
    tempX = SnakeBody[length].first;
    tempY = SnakeBody[length].second;
    if(tempX==FoodCords[0].first && tempY==FoodCords[0].second){
        FoodCords.clear();
        SnakeBody.push_back(std::make_pair(tempX-1, tempY));
        randFoodCords();
        score+=100;
    }
    else{
        SnakeBody.pop_front();
        SnakeBody.push_back(std::make_pair(tempX-1, tempY));
    }
    direction=1;

}


void Snake::randFoodCords() {
    int valX, valY;
    bool var = false;
    srand(time(0));
    while(!var) {
        valX = rand() % board.getWidth();
        valY = rand() % board.getHeight();
        for(int i=0;i<getSnakeSize();i++){
            if(SnakeBody[i].first==valY && SnakeBody[i].second==valX){
                var=false;
                break;
            }
            else{
                var=true;
            }
        }
    }

    FoodCords.push_back(std::make_pair(valY,valX));

}

int Snake::getSecondFoodCords(int index) const {
    return FoodCords[index].second;
}

int Snake::getFirstFoodCords(int index) const {
    return FoodCords[index].first;
}

bool Snake::isColliding() {
    int len=SnakeBody.size()-1;
    bool headSnack=false;
    bool headOnWall=false;
    for(int i=0;i<len;i++){
        if(SnakeBody[len].first==SnakeBody[i].first && SnakeBody[len].second==SnakeBody[i].second)
            headSnack=true;
    }
    if(SnakeBody[len].first>=board.getHeight() || SnakeBody[len].second>=board.getWidth() || SnakeBody[len].first<0 || SnakeBody[len].second<0)
        headOnWall=true;
    if(headOnWall || headSnack) {
        return true;
        state=FINISHED;
    }
    else
        return false;


}

int Snake::getSnakeDir() const {
    return direction;
}

void Snake::moveSneak() {
    if(getSnakeDir()==1)
        moveSneakUp();
    else if(getSnakeDir()==2)
        moveSneakRight();
    else if(getSnakeDir()==3)
        moveSneakLeft();
    else if(getSnakeDir()==4)
        moveSneakDown();
}

GameState Snake::getGameState() {
    if(isColliding())
        return FINISHED;
}

void Snake::setDirection(int d) {
    direction=d;
}

int Snake::getScore() const{
    return score;
}




