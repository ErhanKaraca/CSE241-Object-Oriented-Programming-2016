/*----------------------------------------------------------------------------*/
/*-----------------------------------HW03-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*----------------------------------main.cpp----------------------------------*/
/*----------------------------------------------------------------------------*/
#include <iostream>
#include "CPUProgram.h"
#include "CPU.h"

using namespace std;

int main(int argc, char** argv) {

    CPUProgram myprog(argv[1]);
    CPU myCPU(0,0,0,0,0);   
    //argv[2]="1";
    
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
    if(myCPU.myAtoi(argv[2])!=1 && myCPU.myAtoi(argv[2])!=0)
    {
    	cerr<<"Wrong Option."<<endl;
    	return 0;
    }
    
    if(myCPU.myAtoi(argv[2])==0)
    {
        while(!myCPU.halted())
        {
            string instruction=myprog.getLine(myCPU.PCGet());
            myCPU.execute(instruction);            
        }
        
    }
    else if(myCPU.myAtoi(argv[2])==1)
    {    
        while(!myCPU.halted())
        {
            string instruction=myprog.getLine(myCPU.PCGet());            
            myCPU.execute(instruction);
            myCPU.screenInst(instruction);            
            myCPU.print();
        }        
    }        
    return 0;   
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/