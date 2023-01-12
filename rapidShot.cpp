#include "rapidShot.h"

RapidShot::RapidShot(sf::RenderWindow *window, PowerUpTypes powerUp, int xPos): PowerUp(window, powerUp, xPos){
    win = window;
    rapidReload = 1;
    rapidBulletSpeed = -35;
    rapidShotTimer = 90;
}

void RapidShot::moveRapidShot(int xPos, int yPos){
    rapidShotSprite.setPosition(xPos+5, yPos-20);
    x = xPos+5;
    y = yPos-20;
}

int RapidShot::loadRapidShot(){
    if(!rapidShotTexture.loadFromFile(RAPID_SHOT_TEXTURE)){
        return EXIT_FAILURE;
    }
    rapidShotSprite.setTexture(rapidShotTexture);
    rapidShotSprite.setPosition(-100,-100);

    return 0;
}

void RapidShot::drawRapidShot(){
    win->draw(rapidShotSprite);
}
