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
    vector<Npc*> npcBaldio;
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
    npcBaldio.push_back(new Npc("Repartidor",cargador2,noItem3));

    Clothes* mesero1 = new Clothes("Ropa","Disfraz de mesero","Puedes entrar a la cocina, comedor y almacén",0,"Mesero");
    Clothes* mesero2 = new Clothes("Ropa","Disfraz de mesero","Puedes entrar a la cocina, comedor y almacén",0,"Mesero");
    Clothes* mesero3 = new Clothes("Ropa","Disfraz de mesero","Puedes entrar a la cocina, comedor y almacén",0,"Mesero");
    Clothes* chef = new Clothes("Ropa","Disfraz de chef","Puedes entrar a la cocina",0,"Chef");
    Item* bandeja = new Item("Distractor","Bandeja","La usan los meseros, pero no veo por qué guardarla", 2);
    Item* cuchillo = new Item("Arma", "Cuchillo","Se ve que es de alta calidad, está muy filoso", 3);
    Item* noItem4;
    Item* noItem5;
    npcCocina.push_back(new Npc("Chef",chef,cuchillo));
    npcCocina.push_back(new Npc("Mesero",mesero1,noItem4));
    npcComedor.push_back(new Npc("Mesero",mesero2,bandeja));
    npcAlmacen.push_back(new Npc("Mesero",mesero3,noItem5));
    
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

    vector<Npc*> npcBoveda;
    npcBoveda.push_back(nullptr);

    vector<Clothes*> accessParking;
    Clothes* hitmanClothes = new Clothes("Ropa","Ropa normal","Ropa común, cuidado que puede llamar la atención",0,"Hitman");
    accessParking.push_back(hitmanClothes);
    accessParking.push_back(mesero1);
    accessParking.push_back(chef);
    accessParking.push_back(valet);
    accessParking.push_back(cargador1);
    accessParking.push_back(ejecutivo);
    accessParking.push_back(guardia1);

    vector<Clothes*> accessBaldio = accessParking;
    vector<Clothes*> accessAlmacen;
    accessAlmacen.push_back(cargador1);
    accessAlmacen.push_back(mesero1);

    vector<Clothes*> accessCocina;
    accessCocina.push_back(mesero1);
    accessCocina.push_back(chef);
    
    vector<Clothes*> accessComedor;
    accessComedor.push_back(mesero1);
    accessCocina.push_back(ejecutivo);

    vector<Clothes*> accessSala;
    accessSala.push_back(ejecutivo);
    accessSala.push_back(guardia1);

    vector<Clothes*> accessBanio = accessParking;

    vector<Clothes*> accessBoveda;
    accessBoveda.push_back(ejecutivo);

    Room* estacionamiento = new Room("Estacionamiento","Lugar donde puedes aparcar tu coche y el del valet te lo cuidará",accessParking,itemsParking,npcParking,false,false);
    Room* baldio = new Room("Terreno Baldío","Parece que está muy abandonado por aquí, al parecer aquí es donde estacionan el camion de repartidores",accessBaldio,itemsBaldio,npcBaldio,false,false);
    Room* almacen = new Room("Almacén","Aquí guardan toda la comida para la semana",accessAlmacen,itemsAlmacen,npcAlmacen,false,true);
    Room* cocina = new Room("Cocina","Aquí cocinan la comida para el ejecutivo de alto mando",accessCocina,itemsCocina,npcCocina,false,false);
    Room* comedor = new Room("Comedor","Aquí es la sala de reuniones o para otros es el comedor",accessComedor,itemsComedor,npcComedor,false,false);
    Room* sala = new Room("Sala","Sala de estar de la casa, donde puedes esperar para entrar al comedor",accessSala,itemsSala,npcSala,false,false);
    Room* banio = new Room("Baño","Wow, todo está hecho de porcelana y mármol, ¡Bastante elegante!",accessBanio,itemsBanio,npcBanio,false,false);
    Room* boveda = new Room("Bóveda","Mira, aquí guardan los papeles...",accessBoveda,itemsBoveda,npcBoveda,true,false);

    vector<Room*> exitsParking;
    exitsParking.push_back(baldio);
    exitsParking.push_back(sala);
    estacionamiento->setExits(exitsParking);

    vector<Room*> exitsBaldio;
    exitsBaldio.push_back(estacionamiento);
    exitsBaldio.push_back(almacen);
    baldio->setExits(exitsBaldio);

    vector<Room*> exitsAlmacen;
    exitsAlmacen.push_back(baldio);
    exitsBaldio.push_back(cocina);
    almacen->setExits(exitsAlmacen);

    vector<Room*> exitsCocina;
    exitsCocina.push_back(almacen);
    exitsCocina.push_back(comedor);
    cocina->setExits(exitsCocina);

    vector<Room*> exitsComedor;
    exitsComedor.push_back(cocina);
    exitsComedor.push_back(sala);
    comedor->setExits(exitsComedor);
    
    vector<Room*> exitsSala;
    exitsSala.push_back(comedor);
    exitsSala.push_back(boveda);
    exitsSala.push_back(banio);
    exitsSala.push_back(estacionamiento);
    sala->setExits(exitsSala);

    vector<Room*> exitsBanio;
    exitsBanio.push_back(sala);
    banio->setExits(exitsBanio);

    vector<Room*> exitsBoveda;
    exitsBoveda.push_back(sala);
    banio->setExits(exitsBoveda);
}

int main(){
    

    return 0;
}

