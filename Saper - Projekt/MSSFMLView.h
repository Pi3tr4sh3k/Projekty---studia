
#ifndef SAPER_MSSFMLVIEW_H
#define SAPER_MSSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MinesweeperBoard.h"

class MSSFMLView {
    MinesweeperBoard &board;
    sf::RectangleShape pole;
    int sizePx=40;
    sf::Font font;
    sf::Texture tekstura;
    sf::Sprite flaga;
    sf::Text tekst;
    sf::Texture for_bomb;
    sf::Sprite coffin;
    sf::Text wilkommen;
    sf::Text legend;
public:
    explicit MSSFMLView(MinesweeperBoard &b);
    int getSize()const;
    void draw (sf::RenderWindow &win);
};


#endif //SAPER_MSSFMLVIEW_H
