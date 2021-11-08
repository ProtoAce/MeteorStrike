#include <SFML/Graphics.hpp>
#include "spaceship.h"
#include "mainMenu.h"
#include <iostream>

int main()
{

    
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    MainMenu menu(&window);

    menu.start();

    
    // Game game(&window);
    // game.start();
    return 0;
}
