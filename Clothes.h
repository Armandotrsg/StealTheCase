#ifndef CLOTHES_H
#define CLOTHES_H

#include <iostream>
#include "Item.h"

using namespace std;

class Clothes : public Item{
    private:
        string job;
    public:
        Clothes();
        Clothes(string,string,string,int,string);
        string getJob() const;
        void setJob(string);
        string getDescription();
        

};

#endif