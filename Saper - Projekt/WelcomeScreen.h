#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MinesweeperBoard.h"
#ifndef SAPER_WELCOMESCREEN_H
#define SAPER_WELCOMESCREEN_H


class WelcomeScreen {
    GameMode tryb;
    sf::RectangleShape pole;
    sf::Font font;
    sf::Text tekst;
    int sizePx=50;
    int recwidth=500;
    int recheight=200;
public:
    GameMode Tryb();
    WelcomeScreen();


};


#endif //SAPER_WELCOMESCREEN_H
