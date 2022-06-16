#include "Clothes.h"

Clothes::Clothes(){
    this->job = "";
}

Clothes::Clothes(string type,string name,string description,int space,string job) : Item(type,name,description,space){
    this->job = job;
    
}

string Clothes::getJob() const{
    return this->job;
}

void Clothes::setJob(string job){
    this->job = job;
}

string Clothes::getDescription(){
    return Item::getDescription() + "\nRopa de " + getJob() + "\n"; //polimorfismo de la clase base item
}

