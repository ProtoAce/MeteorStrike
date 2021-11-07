#include <SFML/Graphics.hpp>
#include "spaceship.h"
#include "game.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    Game game(&window);
    game.start();
    return 0;
}
