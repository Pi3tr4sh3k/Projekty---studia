#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#ifndef SAPER_MSSFMLCONTROLLEREVENT_H
#define SAPER_MSSFMLCONTROLLEREVENT_H

namespace sf{
    class Event;
}
class Minesweeperboard;
class MSSFMLView;
class MSSFMLControllerEvent {
    MinesweeperBoard & board;
    MSSFMLView & widok;
public:
    MSSFMLControllerEvent(MinesweeperBoard &b, MSSFMLView & w);
    void handleEvent(sf::Event & event);
};


#endif //SAPER_MSSFMLCONTROLLEREVENT_H
