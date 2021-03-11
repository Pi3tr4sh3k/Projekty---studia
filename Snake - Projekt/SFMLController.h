

#ifndef SNAKE2_SFMLCONTROLLER_H
#define SNAKE2_SFMLCONTROLLER_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "SFMLView.h"
#include "SBoard.h"
namespace sf{
    class Event;
}
class SBoard;
class SFMLView;
class Snake;
class SFMLController {
    SBoard &board;
    Snake &snake;
    SFMLView &view;
public:
    SFMLController(SBoard &b, Snake &s, SFMLView &v);
    void handleEvent(sf::Event &event);


};


#endif //SNAKE2_SFMLCONTROLLER_H
