#include "mainMenu.h"

MainMenu::MainMenu(sf::RenderWindow *window):leaderBoard(window){
    win = window;
    music = new GameMusic(window);
};

MainMenu::~MainMenu(){
    leaderBoard.saveToFile();
}


void MainMenu::start(){
    if(load(FONT) == EXIT_FAILURE){
        return;
    }
    if(music->load() == EXIT_FAILURE){
        return;
    }
    music->play();


    menuLoop();
}

int MainMenu::load(std::string fontFile){
    if(!font.loadFromFile(fontFile)){
        return EXIT_FAILURE;
    }

    leaderBoard.loadFromFile();

    sf::Color brown(139,104,75,200);
    play.setFont(font);
    play.setCharacterSize(20);
    play.setFillColor(brown);
    play.setPosition(150.f,400.f);
    play.setString("Play");

    highScores.setFont(font);
    highScores.setCharacterSize(20);
    highScores.setFillColor(brown);
    highScores.setPosition(150.f,460.f);
    highScores.setString("HighScores");

    exit.setFont(font);
    exit.setCharacterSize(20);
    exit.setFillColor(brown);
    exit.setPosition(150.f,520.f);
    exit.setString("Exit");

    if(!arrowLeftTexture.loadFromFile(ARROW_LEFT)){
        return EXIT_FAILURE;
    }
    arrowLeftSprite.setTexture(arrowLeftTexture);

    if(!arrowRightTexture.loadFromFile(ARROW_RIGHT)){
        return EXIT_FAILURE;
    }
    arrowRightSprite.setTexture(arrowRightTexture);

    if(!titleTexture.loadFromFile(TITLE)){
        return EXIT_FAILURE;
    }
    titleSprite.setTexture(titleTexture);
    titleSprite.setPosition(50.f,25.f);

    return 0;
}

void MainMenu::draw(){
    win->draw(play);
    win->draw(highScores);
    win->draw(exit);
    win->draw(titleSprite);
}

void MainMenu::drawSelection(int menuOption){
    switch(menuOption){
        case 0:
            arrowRightSprite.setPosition(120.f, 402.f);
            arrowLeftSprite.setPosition(360.f, 402.f);
            break;
        case 1:
            arrowRightSprite.setPosition(120.f, 462.f);
            arrowLeftSprite.setPosition(360.f, 462.f);
            break;
        case 2:
            arrowRightSprite.setPosition(120.f, 522.f);
            arrowLeftSprite.setPosition(360.f, 522.f);
            break;
    }
    win->draw(arrowRightSprite);
    win->draw(arrowLeftSprite);
}

void MainMenu::gameOption(int menuOption, bool &playing){
    if(menuOption == 0){
        Game game(win, music);
        int score;
        score = game.start();
        leaderBoard.addScore(score);
    }else if(menuOption == 1){
        leaderBoard.highScoreLoop();
    }else if(menuOption == 2){
        playing = false;
    }
}


void MainMenu::menuLoop(){
    bool playing = true;
    int menuOption = 0;
    while(playing && win->isOpen()){
        sf::Event event;
        while(win->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                win->close();
            }
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Down){
                    if(menuOption == 2){
                        menuOption = 0;
                    }else{
                        menuOption++;
                    }
                }else if(event.key.code == sf::Keyboard::Up){
                    if(menuOption == 0){
                        menuOption = 2;
                    }else{
                        menuOption --;
                    }
                
                }else if(event.key.code == sf::Keyboard::Enter){
                    gameOption(menuOption, playing);
                }
            }
        }  

        //check if song has ended
        if(music->songEnded()){
            if(music->nextSong() == EXIT_FAILURE){
                return;
            }
        }


        win->clear();

        draw();
        drawSelection(menuOption);

        win->display();

        win->setFramerateLimit(30);
    


    }
}
