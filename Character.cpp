#include "Character.h"

Character::Character(){
    this->name = "";
}

Character::Character(string name, Clothes* disguise){
    this->name = name;
    this->disguise = disguise;
}

string Character::getName(){
    return this->name;
}

void Character::setName(string name){
    this->name = name;
}

Clothes* Character::getDisguise() const{
    return this->disguise;
}

void Character::setDisguise(Clothes* newClothes){
    this->disguise = newClothes;
}