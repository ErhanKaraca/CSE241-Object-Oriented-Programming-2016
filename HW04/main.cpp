/*----------------------------------------------------------------------------*/
/*-----------------------------------HW04-------------------------------------*/
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
    //argv[2]="2";
    CPU myCPU(0,0,0,0,0);
    Memory myMemory(1);
    CPUProgram myCPUProgram(argv[1]);
    int option=Atoi(argv[2]);
    
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
    //Testing class Memory
    /*
        Memory myMemory(1);
        myMemory.memSet(0,100);
        cout<<myMemory.memGet(0)<<endl;
        myMemory.printAll();
    */
    //Testing class CPU
    /*
    CPU myCPU(0);
    myCPU.execute("MOV R1, 10", myMemory);
    myCPU.execute("MOV R1, #0", myMemory);
    myCPU.execute("MOV #1, 59", myMemory);
    myCPU.execute("MOV #1, R2", myMemory);
    
    myCPU.print();
    myMemory.printAll();
    */
    //Testing class CPUProgram
    /*
    CPUProgram myCPUProgram(1);
    myCPUProgram.ReadFile(argv[1]);
    cout<<myCPUProgram.getLine(1)<<endl;
    cout<<myCPUProgram.getLine(myCPUProgram.size());
    */
    
    
    Computer myComputer1(myCPU, myCPUProgram, myMemory, option);
    Computer myComputer2(option);
    myComputer2.setCPU(myComputer1.getCPU());
    myComputer2.setCPUProgram(myComputer1.getCPUProgram());
    myComputer2.setMemory(myComputer1.getMemory());
    
    myComputer2.execute(argv[1],option);
    //myComputer2.getMemory().printAll();
    //myComputer2.getCPU().print();
    
    

    
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/