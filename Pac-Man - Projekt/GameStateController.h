

#ifndef PACMAN2_GAMESTATECONTROLLER_H
#define PACMAN2_GAMESTATECONTROLLER_H

#include "PacManBoard.h"
#include "EnemyUnits.h"
#include "Player.h"
enum GameState {WIN,LOSE,RUNNING};
class PacManBoard;
class Player;
class EnemyUnits;

class GameStateController {
    PacManBoard &board;
    Player &p1;
    EnemyUnits &unit1;
    EnemyUnits &unit2;
public:
    GameStateController(PacManBoard &b, Player &p, EnemyUnits &u1, EnemyUnits &u2);
    GameState getGameState()const;
};


#endif //PACMAN2_GAMESTATECONTROLLER_H
