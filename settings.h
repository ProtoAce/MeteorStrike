#ifndef SETTINGS
#define SETTINGS

#include <string>
#include <vector>

//window size
const double WINDOW_HEIGHT = 500;
const double WINDOW_WIDTH = 500;

//game settings
const int SHIP_SPEED = 5;
const int BULLET_SPEED = -15; // negative to move up screen
const int BULLET_SHOOT_DELAY = 10; //seconds * fps
const int METEORITE_SPEED = 5;
const int METEORITE_COUNT = 50;
const int METEORITE_SPAWN_SPEED = 15; // seconds * fps

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

//font
const std::string FONT = "arcadeFont.ttf";





#endif