#ifndef HIGHSCORES
#define HIGHSCORES

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "constants.h"


class Highscores{

    int highScoreCount;
    std::vector<int> highScores;
    std::vector<sf::Text*> highScoreTexts; 
    sf::Font font;
    sf::RenderWindow *win;


    public:

    Highscores(sf::RenderWindow *window);
    int loadFromFile();
    void saveToFile();
    void addScore(int score);
    void draw();

    void highScoreLoop();


};


#endif