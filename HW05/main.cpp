/*----------------------------------------------------------------------------*/
/*-----------------------------------HW05-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*----------------------------------main.cpp----------------------------------*/
/*----------------------------------------------------------------------------*/
#include <iostream>
#include "CPUProgram.h"
#include "CPU.h"
#include "Computer.h"
#include "Memory.h"

using namespace std;

int Atoi(string str){
    int x = 0;    
    for (int i = 0; str[i]!='\0'; ++i)
        x = x*10 + str[i] - '0';
    return x;
}

int main(int argc, char** argv) {
    
    //argv[1]="examp.txt";
    //argv[2]="0";
    
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
    }
    char* filename = argv[1];
    int option = Atoi(argv[2]);
    
    CPU myCPU(0,0,0,0,0);
    Memory myMemory(1);
    CPUProgram myCPUProgram(option);
    
    myCPUProgram.ReadFile(filename);
    
    myCPUProgram += "MOV R1, 50";
    myCPUProgram += "MOV R2, 100";
    myCPUProgram += "MOV R3, 150";
    myCPUProgram += "MOV R4, 200";
    myCPUProgram += "MOV R5, 300";
    
    Computer myComputer1(myCPU, myCPUProgram, myMemory, option);
    Computer myComputer2(option);
    myComputer2.setCPU(myComputer1.getCPU());
    myComputer2.setCPUProgram(myComputer1.getCPUProgram());
    myComputer2.setMemory(myComputer1.getMemory());
    
    myComputer2.execute(argv[1],option);  
    
    cout << myCPUProgram[0] << endl;
    cout << myCPUProgram[myCPUProgram.size() - 1] << endl;
    cout<<myCPUProgram.size()<<endl;
    cout<<myCPUProgram(5,10);
    myComputer2.getCPU().print();
    
    
    return 0;
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
