/*----------------------------------------------------------------------------*/
/*-----------------------------------HW06-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*----------------------------------CPU.cpp-----------------------------------*/
/*----------------------------------------------------------------------------*/
#include "CPU.h"
#include "Memory.h"
#include <cstdlib>
#include <string>
using namespace std;

/*CPU constructerlari CPU objesini 0'a initialize etmek için kullanilir.      */
CPU::CPU(){   
    for(int i=0; i<5; ++i)
    {
        regArray[i]=0;
    }   
}
/*Option constructer.                                                         */
CPU::CPU(int opt): option(opt){}
/*Reg degerleri 0 initialize edilir.                                          */
CPU::CPU(int r1, int r2, int r3, int r4, int r5){

    regArray[0]=r1;
    regArray[1]=r2;
    regArray[2]=r3;
    regArray[3]=r4;
    regArray[4]=r5;   
}
int CPU::PC=1;
/*Gelen instructionun HLT sonlandirma instructiounu olup ulmadigina bakar.    
 Duruma gore true veya false dondurur.                                        */
bool CPU::halted()
{
    if(inst=="HLT")
    {
        return true;
    }
    else
        return false;
}
/*Instructionu ekrana bastirmak icin kullanilir.                              */
void CPU::screenInst(string str) {
    string s2,s3;
    instClearFunc(str);
    upperFunc(str);
    if(commaControl(str)==1)
    {
        string s1=instParse(str);
        infoParse(str,s2,s3);
        instClearFunc(s2);
        instClearFunc(s3);
        cout<<s1<<" "<<s2<<","<<" "<<s3<<endl;    
    }
    else if(commaControl(str)==0)
    {
        string s1,s2;        
        s1=instParse(str);
        s2=str.erase(0,3);
        instClearFunc(s2);
        cout<<s1<<" "<<s2<<endl;        
    }    
}
/*Calistrilacak olan instructionun sirasini tutar.                            */
int CPU::PCGet()const{
    return PC;
}
/*Calistrilacak olan fonksiyonu ayarlar.                                      */
void CPU::PCSet(int line){
    PC=line;
}
/*Register daki degerin icerigini döndürür.                                   */
int CPU::regGet(int reg) const{
    return regArray[reg-1];
}
/*Register degerini ayarlar.                                                  */
void CPU::regSet(int reg,int value){
    regArray[reg-1]=value;
}
/*İki register arasindaki MOV fonksiyonunu ayarlar.                           */
void CPU::regMove(int reg1, int reg2){
    regSet(reg2,regGet(reg1));
}
/*Register a sabit deger atar.                                                */
void CPU::constMove(int reg1, int number){
    regSet(reg1,number);
}
/*İki register arasindaki değerleri toplar.                                   */
void CPU::regAddFunc(int a, int b){
    regSet(a,regGet(a)+regGet(b));
}
/*Sabit degeri register içindeki deger ile toplar registera atar.             */
void CPU::constAddFunc(int a,int b){
    regSet(a,regGet(a)+b);    
}
/*Registerlar arasinda çıkarma islemini gerçeklesitirir.                      */
void CPU::regSubFunc(int a,int b){
    regSet(a,regGet(a)-regGet(b));
}
/*Registerdan sabit degeri çıkarır ve registerın icine atar.                  */
void CPU::constSubFunc(int a, int b){
    regSet(a,regGet(a)-b);
}
/*Ekrana yazdırma fonksiyonu.                                                 */
void CPU::Prn(int a)const{
    cout<<a<<endl;
}
/*Gelen registerin degerini kontrol eder ve duruma gore program counter 
   ın degerini değiştirir.                                                    */
