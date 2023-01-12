#ifndef GAME_MUSIC
#define GAME_MUSIC

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>
#include "settings.h"
#include "constants.h"

class GameMusic{

    float x,y;

    sf::Texture playTexture;
    sf::Sprite playSprite;

    sf::Texture pauseTexture;
    sf::Sprite pauseSprite;

    sf::RenderWindow *win;


    std::vector<std::string> songs{SONG_1, SONG_2, SONG_3,
                                   SONG_4, SONG_5, SONG_6,
                                   SONG_7};
    sf::Music music;


    // std::vector<sf::Music *> music;

    bool playingMusic;
    int currentSong;
    int opacity;

    public:

    GameMusic(sf::RenderWindow *window);

    int load();
    void draw();

    void setOpacity(int op);
    bool playing();
    void pause();
    void play();
    bool songEnded();
    int nextSong();




};


#endif