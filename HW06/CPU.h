/*----------------------------------------------------------------------------*/
/*-----------------------------------HW06-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*----------------------------------CPU.h-------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <string>
#include "Memory.h"

using namespace std;

class CPU{

    public:

        CPU();
        CPU(int opt);
        CPU(int r1, int r2, int r3, int r4, int r5);
        void print();
        bool halted();
        void execute(string str, Memory& memory);
        int regGet(int reg)const;       
        void regSet(int reg,int value);      
        void PCSet(int line);
        int PCGet()const;
        void screenInst(string str);
        int myAtoi(string str);
        void printO();

    private:

        string inst;
        string leftInfo,rightInfo;
        int regArray[5];
        static int PC;
        int option;

        void regMove(int reg1, int reg2);
        void constMove(int reg1, int number);
        void regAddFunc(int a, int b);
        void constAddFunc(int a,int b);
        void regSubFunc(int a,int b);
        void constSubFunc(int a,int b);
        void Prn(int a)const;
        void regJumpFunc(int arrReg,int line);
        void jumpFunc(int line);
        void instClearFunc(string& str);
        int semicolonControl(string str)const;
        string instParse(string str);
        void infoParse(string str,string& str1,string& str2);
        void upperFunc(string& str);
        int commaControl(string str)const;
        int numberControl(string str)const;

        void moveRegtoAddress(int reg, int address,Memory& mem);
        void moveAdresstoReg(int address, int reg,Memory& mem);
        void moveAddresstoConst(int address,int number,Memory& mem);
        void addRegtoAdress(int reg, int address,Memory& mem);
        void subRegtoAdress(int reg, int address,Memory& mem);
        void prntAdress(int address,Memory& mem);
        void regJupnLine(int arrReg, int line);
};

#endif
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/