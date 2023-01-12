#include "gameMusic.h"

GameMusic::GameMusic(sf::RenderWindow *window){
    opacity = 200;
    playingMusic = true;
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
    playSprite.setPosition(580,10);
    if(!pauseTexture.loadFromFile(PAUSE_TEXTURE)){
        return EXIT_FAILURE;
    }
    pauseSprite.setTexture(pauseTexture);
    pauseSprite.setPosition(580,10);

    return 0;
}

void GameMusic::pause(){
    playingMusic = false;
    opacity = 200;
    music.pause();
}

void GameMusic::play(){
    playingMusic = true;
    opacity = 200;
    music.play();
}

bool GameMusic::songEnded(){
    if(playingMusic == true){
        if(music.getStatus() == sf::SoundSource::Stopped){
            return true;
        }
    }
    return false;
}


int GameMusic::nextSong(){
    currentSong = (currentSong + 1)%songs.size();
    if(playingMusic == true){
        if (!music.openFromFile(songs.at(currentSong))){
            return EXIT_FAILURE;
        }
        music.play();
    }
    return 0;
}

void GameMusic::draw(){
    if(opacity > 0){
        if(playingMusic){
            playSprite.setColor(sf::Color(139,104,75, opacity));
            win->draw(playSprite);
        }else{
            pauseSprite.setColor(sf::Color(139,104,75, opacity));
            win->draw(pauseSprite);
        }
        opacity = opacity-4;
    }
}

bool GameMusic::playing(){
    return playingMusic;
}

void GameMusic::setOpacity(int op){
    opacity = op;
}