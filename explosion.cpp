#include "explosion.h"

Explosion::Explosion(sf::RenderWindow *window){
    win = window;
}
int Explosion::load(std::vector<std::string> textureFiles){
    for(std::vector<std::string>::iterator it = textureFiles.begin(); it != textureFiles.end(); it++){
        sf::Texture* tempTexture = new sf::Texture;
        if(!tempTexture->loadFromFile(*it)){
            return EXIT_FAILURE;
        }
        sf::Sprite* tempSprite = new sf::Sprite;
        tempSprite->setTexture(*tempTexture);
        explosionTextures.push_back(tempTexture);
        explosionSprites.push_back(tempSprite);

    }
    return 0;
}

void Explosion::draw(int frame, int x, int y){
    explosionSprites.at(frame)->setPosition(x,y);
    win->draw(*explosionSprites.at(frame));
}