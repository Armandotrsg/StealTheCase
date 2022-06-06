#include "Clothes.h"

Clothes::Clothes(){
    this->job = "";
}

Clothes::Clothes(string description,int space,vector<string> _actionWord,string job) : Item(description,space,_actionWord){
    this->job = job;
}

string Clothes::getJob() const{
    return this->job;
}

void Clothes::setJob(string job){
    this->job = job;
}

string Clothes::getDescription(){
    return Item::getDescription() + "\n\nAl ser la ropa que traes puesta no ocupa lugar en el inventario";
}

