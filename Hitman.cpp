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
    Item* vacio; 
    this->inventory.push_back(vacio);
}

int Hitman::getItemIndex(Item* item){ //Regresa el índice donde se encuentra el item ingresado
    for (int i = 0; i < this->inventory.size(); i++){
        if (item == this->inventory[i]){
            return i;
        }
    }
    return -1;
}

Item* Hitman::seekItem(string itemName){ //Busca el item que corresponde al nombre del item ingresado
    for (auto &item : this->inventory){
        if (item->getName() == itemName){
            return item;
        }
    }
    if (itemName == getDisguise()->getName()){ //Busca si el item en realidad se refería a un objeto de tipo Clothes
        Item* item = getDisguise();
        return item; 
    }
    cout << "No tienes ningún item que tenga este nombre" << endl;
    return nullptr;
}

Item* Hitman::getItemType(string itemType){ //Busca el item por tipo
    for (auto &item : this->inventory){
        if (item->getType() == itemType){
            return item;
        }
    }
    return nullptr;
}

int Hitman::getInventorySpaceUsed(){ //Regresa el espacio usado en el inventario
    int suma = 0;
    for (auto &item : this->inventory){
        suma += item->getSpace(); //Lo busca por peso
    }
    return suma;
}


void Hitman::addItem(string newItemname){ //Agrega un item al jugador
    Item* newItem = this->location->getItem(newItemname); //Busca el item
    
    if (newItem != nullptr){ //Si no es nulo:
        int maxInventory = 5;
        if (this->backPack){ //Establece el tamaño máximo del inventario si es que tiene mochila o no
            maxInventory = 10;
        }
        if (newItem->getSpace() <= (maxInventory - getInventorySpaceUsed())){ //Si aún tienes espacio para agregar ese objeto al inventario...
            if (newItem->getType() == "Mochila"){ //Si lo que recogiste era una mochila:
                this->backPack = true; //Se actualiza el atributo
                this->location->removeItem(newItem); //Se elimina el item del cuarto
                cout << "Item añadido exitosamente\nAhora ya tienes más espacio en el inventario (10)" << endl;
            } else if (newItem->getType() == "Ropa"){ //Si el item recogido era ropa
                if (Clothes* newClothes = dynamic_cast<Clothes*>(newItem)){ //Se hace un downcasting para convertir el apuntador item a uno de Clothes
                    Item* currentClothes = getDisguise(); //Se guarda la ropa actual en un apuntador de Item
                    this->location->setItem(currentClothes); //Agrega la ropa que teníamos al cuarto
                    setDisguise(newClothes); //Nos cambia de ropa
                    this->location->removeItem(newItem); //Elimina la ropa que recogimos
                    cout << "Te has cambiado de ropa exitosamente" << endl;
                }
                
            } else{ //Si no es ni mochila ni ropa:
                this->inventory.push_back(newItem); //Agrega el item
                this->location->removeItem(newItem); //Elimina el item del cuarto
                cout << "Item añadido exitosamente" << endl;
            }
        } else { //Si ya no hay espacio en el inventario arroja el error:
            throw "No tienes más espacio en el inventario\n";
        }
    }
}

bool Hitman::hasBackPack(){ //Verifica que tengas mochila
    return this->backPack;
}

Room* Hitman::getLocation(){ 
    return this->location;
}

void Hitman::setLocation(Room* newRoom){ //Actualiza el cuarto
    this->location = newRoom;
}

bool Hitman::move(string dir){
    bool returnType = false;
    Room* voyA=getLocation()->getExit(dir); //Busca la salida del cuarto
    if (voyA!=nullptr){ //Si esta no regresa un valor nulo:
        if (voyA->needsKey()){ //Busca si necesita llave
            
            cout << "Este cuarto necesita una llave...\n";
            
        } else if (voyA->needsTool()){ //Busca si necesita herramienta para abrirse
            
            cout << "Este cuarto parece estar trabado...\n";
             
        } else {
            setLocation(voyA); //Te cambia de cuarto
            returnType = true; //Regresa un bool 
        }
        
    } else {
        cout << "Este cuarto no es una salida para " << getLocation()->getName() << endl; //Mensaje de alerta al usuario
    }
    bool det = true;
    for (auto& ropa : getLocation()->getAccesClothes()){ //Busca que con la ropa que traigas puedas entrar al cuarto sin ser detectado
        if (getDisguise()->getName() == ropa->getName()){
            det = false;
            break;
        }
    }
    this->detected = det;
    
    return returnType;
}

void Hitman::viewInventory(){ //Despliega inventario
    cout << "\t\tINVENTARIO:\n\n";

    int maxInventory = 5;
    if (hasBackPack()){ //Si tiene mochila, ya tienes más espacio en el inventario
        maxInventory = 10;
    }
    cout << "Espacio restante: " << maxInventory - getInventorySpaceUsed() << endl;

    for (int i = 1; i < this->inventory.size(); i++){
        
        if (this->inventory[i]->getType() != "Mochila" || this->inventory[i]->getType() != "Llave"){
            cout << this->inventory[i]->getDescription() << endl;
            cout << "-----------------------------------" << endl;
        }
    }
    cout << getDisguise()->getDescription() << endl;
    cout << "Ingresa la palabra 'usar' o 'dejar' seguido del nombre del objeto de acuerdo a lo que quieras hacer.\nSi quieres salir del inventario escribe 'salir': " << endl;

}

vector<Item*> Hitman::getWholeInventory(){
    return this->inventory;
}

void Hitman::dropItem(string item){
    Item* dropObject = seekItem(item); //Busca el item
    string message;
    if (dropObject != nullptr){ // Si no es nulo:
        if ( dropObject->getType() != "Ropa"){ //verifica que no se intente dropear ropa
            this->location->setItem(dropObject);
            int index = getItemIndex(dropObject);
            this->inventory.erase(this->inventory.begin() + index);
            message = "Item dropeado exitosamente";
        } else{
            message = "No puedes dropear ropa";
        }
        
    } else{
        message = "El item ingresado no coincide con ningún item de tu inventario";
    }
    cout << message << endl;
}

void Hitman::removeItem(Item* usedItem){ //Quita el item del inventario
    int removed = getItemIndex(usedItem);
    this->inventory.erase(this->inventory.begin()+removed);
}



void Hitman::neutralizeNpc(string npc){ //Neutraliza el npc
    Npc* neutralize = getLocation()->getNpc(npc);
    if (neutralize != nullptr){
        this->detected = this->location->removeCharacter(npc); //Se actualiza el estado si fue detectado o no
        
    } else {
        cout << "No hay ningún personaje con este nombre en este cuarto\n";
    }
}

void Hitman::distractNpc(string npc){ //Distrae un npc
    Npc* distract = getLocation()->getNpc(npc);
    if (distract != nullptr){
       distract->setDistracted(true); //Actualiza el atributo del npc a distraído
    } else{
        cout << "\nNo hay ningún npc con este nombre\n";
    }
}
    
bool Hitman::isDetected(){
    return this->detected;
}


