#include "powerUp.h"

PowerUp::PowerUp(sf::RenderWindow * window, PowerUpTypes powerUp, int xPos){
    win = window;
    xToken = xPos;
    yToken = -25;
    enabled = false;
    switch(powerUp){
        case SHIELD:
            tokenFile = SHIELD_TOKEN_TEXTURE;
            break;
        case RAPID_SHOT:
            tokenFile = RAPID_SHOT_TOKEN_TEXTURE;
            break;
    }
}

void PowerUp::move(){
    tokenSprite.move(0, TOKEN_SPEED);
    yToken = yToken+TOKEN_SPEED;
}

void PowerUp::moveOffScreen(){
    tokenSprite.setPosition(-30, -30);
    xToken = -30;
    yToken = -30;
}

int PowerUp::load(){
    if(!tokenTexture.loadFromFile(tokenFile)){
        return EXIT_FAILURE;
    }
    tokenSprite.setTexture(tokenTexture);
    tokenSprite.setPosition(xToken,yToken);
    return 0;
}

void PowerUp::draw(){
    win->draw(tokenSprite);
}

void PowerUp::enable(){
    enabled = true;
}

void PowerUp::disable(){
    enabled = false;
}

bool PowerUp::getStatus(){
    return enabled;
}