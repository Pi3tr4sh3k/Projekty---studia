
#include "ScoreScreen.h"
#include <SFML/Graphics.hpp>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
ScoreScreen::ScoreScreen(Snake &s):snake(s) {
    if(!font.loadFromFile("../font.ttf")){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    field=sf::RectangleShape(sf::Vector2f(fieldWidth,fieldHeight));
    text.setFont(font);
    text2.setFont(font);
    text.setCharacterSize(50);
    field.setFillColor(sf::Color(255,0,0));
    std::ifstream read("score.txt");
    int pom=0;
    while(!read.eof()){
        read >> pom;
        score.push_back(pom);
    }
    read.close();
}

void ScoreScreen::View() {

    std::stringstream lastGame;
    lastGame<<snake.getScore();

    int constexpr width=840;
    int constexpr height=600;

    std::stringstream scoreString[10];
    for(int i=0;i<10;i++){
        scoreString[i] << score[i];
    }

    std::stringstream index[10];
    for(int i=0;i<10;i++){
        index[i] << i+1;
    }
    sf::Event event;

    sf::RenderWindow screen(sf::VideoMode(width, height),"Menu",sf::Style::Close);
    screen.setVerticalSyncEnabled(true);
    while (screen.isOpen()){
        while(screen.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                screen.close();
                continue;
            }
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                screen.close();
        }
        screen.clear(sf::Color::Black);

        text.setCharacterSize(35);
        text.setString("Hall of Fame");
        text.setPosition(300,25);
        screen.draw(text);
        text.setPosition(300,65);
        text.setCharacterSize(20);
        int pom=80;
        for(int i=0;i<10;i++){
            text.setPosition(395,pom+(50*i));
            text.setString(index[i].str()+". "+scoreString[i].str());
            screen.draw(text);
        }

        text.setPosition(50,500);
        text.setString("Your last score was: ");
        screen.draw(text);
        text2.setPosition(50,525);
        text2.setString(lastGame.str());
        screen.draw(text2);
        text2.setCharacterSize(15);
        text2.setColor(sf::Color(108, 145, 39));
        text2.setPosition(600,555);
        text2.setString("Press 'Enter' to exit");
        screen.draw(text2);

        screen.display();


}}
