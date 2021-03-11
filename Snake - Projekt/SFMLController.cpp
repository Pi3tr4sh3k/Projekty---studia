
#include "SFMLController.h"

SFMLController::SFMLController(SBoard &b, Snake &s, SFMLView &v):board(b), snake(s), view(v) {

}

void SFMLController::handleEvent(sf::Event &event) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && snake.getSnakeDir()!=2)
        snake.setDirection(3);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && snake.getSnakeDir()!=3)
        snake.setDirection(2);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && snake.getSnakeDir()!=4)
        snake.setDirection(1);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && snake.getSnakeDir()!=1)
        snake.setDirection(4);
}
