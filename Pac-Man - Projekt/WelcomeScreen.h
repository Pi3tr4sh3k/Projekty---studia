
#ifndef PACMAN2_WELCOMESCREEN_H
#define PACMAN2_WELCOMESCREEN_H
#include <SFML/Graphics.hpp>

class WelcomeScreen {
    sf::RectangleShape field;
    sf::Font font;
    sf::Text text;
    sf::Texture logo_texture;
    sf::Sprite logo;
public:
    WelcomeScreen();
    void welcome();
};


#endif //PACMAN2_WELCOMESCREEN_H
