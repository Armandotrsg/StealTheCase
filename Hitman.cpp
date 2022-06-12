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

void Hitman::addItem(Item* newItem){
    int maxInventory = 5;
    if (hasBackPack()){
        maxInventory = 10;
    }
    if (newItem->getSpace() <= (maxInventory - getInventorySpaceUsed())){
        this->inventory.push_back(newItem);
        if (newItem->getType() == "Mochila"){
            bool idk = hasBackPack();
        } else if (newItem->getType() == "Atuendo"){
            if (Clothes* newClothes = dynamic_cast<Clothes*>(newItem)){
                setDisguise(newClothes);
            }
            dropItem(newItem->getType());
            
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
            Item* hasKey = seekItem("Llave");
            if (hasKey != nullptr){
                setLocation(voyA);
                returnType = true;
            } else {
                cout << "Este cuarto necesita una llave...\n";
            }
        } else if (voyA->needsTool()){
            Item* hasTool = getItemType("Herramienta");
            if (hasTool != nullptr){
                setLocation(voyA);
                returnType = true;
            } else{
                cout << "Este cuarto parece estar trabado...";
            }
        }
        setLocation(voyA);
        returnType = true;
    } else {
        cout << "Este cuarto no es una salida para " << getLocation()->getName() << endl;
    }

    for (auto& ropa : getLocation()->getAccesClothes()){
        if (getDisguise()->getJob() != ropa->getJob()){
            this->detected = true;
        }
    }
    
    return returnType;
}

void Hitman::viewInventory(){
    cout << "\t\tINVENTARIO\n";
    for (auto &item : this->inventory){
        if (item->getSpace() != 0){
            cout << item->getDescription() << endl;
            cout << "-----------------------------------" << endl;
        }
    }
    cout << "Ingresa la palabra USAR o DEJAR seguido del nombre del objeto de acuerdo a lo que quieras hacer" << endl;

}

void Hitman::dropItem(string item){
    Item* dropObject = seekItem(item);
    string message;
    if (dropObject != nullptr){
        this->location->addItem(dropObject);
        int index = getItemIndex(dropObject);
        this->inventory[index] = new Item;
        message = "Item eliminado exitosamente";
    } else{
        message = "El item ingresado no coincide con ningún item de tu inventario";
    }
    cout << message << endl;
}

void Hitman::changeClothes(Clothes* newClothes){
    this->setDisguise(newClothes);
    getLocation()->addItem(newClothes);
}

