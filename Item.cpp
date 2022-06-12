#include "Item.h"

Item::Item(){
    this->description = "";
    this->space = 0;
    this->type = "";
    this->name = "";
}

Item::Item(string type, string name,string description,int space){
    this->description = description;
    this->space = space;
    this->type = type;
    this->name = name;
}

string Item::getDescription(){
    return this-> name + ": " + this->description + "\nPeso: " + to_string(this->space);
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

string Item::getName(){
    return this->name;
}

void Item::setName(string name){
    this->name = name;
}






