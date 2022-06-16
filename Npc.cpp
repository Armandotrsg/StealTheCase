#include "Npc.h"

Npc::Npc(){
    this->distracted = false;
}

Npc::Npc(string nombre, Clothes* ropa, Item* objeto): Character(nombre, ropa){ //Los npc también tienen ropa a dropear
    this->dropItem = objeto;
    this->distracted = false;
}

Item* Npc::getDropItem(){
    return this->dropItem;
}

bool Npc::getDistracted(){
    return this->distracted; //Devuelve si el npc está distraído
}


void Npc::setDropItem(Item* objeto){
    this->dropItem = objeto;
}

void Npc::setDistracted(bool distracted){
    this->distracted = distracted;
}
