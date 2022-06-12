#include "Hitman.h"
#include "Npc.h"
#include "Clothes.h"
#include "Room.h"

void mensajeIntro(){
    cout << "Bienvenido a Hitman";
}

void setup(){
    //Creamos e inicializamos los vectores de tipo Item de cada cuarto que se va a crear
    vector <Item*>  itemsParking;
    vector <Item*>  itemsBaldio;
    vector <Item*>  itemsAlmacen;
    vector <Item*>  itemsCocina;
    vector <Item*>  itemsBoveda;
    vector <Item*>  itemsComedor;
    vector <Item*>  itemsSala;
    vector <Item*>  itemsBanio;

    itemsParking.push_back(new Item("Distractor", "Moneda","Pequeño objeto de níquel, podría hacer ruido...", 1));
    itemsParking.push_back(new Item("Arma", "Navaja", "Un poco oxidada, pero aún tiene filo...", 2));
    itemsParking.push_back(new Item("Arma", "Cloroformo","Ayuda a neutralizar enemigos.", 1));

    itemsBaldio.push_back(new Item("Mochila", "Morral","Un poco percudido, pero aun cumple con su función", 0));
    itemsBaldio.push_back(new Item("Herramienta", "Ganzúa","Ayuda a abrir ciertas puertas cerradas con llave.", 3));
    itemsBaldio.push_back(new Item("Inutil", "Fotogrsfia","Parece que fue tomada en esta misma mansión. La fecha dice 17-mayo-2016", 1));

    itemsAlmacen.push_back(new Item("Distractor", "Tomate","No huele nada bien, pero podrías lanzarlo...", 2));
    itemsAlmacen.push_back(new Item("Inutil", "Recibo de Compras"," Tiene escrito: 'Harina, Tomates, Cebollas, Huevo, Leche...'", 1));

    itemsCocina.push_back(new Item("Arma", "Cuchillo","Se ve que es de alta calidad, está muy filoso", 3));
    itemsCocina.push_back(new Item("Inutil","Bandeja","La usan los meseros, pero no veo por qué guardarla", 2));
    itemsCocina.push_back(new Item("Arma","Cucharón","¡Con esto podrás comer sopa!",1));

    itemsBoveda.push_back(new Item("Objetivo","Papeles", "Llévalo con el jefe sin ser descubierto",4));
    
    itemsComedor.push_back(new Item("Inutil","Plato","Guárdalo para cuando encuentres algún tipo de comida",1));
    itemsComedor.push_back(new Item("Distractor","Bandeja de plata","Wow, puedes ver tu reflejo con esto",2));
    itemsComedor.push_back(new Item("Distractor","Sopa","Good soup",1));
}

int main(){
    

    return 0;
}

