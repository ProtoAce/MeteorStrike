#include "bullet.h"

Bullet::Bullet(sf::RenderWindow * window){
    win = window;
}


float Bullet::getX(){ return x;}

float Bullet::getY(){ return y;}

void Bullet::move(float yPos){
    bulletSprite.move(0, yPos);
    y = y+yPos;
}

int Bullet::load(std::string textureFile, float xPos, float yPos){
    if(!bulletTexture.loadFromFile(textureFile)){
        return EXIT_FAILURE;
    }
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setPosition(xPos,yPos);
    x = xPos;
    y = yPos;

    return 0;
}

void Bullet::draw(){
    win->draw(bulletSprite);
}