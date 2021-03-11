

#include "GameStateController.h"

GameStateController::GameStateController(PacManBoard &b, Player &p, EnemyUnits &u1, EnemyUnits &u2):board(b),p1(p),unit1(u1),unit2(u2) {

}

GameState GameStateController::getGameState() const {
    int temp=0;
    if((p1.getPacManFirstCords(0)!=unit1.getFirstGhostCords(0) && p1.getPacManSecondCords(0)!=unit1.getSecondGhostCords(0)) || (p1.getPacManFirstCords(0)!=unit2.getFirstGhostCords(0) && p1.getPacManSecondCords(0)!=unit2.getSecondGhostCords(0))) {
        for (int i = 0; i < board.getHeight(); i++) {
            for (int j = 0; j < board.getWidth(); j++) {
                if (board.getFieldInfo(j, i) == '.' || board.getFieldInfo(j, i) == '*')
                    temp++;

            }
        }

        if (temp==0)
            return WIN;
    }
    if((p1.getPacManFirstCords(0)==unit1.getFirstGhostCords(0) && p1.getPacManSecondCords(0)==unit1.getSecondGhostCords(0)) || (p1.getPacManFirstCords(0)==unit2.getFirstGhostCords(0) && p1.getPacManSecondCords(0)==unit2.getSecondGhostCords(0))) {
        if(p1.getCharge()==0)
            return LOSE;
        else
            return RUNNING;
    }
    return RUNNING;
}
