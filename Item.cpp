#include "Item.h"

Item::Item(){
    this->description = "";
    this->space = 0;
    this->type = "";
}

Item::Item(string type, string description,int space){
    this->description = description;
    this->space = space;
    this->type = type;
}

string Item::getDescription(){
    return this->description + "\nPeso: " + to_string(this->space);
}

void Item::setDescription(string description){
    this->description = description;
}

int Item::getSpace(){
    return this->space;
}

void Item::setSpace(int space){
    this->space = space;
}

string Item::getType(){
    return this->type;
}

void Item::setType(string type){
    this->type = type;
}






