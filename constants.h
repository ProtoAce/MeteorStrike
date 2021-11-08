#ifndef CONSTANTS
#define CONSTANTS

#include <string>
#include <vector>

//window size
const double WINDOW_HEIGHT = 500;
const double WINDOW_WIDTH = 500;

//textures
const std::string BULLET_TEXTURE = "bullet.png";
const std::string SHIP_TEXTURE = "spaceshiplvl2.png";
const std::string METEORITE_TEXTURE1 = "meteorite1(1).png";
const std::string METEORITE_TEXTURE2 = "meteorite2(1).png";
const std::string METEORITE_TEXTURE3 = "meteorite3(1).png";
const std::vector<std::string> EXPLOSTION_TEXTURES = {"explosion1.png", "explosion2.png",
                                                      "explosion3.png", "explosion4.png",
                                                      "explosion5.png", "explosion6.png",
                                                      "explosion7.png", "explosion8.png",
                                                      "explosion9.png", "explosion10.png",
                                                      "explosion11.png", "explosion12.png",
                                                      "explosion13.png"};

const std::string ARROW_LEFT = "arrowLeft.png";
const std::string ARROW_RIGHT = "arrowRight.png";


//font
const std::string FONT = "arcadeFont.ttf";

//game features
const int MAX_DIFFICULTY = 1;
const int MAX_BUFF = 1;
const int MAX_SHIP_SPEED = 20;
const int MAX_BULLET_SPEED = -50;
const int MIN_BULLET_SHOT_DELAY = 3;
const int MAX_METEORITE_SPEED = 20;
const int MAX_METEORITE_SPAWN_SPEED = 3;



#endif