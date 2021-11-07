
#ifndef EXPLOSION
#define EXPLOSION

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>


class Explosion{


    std::vector<sf::Texture*> explosionTextures;
    std::vector<sf::Sprite*> explosionSprites;

    sf::RenderWindow *win;
    public:

    Explosion(sf::RenderWindow *window);
    int load(std::vector<std::string> textureFiles);
    void draw(int frame, int x, int y);


};


#endif