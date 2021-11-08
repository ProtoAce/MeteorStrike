#ifndef SETTINGS
#define SETTINGS

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>


class Settings{


    sf::RenderWindow * win;
    //game settings
    int SHIP_SPEED = 5;
    int BULLET_SPEED = -15; // negative to move up screen
    int BULLET_SHOOT_DELAY = 10; //seconds * fps
    int METEORITE_SPEED = 5;
    int METEORITE_COUNT = 50;
    int METEORITE_SPAWN_SPEED = 15; // seconds * fps

    public:
    Settings(sf::RenderWindow *window);

};


#endif