#include "score.h"


Score::Score(sf::RenderWindow * window){
    win = window;
    score = 0;
    scoreStr = "Score ";
}

int Score::load(std::string fontFile){
    if(!font.loadFromFile(fontFile)){
        return EXIT_FAILURE;
    }
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(5.f, 465.f);
    text.setString("Score 0");
    return 0;
}

void Score::update(int scoreIncrease){
    score += scoreIncrease;
    std::string output = scoreStr + std::to_string(score);
    text.setString(output);    
    
}

void Score::draw(){
    win->draw(text);
}