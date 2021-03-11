#include "MSTextController.h"
#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"

MSTextController::MSTextController(MinesweeperBoard &p, MSBoardTextView &show) : plansza(p), showtime(show)  {
}

void MSTextController::play() {
    int k, r;
    std::cout<<"Witaj w grze Saper! bum"<<::std::endl;;
    int naprzud;

    while(plansza.getGameState()==RUNNING){
        showtime.display();
        std::cout<<"Prosze wprowadzic rzad i kolumne"<<::std::endl;
        std::cin>>k;
        std::cin>>r;
        if(plansza.isOutside(k,r)){
            std::cout<<"Wybrane wspolrzedne znajduja sie poza plansza prosze wprowadzic raz jeszcze punkty zgodnie z przyjetymi zasadami"<<::std::endl;
            continue;
        }
        else{
            std::cout<<"Aby odslonic pole wybierz 1. Aby postawic flage wybierz 2"<<::std::endl;
            std::cin>>naprzud;
            switch (naprzud){
                case 1:
                    plansza.revealField(k,r);
                    break;
                case 2:
                    plansza.toggleFlag(k,r);
                    break;
                default:
                    std::cout<<"zostal wprowadzony zly numer"<<std::endl;
                    break;
            }

            if(plansza.getGameState()==LOSE) {
                showtime.display();
                std::cout << "Przegranko" << std::endl;
            }
            else if(plansza.getGameState()==WIN){
                showtime.display();
                std::cout<<"Wygranko"<<std::endl;
            }


        }
    }

}