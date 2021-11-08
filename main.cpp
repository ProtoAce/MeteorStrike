#include <SFML/Graphics.hpp>
#include "spaceship.h"
#include "mainMenu.h"
#include <iostream>

int main()
{

    
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
    MainMenu menu(&window);

    menu.start();

    
    // Game game(&window);
    // game.start();
    return 0;
}
