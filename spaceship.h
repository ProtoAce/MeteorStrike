#ifndef SPACESHIP
#define SPACESHIP

#include <SFML/Graphics.hpp>
#include <string>

class SpaceShip{
    float x,y;
    int level; 
    sf::Texture spaceShipTexture;
    sf::Sprite spaceShipSprite;
    sf::RenderWindow *win;
    public:

    SpaceShip(sf::RenderWindow *window);
    float getX();
    float getY();
    void move(float xPos, float yPos);
    int load(std::string textureFile);
    void draw();
};


#endif