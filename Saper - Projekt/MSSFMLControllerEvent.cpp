
#include "MSSFMLControllerEvent.h"
#include <SFML/Graphics.hpp>
MSSFMLControllerEvent::MSSFMLControllerEvent(MinesweeperBoard &b, MSSFMLView &w): board (b), widok (w){

}
void MSSFMLControllerEvent::handleEvent(sf::Event & event) {
        int x, y;
        for(int i=0;i<board.getBoardHeight();i++){
            for(int j=0;j<board.getBoardWidth();j++){
                x=(widok.getSize()+400)+(widok.getSize()+10)*j;
                y=(widok.getSize()+300)+(widok.getSize()+10)*i;
                if(event.mouseButton.button==1 && event.mouseButton.x>=x && event.mouseButton.y>=y && event.mouseButton.x<x+widok.getSize() && event.mouseButton.y<y+widok.getSize())
                    board.toggleFlag(i,j);
                if(event.mouseButton.button==0 && event.mouseButton.x>=x && event.mouseButton.y>=y && event.mouseButton.x<x+widok.getSize() && event.mouseButton.y<y+widok.getSize())
                    board.revealField(i,j);
            }
        }
}