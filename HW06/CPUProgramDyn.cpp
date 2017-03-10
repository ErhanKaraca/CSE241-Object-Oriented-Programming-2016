/*----------------------------------------------------------------------------*/
/*-----------------------------------HW06-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*------------------------------CPUProgramDyn.cpp-----------------------------*/
/*----------------------------------------------------------------------------*/
#include "CPUProgramDyn.h"
#include <fstream>
#include <cstdlib>

using namespace std;

namespace CPUProgramDYN
{
    /*No-param constructor.                                                   */
    CPUProgramDyn::CPUProgramDyn():capacity(0){

        strArray = new string[capacity];
    }
    /*Option constructor.                                                     */
    CPUProgramDyn::CPUProgramDyn(int opt):CPUProgramDyn(){}
    /*Dosya okuma parametreli constructor.                                    */
    CPUProgramDyn::CPUProgramDyn(char* fName): filename(fName),capacity(0){
        ReadFile(filename);
    }
    /*Copy-constructor.                                                       */
    CPUProgramDyn::CPUProgramDyn(const CPUProgramDyn& progObject)
        : capacity(progObject.getCapacity()),filename(progObject.getFilename()),option(0) {

        strArray = new string[capacity];
        for(int i=0; i<capacity; i++){

            strArray[i] = progObject.strArray[i]; 
        }
    }
    /*Destructor.                                                             */
    CPUProgramDyn::~CPUProgramDyn() {

        delete [] strArray;
    }
    /*Dosya ismini döndürür.                                                  */
    char* CPUProgramDyn::getFilename()const{return filename;}
    /*capacity i döndürür.                                                    */
    int CPUProgramDyn::getCapacity()const{return capacity;}
    /*Dosyadan veri okuma func. dosyadaki veri kapasitesi kadar.              */
    void CPUProgramDyn::ReadFile(const char* fileName){

        ifstream doF;
        doF.open(fileName);
        string strF;
        while(getline(doF,strF))
        {
            capacity++;
        }
        doF.close(); 

        strArray = new string[capacity];   

        ifstream doFile;
        doFile.open(fileName);    
        string str;
        int i=0;
        while(getline(doFile,str))
        {        
            strArray[i] = str; 
            ++i;
        }

        doFile.close();

    }
    /*girilen değerdeki satırı döndürür.                                      */
    string CPUProgramDyn::getLine(int lineNo)const{
        if(lineNo>size())
        {
            cerr<<"Can not be this instruction. There is not such instruction."<<endl;
            exit(0);
        }
        return strArray[lineNo-1];
    }
    /*objenin kapasitesini döndürür.                                          */
    int CPUProgramDyn::size()const{

        return capacity;  
    }
    /*girilen değerdeki satırı döndürür. operator overl.                      */
    string& CPUProgramDyn::operator[](int lineNo){

        if(lineNo>=size()){
            cout<<"There is not a instruction."<<endl;
            exit(0);
        }
        return strArray[lineNo];
    }
    /*kendine yeni bir satır ekler.                                           */
    CPUProgramDyn CPUProgramDyn::operator +=(string instruction){
        if(instruction=="")
        {
            cerr<<"Wrong Instruction"<<endl;
            exit(0);
        }

        string* backups;

        backups = new string[capacity];

        for(int i=0; i<capacity; ++i){
            backups[i]=strArray[i];
        }

        delete [] strArray;

        capacity+=1;

        strArray = new string[capacity];

        for(int i=0; i<capacity-1; ++i){
            strArray[i]=backups[i];
        }

        strArray[capacity-1]=instruction;

        delete [] backups;
        return *this;
    }
    /*objeden son satırı çıkarır ve sonra return eder.                        */
    CPUProgramDyn CPUProgramDyn::operator --(){

        string* backups;

        backups = new string[capacity];

        for(int i=0; i<capacity; ++i){
            backups[i]=strArray[i];
        }

        delete [] strArray;
        
        capacity-=1;

        strArray = new string[capacity];

        for(int i=0; i<capacity; ++i){
            strArray[i]=backups[i];
        }

        delete [] backups;

        return *this;
    }
    /*objeden son satırı çıkarır fakat çıkartılmamış değerini return eder.    */
    CPUProgramDyn CPUProgramDyn::operator --(int l){

        CPUProgramDyn prg;
        prg.capacity=this->capacity;
        prg.strArray = new string[prg.capacity];

        for(int i=0; i<capacity; ++i)
        {
            prg.strArray[i]=this->strArray[i];
        }

        string* backups;

        backups = new string[capacity];

        for(int i=0; i<capacity; ++i){
            backups[i]=strArray[i];
        }

        delete [] strArray;

        capacity-=1;

        strArray = new string[capacity];

        for(int i=0; i<capacity; ++i){
            strArray[i]=backups[i];
        }

        delete [] backups;

        for(int i=0; i<capacity; ++i)
        {
            prg.strArray[i]=this->strArray[i];
        }

        return prg;
    }
    /*girilen iki deger arasındaki satıalrı yeni bir obje ile return eder.    */
    CPUProgramDyn CPUProgramDyn::operator()(int x, int y){

        CPUProgramDyn A;

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

        A.capacity = y-x+1;
        A.strArray = new string[A.capacity];
        int c=0;
        for(int i=x; i<=y; ++i){

            A.strArray[c]=this->strArray[i];
            ++c;
        }    

        return A;    
    }
    /*cout operator overloading.                                              */
    ostream& operator<<(ostream& opt, const CPUProgramDyn& other){

        for(int i=0; i<other.size(); ++i){

            opt<<other.strArray[i]<<endl;        
        }
        return opt;
    }
    /*bir obje ye instructionu ekle ve yeni obje return eder.                 */
    CPUProgramDyn operator+(CPUProgramDyn& other,const char*  inst){

        CPUProgramDyn prg;
        prg.capacity=other.size()+1;
        prg.strArray = new string[prg.capacity];

        for(int i=0; i<other.size(); ++i)
        {
            prg.strArray[i]=other.strArray[i];
        }

        prg.strArray[prg.capacity-1]=inst;

        return prg;
    }
    /*iki objeyi ekler birbirine ve yeni obje return eder.                    */
    CPUProgramDyn operator +(const CPUProgramDyn& other1CPUProgram, const CPUProgramDyn& other2CPUProgram) {

        CPUProgramDyn newprg;
        newprg.capacity = other1CPUProgram.size()+other2CPUProgram.size();
        newprg.strArray = new string[newprg.capacity];

        for(int i=0; i<other1CPUProgram.size(); ++i){
            newprg.strArray[i] = other1CPUProgram.strArray[i];
        }

        int c=other1CPUProgram.size();

        for(int i=0; i<other2CPUProgram.size(); ++i){
            newprg.strArray[c] = other2CPUProgram.strArray[i];
            ++c;
        }
        return newprg;
    }
    /*Objelerin dizilerindeki satır sayılarını kontrol eder.                  */
    const bool CPUProgramDyn::operator==(const CPUProgramDyn& o1)const{

        return (size()==o1.size());
    }
    /*Objelerin dizilerindeki satır sayılarını kontrol eder.                  */
    const bool CPUProgramDyn::operator!=(const CPUProgramDyn& o1)const
    {
        return !(size()==o1.size());
    }
    /*Objelerin dizilerindeki satır sayılarını kontrol eder.                  */
    const bool CPUProgramDyn::operator<=(const CPUProgramDyn& o1)const{

        return (size()<=o1.size());
    }
    /*Objelerin dizilerindeki satır sayılarını kontrol eder.                  */
    const bool CPUProgramDyn::operator>=(const CPUProgramDyn& o1)const{

        return (size()>=o1.size());
    }
    /*Objelerin dizilerindeki satır sayılarını kontrol eder.                  */
    const bool CPUProgramDyn::operator<(const CPUProgramDyn& o1)const{

        return (size()<o1.size());
    }
    /*Objelerin dizilerindeki satır sayılarını kontrol eder.                  */
    const bool CPUProgramDyn::operator>(const CPUProgramDyn& o1)const{

        return (size()>o1.size());
    }
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/