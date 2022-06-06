#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>

using namespace std;

class Item{
    private:
        string description;
        vector<string> actionWord; 
        int space;

    public:
        Item();
        Item(string,int, vector<string>);
        virtual string getDescription(); //Polimorfismo para clase derivada clothes
        void setDescription(string);
        int getSpace();
        void setSpace(int);
};
        
#endif