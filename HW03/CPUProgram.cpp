/*----------------------------------------------------------------------------*/
/*-----------------------------------HW03-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*--------------------------------CPUProgram.cpp------------------------------*/
/*----------------------------------------------------------------------------*/
#include "CPUProgram.h"
#include <fstream>
#include <cstdlib>

using namespace std;
/*Dosyadan verileri arraya okur.                                              */
void CPUProgram::ReadFile(char* fileName){
    
    ifstream doFile;
    doFile.open(fileName);
    int i=1;
    string str;
    strArray[0]=" ";
    while(getline(doFile,str))
    {
        
        strArray[i]=str;
        ++i;
    }   
    doFile.close();
    
}
/*CPUProgram ojesinin constructerı dosya adı ile ilklendirilir.               */
CPUProgram::CPUProgram(char* fName): filename(fName){
    ReadFile(filename);
}
/*Arraydaki program counter hangi satırda ise o instructer ı dondurur.        */
string CPUProgram::getLine(int lineNo)const{
    if(lineNo>size())
    {
        cerr<<"Can not be this instruction. There is not such instruction."<<endl;
        exit(0);
    }
    return strArray[lineNo];
}
/*Dosyadan okunan instructerların sayısını döndurur.                          */
int CPUProgram::size()const{

    ifstream doFile;
    doFile.open(filename);
    
    int i=1;
    string str;
    
    while(getline(doFile,str))
    {
        ++i;
    }   
    doFile.close();
    
    return i;   
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/