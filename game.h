#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "spaceship.h"
#include "constants.h"
#include "settings.h"
#include "bullet.h"
#include "meteorite.h"
#include "score.h"
#include "explosion.h"
#include "settings.h"
#include "constants.h"
#include "background.h"
#include "powerUp.h"
#include "shield.h"
#include "gameMusic.h"


class Game{


    sf::RenderWindow * win;
    GameMusic * music;
    SpaceShip ship;
    std::vector<Bullet*> bullets;
    std::vector<Meteorite*> meteorites;
    Score score;
    Explosion explosion;
    Settings settings;
    Background background;
    Shield *shield;

    public:
    Game(sf::RenderWindow *window, GameMusic *musicVar);

    ~Game();

    int start();


    int loadResources();


    void gameLoop();


    void keyPressed(int currentFrame);

    int randomNumberGenerator(int startRange, int endRange);
    int randomX();

    // int RandomYForMeteorite();

    bool collisionLoop();
    bool collisionLoopShip();
    bool collisionCheck(Bullet* bullet, Meteorite* meteorite);
    bool collisionCheckShip(Meteorite* meteorite);
    bool collisionCheckPowerUp(Bullet* bullet, PowerUp* powerUp);
    bool collisionLoopPowerUp();




    Bullet* generateBullet(std::string textureFile);
    Meteorite* generateMeteorite(std::string textureFile, int size);

    int scaleDifficulty(int scaleOption);
    int scaleBuffs(int scaleOption);


    void gameOver();

};


#endif