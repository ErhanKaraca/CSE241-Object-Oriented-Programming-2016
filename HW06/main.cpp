/*----------------------------------------------------------------------------*/
/*-----------------------------------HW06-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*----------------------------------main.cpp----------------------------------*/
/*----------------------------------------------------------------------------*/
#include <iostream>
#include "CPUProgramDyn.h"
#include "CPU.h"
#include "Computer.h"
#include "Memory.h"

using namespace std;
using namespace CPUProgramDYN;
int Atoi(string str){
    int x = 0;    
    for (int i = 0; str[i]!='\0'; ++i)
        x = x*10 + str[i] - '0';
    return x;
}

int main(int argc, char** argv) {
    
    //argv[1]="examp.txt";
    //argv[2]="0";
   /* 
    if(argv[1]==NULL)
    {
    	cerr<<"File not found."<<endl;
    	return 0;
    }    
    if(argv[2]=='\0')
    {
        cerr<<"Incomplete Option."<<endl;
    	return 0;
    }
    if(Atoi(argv[2])!=1 && Atoi(argv[2])!=0 && Atoi(argv[2])!=2)
    {
    	cerr<<"Wrong Option."<<endl;
    	return 0;
    }*/
    char* filename = argv[1];
    int option = Atoi(argv[2]);
    
    CPU myCPU(0,0,0,0,0);
    Memory myMemory(1);
    CPUProgramDyn myCPUProgram(argv[1]);
    
    Computer myComputer1(myCPU, myCPUProgram, myMemory, option);
    
    myComputer1.execute();
    
    myComputer1.getMemory().printAll();
  
   
    
    return 0;
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
