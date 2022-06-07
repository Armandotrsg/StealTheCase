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
        Clothes(string,string,int,vector<string>,string);
        string getJob() const;
        void setJob(string);
        string getDescription();
        

};

#endif