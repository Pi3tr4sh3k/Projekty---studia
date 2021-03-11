#include <iostream>
#include <cstring>
#include "SFMLView.h"
#include <SFML/Graphics.hpp>
#include <sstream>
SFMLView::SFMLView(PacManBoard &b, Player &p, EnemyUnits &e1, EnemyUnits &e2, GameStateController &s):board(b),p1(p),enemy1(e1),enemy2(e2), state(s) {
    if(!wall_texture.loadFromFile("../wall.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!point_texture.loadFromFile("../point.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!boost_texture.loadFromFile("../boost.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!pacman_texture.loadFromFile("../pacman.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!pacman_eat_texture.loadFromFile("../pacman_eat.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!red_textureRL.loadFromFile("../redRL.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!red_textureUP.loadFromFile("../redUP1.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!red_textureDOWN.loadFromFile("../redDOWN.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!green_textureDOWN.loadFromFile("../greenDOWN.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!green_textureUP.loadFromFile("../greenUP.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!green_textureRL.loadFromFile("../greenRL.png",sf::IntRect(0,0,30,30))){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!font.loadFromFile("../font.ttf")){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    square=sf::RectangleShape(sf::Vector2f(getSquareSize(),getSquareSize()));
    text.setFont(font);
    text.setCharacterSize(20);
    text2.setFont(font);
    text2.setCharacterSize(10);
    pacman.setOrigin(15,15);
    pacman_eat.setOrigin(15,15);


}

int SFMLView::getSquareSize() const {
    return size;
}

void SFMLView::draw(sf::RenderWindow &win) {
    std::stringstream score;
    std::stringstream charges;
    charges<<p1.getCharge();
    score<<p1.getScore();
    text.setCharacterSize(20);
    text.setPosition(570,65);
    text.setString("Score: ");
    win.draw(text);
    text.setPosition(670,65);
    text.setString(score.str());
    win.draw(text);
    text.setString("Charges: ");
    text.setPosition(570,130);
    win.draw(text);
    text.setPosition(670,130);
    text.setString(charges.str());
    win.draw(text);





    for(int i = 0;i<board.getHeight();i++){
        for(int j = 0;j<board.getWidth();j++){
            if(j==p1.getPacManFirstCords(0) && i==p1.getPacManSecondCords(0))
                board.setFieldStatus(j,i,'P');
        }
    }



    for(int i = 0;i<board.getHeight();i++){
        for(int j=0;j<board.getWidth();j++){
            posX=getSquareSize()+getSquareSize()*j;
            posY=(getSquareSize()+getSquareSize()*i)+40;
            square.setPosition(posX,posY);
            wall.setPosition(posX,posY);
            point.setPosition(posX,posY);
            boost.setPosition(posX,posY);
            pacman.setPosition(posX+15,posY+15);
            pacman_eat.setPosition(posX+15,posY+15);
            red.setPosition(posX,posY);
            green.setPosition(posX,posY);
            if(board.getFieldInfo(j,i)=='.') {
                square.setFillColor(sf::Color(0, 0, 0));
                win.draw(square);
                point.setTexture(point_texture);
                win.draw(point);
            }

            else if(board.getFieldInfo(j,i)=='W'){
                wall.setTexture(wall_texture);
                win.draw(wall);
            }

            else if(board.getFieldInfo(j,i)=='*'){
                square.setFillColor(sf::Color(0, 0, 0));
                win.draw(square);
                boost.setTexture(boost_texture);
                win.draw(boost);
            }
            else if(board.getFieldInfo(j,i)=='S'){
                square.setFillColor(sf::Color(0,0,0));
                win.draw(square);
            }

            else if(board.getFieldInfo(j,i)=='P'){
                square.setFillColor(sf::Color(0,0,0));
                win.draw(square);
                if(p1.isJapaOpen()){
                    pacman.setTexture(pacman_texture);
                    if(p1.getDirection()==RIGHT)
                        pacman.setRotation(90);
                    else if(p1.getDirection()==DOWN)
                        pacman.setRotation(180);
                    else if(p1.getDirection()==LEFT)
                        pacman.setRotation(270);
                    else if(p1.getDirection()==UP)
                        pacman.setRotation(360);
                    win.draw(pacman);
                }
                else if(!p1.isJapaOpen())
                {
                    pacman_eat.setTexture(pacman_eat_texture);
                    if(p1.getDirection()==RIGHT)
                        pacman_eat.setRotation(90);
                    else if(p1.getDirection()==DOWN)
                        pacman_eat.setRotation(180);
                    else if(p1.getDirection()==LEFT)
                        pacman_eat.setRotation(270);
                    else if(p1.getDirection()==UP)
                        pacman_eat.setRotation(360);
                    win.draw(pacman_eat);
                }




            }

            else if(board.getFieldInfo(j,i)==' '){
                square.setFillColor(sf::Color(0,0,0));
                win.draw(square);
            }


            if(j==enemy2.getFirstGhostCords(0) && i==enemy2.getSecondGhostCords(0)){
                square.setFillColor(sf::Color(0,0,0));
                red.setTexture(red_textureRL);
                if(enemy2.getDirection()==LEFT){
                    red.setTextureRect(sf::IntRect(30,0,-30,30));
                }
                else if(enemy2.getDirection()==RIGHT)
                    red.setTextureRect(sf::IntRect(0,0,30,30));
                else if(enemy2.getDirection()==DOWN)
                    red.setTexture(red_textureDOWN);
                else
                    red.setTexture(red_textureUP);
                win.draw(red);

            }
            if(j==enemy1.getFirstGhostCords(0) && i==enemy1.getSecondGhostCords(0)){
                square.setFillColor(sf::Color(0,0,0));
                green.setTexture(green_textureRL);
                if(enemy1.getDirection()==LEFT)
                    green.setTextureRect(sf::IntRect(30,0,-30,30));
                else if(enemy1.getDirection()==RIGHT)
                    green.setTextureRect(sf::IntRect(0,0,30,30));
                else if(enemy1.getDirection()==DOWN)
                    green.setTexture(green_textureDOWN);
                else
                    green.setTexture(green_textureUP);
                win.draw(green);
            }


        }
    }
    if(state.getGameState()==LOSE)
    {
        text.setCharacterSize(30);
        text.setPosition(570,510);
        text.setFillColor(sf::Color(255, 255, 13));
        text.setString("Game Over");
        win.draw(text);
        text.setPosition(540,550);
        text.setCharacterSize(20);
        text.setString("Press \"Esc\" to exit");
        win.draw(text);
        text.setFillColor(sf::Color(255,255,255));
    }
    else if(state.getGameState()==WIN){
        text.setCharacterSize(30);
        text.setPosition(620,500);
        text.setFillColor(sf::Color(255, 255, 13));
        text.setString("WIN");
        win.draw(text);
        text.setPosition(540,550);
        text.setCharacterSize(20);
        text.setString("Press \"Esc\" to exit");
        win.draw(text);
        text.setFillColor(sf::Color(255,255,255));
    }

}
