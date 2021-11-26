#ifndef BACKGROUND
#define BACKGROUND

#include <SFML/Graphics.hpp>
#include "settings.h"

class Background{

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::RenderWindow *win;
    int y;

    public:

    Background(sf::RenderWindow *window);
    void move();
    int load(std::string textureFile);
    void draw();


};


#endif