#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
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


class Game{


    sf::RenderWindow * win;
    SpaceShip ship;
    std::vector<Bullet*> bullets;
    std::vector<Meteorite*> meteorites;
    Score score;
    Explosion explosion;
    Settings settings;



    public:
    Game(sf::RenderWindow *window);

    ~Game();

    void start();


    int loadResources();


    void gameLoop();


    void keyPressed(int currentFrame);

    int randomNumberGenerator(int startRange, int endRange);
    int RandomXForMeteorite();

    // int RandomYForMeteorite();

    bool collisionLoop();
    bool collisionLoopShip();
    bool collisionCheck(Bullet* bullet, Meteorite* meteorite);
    bool collisionCheckShip(Meteorite* meteorite);

    Bullet* generateBullet(std::string textureFile);
    Meteorite* generateMeteorite(std::string textureFile, int size);

    int scaleDifficulty(int scaleOption);
    int scaleBuffs(int scaleOption);


    void gameOver();

};


#endif