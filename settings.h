#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include "constants.h"


class Settings{

    const int MAX_DIFFICULTY = 1;
    const int MAX_BUFF = 1;

    sf::RenderWindow * win;
    //game settings
    int shipSpeed = 5;
    int bulletShotDelay = 10; //seconds * fps
    int bulletSpeed = -15; // negative to move up screen
    int meteoriteSpeed = 5;
    int meteoriteSpawnLimit = 50;
    int meteoriteSpawnSpeed = 20; // seconds * fps

    float shipSpeedMultiple = 1.1;
    float bulletSpeedMultiple = 1.1;

    public:

    friend class Game;
    friend class Meteorite;

    int increaseShipSpeed();
    int increaseBulletSpeed();
    int decreaseBulletShotDelay();
    int increaseMeteoriteSpeed();
    int increaseMeteoriteSpawnSpeed();


};


#endif