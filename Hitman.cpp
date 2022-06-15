#include "Hitman.h"

Hitman::Hitman(){
    this->detected = false;
    this->backPack = false;
    
    this->inventory.push_back(new Item);
    this->location = nullptr;
}

Hitman::Hitman(string name,Clothes* disguise,Room* location) : Character(name,disguise){
    this->location = location;
    this->backPack = false;
    this->detected = false;
    Item* vacio; //Borrar
    this->inventory.push_back(vacio);
}

int Hitman::getItemIndex(Item* item){
    for (int i = 0; i < this->inventory.size(); i++){
        if (item == this->inventory[i]){
            return i;
        }
    }
    return -1;
}

Item* Hitman::seekItem(string itemName){
    for (auto &item : this->inventory){
        if (item->getName() == itemName){
            return item;
        }
    }
    if (itemName == getDisguise()->getName()){
        Item* item = getDisguise();
        return item;
    }
    cout << "No tienes ningún item que tenga este nombre" << endl;
    return nullptr;
}

Item* Hitman::getItemType(string itemType){
    for (auto &item : this->inventory){
        if (item->getType() == itemType){
            return item;
        }
    }
    return nullptr;
}

int Hitman::getInventorySpaceUsed(){
    int suma = 0;
    for (auto &item : this->inventory){
        suma += item->getSpace();
    }
    return suma;
}

void Hitman::addSpecificItem(Item* item){
    this->inventory.push_back(item);
}

void Hitman::addItem(string newItemname){
    Item* newItem = this->location->getItem(newItemname);
    
    if (newItem != nullptr){
        int maxInventory = 5;
        if (hasBackPack()){
            maxInventory = 10;
        }
        if (newItem->getSpace() <= (maxInventory - getInventorySpaceUsed())){
            if (newItem->getType() == "Mochila"){
                bool idk = hasBackPack();
                this->location->removeItem(newItem);
            } else if (newItem->getType() == "Ropa"){
                if (Clothes* newClothes = dynamic_cast<Clothes*>(newItem)){
                    Item* currentClothes = getDisguise();
                    this->location->setItem(currentClothes);
                    setDisguise(newClothes);
                    this->location->removeItem(newItem);
                }
                
            } else{
                this->inventory.push_back(newItem);
                this->location->removeItem(newItem);
            }
        } else {
            cout << "No tienes más espacio en el inventario\n";
        }
    }
}

bool Hitman::hasBackPack(){
    for (auto &item : this->inventory){
        if (item->getType() == "Mochila"){
            this->backPack = true;
        }
    }
    return backPack;
}

Room* Hitman::getLocation(){
    return this->location;
}

void Hitman::setLocation(Room* newRoom){
    this->location = newRoom;
}

bool Hitman::move(string dir){
    bool returnType = false;
    Room* voyA=getLocation()->getExit(dir);
    if (voyA!=nullptr){
        if (voyA->needsKey()){
            
            cout << "Este cuarto necesita una llave...\n";
            
        } else if (voyA->needsTool()){
            
            cout << "Este cuarto parece estar trabado...\n";
             
        } else {
            setLocation(voyA);
            returnType = true;
        }
        
    } else {
        cout << "Este cuarto no es una salida para " << getLocation()->getName() << endl;
    }
    bool det = true;
    for (auto& ropa : getLocation()->getAccesClothes()){
        if (getDisguise()->getName() == ropa->getName()){
            det = false;
            break;
        }
    }
    this->detected = det;
    
    return returnType;
}

void Hitman::viewInventory(){
    cout << "\t\tINVENTARIO:\n\n";
    for (int i = 1; i < this->inventory.size(); i++){
        
        if (this->inventory[i]->getType() != "Mochila" || this->inventory[i]->getType() != "Llave"){
            cout << this->inventory[i]->getDescription() << endl;
            cout << "-----------------------------------" << endl;
        }
    }
    cout << getDisguise()->getDescription() << endl;
    cout << "Ingresa la palabra 'usar' o 'dejar' seguido del nombre del objeto de acuerdo a lo que quieras hacer: " << endl;

}

vector<Item*> Hitman::getWholeInventory(){
    return this->inventory;
}

void Hitman::dropItem(string item){
    Item* dropObject = seekItem(item);
    string message;
    if (dropObject != nullptr){
        if ( dropObject->getType() != "Ropa"){
            this->location->setItem(dropObject);
            int index = getItemIndex(dropObject);
            this->inventory.erase(this->inventory.begin() + index);
            message = "Item eliminado exitosamente";
        }
        
    } else{
        message = "El item ingresado no coincide con ningún item de tu inventario";
    }
    cout << message << endl;
}



void Hitman::neutralizeNpc(string npc){
    Npc* neutralize = getLocation()->getNpc(npc);
    if (neutralize != nullptr){
        this->detected = this->location->removeCharacter(npc);
        
    } else {
        cout << "No hay ningún personaje con este nombre en este cuarto\n";
    }
}

void Hitman::distractNpc(string npc){
    Npc* distract = getLocation()->getNpc(npc);
    if (distract != nullptr){
       distract->setDistracted(true);
    } else{
        cout << "\nNo hay ningún npc con este nombre\n";
    }
}
    
bool Hitman::isDetected(){
    return this->detected;
}


