#ifndef SCORE
#define SCORE

#include <SFML/Graphics.hpp>
#include <string>
#include "constants.h"


class Score{

    int score;
    std::string scoreStr;

    sf::Font font;
    sf::Text text;
    sf::RenderWindow *win;

    int size, health;

    public:
    friend class Game;

    Score(sf::RenderWindow *window);
    float getX();
    float getY();
    void update(int scoreIncrease);
    int load(std::string fontFile);
    void draw();


};


#endif