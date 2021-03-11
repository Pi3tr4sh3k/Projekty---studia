//
// Created by pfrei on 26.03.2020.
//

#include "MSBoardTextView.h"
#include <iostream>
using namespace std;

MSBoardTextView::MSBoardTextView(MinesweeperBoard &plansza_przyklad): plansza(plansza_przyklad){
    wys=plansza.getBoardHeight();
    szer=plansza.getBoardWidth();
}

void MSBoardTextView::display(){
    for(int wysokosc=0;wysokosc<wys;wysokosc++){
        for(int szerokosc=0;szerokosc<szer;szerokosc++){
            cout<<"["<<plansza.getFieldInfo(wysokosc,szerokosc)<<"]";
        }
        cout<<endl;
    }
    cout<<"------------------------------------------------"<<endl;
}

