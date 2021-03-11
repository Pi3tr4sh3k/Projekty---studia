
#include "WelcomeScreen.h"
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>
WelcomeScreen::WelcomeScreen() {
    if(!font.loadFromFile("../font.ttf")){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    field=sf::RectangleShape(sf::Vector2f(fieldWidth,fieldHeight));
    text.setFont(font);
    text.setCharacterSize(50);
    field.setFillColor(sf::Color(255,0,0));

}

float WelcomeScreen::mode() {
    int constexpr width=840;
    int constexpr height=600;
    sf::Event event;
    sf::RenderWindow screen(sf::VideoMode(width, height),"Menu",sf::Style::Close);
    screen.setVerticalSyncEnabled(true);
    while (screen.isOpen()){

        while(screen.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                screen.close();
                continue;
            }
//            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) cele diagnostyczne
//                screen.close();
            if(event.mouseButton.button == 0 && event.mouseButton.x >= 325 && event.mouseButton.x <= 325+fieldWidth && event.mouseButton.y >= 100 && event.mouseButton.y <= 100+fieldHeight)
                return 0.25;
            if (event.mouseButton.button == 0 && event.mouseButton.x >= 325 && event.mouseButton.x <= 325+fieldWidth && event.mouseButton.y >= 250 && event.mouseButton.y <= 250+fieldHeight)
                return 0.1;
            if (event.mouseButton.button == 0 && event.mouseButton.x >= 325 && event.mouseButton.x <= 325+fieldWidth && event.mouseButton.y >= 400 && event.mouseButton.y <= 400+fieldHeight)
                return 0.05;
            screen.clear(sf::Color::Black);
            text.setCharacterSize(15);
            text.setString("Select level of difficulty");
            text.setPosition(300,25);
            screen.draw(text);

            field.setFillColor(sf::Color(131, 201, 8));
            text.setString("ADEPT");
            text.setPosition(400, 140);
            field.setPosition(325, 100);
            screen.draw(field);
            screen.draw(text);

            field.setFillColor(sf::Color(95, 118, 186));
            text.setString("PADAWAN");
            text.setPosition(390, 290);
            field.setPosition(325, 250);
            screen.draw(field);
            screen.draw(text);

            field.setFillColor(sf::Color(222, 38, 96));
            text.setString("JEDI MASTER");
            text.setPosition(375,440);
            field.setPosition(325, 400);
            screen.draw(field);
            screen.draw(text);
            screen.display();



        }
    }

}
