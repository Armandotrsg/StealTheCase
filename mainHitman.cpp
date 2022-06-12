#include "Hitman.h"
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

    //itemsCocina.push_back(new Item("Arma", "Cuchillo","Se ve que es de alta calidad, está muy filoso", 3));
    itemsCocina.push_back(new Item("Inutil","Bandeja","La usan los meseros, pero no veo por qué guardarla", 2));
    itemsCocina.push_back(new Item("Arma","Cucharón","¡Con esto podrás comer sopa!",1));

    itemsBoveda.push_back(new Item("Objetivo","Papeles", "Llévalo con el jefe sin ser descubierto",4));
    
    itemsComedor.push_back(new Item("Inutil","Plato","Guárdalo para cuando encuentres algún tipo de comida",1));
    itemsComedor.push_back(new Item("Distractor","Bandeja de plata","Wow, puedes ver tu reflejo con esto",2));
    itemsComedor.push_back(new Item("Distractor","Sopa","Good soup",1));

    itemsSala.push_back(new Item("Arma","Florero","Está hecho de barro y tiene una margarita sembrada",3));
    itemsSala.push_back(new Item("Distractor","Gameboy","Puedes pasar horas y horas jugando con él",2));
    itemsSala.push_back(new Item("Inútil","Almohada","Esto puede ser útil cuando tengas sueño",3));

    itemsBanio.push_back(new Item("Arma","Amoniaco","Esto puede ser peligroso para hacer la limpieza",3));
    itemsBanio.push_back(new Item("Inútil","Cepillo de dientes","Siempre hay que tener buen aliento",1));

    //La llave la dropea un Npc

    vector<Npc*> npcParking;
    vector<Npc*> npcAlmacen;
    vector<Npc*> npcCocina;
    vector<Npc*> npcComedor;
    vector<Npc*> npcSala;
    vector<Npc*> npcBanio;

    Item* noItem1;
    Clothes* valet = new Clothes("Ropa","Disfraz de valet","Puedes entrar a la sala con esto",0,"Valet");
    npcParking.push_back(new Npc("Valet",valet,noItem1));

    Clothes* cargador1 = new Clothes("Ropa","Disfraz de repartidor","Puedes entrar al almacén con esto",0,"Repartidor");
    Clothes* cargador2 = new Clothes("Ropa","Disfraz de repartidor","Puedes entrar al almacén con esto",0,"Repartidor");
    Item* noItem2;
    Item* noItem3;
    npcAlmacen.push_back(new Npc("Repartidor",cargador1,noItem2));
    npcAlmacen.push_back(new Npc("Repartidor",cargador2,noItem3));

    Clothes* mesero1 = new Clothes("Ropa","Disfraz de mesero","Puedes entrar a la cocina, comedor y almacén",0,"Mesero");
    Clothes* mesero2 = new Clothes("Ropa","Disfraz de mesero","Puedes entrar a la cocina, comedor y almacén",0,"Mesero");
    Clothes* chef = new Clothes("Ropa","Disfraz de chef","Puedes entrar a la cocina",0,"Chef");
    Item* bandeja = new Item("Distractor","Bandeja","La usan los meseros, pero no veo por qué guardarla", 2);
    Item* cuchillo = new Item("Arma", "Cuchillo","Se ve que es de alta calidad, está muy filoso", 3);
    Item* noItem4;
    npcCocina.push_back(new Npc("Chef",chef,cuchillo));
    npcCocina.push_back(new Npc("Mesero",mesero1,noItem4));
    npcComedor.push_back(new Npc("Mesero",mesero2,bandeja));
    
    Clothes* target = new Clothes("Ropa","Disfraz de ejecutivo","Puedes entrar a la sala y al comedor",0,"Ejecutivo");
    Item* llave = new Item("Llave","Llave","Creo que esto es clave para lograr mi objetivo",4);
    npcComedor.push_back(new Npc("Ejecutivo",target,llave));

    Clothes* guardia1 = new Clothes("Ropa","Disfraz de guardia","Puedes entrar a la bóveda",0,"Guardia");
    Clothes* guardia2 = new Clothes("Ropa","Disfraz de guardia","Puedes entrar a la bóveda",0,"Guardia");
    Item* taser = new Item("Distractor","Taser","Cuidado que te puede paralizar",3);
    Item* pistola = new Item("Arma","Pistola","Aunque solo le quede una bala puede ser de utilidad",4);
    npcSala.push_back(new Npc("Guardia 1",guardia1,taser));
    npcSala.push_back(new Npc("Guardia 2",guardia2,pistola));

    Clothes* ejecutivo = new Clothes("Ropa","Disfraz de ejecutivo","Puedes entrar a la sala y al comedor",0,"Ejecutivo");
    Item* pluma = new Item("Inutil","Pluma","Que bueno que tengo una, ya podré hacer mi lista de compras",1);
    npcBanio.push_back(new Npc("Ejecutivo",ejecutivo,pluma));
}

int main(){
    

    return 0;
}

