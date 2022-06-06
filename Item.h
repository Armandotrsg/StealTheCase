#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item{
    private:
        string description;
        string actionWord;
        int space;

    public:
        Item();
        Item(string,int);
        virtual string getDescription();
        void setDescription(string);
        int getSpace();
        void setSpace(int);
};

#endif