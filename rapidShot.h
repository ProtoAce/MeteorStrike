#ifndef RAPID_SHOT_PU
#define RAPID_SHOT_PU

#include <SFML/Graphics.hpp>
#include "settings.h"
#include "constants.h"
#include "powerUp.h"

class RapidShot: public PowerUp{

    float x,y;

    sf::Texture rapidShotTexture;
    sf::Sprite rapidShotSprite;

    sf::RenderWindow *win;

    int rapidReload;
    int rapidBulletSpeed;
    int rapidShotTimer;

    public:
    friend class Game;

    RapidShot(sf::RenderWindow *window, PowerUpTypes powerUp, int xPos);

    void moveRapidShot(int xPos, int yPos);
    int loadRapidShot();
    void drawRapidShot();
};


#endif