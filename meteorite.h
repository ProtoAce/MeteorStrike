#ifndef METEORITE
#define METEORITE

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "spaceship.h"
#include "settings.h"
#include "bullet.h"


class Meteorite{

    float x,y,xVelocity, yVelocity;

    sf::Texture meteoriteTexture;
    sf::Sprite meteoriteSprite;
    sf::RenderWindow *win;
    Settings settings;

    int size, health;

    public:

    Meteorite(sf::RenderWindow *window, int meteoriteSize, const Settings &setting);
    float getX();
    float getY();
    int getSize();
    int getHealth();
    void setXVelocity(int velocity);
    int decrementHealth();
    void move();
    int load(std::string textureFile, float x, float y);
    void draw();


};


#endif