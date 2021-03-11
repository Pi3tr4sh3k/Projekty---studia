
#include <SFML/Graphics.hpp>

#ifndef PACMAN2_SFMLVIEW_H
#define PACMAN2_SFMLVIEW_H

#include "PacManBoard.h"
#include "Player.h"
#include "EnemyUnits.h"
#include "GameStateController.h"
class SFMLView {
    PacManBoard &board;
    Player &p1;
    EnemyUnits &enemy1;
    EnemyUnits &enemy2;
    GameStateController &state;
    //objects textures
    sf::Texture wall_texture;
    sf::Sprite wall;
    sf::Texture point_texture;
    sf::Sprite point;
    sf::Texture boost_texture;
    sf::Sprite boost;
    //pac-man
    sf::Texture pacman_texture;
    sf::Sprite pacman;
    sf::Texture pacman_eat_texture;
    sf::Sprite pacman_eat;
    //red
    sf::Texture red_textureRL;
    sf::Texture red_textureUP;
    sf::Texture red_textureDOWN;
    sf::Sprite red;
    //green
    sf::Texture green_textureRL;
    sf::Texture green_textureUP;
    sf::Texture green_textureDOWN;
    sf::Sprite green;

    int alignX=200;
    int alignY=200;
    sf::RectangleShape square;
    int size=30;
    sf::Font font;
    sf::Text text;
    sf::Text text2;
    int posX;
    int posY;
public:
    SFMLView(PacManBoard &b, Player &p, EnemyUnits &e1, EnemyUnits &e2, GameStateController &s);
    int getSquareSize() const;
    void draw(sf::RenderWindow &win);

};


#endif //PACMAN2_SFMLVIEW_H
