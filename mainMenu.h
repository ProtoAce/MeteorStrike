#ifndef MAIN_MENU
#define MAIN_MENU

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "game.h"


class MainMenu{
        
    sf::RenderWindow * win;
    sf::Font font;
    sf::Text play;
    sf::Text highScores;
    sf::Text exit;
    sf::Texture arrowLeftTexture;
    sf::Texture arrowRightTexture;
    sf::Sprite arrowLeftSprite;
    sf::Sprite arrowRightSprite;

    public:

    MainMenu(sf::RenderWindow *window);

    void start();

    void menuLoop();

    int load(std::string fontFile);

    void draw();

    void drawSelection(int menuOption);

    void gameOption(int menuOption, bool &playing);




};


#endif