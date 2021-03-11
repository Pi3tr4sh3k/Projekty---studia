
#include <cstring>
#include "WelcomeScreen.h"
#include <SFML/Graphics.hpp>
#include <iostream>
WelcomeScreen::WelcomeScreen() {
    if(!font.loadFromFile("../font.ttf")){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    if(!logo_texture.loadFromFile("../logo.png")){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color(255, 255, 13));
    logo.setTexture(logo_texture);
}

void WelcomeScreen::welcome() {
    sf::Event event;
    sf::RenderWindow welcomeScreen(sf::VideoMode(800,600),"Pac-Man",sf::Style::Close);
    welcomeScreen.setVerticalSyncEnabled(true);
    while(welcomeScreen.isOpen()){
        welcomeScreen.clear(sf::Color(0,0,0));
        while(welcomeScreen.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                welcomeScreen.close();
                continue;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                welcomeScreen.close();
        }
            logo.setPosition(0,-50);
            welcomeScreen.draw(logo);
            text.setString("Press \"Enter\" to start the game");
            text.setPosition(120,300);
            welcomeScreen.draw(text);


            welcomeScreen.display();

    }
}
