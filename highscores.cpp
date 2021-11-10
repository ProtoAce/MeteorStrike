#include "highscores.h"

Highscores::Highscores(sf::RenderWindow *window){
    win = window;
    highScoreCount = 0;
}

int Highscores::loadFromFile(){
    std::ifstream fileIn(HIGHSCORE_FILE);
    std::string line;
    sf::Color brown(139,104,75,200);
    int currentScore = 1;
    if(!font.loadFromFile(FONT)){
        return EXIT_FAILURE;
    }
    while(!(fileIn.eof())){
        std::getline(fileIn, line);
        if(line == ""){break;}
        highScores.push_back(stoi(line));
        
    }
    std::sort(highScores.begin(), highScores.end(), std::greater<int>());
    for(int i = 0; i < highScores.size(); i++){
        std::string outputText = std::to_string(currentScore) + ". " + std::to_string(highScores.at(i));
        sf::Text *tempScore = new sf::Text;
        tempScore->setFont(font);
        tempScore->setCharacterSize(20);
        tempScore->setFillColor(brown);
        tempScore->setPosition(150.f,200.f + 20*currentScore);
        tempScore->setString(outputText);
        highScoreTexts.push_back(tempScore);
        currentScore++;
        highScoreCount++;
    }
    return 0;
}

void Highscores::saveToFile(){
    std::ofstream fileOut;
    fileOut.open(HIGHSCORE_FILE, std::ofstream::trunc);
    for(int i = 0; i < highScores.size(); i++){
        fileOut << highScores.at(i) << "\n";
    }
    fileOut.close();

}

void Highscores::addScore(int score){
    std::cout<<  "highscorecount upon adding score" << highScoreCount << "\n";
    if(highScoreCount < 10 || score > highScores.back()){
        if(highScoreCount < 10){
            highScoreCount++;
        }
        if(highScoreCount >= 10){
            highScores.pop_back();
        }
        highScores.push_back(score);
        std::sort(highScores.begin(), highScores.end(), std::greater<int>());
        highScoreTexts.erase(highScoreTexts.begin(), highScoreTexts.end());
        int currentScore = 1;
        //really innefficient!;
        sf::Color brown(139,104,75,200);
        for(int i = 0; i < highScores.size(); i++){
            std::string outputText = std::to_string(currentScore) + ". " + std::to_string(highScores.at(i));
            sf::Text *tempScore = new sf::Text;
            tempScore->setFont(font);
            tempScore->setCharacterSize(20);
            tempScore->setFillColor(brown);
            tempScore->setPosition(150.f,200.f + 20*currentScore);
            tempScore->setString(outputText);
            highScoreTexts.push_back(tempScore);
            currentScore++;
        }
    }
}

void Highscores::draw(){
    for(std::vector<sf::Text*>::iterator it = highScoreTexts.begin(); it != highScoreTexts.end(); it++){
        win->draw(**it);
    }
}

void Highscores::highScoreLoop(){
    bool inMenu = true;
    while(inMenu && win->isOpen()){
        sf::Event event;
        while(win->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                win->close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Enter){
                    inMenu = false;
                }
            }
        }  
        win->clear();

        draw();

        win->display();

        win->setFramerateLimit(30);
    


    }
}

