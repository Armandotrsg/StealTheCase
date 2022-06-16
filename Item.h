#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>

using namespace std;

class Item{
    private:
        string type; //Tipo de item: arma, distractor, inutil u objetivo
        string name;
        string description; 
        int space; //Espacio que ocupa en el inventario

    public:
        Item();
        Item(string,string,string,int);
        virtual string getDescription(); //Polimorfismo para clase derivada clothes
        void setDescription(string);
        int getSpace();
        void setSpace(int);
        string getType();
        void setType(string);
        string getName();
        void setName(string);
};
        
#endif