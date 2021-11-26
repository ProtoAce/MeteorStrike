#ifndef POWER_UPS
#define POWER_UPS

#include <SFML/Graphics.hpp>
#include "settings.h"

class PowerUp{

    float xToken,yToken;
    
    std::string tokenFile;

    sf::Texture tokenTexture;
    sf::Sprite tokenSprite;
    sf::RenderWindow *win;

    bool enabled;

    public:

    friend class Game;

    PowerUp(sf::RenderWindow * window, PowerUpTypes powerUp, int xPos);

    void enable();
    void disable();

    void move();
    void moveOffScreen();
    int load();
    void draw();


};


#endif