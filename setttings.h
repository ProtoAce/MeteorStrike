#ifndef SETTINGS
#define SETTINGS

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>


class Settings{
    friend Game;

    CONST int MAX_DIFFICULTY = 1;
    CONST int MAX_BUFF = 1;

    sf::RenderWindow * win;
    //game settings
    int shipSpeed = 5;
    int bulletSpeed = -15; // negative to move up screen
    int bulletShotDelay = 10; //seconds * fps
    int meteoriteSpeed = 5;
    int meteoriteSpawnLimit = 50;
    int meteoriteSpawnSpeed = 15; // seconds * fps

    float shipSpeedMultiple = 1.1;
    float bulletSpeedMultiple = 1.1;

    public:
    int increaseShipSpeed();
    int increaseBulletSpeed();
    int decreaseBulletShotDelay();
    int increaseMeteoriteSpeed();
    int increaseMeteoriteSpawnSpeed();


};


#endif