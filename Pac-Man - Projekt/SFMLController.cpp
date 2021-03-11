

#include "SFMLController.h"
#include <SFML/Graphics.hpp>
SFMLController::SFMLController(PacManBoard &board1, Player &p, EnemyUnits &u1, EnemyUnits &u2, SFMLView &v): board(board1), p1(p), unit1(u1), unit2(u2), view(v){

}

void SFMLController::handleEvent(sf::Event event) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            p1.changeDirection(1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            p1.changeDirection(2);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            p1.changeDirection(3);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            p1.changeDirection(4);

}
