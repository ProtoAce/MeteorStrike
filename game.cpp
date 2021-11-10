#include "game.h"

Game::Game(sf::RenderWindow *window) : ship(window), score(window), explosion(window){
    win = window;
    srand(time(NULL));//generates random seed
};

Game::~Game(){}

int Game::start(){
    
    if(loadResources() == EXIT_FAILURE){
        return 0;
    }

    gameLoop();

    return score.score;

}

void Game::gameLoop(){
    int currentFrame = 1;
    int difficultyScaleType = 0;
    int buffScaleType = 0;
    int prevBuffScoreMultiple = 1;
    int prevDifficultyScoreMultiple = 1;
    bool playing = true;

    while(playing && win->isOpen()){
        sf::Event event;
        while(win->pollEvent(event)){
            if(event.type == sf::Event::Closed){
                win->close();
            }
        }
        keyPressed(currentFrame);

        if(currentFrame % settings.bulletShotDelay == 0){
            bullets.push_back(generateBullet(BULLET_TEXTURE));
        }

        if(score.score > 0){
            if(score.score >= DIFFICULTY_SCALE_RATE*prevDifficultyScoreMultiple){
                prevDifficultyScoreMultiple++;
                scaleDifficulty(difficultyScaleType);
                difficultyScaleType = (difficultyScaleType + 1)%2;
            }

            if(score.score >= BUFF_SCALE_RATE*prevBuffScoreMultiple){
                prevBuffScoreMultiple++;
                scaleBuffs(buffScaleType);
                buffScaleType = (buffScaleType + 1)%3;
            }
        }



        win->clear();

        //bullets
        for(std::vector<Bullet*>::iterator i = bullets.begin(); i != bullets.end(); i++){
            if((*i)->getY() <= 0){
                bullets.erase(i);
                i--;
            }else{
                (*i)->move(settings.bulletSpeed);
                (*i)->draw();
            }
        } 

        //ship
        ship.draw();

        //meteorite
        if(meteorites.size() < settings.meteoriteSpawnLimit){
            if(currentFrame % settings.meteoriteSpawnSpeed == 0){

                switch(randomNumberGenerator(1,3)){
                    case(1):
                        meteorites.push_back(generateMeteorite(METEORITE_TEXTURE1, 1));
                        break;
                    case(2):
                        meteorites.push_back(generateMeteorite(METEORITE_TEXTURE2, 2));
                        break;
                    case(3):
                        meteorites.push_back(generateMeteorite(METEORITE_TEXTURE3, 3));
                        break;

                }
            }

        }
        for(std::vector<Meteorite*>::iterator i = meteorites.begin(); i != meteorites.end(); i++){
            (*i)->move();
            (*i)->draw();
            if((*i)->getX() < 0 || (*i)->getX() > WINDOW_WIDTH || (*i)->getY() > WINDOW_HEIGHT){
                meteorites.erase(i);
                i--;
            }
        } 

        //deletes any hit meteorites and adds score accordingly
        collisionLoop();

        if(collisionLoopShip()){
            playing = false;
        }



        score.draw();
    

        win->display();

        win->setFramerateLimit(30);

        currentFrame++;
    }

    gameOver();


}

int Game::loadResources(){
    if(ship.load(SHIP_TEXTURE) == EXIT_FAILURE){
        return EXIT_FAILURE;
    }
    if(score.load(FONT) == EXIT_FAILURE){
        return EXIT_FAILURE;
    }
    if(explosion.load(EXPLOSTION_TEXTURES) == EXIT_FAILURE){
        return EXIT_FAILURE;
    }
    return 0;
}

Bullet* Game::generateBullet(std::string textureFile){
    Bullet* newBullet = new Bullet(win);
    if(newBullet->load(textureFile, ship.getX()+21, ship.getY()+10) == EXIT_FAILURE){//offset x and y to center of ship
        std::cout << "Load Failure\n";
        exit(1);
    };
    return newBullet;
}

Meteorite* Game::generateMeteorite(std::string textureFile, int size){
    Meteorite* newMeteorite = new Meteorite(win, size);
    if(newMeteorite->load(textureFile, RandomXForMeteorite(), -50) == EXIT_FAILURE){
        std::cout << "Load Failure\n";
        exit(1);
    }
    newMeteorite->setXVelocity(randomNumberGenerator(-2,4));
    
    return newMeteorite;
}



