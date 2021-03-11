
#include <cstring>
#include <iostream>
#include "SFMLView.h"
#include <sstream>
int SFMLView::getSize() const {
    return sizePx;
}

SFMLView::SFMLView(SBoard &b, Snake &s): board(b), snake(s) {
    if(!font.loadFromFile("../font.ttf"))
    {
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    pole=sf::RectangleShape(sf::Vector2f(getSize(),getSize()));
    text.setFont(font);
    text.setCharacterSize(50);
}

void SFMLView::draw(sf::RenderWindow &win) {
    std::stringstream sc;
    snakeLength=snake.getSnakeSize()-2;
    int len=snake.getSnakeSize()-1;
    char board_temp[board.getHeight()][board.getWidth()];
    text.setPosition(400, 150);
    text.setCharacterSize(20);
    text.setString("Press esc to exit the game");
    win.draw(text);
    text.setPosition(400,170);
    text.setString("Up - to move up");
    win.draw(text);
    text.setPosition(400,190);
    text.setString("Left - to move left");
    win.draw(text);
    text.setPosition(400,210);
    text.setString("Right - to move right");
    win.draw(text);
    text.setPosition(400,230);
    text.setString("Down - to move down");
    win.draw(text);
    sc << snake.getScore();
    text.setPosition(400,50);
    text.setCharacterSize(50);
    text.setString("Score: ");
    win.draw(text);
    text.setPosition(600,50);
    text.setString(sc.str());
    win.draw(text);

        for(int i=0;i<board.getHeight();i++){
            for(int j=0;j<board.getWidth();j++){
            board_temp[i][j]=' ';
            }
        }

    do{
        for(int i=0;i<board.getHeight();i++){
            for(int j=0;j<board.getWidth();j++){
                if(snake.getFirstSnakeCords(snakeLength)==i && snake.getSecondSnakeCords(snakeLength)==j)
                    board_temp[i][j]='W';
                else if(snake.getFirstFoodCords(0)==i && snake.getSecondFoodCords(0)==j)
                    board_temp[i][j]='A';
                if(snake.getFirstSnakeCords(len)==i && snake.getSecondSnakeCords(len)==j)
                    board_temp[i][j]='G';
            }
        }
        --snakeLength;

    }while(snakeLength>=0);
    if(snake.isColliding()){
        text.setPosition(400,400);
        text.setCharacterSize(50);
        text.setString("Game Over");
        win.draw(text);
        text.setCharacterSize(20);
        text.setPosition(400,460);
        text.setString("Press 'ESC' to exit the game");
        win.draw(text);
    }


    for(int i=0;i<board.getHeight();i++){
        for(int j=0;j<board.getWidth();j++){
            posX=getSize()+(getSize()+5)*j;
            posY=getSize()+(getSize()+5)*i;
            pole.setPosition(posX+5,posY+5);
            if (board_temp[i][j]=='A') {
                pole.setFillColor(sf::Color(255, 0, 0));
                win.draw(pole);
            }
            else if(board_temp[i][j]==' '){
                pole.setFillColor(sf::Color(28, 28, 24));
                win.draw(pole);
            }
            else if(board_temp[i][j]=='G'){
                pole.setFillColor(sf::Color(87, 87, 23));
                win.draw(pole);
            }
            else if(board_temp[i][j]=='W'){
                pole.setFillColor(sf::Color(135, 135, 53));
                win.draw(pole);
            }

        }
    }


}

