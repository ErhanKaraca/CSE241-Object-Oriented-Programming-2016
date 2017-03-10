/*----------------------------------------------------------------------------*/
/*-----------------------------------HW06-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*--------------------------------Computer.h----------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef COMPUTER_H
#define COMPUTER_H


#include "CPU.h"
#include "CPUProgramDyn.h"
#include "Memory.h"

#include <iostream>
#include <string>
using namespace CPUProgramDYN;
using namespace std;

class Computer {
    
    public:
        Computer();
        Computer(int opt);
        Computer(CPU c, CPUProgramDyn cprgrm, Memory mem, int opt);
        void execute();
        void execute(char* filename, int option);
        void setCPU(CPU myCPU);
        void setCPUProgram(CPUProgramDyn myCPUProgram);
        void setMemory(Memory myMemory);
        
        CPU getCPU();
        CPUProgramDyn getCPUProgram();
        Memory getMemory();        
        
    private:
        
        CPU cpu;
        CPUProgramDyn cpuprogram;
        Memory memory;
        int option;

};

#endif
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