void CPU::regJumpFunc(int arrReg,int line){
        
    if(regGet(arrReg)==0)
    {
        PCSet(line);
    }
    else{
        PC+=1;
    }        
}
/*Gelen line degerine gore program counterı set eder.                         */
void CPU::jumpFunc(int line){
    PCSet(line);    
}
/*Registerların degerini ekrana print eder.                                   */
void CPU::print(){
    
    cout<<"CPU Register Values:"<<endl;
    for(int i=1; i<=5; ++i)
    {
        cout<<"["<<i-1<<"]"<< " -> "<<regGet(i)<<endl;
    }
}
/*Registerların degerini ekrana print eder.PC ile.                            */
void CPU::printO(){

    cout<<"R1= "<<regGet(1)
            <<" R2= "<<regGet(2)
            <<" R3= "<<regGet(3)
            <<" R4= "<<regGet(4)
            <<" R5= "<<regGet(5);

    cout<<" PC= "<<PCGet()<<endl;
}
/*Gelen stringi düzenler.                                                     */
void CPU::instClearFunc(string& str){
    
    int i=0;
    while(str[i]==' ')
    {
        ++i;    
    }
    str.erase(0,i);

    if(semicolonControl(str)==1)
    {
        size_t coma=str.find_first_of(';');
        str.erase(coma,str.size()-coma);
    }
    
    int k=str.size();
    int c=0;
    while(str[k-1]==' ')
    {
        --k;
        ++c;
    }
    str.erase(str.size()-c,c);
    return ;
}
/*Gelen stringte noktalı virgül olup olmadigini kontrol eder.                 */
int CPU::semicolonControl(string str)const{
    for(int i=0; i<str.size();++i)
    {
        if(str[i]==';')
        {
            return 1;
        }
    }
    return 0;
}
/*Gelen satırdaki intruction degeri alıp dondurur.                            */
string CPU::instParse(string str){    
    string inst;
    inst=str.substr(0,3);
    return inst;
}
/*Stringe gelen instructionu istenilen degerlerini boler.                     */
void CPU::infoParse(string str,string& str1,string& str2){
    str.erase(0,3);
    for(int x=0; x<str.size(); ++x)
    {
        if(str[x]==',')
        {
            str1=str.substr(0,x);
            str2=str.substr(x+1,str.size());
        }        
    }
}
/*Gelen stringi integer degere donusturur.                                    */
int CPU::myAtoi(string str){
    int x = 0;    
    for (int i = 0; str[i]!='\0'; ++i)
        x = x*10 + str[i] - '0';
    return x;
}
/*Stringi büyük harf olup olmadigi kontrol edip küçük harleri büyük harp yapar*/
void CPU::upperFunc(string& str){
    for(int i=0; i<str.size(); ++i)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i] -= 'a' - 'A'; 
        }
    }
    return ;
}
/*Stringte virgül olup olmadiğini kontrol eder.                               */
int CPU::commaControl(string str)const{

    int count=0;
    for(int i=0; i<str.size(); ++i)
    {
        if(str[i]==',')
        {
            ++count;
        }
    }
    return count;
}
/*Stringin number olup olmadigini kontrol eder.                               */
int CPU::numberControl(string str)const{
    for(int x=0; x<str.size(); ++x){
        if(str[x]<'0' || str[x]>'9')
        {
            return 0;
        }        
    }
    return 1;
}
/*Reg-Address move eder..                                                     */
void CPU::moveRegtoAddress(int reg, int address, Memory& mem){
    
    mem.setMem(address,regGet(reg));
}
/*Address-Reg move eder.                                                      */
void CPU::moveAdresstoReg(int address, int reg,Memory& mem){
    regSet(reg,mem.getMem(address));
}
/*Address-Constant move eder.                                                 */
void CPU::moveAddresstoConst(int address,int number,Memory& mem){
    mem.setMem(address,number);
}
/*Reg-Address toplar..                                                        */
void CPU::addRegtoAdress(int reg, int address,Memory& mem){
    regSet(reg,regGet(reg)+mem.getMem(address));
}
/*Reg-Address çıkarma işlemi yapar..                                          */
void CPU::subRegtoAdress(int reg, int address,Memory& mem){
    regSet(reg,regGet(reg)-mem.getMem(address));
}
/*Girilen addressteki degeri print eder..                                     */
void CPU::prntAdress(int address,Memory& mem){
    cout<<mem.getMem(address)<<endl;
}
/*Reg degeri 0 veya 0 altında ise komuttaki satıra atlar..                    */
void CPU::regJupnLine(int arrReg, int line){
    if(regGet(arrReg)<0 || regGet(arrReg)==0)
    {
        PCSet(line);
    }
    else{
        PC+=1;
    }
}
/*İnstructionların çalıştırıldığı fonksiyon.                                  */
void CPU::execute(string str,Memory& memory){
    
    
    if(commaControl(str)==1)
    {
        instClearFunc(str);
        upperFunc(str);
        inst=instParse(str);
        infoParse(str,leftInfo,rightInfo);
        instClearFunc(leftInfo);
        instClearFunc(rightInfo);
        
        if(leftInfo.size()==2 && leftInfo[0]=='R' && numberControl(rightInfo)==1)
        {
            int number=myAtoi(rightInfo);
            int reg=leftInfo[1]-'0';
            
            if(inst=="MOV")
            {
                constMove(reg,number);
                PC+=1;
            }
            else if(inst=="SUB")
            {
                constSubFunc(reg,number);
                PC+=1;
            }
            else if(inst=="ADD")
            {
                constAddFunc(reg,number);
                PC+=1;
            }
            else if(inst=="JMP")
            {
                regJumpFunc(reg,number);
            }
            else if(inst=="JPN")
            {
                regJupnLine(reg,number);
            }
            else{        
                cerr<<"Here, There is wrong instruction"<<endl;
                exit(0);        
            } 
        }
        else if(leftInfo.size()==2 && rightInfo.size()==2 && leftInfo[0]=='R' && rightInfo[0]=='R')
        {
            int reg1=leftInfo[1]-'0';
            int reg2=rightInfo[1]-'0';
            
            if(inst=="MOV")
            {
                regMove(reg1,reg2);
                PC+=1;
            }
            else if(inst=="SUB")
            {
                regSubFunc(reg1,reg2);
                PC+=1;
            }
            else if(inst=="ADD")
            {
                regAddFunc(reg1,reg2);
                PC+=1;
            }
            else{        
                cerr<<"Here, There is wrong instruction"<<endl;
                exit(0);        
            } 
        }
        else if(leftInfo.size()==2 && numberControl(&leftInfo[1])==1 && leftInfo[0]=='R' && rightInfo[0]=='#' && numberControl(&rightInfo[1])==1)
        {
            int reg = leftInfo[1]-'0';
            int address = myAtoi(&rightInfo[1]);
            //reg-address
            if(inst=="MOV")
            {
                moveRegtoAddress(reg,address,memory);
                PC+=1;
            }
            else if(inst=="SUB")
            {
                subRegtoAdress(reg,address,memory);
                PC+=1;
            }
            else if(inst=="ADD")
            {
                addRegtoAdress(reg,address,memory);
                PC+=1;
            }
        }
        else if(leftInfo[0]=='#' && numberControl(&leftInfo[1])==1 && rightInfo.size()==2 && rightInfo[0]=='R' && numberControl(&rightInfo[1])==1)
        {
            //address-reg
            int address=myAtoi(&leftInfo[1]);
            int reg = rightInfo[1]-'0';
            if(inst=="MOV")
            {
                moveAdresstoReg(address, reg, memory);
                PC+=1;
            }
        
        }
        else if(leftInfo[0]=='#' && numberControl(&leftInfo[1])==1 && numberControl(rightInfo)==1)
        {
            int number=myAtoi(rightInfo);
            int address=myAtoi(&leftInfo[1]);
            //address-const
            if(inst=="MOV")
            {
                moveAddresstoConst(address,number,memory);
                PC+=1;
            }
        
        }
        else{        
                cerr<<"Here, There is wrong instruction"<<endl;
                exit(0);        
            }
            
    }
    else if(commaControl(str)==0)
    {
        instClearFunc(str);
        upperFunc(str);
        inst=instParse(str);
        string info=str.erase(0,3);
        instClearFunc(info);       
        
        if(inst=="JMP" && numberControl(info)==1)
        {
            jumpFunc(myAtoi(info));
        }
        else if(inst=="PRN" && info[0]=='#' && numberControl(&info[1])==1)
        {
            prntAdress(myAtoi(&info[1]),memory);
            PC+=1;
        }
        else if(inst=="PRN" && info.size()==2 && info[0]=='R' && numberControl(&info[1])==1)
        {
            Prn(regGet(myAtoi(&info[1])));
            PC+=1;
        }
        else if(inst=="PRN" && numberControl(info)==1)
        {
            Prn(myAtoi(info));
            PC+=1;
        }
        else if(inst!="PRN" && inst!="JMP" && inst!="HLT")
        {
            cerr<<"Here, There is wrong instruction"<<endl;
            exit(0);
        }
    }
    else{        
            cerr<<"Here, There is wrong instruction"<<endl;
            exit(0);        
    }      
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/