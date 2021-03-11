
#ifndef SNAKE2_WELCOMESCREEN_H
#define SNAKE2_WELCOMESCREEN_H
#include <SFML/Graphics.hpp>

class WelcomeScreen {
    sf::RectangleShape field;
    sf::Font font;
    sf::Text text;
    int fieldWidth=200;
    int fieldHeight=100;
public:
    WelcomeScreen();
    float mode();
};


#endif //SNAKE2_WELCOMESCREEN_H
