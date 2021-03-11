#include <iostream>
#include "Player.h"
#include "PacManBoard.h"
#include "TextDisplay.h"
#include "EnemyUnits.h"
#include <SFML/Graphics.hpp>
#include "SFMLView.h"
#include "SFMLController.h"
#include "GameStateController.h"
#include "Score.h"
#include "HScore.h"
#include "WelcomeScreen.h"
int main() {
    PacManBoard board;

    Player p1(board);
    EnemyUnits ghost1(board,p1);
    EnemyUnits ghost2(board,p1);
    GameStateController state(board,p1,ghost1,ghost2);
    TextDisplay view(board,p1,ghost1,ghost2);
    view.display();

    //SFML Wyswietlanie
    sf::Clock clk;
    sf::Clock clk2;

    WelcomeScreen welcome;
    welcome.welcome();
    SFMLView winView(board,p1,ghost1,ghost2,state);
    SFMLController ctrl(board,p1,ghost1,ghost2,winView);
    sf::RenderWindow win(sf::VideoMode(800,600),"Pac-Man",sf::Style::Close);
    win.setVerticalSyncEnabled(1);

    while(win.isOpen()){
        sf::Event event;
        ctrl.handleEvent(event);
        while(win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
        }
        if(state.getGameState()==RUNNING) {
            if (clk2.getElapsedTime().asSeconds() > 0.2) {
                ghost1.moveGhost();
                ghost2.moveGhost2();
                clk2.restart();
            }
            if (clk.getElapsedTime().asSeconds() >0.1) {

                p1.movePlayer();
                clk.restart();
            }
        }
        win.clear(sf::Color(0,0,0));
        winView.draw(win);
        win.display();
    }
    Score score(p1);
    score.saveScore();
    HScore endScreen(p1);
    endScreen.view();
    return 0;


}
