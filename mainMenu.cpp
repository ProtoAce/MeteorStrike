#include "mainMenu.h"

MainMenu::MainMenu(sf::RenderWindow *window){
    win = window;
};


void MainMenu::start(){
    if(load(FONT) == EXIT_FAILURE){
        return;
    }

    menuLoop();
}

int MainMenu::load(std::string fontFile){
    if(!font.loadFromFile(fontFile)){
        return EXIT_FAILURE;
    }
    play.setFont(font);
    play.setCharacterSize(20);
    play.setFillColor(sf::Color::White);
    play.setPosition(150.f,200.f);
    play.setString("Play");

    highScores.setFont(font);
    highScores.setCharacterSize(20);
    highScores.setFillColor(sf::Color::White);
    highScores.setPosition(150.f,260.f);
    highScores.setString("HighScores");

    exit.setFont(font);
    exit.setCharacterSize(20);
    exit.setFillColor(sf::Color::White);
    exit.setPosition(150.f,320.f);
    exit.setString("Exit");

    if(!arrowLeftTexture.loadFromFile(ARROW_LEFT)){
        return EXIT_FAILURE;
    }
    arrowLeftSprite.setTexture(arrowLeftTexture);

    if(!arrowRightTexture.loadFromFile(ARROW_RIGHT)){
        return EXIT_FAILURE;
    }
    arrowRightSprite.setTexture(arrowRightTexture);


    return 0;
}

void MainMenu::draw(){
    win->draw(play);
    win->draw(highScores);
    win->draw(exit);
}

void MainMenu::drawSelection(int menuOption){
    switch(menuOption){
        case 0:
            arrowRightSprite.setPosition(120.f, 202.f);
            arrowLeftSprite.setPosition(360.f, 202.f);
            break;
        case 1:
            arrowRightSprite.setPosition(120.f, 262.f);
            arrowLeftSprite.setPosition(360.f, 262.f);
            break;
        case 2:
            arrowRightSprite.setPosition(120.f, 322.f);
            arrowLeftSprite.setPosition(360.f, 322.f);
            break;
    }
    win->draw(arrowRightSprite);
    win->draw(arrowLeftSprite);
}

void MainMenu::gameOption(int menuOption, bool &playing){
    if(menuOption == 0){
        Game game(win);
        game.start();
    }else if(menuOption == 1){
        //leaderboard;
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


        win->clear();

        draw();
        drawSelection(menuOption);

        win->display();

        win->setFramerateLimit(30);
    


    }
}
