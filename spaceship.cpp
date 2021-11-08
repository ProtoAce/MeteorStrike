#include "spaceship.h"


SpaceShip::SpaceShip(sf::RenderWindow * window){
    win = window;
}


float SpaceShip::getX(){ return x;}

float SpaceShip::getY(){ return y;}

void SpaceShip::move(float xPos, float yPos){
    if(x+xPos > WINDOW_WIDTH - 50){
        spaceShipSprite.setPosition(WINDOW_WIDTH - 50, WINDOW_HEIGHT-100);
        x = WINDOW_WIDTH - 50;

    }else if(x+xPos < -12){
        spaceShipSprite.setPosition(-12.f, WINDOW_HEIGHT-100);
        x = -12;
    }else{
        spaceShipSprite.move(xPos, yPos);
        x = x+xPos;
        y = y+yPos;
    }
}

int SpaceShip::load(std::string textureFile){
    if(!spaceShipTexture.loadFromFile(textureFile)){
        return EXIT_FAILURE;
    }
    spaceShipSprite.setTexture(spaceShipTexture);
    spaceShipSprite.setPosition(WINDOW_WIDTH/2 - 25,WINDOW_HEIGHT-100);
    x = WINDOW_WIDTH/2 - 25;
    y = WINDOW_HEIGHT-100;

    return 0;
}

void SpaceShip::draw(){
    win->draw(spaceShipSprite);
}