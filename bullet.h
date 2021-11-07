#ifndef BULLET
#define BULLET

#include <SFML/Graphics.hpp>
#include "settings.h"

class Bullet{

    float x,y;

    sf::Texture bulletTexture;
    sf::Sprite bulletSprite;
    sf::RenderWindow *win;

    public:

    Bullet(sf::RenderWindow *window);
    float getX();
    float getY();
    void move(float yPos);
    int load(std::string textureFile, float x, float y);
    void draw();


};


#endif