void Game::keyPressed(int currentFrame){
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    //     if(currentFrame % settings.bulletShotDelay == 0){
    //         bullets.push_back(generateBullet(BULLET_TEXTURE));
    //     }
    // }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        ship.move(-settings.shipSpeed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        ship.move(settings.shipSpeed, 0);
    // }
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    //     ship.move(0, -SHIP_SPEED);
    // }
    // if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    //     ship.move(0, SHIP_SPEED);
    }else{
        //do nothin
    }

}

int Game::randomNumberGenerator(int startRange, int endRange){
    return rand() % endRange + startRange;
}

// int Game::RandomYForMeteorite(){
//     return -randomNumberGenerator(10,50);

// }

int Game::RandomXForMeteorite(){
    return randomNumberGenerator(0,WINDOW_WIDTH);
}

bool Game::collisionLoop(){
    for(std::vector<Meteorite*>::iterator itMeteorite = meteorites.begin(); itMeteorite != meteorites.end(); itMeteorite++){
        for(std::vector<Bullet*>::iterator itBullet = bullets.begin(); itBullet != bullets.end(); itBullet++){
           if(collisionCheck((*itBullet), (*itMeteorite))){
               bullets.erase(itBullet);
               itBullet--;
               if((*itMeteorite)->decrementHealth() <= 0){
                   score.update((*itMeteorite)->getSize());
                   meteorites.erase(itMeteorite);
                   itMeteorite--;
               }
               break;
           }

        }
    }
    return false;
}

bool Game::collisionLoopShip(){
    for(std::vector<Meteorite*>::iterator itMeteorite = meteorites.begin(); itMeteorite != meteorites.end(); itMeteorite++){
        if(collisionCheckShip(*itMeteorite)){
            return true;
        }
    }
    return false;
}


bool Game::collisionCheck(Bullet* bullet, Meteorite* meteorite){
    float meteoriteRadius = 0;
    switch(meteorite->getSize()){
        case 1:
            meteoriteRadius = 7.5;
            break;
        case 2:
            meteoriteRadius = 12.5;
            break;
        case 3: 
            meteoriteRadius = 25;
            break;
    }
    if(sqrt(pow(bullet->getX()-meteorite->getX()-meteoriteRadius,2) 
           +pow(bullet->getY()-meteorite->getY()-meteoriteRadius,2)) 
                                 <= meteoriteRadius){
        return true;
    }
    return false;
}

bool Game::collisionCheckShip(Meteorite* meteorite){
    float meteoriteRadius = 0;
    switch(meteorite->getSize()){
        case 1:
            meteoriteRadius = 7.5;
            break;
        case 2:
            meteoriteRadius = 12.5;
            break;
        case 3: 
            meteoriteRadius = 25;
            break;
    }
    if(ship.getY()-meteorite->getY()-meteoriteRadius*2 <= 0 &&
       ship.getY()-meteorite->getY() >= -60){
        if(meteorite->getX() >= ship.getX()-2*meteoriteRadius &&
           meteorite->getX() <= ship.getX() + 40){
            return true;

        }
        
    }
    return false;
}



void Game::gameOver(){
    int currentSprite = 0;
    int currentFrame = 0;
    while(currentFrame != 13){
        
        win->clear();

        for(std::vector<Bullet*>::iterator i = bullets.begin(); i != bullets.end(); i++){
            (*i)->draw();
        }

        for(std::vector<Meteorite*>::iterator i = meteorites.begin(); i != meteorites.end(); i++){
            (*i)->draw();
        }

        score.draw();

        explosion.draw(currentSprite, ship.getX()-20 ,ship.getY()-10);
        
        currentFrame++;

        win->display();
        win->setFramerateLimit(30);
        
        currentSprite++;
    }

}

int Game::scaleDifficulty(int scaleOption){
    int maxDifficulty = 0;
    switch(scaleOption){
        case 0:
            settings.increaseMeteoriteSpeed();
            break;
        case 1: 
            settings.increaseMeteoriteSpawnSpeed();
            break;
    }
    return 0;

}

int Game::scaleBuffs(int scaleOption){
    int maxDifficulty = 0;
    switch(scaleOption){
        case 0:
            settings.increaseShipSpeed();
            break;
        case 1: 
            settings.increaseBulletSpeed();
            break;
        case 2: 
            settings.decreaseBulletShotDelay();
            break;
    }
    return 0;

}