#include "Hitman.h"
#include "Clothes.h"
#include "Room.h"
#include <fstream>
#include <string>

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
    //Inicializamos cuartos con el constructor
    Room* estacionamiento = new Room("Estacionamiento","Lugar donde puedes aparcar tu coche y el del valet te lo cuidará",false,false);
    Room* baldio = new Room("Terreno Baldío","Parece que está muy abandonado por aquí, al parecer aquí es donde estacionan el camion de repartidores",false,false);
    Room* almacen = new Room("Almacén","Aquí guardan toda la comida para la semana",false,true);
    Room* cocina = new Room("Cocina","Aquí cocinan la comida para el ejecutivo de alto mando",false,false);
    Room* comedor = new Room("Comedor","Aquí es la sala de reuniones o para otros es el comedor",false,false);
    Room* sala = new Room("Sala","Sala de estar de la casa, donde puedes esperar para entrar al comedor",false,false);
    Room* banio = new Room("Baño","Wow, todo está hecho de porcelana y mármol, ¡Bastante elegante!",false,false);
    Room* boveda = new Room("Bóveda","Mira, aquí guardan los papeles...",true,false);

    //Agregamos items a los cuartos
    estacionamiento->setItem(new Item("Distractor", "Moneda","Pequeño objeto de níquel, podría hacer ruido...", 1));
    estacionamiento->setItem(new Item("Arma", "Navaja", "Un poco oxidada, pero aún tiene filo...", 2));
    estacionamiento->setItem(new Item("Arma", "Cloroformo","Ayuda a neutralizar enemigos.", 1));
    
    baldio->setItem(new Item("Mochila", "Morral","Un poco percudido, pero aun cumple con su función", 0));
    baldio->setItem(new Item("Herramienta", "Ganzúa","Ayuda a abrir ciertas puertas trabadas.", 3));
    baldio->setItem(new Item("Inutil", "Fotografía","Parece que fue tomada en esta misma mansión. La fecha dice 17-mayo-2016", 1));

    almacen->setItem(new Item("Distractor", "Tomate","No huele nada bien, pero podrías lanzarlo...", 2));
    almacen->setItem(new Item("Inutil", "Recibo de Compras"," Tiene escrito: 'Harina, Tomates, Cebollas, Huevo, Leche...'", 1));

    cocina->setItem(new Item("Inutil","Bandeja","La usan los meseros, pero no veo por qué guardarla", 2));
    cocina->setItem(new Item("Arma","Cucharón","Cucharón de metal, bastante resistente... ¡Con esto podrás comer sopa!",1));

    boveda->setItem(new Item("Objetivo","Papeles", "Llévalo con el jefe sin ser descubierto",4));

    comedor->setItem(new Item("Inutil","Plato","Guárdalo para cuando encuentres algún tipo de comida",1));
    comedor->setItem(new Item("Distractor","Bandeja de plata","Wow, puedes ver tu reflejo con esto",2));
    comedor->setItem(new Item("Distractor","Sopa","Good soup",1));

    sala->setItem(new Item("Arma","Florero","Está hecho de barro y tiene una margarita sembrada",3));
    sala->setItem(new Item("Distractor","Gameboy","Puedes pasar horas y horas jugando con él",2));
    sala->setItem(new Item("Inutil","Almohada","Esto puede ser útil cuando tengas sueño",3));

    banio->setItem(new Item("Arma","Amoniaco","Esto puede ser peligroso para hacer la limpieza",3));
    banio->setItem(new Item("Inutil","Cepillo de dientes","Siempre hay que tener buen aliento",1));

    //Agregamos npc's a los cuartos junto con su ropa e item a la mano

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
    Item* bandeja = new Item("Distractor","Bandeja de plata","La usan los meseros, pero mira puedo ver mi reflejo en ella...", 2);
    Item* cuchillo = new Item("Arma", "Cuchillo","Se ve que es de alta calidad, está muy filoso", 3);
    Item* noItem4;
    Item* noItem5;
    cocina->addNpc(new Npc("Chef",chef,cuchillo));
    cocina->addNpc(new Npc("Mesero",mesero1,noItem4));
    almacen->addNpc(new Npc("Mesero",mesero2,bandeja));
    comedor->addNpc(new Npc("Mesero",mesero3,noItem5));
    
    Clothes* target = new Clothes("Ropa","Disfraz de ejecutivo","Puedes entrar a la sala y al comedor",0,"Ejecutivo");
    Item* llave = new Item("Llave","Llave","Creo que esto es clave para lograr mi objetivo",4);
    comedor->addNpc(new Npc("Ejecutivo",target,llave));  //Este tiene la llave para abrir la bóveda

    Clothes* guardia1 = new Clothes("Ropa","Disfraz de guardia","Puedes entrar a la bóveda",0,"Guardia");
    Clothes* guardia2 = new Clothes("Ropa","Disfraz de guardia","Puedes entrar a la bóveda",0,"Guardia");
    Item* taser = new Item("Distractor","Taser","Cuidado que te puede paralizar",3);
    Item* pistola = new Item("Arma","Pistola","Aunque solo le quede una bala puede ser de utilidad",4);
    sala->addNpc(new Npc("Guardia 1",guardia1,taser));
    sala->addNpc(new Npc("Guardia 2",guardia2,pistola));

    Clothes* ejecutivo = new Clothes("Ropa","Disfraz de ejecutivo","Puedes entrar a la sala y al comedor",0,"Ejecutivo");
    Item* pluma = new Item("Inutil","Pluma","Que bueno que tengo una, ya podré hacer mi lista de compras",1);
    banio->addNpc(new Npc("Ejecutivo",ejecutivo,pluma));

    //Agregamos la ropa con la que puedes acceder a los cuartos para que no seas detectado
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
    sala->addAccessClothes(valet);

    banio->addAccessClothes(hitmanClothes);
    banio->addAccessClothes(mesero1);
    banio->addAccessClothes(chef);
    banio->addAccessClothes(valet);
    banio->addAccessClothes(cargador1);
    banio->addAccessClothes(ejecutivo);
    banio->addAccessClothes(guardia1);

    boveda->addAccessClothes(ejecutivo);

    //Inicializamos salidas de los cuartos
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
    
    mensajeIntro(); //Desplegamos mensaje de intro al juego

    Hitman* player = new Hitman("name",hitmanClothes,estacionamiento); //Inicializamos personaje
    string com1, com2, frase; //Strings que recibirán los input del usuario
    cout << *(player->getLocation()) << endl; //Muestra donde te ubicas a inicio
    cout << "\n Recuerda que puedes utilizar los siguientes comandos (escribelos como se muestran):" << "\n\t- ayuda \n\t- ver inventario \n\t- moverse (cuarto) \n\t- tomar (objeto)\n\t- salir"; //Muestra los comandos
    while(!player->isDetected()){ //El juego se ejecuta mientras no seas detectado
        com1 = ""; com2 = ""; frase = ""; //Reseteamos los strings cada ciclo
        cout << "\n\n\t\t\tMENÚ PRINCIPAL" << endl;
        cout << "\nIngresa un comando: ";
        getline(cin,frase);
        //Partimos las palabras ingresadas por el usuario en 2 strings diferentes
        bool oneWord = true;
        for (int i = 0; i < frase.length(); i++){
            if (frase[i] == ' '){
                oneWord = false; //Detecta que hay un espacio, se para el ciclo y se sabe que la frase ingresada no es de una palabra
                break;
            }
            com1 += frase[i]; //El primer string se genera hasta que encuentre un espacio o acabe la palabra
        }
        if (!oneWord){ 
            for (int i =com1.length()+1; i < frase.length(); i++ ){ //Al no ser de una palabra, agregamos el resto del string a com2
                com2 += frase[i];
            }
        }
        
        if(com1 == "ayuda" || com1 == "Ayuda" ){ //Si la primer palabra es ayuda, despliega donde te encuentras y cuáles son los comandos
            cout << player->getLocation()->getDescription();
            cout << "\n Recuerda que puedes utilizar los siguientes comandos (escribelos como se muestran):" << "\n\t- ayuda \n\t- ver inventario \n\t- moverse (cuarto) \n\t- tomar (objeto)\n\t- salir";
        }
        else if (com1 == "ver" || com1 == "Ver"){ //Si la primer palabra es ver, despliega el inventario
            com1 = ""; com2 = ""; frase = ""; //reseteamos valores de strings
            player->viewInventory(); //Aquí vas a poder interactuar con los objetos
            getline(cin,frase);
            //Partimos la frase ingresada en 2 strings diferentes
            bool oneWord = true;
            for (int i = 0; i < frase.length(); i++){
                if (frase[i] == ' '){
                    oneWord = false;
                    break;
                }
                com1 += frase[i];
            }
            if (!oneWord){
                for (int i =com1.length()+1; i < frase.length(); i++ ){
                    com2 += frase[i];
                }
            }
            if (com1 == "salir" || com1 == "Salir"){ //Si ingresó salir, se regresa al menú principal
                continue;
            }
           
            Item* toUse = player->seekItem(com2);  //Busca el objeto ingresado en la segunda palabra en el cuarto
            if (toUse != nullptr){ //Si no es un un valor nulo:
                if(com1 == "usar" || com1 == "Usar"){ //Si la primer palabra es usar, le daremos el uso correcto a cada item que tengas
                    if(toUse->getType() == "Inutil"){ //Si el objeto no sirve, no se hace nada
                        cout << "\nEste objeto no tiene ninguna utilidad.";
                    }
                    else if(toUse->getType() == "Arma"){ //Si es un arma:
                        string com3;
                        if(player->getLocation()->getNumberOfCharacters() != 0){ //Si hay personajes en el cuarto
                            cout << "\nSelecciona el objetivo a neutralizar: \n";
                            vector<Npc*> roomCharacters = player->getLocation()->getAllCharacters(); 
                            for (auto npc : roomCharacters){
                                cout <<"\n- " <<npc->getName() << endl; //imprimimos los personajes
                            }
                            cin >> com3; //Ingresa el objetivo
                            Npc* neutralize = player->getLocation()->getNpc(com3);
                            if(neutralize != nullptr){ //Si el objetivo existe, lo eliminará
                                player->neutralizeNpc(com3);
                                player->removeItem(toUse); //Al usarse se gasta el arma
                                cout << "\n Has neutralizado a " << com3;
                                
                            }
                        }
                        else{
                            cout << "\nNo hay nadie en este cuarto."; //Si no hay nadie en el cuarto no se hace nada
                        }
                    }
                    else if(toUse->getType() == "Distractor"){ //Si el objeto es de tipo distractor:
                        string com3;
                        if(player->getLocation()->getNumberOfCharacters() != 0){ //Si hay más de un personaje en el cuarto:
                            cout << "\nSelecciona el objetivo a distraer: \n";
                            vector<Npc*> roomCharacters = player->getLocation()->getAllCharacters(); 
                                for (auto npc : roomCharacters){
                                    cout <<"\n- " <<npc->getName() << endl; //imprimimos los personajes en el cuarto
                                }

                            cin >> com3;
                            Npc* distract = player->getLocation()->getNpc(com3);
                            if(distract != nullptr){ //Si encuenntra al personaje ingresado, lo distrae
                                player->distractNpc(com3);
                                player->removeItem(toUse); //Se gasta el objeto y se elimina
                                cout << "\n Has distraído a " << com3;
                            }
                        }
                        else{
                            cout << "\nNo hay nadie en este cuarto."; //Si no hay nadie en el cuarto no se hace nada
                        }
                    } 
                    else if(toUse->getType() == "Llave"){ //Si se usa una llave:
                        bool hayCuarto = false;   
                        for(int i = 0; i < player->getLocation()->getAllExits().size(); i++){  //Busca los cuartos que necesiten una llave y te los muestra
                            if (player->getLocation()->getAllExits()[i]->needsKey() == true){
                                hayCuarto = true;
                                cout << "\nEstos cuartos pueden ser abiertos con tu llave: ";
                                cout << endl << player->getLocation()->getAllExits()[i]->getName();
                                cout << "\nSelecciona el cuarto que quieres abrir: ";
                                getline(cin,frase);
                                
                                Room* cuarto = player->getLocation()->getExit(frase);
                                if(cuarto != nullptr){
                                    player->getLocation()->getExit(frase)->setKey(false); //El cuarto ya no necesita llave
                                    player->removeItem(toUse); //Elimina el item usado
                                } else{
                                    break;
                                }
                                
                            }
                            
                        }
                        if (!hayCuarto){
                                cout << "\nNo hay ningún cuarto cerca que necesite una llave."; 
                            }
                    }
                    else if(toUse->getType() == "Herramienta"){ //Si se usa una herramienta 
                        bool hayCuarto = false;  
                        for(int i = 0; i < player->getLocation()->getAllExits().size(); i++){ //Busca los cuartos cerca y te muestra los que necesiten herramienta para abrirse
                            if (player->getLocation()->getAllExits()[i]->needsTool() == true){
                                hayCuarto = true;
                                cout << "\nEstos cuartos pueden ser abiertos con tu Herramienta: ";
                                cout << endl << player->getLocation()->getAllExits()[i]->getName();
                                cout << "\nSelecciona el cuarto que quieres abrir: ";
                                getline(cin,frase);
                                Room* cuarto = player->getLocation()->getExit(frase);
                                if(cuarto != nullptr){
                                    player->getLocation()->getExit(frase)->setTool(false); //El cuarto ya no necesita herramienta
                                    player->removeItem(toUse); //Elimina el item usado
                                }else{
                                    break;
                                }
                            }
                            
                        }  
                        if (!hayCuarto){
                                cout << "\nNo hay ningún cuarto cerca que necesite una herramienta.";
                            } 
                    }
                    else if(toUse->getType() == "Objetivo"){ //Para ganar, cuando tengas los papeles "Hay que usar los papeles"
                        cout << "\nFelicidades, has conseguido robar los papeles.";
                        break;
                    } else {
                        cout << "No hay ningún objeto que coincida con ese nombre en tu inventario" << endl; //mensaje de error
                    }
                
                } 
                else if (com1 == "dejar" || com1 == "Dejar"){
                    player->dropItem(com2); //Si ingresa dejar, dropea el item

                }
                
            
            }
            
        }
        else if (com1 == "moverse" || com1 == "Moverse"){ //Si es moverse, busca a donde te vas a mover
            if (com2 == ""){
                cout << "¿A dónde te vas a mover?\n";  //Si solo ingreso una palabra,le vuelve a preguntar a donde
                getline(cin,com2);
            }    
            player->move(com2);
            cout << *(player->getLocation()); //Te muestra tu nueva ubicación
            
        }
        else if (com1 == "tomar" || com1 == "Tomar"){ //Si vas a tomar un objeto
            if (com2 == ""){
                cout << "¿Qué quieres tomar?\n"; //Si solo ingresó una palabra vuelve a preguntar
                getline(cin,com2);
            }
            try{
                player->addItem(com2); //Si no encontró el objeto en la ubicación lanza un mensaje de error
                
            } catch (const char* msg){
                cerr << msg; //Despliega el mensaje de error
            }
            
            
        } else if (com1 == "salir" || com1 == "Salir"){
            break; //salir del juego
        } else {
            cout << "\nComando Inválido\nEscribe ayuda para ver los comandos disponibles.\n"; //Si tu comando no coincide con ninguno
        }
    }

    if (player->isDetected()){ //Si has sido detectado muestra el mensaje de fin del juego
        cout << "\n¡Te han detectado!" << endl;
        cout << "Recuerda que ciertos atuendos llaman la atención en unos cuartos.\n";
        cout << "También recuerda que debes distraer a un personaje si quieres neutralizar a otro";
        cout << "\n\n\t\t\tFIN DEL JUEGO";
    }

    return 0;
}

