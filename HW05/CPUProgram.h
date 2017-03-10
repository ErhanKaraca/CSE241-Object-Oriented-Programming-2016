/*----------------------------------------------------------------------------*/
/*-----------------------------------HW05-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*--------------------------------CPUProgram.h--------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef CPUProgram_H
#define CPUProgram_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CPUProgram{

    public:
        
        CPUProgram();
        CPUProgram(int opt);
        CPUProgram(char* fName);
        void ReadFile(char* fileName);
        string getLine(int lineNo)const;
        int size()const;        
        
        vector<string>& getArray(){return strArray;}
        string& operator[](int lineNo);
        CPUProgram operator+=(string instruction);       
        CPUProgram operator--();
        CPUProgram operator--(int l);
        CPUProgram operator()(int x, int y);        
        friend ostream& operator<<(ostream& opt, const CPUProgram& other);
        friend CPUProgram operator+(CPUProgram& other,const char* inst);
        friend CPUProgram operator+(const CPUProgram& other1CPUProgram,const CPUProgram& other2CPUProgram);        
        const bool operator==(const CPUProgram& o1)const;
        const bool operator!=(const CPUProgram& o1)const;
        const bool operator<=(const CPUProgram& o1)const;
        const bool operator>=(const CPUProgram& o1)const;
        const bool operator<(const CPUProgram& o1)const;
        const bool operator>(const CPUProgram& o1)const;
    private:

        char* filename;
        vector<string> strArray;
};
#endif
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/