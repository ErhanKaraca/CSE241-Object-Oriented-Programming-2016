/*----------------------------------------------------------------------------*/
/*-----------------------------------HW04-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*--------------------------------Computer.h----------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef COMPUTER_H
#define COMPUTER_H


#include "CPU.h"
#include "CPUProgram.h"
#include "Memory.h"

#include <iostream>
#include <string>

using namespace std;

class Computer {
    
    public:
        Computer();
        Computer(int opt);
        Computer(CPU c, CPUProgram cprgrm, Memory mem, int opt);
        void execute();
        void execute(char* filename, int option);
        void setCPU(CPU myCPU);
        void setCPUProgram(CPUProgram myCPUProgram);
        void setMemory(Memory myMemory);
        
        CPU getCPU();
        CPUProgram getCPUProgram();
        Memory getMemory();        
        
    private:
        
        CPU cpu;
        CPUProgram cpuprogram;
        Memory memory;
        int option;

};

#endif
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

