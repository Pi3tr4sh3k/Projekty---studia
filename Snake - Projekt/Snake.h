
#ifndef SNAKE2_SNAKE_H
#define SNAKE2_SNAKE_H
#include <deque>
#include "SBoard.h"
enum GameState {RUNNING, FINISHED};
class Snake {
    GameState state;
    std::deque<std::pair<int, int>> SnakeBody;
    int direction;
    int pastDirection;
    SBoard &board;
    int tempX, tempY;
    int score;
    std::deque<std::pair<int,int>> FoodCords;
public:
    explicit Snake(SBoard &b);
    int getSnakeSize() const;
    int getFirstSnakeCords(int index) const;
    int getSecondSnakeCords(int index) const;
    void moveSneakRight();
    void moveSneakLeft();
    void moveSneakDown();
    void moveSneakUp();
    void randFoodCords();
    int getFirstFoodCords(int index) const;
    int getSecondFoodCords(int index) const;
    bool isColliding();
    int getSnakeDir() const;
    void moveSneak();
    GameState getGameState();
    void setDirection(int d);
    int getScore() const;
};
#endif
