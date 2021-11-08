#include "meteorite.h"

Meteorite::Meteorite(sf::RenderWindow * window, int meteoriteSize){
    size = meteoriteSize; 
    health = meteoriteSize;
    win = window;
    yVelocity = settings.meteoriteSpeed;
}


float Meteorite::getX(){ return x;}

float Meteorite::getY(){ return y;}

int Meteorite::getSize(){ return size;}

int Meteorite::getHealth(){ return health;}

void Meteorite::setXVelocity(int velocity){ xVelocity = velocity;}

int Meteorite::decrementHealth(){ return --health;}


void Meteorite::move(){
    meteoriteSprite.move(xVelocity, yVelocity);
    y = y+yVelocity;
    x = x+xVelocity;
}

int Meteorite::load(std::string textureFile, float xPos, float yPos){
    if(!meteoriteTexture.loadFromFile(textureFile)){
        return EXIT_FAILURE;
    }
    meteoriteSprite.setTexture(meteoriteTexture);
    meteoriteSprite.setPosition(xPos,yPos);
    x = xPos;
    y = yPos;
    return 0;
}

void Meteorite::draw(){
    win->draw(meteoriteSprite);
}