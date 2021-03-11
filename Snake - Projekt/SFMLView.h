
#ifndef SNAKE2_SFMLVIEW_H
#define SNAKE2_SFMLVIEW_H
#include <SFML/Graphics.hpp>
#include "SBoard.h"
#include "Snake.h"
#include <sstream>

class SFMLView {
    SBoard &board;
    Snake &snake;

    sf::RectangleShape pole;
    int sizePx=30;
    sf::Font font;
    sf::Text text;
    int posX, posY;
    int snakeLength;
public:
    SFMLView(SBoard &b, Snake &s);
    int getSize() const;
    void draw(sf::RenderWindow &win);


};


#endif //SNAKE2_SFMLVIEW_H
