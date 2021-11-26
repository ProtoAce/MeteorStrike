#ifndef CONSTANTS
#define CONSTANTS

#include <string>
#include <vector>

//window size
const double WINDOW_HEIGHT = 650;
const double WINDOW_WIDTH = 650;

//textures
const std::string TITLE = "assets/sprites/MeteorStrike.png";
const std::string BULLET_TEXTURE = "assets/sprites/bullet.png";
const std::string SHIP_TEXTURE = "assets/sprites/spaceshiplvl2.png";
const std::string METEORITE_TEXTURE1 = "assets/sprites/meteorite1(1).png";
const std::string METEORITE_TEXTURE2 = "assets/sprites/meteorite2(1).png";
const std::string METEORITE_TEXTURE3 = "assets/sprites/meteorite3(1).png";
const std::vector<std::string> EXPLOSTION_TEXTURES = {"assets/sprites/explosion1.png", "assets/sprites/explosion2.png",
                                                      "assets/sprites/explosion3.png", "assets/sprites/explosion4.png",
                                                      "assets/sprites/explosion5.png", "assets/sprites/explosion6.png",
                                                      "assets/sprites/explosion7.png", "assets/sprites/explosion8.png",
                                                      "assets/sprites/explosion9.png", "assets/sprites/explosion10.png",
                                                      "assets/sprites/explosion11.png", "assets/sprites/explosion12.png",
                                                      "assets/sprites/explosion13.png"};

const std::string ARROW_LEFT = "assets/sprites/arrowLeft.png";
const std::string ARROW_RIGHT = "assets/sprites/arrowRight.png";
const std::string HIGHSCORE_FILE = "assets/gameData/intVectorLoad.txt";
const std::string BACKGROUND_STARS = "assets/sprites/background/stars2.png";
const std::string SHIELD_TOKEN_TEXTURE = "assets/sprites/shieldToken.png";
const std::string SHIELD_TEXTURE = "assets/sprites/shield.png";
const std::string RAPID_SHOT_TOKEN_TEXTURE = "assets/sprites/rapidShotToken.png";
const std::string RAPID_SHOT_TEXTURE = "assets/sprites/rapidShot.png";
const std::string PAUSE_TEXTURE = "assets/sprites/pause.png";
const std::string PLAY_TEXTURE = "assets/sprites/play.png";
const std::string SONG_1 = "assets/audio/8bit/AdhesiveWombat-NightShade.ogg";
//font
const std::string FONT = "assets/font/arcadeFont.ttf";

//game features
const int MAX_DIFFICULTY = 1;
const int MAX_BUFF = 1;
const int MAX_SHIP_SPEED = 12;
const int MAX_BULLET_SPEED = -30;
const int MIN_BULLET_SHOT_DELAY = 4;
const int MAX_METEORITE_SPEED = 10;
const int MAX_METEORITE_SPAWN_SPEED = 5;
const int BUFF_SCALE_RATE = 10;
const int DIFFICULTY_SCALE_RATE = 10;
const int TOKEN_SPEED = 5;
const int POWER_UP_RATE = 10;

//powerup enum
enum PowerUpTypes{
    SHIELD = 0,
    RAPID_SHOT = 1
};

#endif