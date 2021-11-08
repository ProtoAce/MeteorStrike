#include "settings.h"

int Settings::increaseShipSpeed(){
    if(shipSpeed == MAX_SHIP_SPEED){
        std::cout << "maxbuff\n";
        return MAX_BUFF;
    }else{
        shipSpeed++;
        return 0;
    }
}
int Settings::increaseBulletSpeed(){
    if(bulletSpeed == MAX_BULLET_SPEED){
        std::cout << "maxbuff\n";
        return MAX_BUFF;
    }else{
        bulletSpeed--;
        return 0;
    }
}
int Settings::decreaseBulletShotDelay(){
    if(bulletShotDelay == MIN_BULLET_SHOT_DELAY){
        std::cout << "maxbuff\n";
        return MAX_BUFF;
    }else{
        bulletShotDelay--;
        return 0;
    }
}
int Settings::increaseMeteoriteSpeed(){
    if(meteoriteSpeed == MAX_METEORITE_SPEED){
        std::cout << "maxdifficulty\n";
        return MAX_DIFFICULTY;
    }else{
        meteoriteSpeed++;
        return 0;
    }
}
int Settings::increaseMeteoriteSpawnSpeed(){
    if(meteoriteSpawnSpeed == MAX_METEORITE_SPAWN_SPEED){
        std::cout << "maxdifficulty\n";
        return MAX_DIFFICULTY;
    }else{
        meteoriteSpawnSpeed--;
        return 0;
    }
}