#ifndef REQUIREDINCS_H
#define REQUIREDINCS_H

#include "Memory.h"
#include "CPU.h"
#include "CPUProgram.h"
#include "Computer.h"

/*_mainTester.cpp
 
    #include <iostream>
    #include "requiredIncs.h"

    #include "Memory.h"
    #include "CPU.h"
    #include "CPUProgram.h"
    #include "Computer.h"
    using namespace std;

    int Atoi(string str){
        int x = 0;    
        for (int i = 0; str[i]!='\0'; ++i)
            x = x*10 + str[i] - '0';
        return x;
    }

    int main(int argc, char** argv) {
        
        const char* filename = argv[1];
        int option=Atoi(argv[2]);

        Memory myMemory(option);
        myMemory.setMem(0,100);
        cout<<myMemory.getMem(0)<<endl;
        myMemory.printAll();
 
        CPU myCPU(option);
        myCPU.execute("MOV #0, R1", myMemory);
        myCPU.execute("MOV R1, #1", myMemory);

        myCPU.print();
        myMemory.printAll();
 
        CPUProgram myCPUProgram(option);
        myCPUProgram.ReadFile(filename);
        cout<<myCPUProgram.getLine(1)<<endl;
 * 
        // HOCAM PC 1 İLE SET EDİLMİŞTİR O NEDENLE CPUPROGRAM FARKLI ÇALIŞMAKTADIR.
 * 
        cout<<myCPUProgram.getLine(myCPUProgram.size());

        Computer myComputer1(myCPU, myCPUProgram, myMemory, option);
        Computer myComputer2(option);
        myComputer2.setCPU(myComputer1.getCPU());
        myComputer2.setCPUProgram(myComputer1.getCPUProgram());
        myComputer2.setMemory(myComputer1.getMemory());

        myComputer2.execute();
    } 
 
 */
#endif /* REQUIREDINCS_H */

