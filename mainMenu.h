#ifndef MAIN_MENU
#define MAIN_MENU

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include "game.h"
#include "highscores.h"
#include "gameMusic.h"


class MainMenu{
        
    sf::RenderWindow * win;
    sf::Font font;
    sf::Text play;
    sf::Text highScores;
    sf::Text exit;
    sf::Texture arrowLeftTexture;
    sf::Texture arrowRightTexture;
    sf::Texture titleTexture;
    sf::Sprite arrowLeftSprite;
    sf::Sprite arrowRightSprite;
    sf::Sprite titleSprite;

    Highscores leaderBoard;
    GameMusic *music;



    public:

    MainMenu(sf::RenderWindow *window);
    ~MainMenu();

    void start();

    void menuLoop();

    int load(std::string fontFile);

    void draw();

    void drawSelection(int menuOption);

    void gameOption(int menuOption, bool &playing);




};


#endif