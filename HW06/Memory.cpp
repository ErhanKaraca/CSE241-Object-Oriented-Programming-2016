/*----------------------------------------------------------------------------*/
/*-----------------------------------HW06-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*--------------------------------Memory.cpp----------------------------------*/
/*----------------------------------------------------------------------------*/
#include "Memory.h"
#include <iostream>
using namespace std;
/*Default constructer..                                                       */
Memory::Memory(){
    for(int i=0; i<50; ++i)
    {
        setMem(i,0);
    }
}
/*Option constructer..                                                        */
Memory::Memory(int opt):option(opt){
    for(int i=0; i<50; ++i)
    {
        setMem(i,0);
    }
}
/*Tüm memoryi ekrana print eder..                                             */
void Memory::printAll(){
   cout<<"Memory Values:"<<endl;
    for(int i=0; i<50; ++i)
    {
        cout<<"["<<i<<"]"<< " -> "<<getMem(i)<<endl;
    }   
    
}
/*Memory den girilen adresin degerini dondurur..                              */
int Memory::getMem(int value){
    return memory[value];
}
/*Memorydeki adrese deger set eder..                                          */
void Memory::setMem(int address, int value){
    memory[address]=value;
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/