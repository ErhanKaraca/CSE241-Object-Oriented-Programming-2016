/*----------------------------------------------------------------------------*/
/*-----------------------------------HW05-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*--------------------------------CPUProgram.cpp------------------------------*/
/*----------------------------------------------------------------------------*/
#include "CPUProgram.h"
#include <fstream>
#include <cstdlib>

using namespace std;
/*Default constructer..                                                       */
CPUProgram::CPUProgram(){}
/*Option constructerı..*/
CPUProgram::CPUProgram(int opt){}
/*CPUProgram ojesinin constructerı dosya adı ile ilklendirilir.               */
CPUProgram::CPUProgram(char* fName): filename(fName){
    ReadFile(filename);
}
/*Dosyadan verileri arraya okur.                                              */
void CPUProgram::ReadFile(char* fileName){
    
    ifstream doFile;
    doFile.open(fileName);    
    string str;    
    while(getline(doFile,str))
    {        
        strArray.push_back(str);
        
    }   
    doFile.close();
    
}
/*Arraydaki program counter hangi satırda ise o instructer ı dondurur.        */
string CPUProgram::getLine(int lineNo)const{
    if(lineNo>size())
    {
        cerr<<"Can not be this instruction. There is not such instruction."<<endl;
        exit(0);
    }
    return strArray[lineNo-1];
}
/*Dosyadan okunan instructerların sayısını döndurur.                          */
int CPUProgram::size()const{
    
    return strArray.size();  
}
/*İndexe girilen değerdeki satırı return eder.                                */
string& CPUProgram::operator[](int lineNo){
    
    if(lineNo>getArray().size()){
        cout<<"There is not a instruction."<<endl;
        exit(0);
    }
    return strArray[lineNo];
}
/*CPUProgram objesi ile bir stringi toplar ve kendine ekler.                  */
CPUProgram CPUProgram::operator +=(string instruction){
    if(instruction=="")
    {
        cerr<<"Wrong Instruction"<<endl;
        exit(0);
    }
    strArray.push_back(instruction);
    return *this;
}
/*İki ayrı CPUProgram objesini toplar ve yeni bir obje return eder.           */
CPUProgram operator +(const CPUProgram& other1CPUProgram, const CPUProgram& other2CPUProgram) {
    CPUProgram newprg;
    for(int i=0; i<other1CPUProgram.size(); ++i){
        newprg.strArray.push_back(other1CPUProgram.strArray[i]);
    }
    for(int i=0; i<other2CPUProgram.size(); ++i){
        newprg.strArray.push_back(other2CPUProgram.strArray[i]);
    }
    return newprg;
}
/*CPUProgram objesini ekrana print eder.                                      */
ostream& operator<<(ostream& opt, const CPUProgram& other){
    
    for(int i=0; i<other.size(); ++i){
        
        opt<<other.strArray[i]<<endl;        
    }
    return opt;
}
/*Objenin dizisinin son satırını siler ve öyle return eder.                   */
CPUProgram CPUProgram::operator --(){
   
    strArray.pop_back();
    return *this;
}
/*Objenin dizisini return eder sonra objenin dizisinin onundan bir instruction 
    siler.                                                                    */
CPUProgram CPUProgram::operator --(int l){
    
    CPUProgram prg;
    prg.strArray=this->strArray;
    strArray.pop_back();
    return prg;
}
/*Objelerin dizilerindeki satır sayılarını kontrol eder.                      */
const bool CPUProgram::operator==(const CPUProgram& o1)const{
    
    return (size()==o1.size());
}
/*Objelerin dizilerindeki satır sayılarını kontrol eder.                      */
const bool CPUProgram::operator!=(const CPUProgram& o1)const
{
    return !(size()==o1.size());
}
/*Objelerin dizilerindeki satır sayılarını kontrol eder.                      */
const bool CPUProgram::operator<=(const CPUProgram& o1)const{
    
    return (size()<=o1.size());
}
/*Objelerin dizilerindeki satır sayılarını kontrol eder.                      */
const bool CPUProgram::operator>=(const CPUProgram& o1)const{

    return (size()>=o1.size());
}
/*Objelerin dizilerindeki satır sayılarını kontrol eder.                      */
const bool CPUProgram::operator<(const CPUProgram& o1)const{

    return (size()<o1.size());
}
/*Objelerin dizilerindeki satır sayılarını kontrol eder.                      */
const bool CPUProgram::operator>(const CPUProgram& o1)const{

    return (size()>o1.size());
}
/*Girilen iki sayı arasındaki instructionlara sahip yeni obje return eder.    */
CPUProgram CPUProgram::operator()(int x, int y){
    
    CPUProgram A;
    if(x>y)
    {
        cerr<<"Wrong interval."<<endl;
        return A;
    }
    if(y>size())
    {
        cerr<<"Wrong interval."<<endl;
        return A;    
    }
    if(x>size())
    {
        cerr<<"Wrong interval."<<endl;
        return A;    
    }
    
    for(int i=x; i<=y; ++i){
    
        A.strArray.push_back(strArray[i]);
        
    }    
    
    return A;
    
}
/*CPUProbram objesi ile bir instrcutionu toplar ve yeni bir obje return eder. */
CPUProgram operator+(CPUProgram& other,const char*  inst){
    
    CPUProgram prg;
    prg.strArray=other.strArray;
    prg.strArray.push_back(inst);
    return prg;
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/