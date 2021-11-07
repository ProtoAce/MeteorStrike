#include "spaceship.h"


SpaceShip::SpaceShip(sf::RenderWindow * window){
    win = window;
}


float SpaceShip::getX(){ return x;}

float SpaceShip::getY(){ return y;}

void SpaceShip::move(float xPos, float yPos){
    if(x+xPos > 450){
        spaceShipSprite.setPosition(450.f, 400.f);
        x = 450;

    }else if(x+xPos < -12){
        spaceShipSprite.setPosition(-12.f, 400.f);
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
    spaceShipSprite.setPosition(225.f,400.f);
    x = 225;
    y = 400;

    return 0;
}

void SpaceShip::draw(){
    win->draw(spaceShipSprite);
}