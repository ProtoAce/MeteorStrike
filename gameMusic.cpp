#include "gameMusic.h"

GameMusic::GameMusic(sf::RenderWindow *window){
    opacity = 256;
    playing = true;
    currentSong = 0;
    win = window;
}

int GameMusic::load(){
    //audio

    // for(int i = 0; i < MUSIC_FILES.size(); i++){
    //     sf::Music song;
    //     if (!song.openFromFile(MUSIC_FILES.at(i))){
    //         return EXIT_FAILURE;
    //     }
    //     std::cout << "test1\n";
    //     music.push_back(&song);
    //     std::cout << "test2\n";
    // }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(songs.begin(), songs.end(), std::default_random_engine(seed));

    if (!music.openFromFile(songs.at(currentSong))){
        return EXIT_FAILURE;
    }
    music.setVolume(60);

    //textures
    if(!playTexture.loadFromFile(PLAY_TEXTURE)){
        return EXIT_FAILURE;
    }
    playSprite.setTexture(playTexture);
    playSprite.setPosition(530,50);
    if(!pauseTexture.loadFromFile(PAUSE_TEXTURE)){
        return EXIT_FAILURE;
    }
    pauseSprite.setTexture(pauseTexture);
    pauseSprite.setPosition(530,50);

    return 0;
}

void GameMusic::pause(){
    playing = false;
    opacity = 100;
    music.pause();
}

void GameMusic::play(){
    playing = true;
    opacity = 256;
    music.play();
}

bool GameMusic::songEnded(){
    if(playing == true){
        if(music.getStatus() == sf::SoundSource::Stopped){
            currentSong = (currentSong + 1)%songs.size();
            return true;
        }
    }
    return false;
}


int GameMusic::nextSong(){
    if(playing == true){
        if (!music.openFromFile(songs.at(currentSong))){
            return EXIT_FAILURE;
        }
        music.play();
    }
    return 0;
}

void GameMusic::draw(){
    if(opacity > 0){
        if(playing){
            playSprite.setColor(sf::Color(255, 255, 255, opacity));
            win->draw(playSprite);
        }else{
            pauseSprite.setColor(sf::Color(255, 255, 255, opacity));
            win->draw(pauseSprite);
        }
        opacity = opacity-2;
    }
}