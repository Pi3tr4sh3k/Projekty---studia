
#include <iostream>
#include "TextDisplay.h"

TextDisplay::TextDisplay(PacManBoard &b, Player &p, EnemyUnits &e, EnemyUnits &e2):board (b), p1(p), e1(e),e2(e2){
wys=board.getHeight();
szer=board.getWidth();

    for(int i = 0;i<wys;i++){
        for(int j = 0;j<szer;j++){
            if(j==p1.getPacManFirstCords(0) && i==p1.getPacManSecondCords(0))
                board.setFieldStatus(j,i,'P');
            }
        }
    for(int i = 0;i<wys;i++){
        for(int j = 0;j<szer;j++){
            if(j==e1.getFirstGhostCords(0) && i==e1.getSecondGhostCords(0))
                board.setFieldStatus(j,i,'E');
        }
    }
    for(int i = 0;i<wys;i++){
        for(int j = 0;j<szer;j++){
            if(j==e2.getFirstGhostCords(0) && i==e2.getSecondGhostCords(0))
                board.setFieldStatus(j,i,'E');
        }
    }

}
void TextDisplay::display() {
    for(int i=0;i<wys;i++){
        for(int j=0;j<szer;j++) {
            std::cout << "[" << board.getFieldInfo(j, i) << "]";
        }
        std::cout << std::endl;
    }
    std::cout<<"------------------------------------------"<<std::endl;
}

