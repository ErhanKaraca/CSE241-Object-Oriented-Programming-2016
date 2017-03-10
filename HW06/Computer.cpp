/*----------------------------------------------------------------------------*/
/*-----------------------------------HW06-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*--------------------------------Computer.cpp--------------------------------*/
/*----------------------------------------------------------------------------*/
#include "Computer.h"
#include "CPU.h"
#include "CPUProgramDyn.h"
#include "Memory.h"
/*Default constructer..                                                       */
Computer::Computer(){}
/*Option alan constructer..                                                   */
Computer::Computer(int opt):option(opt){}
/*Tüm parametreleri alan constructer..                                        */
Computer::Computer(CPU c, CPUProgramDyn cprgrm, Memory mem, int opt): 
            cpu(c), cpuprogram(cprgrm), memory(mem), option(opt){
}
/*Computer objesine CPU yu set eder..                                         */
void Computer::setCPU(CPU myCPU){    
    cpu=myCPU;    
}
/*Computer objesine CPUProgramı set eder..                                    */
void Computer::setCPUProgram(CPUProgramDyn myCPUProgram){
    cpuprogram=myCPUProgram;
}
/*Computer objesine Memoryi set eder..                                        */
void Computer::setMemory(Memory myMemory){    
    memory=myMemory;
}
/*Computer classında cpu bilgisini tutar..                                    */
CPU Computer::getCPU(){
    return cpu;    
}
/*Computer classında cpuprogram objesini tutar..                              */
CPUProgramDyn Computer::getCPUProgram(){
    return cpuprogram;    
}
/*Computer classında memory objesini tutar..                                  */
Memory Computer::getMemory(){
    return memory;    
}
/*Computer objesinin fonksiyonu programın calismasini saglar..                */
void Computer::execute(){
    
    while(!cpu.halted())
    {
        cpu.execute(cpuprogram.getLine(cpu.PCGet()),memory);   
    }  
    
}
/*Computer objesinin fonksiyonu programın calismasini saglar..                */
void Computer::execute(char* filename, int option){
    /*Dosya okunur..*/
    cpuprogram.ReadFile(filename);
    /*Option..*/
    if(option==0)
    {
        while(!cpu.halted()){
        cpu.execute(cpuprogram.getLine(cpu.PCGet()),memory);        
        }
        //memory.printAll();
        
    }
    /*Option..*/
    else if(option==1)
    {    
        while(!cpu.halted())
        {
            cpu.execute(cpuprogram.getLine(cpu.PCGet()),memory);            
            cpu.screenInst(cpuprogram.getLine(cpu.PCGet()));                        
            cpu.printO();
                        
        }        
    }
    /*Option..*/
    else if(option==2)
    {
        while(!cpu.halted())
        {
            cpu.execute(cpuprogram.getLine(cpu.PCGet()),memory);
            memory.printAll();
        }   
    }
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/