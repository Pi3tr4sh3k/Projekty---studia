#include "SBoard.h"
#include "Snake.h"
#include "SnakeDisplay.h"
#include <SFML/Graphics.hpp>
#include "SFMLView.h"
#include "SFMLController.h"
#include "WelcomeScreen.h"
#include "Score.h"
#include "ScoreScreen.h"
int main() {
    SBoard board;
    Snake snake(board);
    WelcomeScreen screen;
    float lvl = screen.mode();
    snake.randFoodCords();
    SnakeDisplay wys(board, snake);
    SFMLView view(board, snake);
    bool czy=false;
    sf::Clock clk;
    wys.display();
    sf::RenderWindow win(sf::VideoMode(800,640),"Snake", sf::Style::Close);
    win.setVerticalSyncEnabled(true);
    SFMLController ctrl(board,snake,view);
    while(win.isOpen()){
        sf::Event event;
        while(win.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                win.close();
                continue;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
            ctrl.handleEvent(event);
        }
        win.clear(sf::Color::Black);
        if(!snake.isColliding()){
            if(clk.getElapsedTime().asSeconds()>lvl) {
                if (snake.getSnakeDir() == 1)
                    snake.moveSneakUp();
                else if (snake.getSnakeDir() == 2)
                    snake.moveSneakRight();
                else if (snake.getSnakeDir() == 3)
                    snake.moveSneakLeft();
                else if (snake.getSnakeDir() == 4)
                    snake.moveSneakDown();
            clk.restart();
        }
        }
        view.draw(win);
        win.display();
    }
    Score score(snake);
    score.saveScore();
    ScoreScreen koniec(snake);
    koniec.View();
    return 0;
}
