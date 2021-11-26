#ifndef SHIELD_PU
#define SHIELD_PU

#include <SFML/Graphics.hpp>
#include "settings.h"
#include "constants.h"
#include "powerUps.h"

class Shield: public PowerUp{

    float x,y;

    sf::Texture shieldTexture;
    sf::Sprite shieldSprite;

    sf::RenderWindow *win;

    public:

    Shield(sf::RenderWindow *window, PowerUpTypes powerUp, int xPos);

    void moveShield(int xPos, int yPos);
    int loadShield();
    void drawShield();


};


#endif