#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H


class MSTextController {
    MinesweeperBoard &plansza;
    MSBoardTextView &showtime;

public:
    MSTextController(MinesweeperBoard &p, MSBoardTextView &show);
    void play();

};



#endif //SAPER_MSTEXTCONTROLLER_H
