#include "Npc.h"

Npc::Npc(){
    this->distracted = false;
    this->neutralized = false;
}

Npc::Npc(string nombre, Clothes* ropa, Item* objeto, bool distracted, bool neutralized): Character(nombre, ropa){
    this->dropItem = objeto;
    this->distracted = distracted;
    this->neutralized = neutralized;
}