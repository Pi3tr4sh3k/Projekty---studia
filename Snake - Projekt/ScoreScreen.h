#ifndef SNAKE2_SCORESCREEN_H
#define SNAKE2_SCORESCREEN_H
#include "Score.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Snake.h"
#include <sstream>
class ScoreScreen {
    sf::RectangleShape field;
    sf::Font font;
    sf::Text text;
    int fieldWidth=100;
    int fieldHeight=50;
    std::vector<int>score;
    Snake &snake;
    sf::Text text2;
public:
    ScoreScreen(Snake &s);
    void View();
};


#endif //SNAKE2_SCORESCREEN_H
