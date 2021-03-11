
#ifndef PACMAN2_HSCORE_H
#define PACMAN2_HSCORE_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <sstream>

class HScore {
    Player &p1;
    std::vector<int>score;
    sf::RectangleShape field;
    sf::Font font;
    sf::Text text;
public:
    HScore(Player &p);
    void view();
};


#endif //PACMAN2_HSCORE_H
