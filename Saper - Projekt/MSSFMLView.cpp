#include <iostream>
#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstring>
int MSSFMLView::getSize() const {
    return sizePx;

}
MSSFMLView::MSSFMLView(MinesweeperBoard &b):board(b){
    if(!for_bomb.loadFromFile("../coffin.png",sf::IntRect(0,0,40,40)))
    {
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!tekstura.loadFromFile("../flagav2.png",sf::IntRect(0,0,40,40)))
    {
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!font.loadFromFile("../final_font.ttf"))
    {
        std::cerr<<strerror(errno) << std::endl;
        abort();
    }
    pole=sf::RectangleShape(sf::Vector2f(getSize(),getSize()));
    tekst.setFont(font);
    tekst.setCharacterSize(getSize());



}
void MSSFMLView::draw(sf::RenderWindow &win) {
        int positionX=0;
        int positionY=0;
        constexpr int align_x=400;
        constexpr int align_y=300;
        char pomocnicza;
        wilkommen.setFont(font);
        legend.setFont(font);
        legend.setString("Instruction:");
        legend.setPosition(800,50);
        win.draw(legend);
        legend.setString("Press 'esc' to exit");
        legend.setPosition(750,100);
        legend.setColor(sf::Color(255,0,0));
        win.draw(legend);
        legend.setString("Left click - reveal field");
        legend.setPosition(700,150);
        win.draw(legend);
        legend.setString("Right click - toggle flag");
        legend.setPosition(700,200);
        win.draw(legend);
        wilkommen.setString("Minesweeper");
        wilkommen.setPosition(800,0);
        win.draw(wilkommen);

        for(int i=0;i<board.getBoardHeight();i++){
            for(int j=0;j<board.getBoardWidth();j++){
                positionX=getSize()+(getSize()+10)*j;
                positionY=getSize()+(getSize()+10)*i;
                coffin.setPosition((positionX+getSize()/4)-10 + align_x,(positionY-getSize()/4) + 10 + align_y);
                flaga.setPosition((positionX+getSize()/4)-10 + align_x,(positionY-getSize()/4 + 10 + align_y));
                pole.setPosition(positionX + align_x,positionY + align_y);
                tekst.setPosition((positionX+getSize()/4)-1 + align_x,(positionY-getSize()/4) + 5 + align_y);
                if(board.getFieldInfo(i,j)==' ') {
                    tekst.setString("");
                    pole.setFillColor(sf::Color(0, 255, 0));
                    win.draw(pole);
                    win.draw(tekst);
                }
                else if(board.getFieldInfo(i,j)=='F'){
                    //tekst.setString("F");
                    flaga.setTexture(tekstura);

                    pole.setFillColor(sf::Color(0,0,100));
                    win.draw(pole);
                    win.draw(flaga);
                }
                else if(board.getFieldInfo(i,j)=='x'){
                   // tekst.setString("X");
                    coffin.setTexture(for_bomb);
                    pole.setFillColor(sf::Color(164,0,0));
                    win.draw(pole);
                    win.draw(coffin);
                   // win.draw(tekst);
                }
                else if(board.countMines(i,j)>0 && board.isRevealed(i,j)){
                    pomocnicza=board.countMines(i,j)+48;
                    tekst.setString(pomocnicza);
                    pole.setFillColor(sf::Color(255,0,0));
                    win.draw(pole);
                    win.draw(tekst);

                }
                else if(board.getFieldInfo(i,j)=='#'){
                    tekst.setString("#");
                    pole.setFillColor(sf::Color(255,255,255));
                    win.draw(pole);
                    win.draw(tekst);
                }
                else if(board.getFieldInfo(i,j)=='_'){
                    tekst.setString("");
                    pole.setFillColor(sf::Color(128,128,128));
                    win.draw(pole);
                    win.draw(tekst);
                }



            }

        }
   if(board.getGameState()==WIN){
       tekst.setString("GG WP");
       tekst.setPosition(0,200);
       win.draw(tekst);
       tekst.setString("Press 'Esc' to exit the game");
       tekst.setPosition(0,250);
       win.draw(tekst);
    }
    else if(board.getGameState()==LOSE){

        tekst.setString("Game Over");
        tekst.setPosition(0,200);
        win.draw(tekst);
        tekst.setString("Press 'Esc' to exit the game");
        tekst.setPosition(0,250);
        win.draw(tekst);

    }

}
