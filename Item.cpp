#include "Item.h"

Item::Item(){
    this->description = "";
    this->space = 0;
    
}

Item::Item(string description,int space, vector<string> _actionWord){
    this->description = description;
    this->space = space;
    for (auto &var:_actionWord){
        this->actionWord.push_back(var);
    }
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







