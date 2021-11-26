#ifndef GAME_MUSIC
#define GAME_MUSIC

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include "settings.h"
#include "constants.h"
#include "powerUps.h"

class GameMusic{

    float x,y;

    sf::Texture playTexture;
    sf::Sprite playSprite;

    sf::Texture pauseTexture;
    sf::Sprite pauseSprite;

    sf::RenderWindow *win;


    std::vector<std::string> songs{SONG_1};
    sf::Music music;


    // std::vector<sf::Music *> music;

    bool playing;
    int currentSong;
    int opacity;

    public:

    GameMusic(sf::RenderWindow *window);

    int load();
    void draw();

    void pause();
    void play();
    bool songEnded();
    int nextSong();




};


#endif