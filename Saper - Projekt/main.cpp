#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MSSFMLView.h"
#include"MSSFMLControllerEvent.h"
#include "WelcomeScreen.h"
int main() {
    GameMode mode;
    WelcomeScreen screen;
    mode=screen.Tryb();
    MinesweeperBoard board (20,10,mode);
    //MSBoardTextView view (board);
    MSSFMLView view(board);
    sf::RenderWindow win(sf::VideoMode(1920,1080), "Ser",sf::Style::Fullscreen);
    //view.display();
    win.setVerticalSyncEnabled(true);
    MSSFMLControllerEvent ctrl(board,view);
    while(win.isOpen()){
        sf::Event event;
        while(win.pollEvent(event)){
            if(event.type==sf::Event::Closed) {
                win.close();
                continue;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                win.close();
            }
             ctrl.handleEvent(event);
        }
        win.clear();
        view.draw(win);
        win.display();
    }
    return 0;
}
