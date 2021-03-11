//
// Created by pfrei on 19.04.2020.
//
#include "MinesweeperBoard.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "WelcomeScreen.h"
#include <cstring>
#include <iostream>
//int WelcomeScreen::getSize(int sizePx) {
//    return sizePx;
//}

WelcomeScreen::WelcomeScreen(){
    if(!font.loadFromFile("../final_font.ttf"))
    {
        std::cerr<<strerror(errno) << std::endl;
        abort();
    }
    pole=sf::RectangleShape(sf::Vector2f(recwidth,recheight));
    tekst.setFont(font);
    tekst.setCharacterSize(50);
    pole.setFillColor(sf::Color(255,0,0));

}
GameMode WelcomeScreen::Tryb() {
    int constexpr width=1920;
    int constexpr height = 1080;
    sf::Event event;

    sf::RenderWindow screen(sf::VideoMode(width,height),"Minesweeper lvl",sf::Style::Fullscreen);
    screen.setVerticalSyncEnabled(true);
    while(screen.isOpen()) {

        while (screen.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                screen.close();
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                screen.close();
            if (event.mouseButton.button == 0 && event.mouseButton.x >= 700 && event.mouseButton.x <= 700+recwidth &&
                event.mouseButton.y >= 200 && event.mouseButton.y <= 200+recheight)
                return easy;
            if (event.mouseButton.button == 0 && event.mouseButton.x >= 700 && event.mouseButton.x <= 700+recwidth &&
                event.mouseButton.y >= 500 && event.mouseButton.y <= 500+recheight)
                return medium;
            if (event.mouseButton.button == 0 && event.mouseButton.x >= 700 && event.mouseButton.x <= recwidth+700 &&
                event.mouseButton.y >= 700 && event.mouseButton.y <= 700+recheight)
                return hard;

            screen.clear(sf::Color::Black);
            tekst.setString("Select level of difficulty");
            tekst.setPosition(600, 100);
              screen.draw(tekst);

            tekst.setString("NOOB");
            tekst.setPosition(880, 270);
            pole.setPosition(700, 200);
            screen.draw(pole);
             screen.draw(tekst);

            tekst.setString("CASUAL PLAYER");
            tekst.setPosition(740, 570);
            pole.setPosition(700, 500);
            screen.draw(pole);
            screen.draw(tekst);

            tekst.setString("VETERAN");
            tekst.setPosition(830,870);
            pole.setPosition(700, 800);
            screen.draw(pole);
            screen.draw(tekst);
            screen.display();
        }
    }

}
