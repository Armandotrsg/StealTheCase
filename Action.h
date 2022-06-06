#ifndef ACTION_H
#define ACTION_H
#include <iostream>
#include <vector>

using namespace std;
class Action{
    private:
        string command;
        string secondWord;
        vector<string> commandWords;
    
    public:
        Action();
        Action(string, string);
        string getCommand() const;
        string getSecondWord() const;
        void printAllCommands();
        void setSecondWord(string);
        bool unknown();
        bool hasSecondWord();
        void execute();
        friend istream& operator >> (istream& is, Action& act);
};

#endif