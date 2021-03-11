
#ifndef PACMAN2_SFMLCONTROLLER_H
#define PACMAN2_SFMLCONTROLLER_H
#include "PacManBoard.h"
#include "Player.h"
#include "EnemyUnits.h"
#include "SFMLView.h"
#include <SFML/Graphics.hpp>

namespace sf{
    class Event;

}
class PacManBoard;
class SFMLView;
class Player;
class EnemyUnits;

class SFMLController {
    PacManBoard &board;
    Player &p1;
    EnemyUnits &unit1;
    EnemyUnits &unit2;
    SFMLView &view;
public:
    SFMLController(PacManBoard &board1, Player &p, EnemyUnits &u1, EnemyUnits &u2, SFMLView &v);
    void handleEvent(sf:: Event event);


};


#endif //PACMAN2_SFMLCONTROLLER_H
