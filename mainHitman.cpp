#include "Hitman.h"
#include "Clothes.h"
#include "Room.h"
#include <fstream>

void mensajeIntro(){
    ifstream archivoIntro;
    archivoIntro.open("mensajeIntro.txt");
    string mensaje;
    while (getline(archivoIntro,mensaje)){
        cout << mensaje << endl;
    }
    archivoIntro.close();
}

int main(){
    //mensajeIntro();
    //Creamos e inicializamos los vectores de tipo Item de cada cuarto que se va a crear

    Room* estacionamiento = new Room("Estacionamiento","Lugar donde puedes aparcar tu coche y el del valet te lo cuidará",false,false);
    Room* baldio = new Room("Terreno Baldío","Parece que está muy abandonado por aquí, al parecer aquí es donde estacionan el camion de repartidores",false,false);
    Room* almacen = new Room("Almacén","Aquí guardan toda la comida para la semana",false,true);
    Room* cocina = new Room("Cocina","Aquí cocinan la comida para el ejecutivo de alto mando",false,false);
    Room* comedor = new Room("Comedor","Aquí es la sala de reuniones o para otros es el comedor",false,false);
    Room* sala = new Room("Sala","Sala de estar de la casa, donde puedes esperar para entrar al comedor",false,false);
    Room* banio = new Room("Baño","Wow, todo está hecho de porcelana y mármol, ¡Bastante elegante!",false,false);
    Room* boveda = new Room("Bóveda","Mira, aquí guardan los papeles...",true,false);

    estacionamiento->setItem(new Item("Distractor", "Moneda","Pequeño objeto de níquel, podría hacer ruido...", 1));
    estacionamiento->setItem(new Item("Arma", "Navaja", "Un poco oxidada, pero aún tiene filo...", 2));
    estacionamiento->setItem(new Item("Arma", "Cloroformo","Ayuda a neutralizar enemigos.", 1));
    
    baldio->setItem(new Item("Mochila", "Morral","Un poco percudido, pero aun cumple con su función", 0));
    baldio->setItem(new Item("Herramienta", "Ganzúa","Ayuda a abrir ciertas puertas trabadas.", 3));
    baldio->setItem(new Item("Inutil", "Fotografía","Parece que fue tomada en esta misma mansión. La fecha dice 17-mayo-2016", 1));

    almacen->setItem(new Item("Distractor", "Tomate","No huele nada bien, pero podrías lanzarlo...", 2));
    almacen->setItem(new Item("Inutil", "Recibo de Compras"," Tiene escrito: 'Harina, Tomates, Cebollas, Huevo, Leche...'", 1));

    cocina->setItem(new Item("Inutil","Bandeja","La usan los meseros, pero no veo por qué guardarla", 2));
    cocina->setItem(new Item("Arma","Cucharón","¡Con esto podrás comer sopa!",1));

    boveda->setItem(new Item("Objetivo","Papeles", "Llévalo con el jefe sin ser descubierto",4));

    comedor->setItem(new Item("Inutil","Plato","Guárdalo para cuando encuentres algún tipo de comida",1));
    comedor->setItem(new Item("Distractor","Bandeja de plata","Wow, puedes ver tu reflejo con esto",2));
    comedor->setItem(new Item("Distractor","Sopa","Good soup",1));

    sala->setItem(new Item("Arma","Florero","Está hecho de barro y tiene una margarita sembrada",3));
    sala->setItem(new Item("Distractor","Gameboy","Puedes pasar horas y horas jugando con él",2));
    sala->setItem(new Item("Inútil","Almohada","Esto puede ser útil cuando tengas sueño",3));

    banio->setItem(new Item("Arma","Amoniaco","Esto puede ser peligroso para hacer la limpieza",3));
    banio->setItem(new Item("Inútil","Cepillo de dientes","Siempre hay que tener buen aliento",1));


    //La llave la dropea un Npc

    

    //All right
    Item* noItem1;
    Clothes* valet = new Clothes("Ropa","Disfraz de valet","Puedes entrar a la sala con esto",0,"Valet");
    estacionamiento->addNpc(new Npc("Valet",valet,noItem1));

    Clothes* cargador1 = new Clothes("Ropa","Disfraz de repartidor","Puedes entrar al almacén con esto",0,"Repartidor");
    Clothes* cargador2 = new Clothes("Ropa","Disfraz de repartidor","Puedes entrar al almacén con esto",0,"Repartidor");
    Item* noItem2;
    Item* noItem3;
    almacen->addNpc(new Npc("Repartidor",cargador1,noItem2));
    baldio->addNpc(new Npc("Repartidor",cargador2,noItem3));

    Clothes* mesero1 = new Clothes("Ropa","Disfraz de mesero","Puedes entrar a la cocina, comedor y almacén",0,"Mesero");
    Clothes* mesero2 = new Clothes("Ropa","Disfraz de mesero","Puedes entrar a la cocina, comedor y almacén",0,"Mesero");
    Clothes* mesero3 = new Clothes("Ropa","Disfraz de mesero","Puedes entrar a la cocina, comedor y almacén",0,"Mesero");
    Clothes* chef = new Clothes("Ropa","Disfraz de chef","Puedes entrar a la cocina",0,"Chef");
    Item* bandeja = new Item("Distractor","Bandeja","La usan los meseros, pero no veo por qué guardarla", 2);
    Item* cuchillo = new Item("Arma", "Cuchillo","Se ve que es de alta calidad, está muy filoso", 3);
    Item* noItem4;
    Item* noItem5;
    cocina->addNpc(new Npc("Chef",chef,cuchillo));
    cocina->addNpc(new Npc("Mesero",mesero1,noItem4));
    almacen->addNpc(new Npc("Mesero",mesero2,bandeja));
    comedor->addNpc(new Npc("Mesero",mesero3,noItem5));
    
    Clothes* target = new Clothes("Ropa","Disfraz de ejecutivo","Puedes entrar a la sala y al comedor",0,"Ejecutivo");
    Item* llave = new Item("Llave","Llave","Creo que esto es clave para lograr mi objetivo",4);
    comedor->addNpc(new Npc("Ejecutivo",target,llave));

    Clothes* guardia1 = new Clothes("Ropa","Disfraz de guardia","Puedes entrar a la bóveda",0,"Guardia");
    Clothes* guardia2 = new Clothes("Ropa","Disfraz de guardia","Puedes entrar a la bóveda",0,"Guardia");
    Item* taser = new Item("Distractor","Taser","Cuidado que te puede paralizar",3);
    Item* pistola = new Item("Arma","Pistola","Aunque solo le quede una bala puede ser de utilidad",4);
    sala->addNpc(new Npc("Guardia 1",guardia1,taser));
    sala->addNpc(new Npc("Guardia 2",guardia2,pistola));

    Clothes* ejecutivo = new Clothes("Ropa","Disfraz de ejecutivo","Puedes entrar a la sala y al comedor",0,"Ejecutivo");
    Item* pluma = new Item("Inutil","Pluma","Que bueno que tengo una, ya podré hacer mi lista de compras",1);
    banio->addNpc(new Npc("Ejecutivo",ejecutivo,pluma));

    //All right 2

    //Puede que sí necesite crear objetos fijos
    Clothes* hitmanClothes = new Clothes("Ropa","Ropa normal","Ropa común, cuidado que puede llamar la atención",0,"Hitman");
    estacionamiento->addAccessClothes(hitmanClothes);
    estacionamiento->addAccessClothes(mesero1);
    estacionamiento->addAccessClothes(chef);
    estacionamiento->addAccessClothes(valet);
    estacionamiento->addAccessClothes(cargador1);
    estacionamiento->addAccessClothes(ejecutivo);
    estacionamiento->addAccessClothes(guardia1);

   
    baldio->addAccessClothes(hitmanClothes);
    baldio->addAccessClothes(mesero1);
    baldio->addAccessClothes(chef);
    baldio->addAccessClothes(valet);
    baldio->addAccessClothes(cargador1);
    baldio->addAccessClothes(ejecutivo);
    baldio->addAccessClothes(guardia1);



    almacen->addAccessClothes(cargador1);
    almacen->addAccessClothes(mesero1);

    cocina->addAccessClothes(mesero1);
    cocina->addAccessClothes(chef);
    
    comedor->addAccessClothes(mesero1);
    comedor->addAccessClothes(ejecutivo);

    sala->addAccessClothes(ejecutivo);
    sala->addAccessClothes(guardia1);

    banio->addAccessClothes(hitmanClothes);
    banio->addAccessClothes(mesero1);
    banio->addAccessClothes(chef);
    banio->addAccessClothes(valet);
    banio->addAccessClothes(cargador1);
    banio->addAccessClothes(ejecutivo);
    banio->addAccessClothes(guardia1);

    boveda->addAccessClothes(ejecutivo);

    //Inicializar salidas de los cuartos
    estacionamiento->addExit(baldio);
    estacionamiento->addExit(sala);

    baldio->addExit(estacionamiento);
    baldio->addExit(almacen);

    almacen->addExit(baldio);
    almacen->addExit(cocina);

    cocina->addExit(almacen);
    cocina->addExit(comedor);

    comedor->addExit(cocina);
    comedor->addExit(sala);
    
    sala->addExit(comedor);
    sala->addExit(boveda);
    sala->addExit(banio);
    sala->addExit(estacionamiento);

    banio->addExit(sala);

    boveda->addExit(sala);
    
    //cout << "\n\nIngresa tu nombre para comenzar:\n>>";
    //string name;
    //cin >> name;
    Hitman* player = new Hitman("name",hitmanClothes,estacionamiento);
    cout << player->isDetected() << endl;
    cout << player->getLocation()->getDescription();
    player->neutralizeNpc("Valet");
    cout << player->getLocation()->getDescription();
    player->addItem("Disfraz de valet");
    cout << player->getLocation()->getDescription();
    player->viewInventory();
    player->move("Terreno Baldío");
    cout << player->isDetected() << endl;
    cout << player->getLocation()->getDescription();
    player->neutralizeNpc("Repartidor");
    cout << player->getLocation()->getDescription();
    player->viewInventory();
    player->addItem("Ganzúa");
    player->viewInventory();
    cout << player->getLocation()->getDescription();
    player->addItem("Disfraz de repartidor");
    player->viewInventory();
    cout << player->getLocation()->getDescription();
    player->move("Almacén");
    cout << player->getLocation()->getDescription();
    cout << player->isDetected() << endl;
    //player->neutralizeNpc("Mesero");
    player->distractNpc("Repartidor");
    player->distractNpc("Mesero");
    player->neutralizeNpc("Mesero");
    cout << player->getLocation()->getDescription();
    

    return 0;
}

