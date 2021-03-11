//
// Created by pfrei on 26.03.2020.
//

#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H

#include "MinesweeperBoard.h"
class MSBoardTextView{
    MinesweeperBoard & plansza;
    int wys;
    int szer;

public:
    void display();
    explicit MSBoardTextView(MinesweeperBoard & plansza_przyklad);
};







#endif //SAPER_MSBOARDTEXTVIEW_H
