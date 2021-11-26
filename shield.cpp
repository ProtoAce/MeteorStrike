#include "shield.h"

Shield::Shield(sf::RenderWindow *window, PowerUpTypes powerUp, int xPos): PowerUp(window, powerUp, xPos){
    win = window;
}

void Shield::moveShield(int xPos, int yPos){
    shieldSprite.setPosition(xPos, yPos);
    x = xPos;
    y = yPos;
}

int Shield::loadShield(){
    if(!shieldTexture.loadFromFile(SHIELD_TEXTURE)){
        return EXIT_FAILURE;
    }
    shieldSprite.setTexture(shieldTexture);
    shieldSprite.setPosition(-100,-100);

    return 0;
}

void Shield::drawShield(){
    win->draw(shieldSprite);
}