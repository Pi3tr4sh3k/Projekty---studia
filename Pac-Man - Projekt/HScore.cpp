

#include "HScore.h"
#include <sstream>
#include <fstream>
#include <cstring>
#include <iostream>
#include <SFML/Graphics.hpp>
HScore::HScore(Player &p):p1(p) {
    if(!font.loadFromFile("../font.ttf")){
        std::cerr<<strerror(errno)<<std::endl;
        abort();
    }
    field=sf::RectangleShape(sf::Vector2f(200,100));
    text.setFont(font);
    text.setCharacterSize(40);
    field.setFillColor(sf::Color(255, 255, 115));
    int temp=0;
    std::ifstream read("hscore.txt");
    while(!read.eof()){
        read>>temp;
        score.push_back(temp);
    }
    read.close();
}

void HScore::view() {
    std::stringstream lastScore;
    lastScore<<p1.getScore();
    std::stringstream scoreS[5];
    for(int i = 0;i<5;i++)
        scoreS[i]<<score[i];

    std::stringstream index[5];

    for(int i = 0; i<5;i++)
        index[i]<<i+1;

    sf::Event event;
    sf::RenderWindow scoreScreen(sf::VideoMode(800,600),"Pac-Man",sf::Style::Close);
    scoreScreen.setVerticalSyncEnabled(true);
    while(scoreScreen.isOpen()){
        while(scoreScreen.pollEvent(event)){
            if(event.type==sf::Event::Closed){
                scoreScreen.close();
                continue;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                scoreScreen.close();
        }
        scoreScreen.clear(sf::Color(0,0,0));
        text.setCharacterSize(35);
        text.setPosition(280,30);
        text.setOutlineThickness(2);
        text.setFillColor(sf::Color(201, 183, 58));
        text.setString("High Score");
        scoreScreen.draw(text);
        text.setPosition(305,200);
        text.setCharacterSize(25);
        text.setFillColor(sf::Color(0,0 , 0));
        int temp=150;
        for(int i=0;i<5;i++){
            if(i==0)
                text.setFillColor(sf::Color(255, 235, 82));
            else if(i==1)
                text.setFillColor(sf::Color(194, 194, 194));
            else if(i==2)
                text.setFillColor(sf::Color(87, 73, 40));
            else
                text.setFillColor(sf::Color(255,255,255));
            text.setPosition(340,temp+(50*i));
            text.setString(index[i].str()+". "+scoreS[i].str());
            scoreScreen.draw(text);
        }
        text.setCharacterSize(20);
        text.setPosition(30,500);
        text.setString("Your last score: ");
        text.setFillColor(sf::Color(39, 156, 148));
        scoreScreen.draw(text);
        text.setPosition(250,500);
        text.setString(lastScore.str());
        scoreScreen.draw(text);


        text.setPosition(510,500);
        text.setFillColor(sf::Color(39, 156, 148));
        text.setString("Press \"Space\" to exit");
        scoreScreen.draw(text);
        scoreScreen.display();
    }
}
