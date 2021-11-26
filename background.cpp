#include "background.h"

Background::Background(sf::RenderWindow * window){
    win = window;
    y = -2600;
}

void Background::move(){
    backgroundSprite.move(0, 2);
    y = y+5;
    if(y == -650){
        std::cout << "moving\n";
        backgroundSprite.setPosition(0,-2600);
        y = -2600;
    }
}

int Background::load(std::string textureFile){
    if(!backgroundTexture.loadFromFile(textureFile)){
        return EXIT_FAILURE;
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0,-2600);
    return 0;
}

void Background::draw(){
    win->draw(backgroundSprite);
}