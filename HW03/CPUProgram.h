#ifndef CPUProgram_H
#define CPUProgram_H

#include <iostream>
#include <string>

using namespace std;

class CPUProgram{

public:

    CPUProgram(char* fName);
    void ReadFile(char* fileName);
    string getLine(int lineNo)const;
    int size()const;   

private:
       
    char* filename;
    string strArray[200]; 

};

#endif