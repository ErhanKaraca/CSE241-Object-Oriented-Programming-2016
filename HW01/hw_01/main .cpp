#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void calc(string str,int array[],ifstream& file,char* arg);
int myatoi(string str);
void myMove(int reg1, int *reg2);
void myMoveConst(int *reg1, int reg2);
void myAdd(int *reg1, int reg2);
void mySub(int *reg1, int reg2);
void myPrint(int reg);
void myPrintConst(int reg);
void eraseFunc(string& str);
int comEndCont(string str);
void clearParse(string& str);
string instParse(string str);
void infoParse(string str,string& str1,string& str2);
int comCont(string str);
int numCont(string str);
void myJumpLine(int* reg1,int line,ifstream& file,char* arg);
void myJump(int line,ifstream& file, char* arg);
void capFunc(string& strr);

void printOption(string str, int *array);



int main(int argc, char** argv){

    string str;
    const int P=5;
    int arr[P]={0,0,0,0,0};

    ifstream filest;  
    filest.open(argv[1]);

    if(argv[1]==NULL)
    {
    	cerr<<"File not found.";
    	return 0;
    }

    if(myatoi(argv[2])!=1 && myatoi(argv[2])!=0)
    {
    	cerr<<"Wrong Option.";
    	return 0;
    }
    while(getline(filest,str))
    {
    	if(myatoi(argv[2])==1)
    	{
    		calc(str,arr,filest,argv[1]);
    		printOption(str,arr);
    	}
    	else if(myatoi(argv[2])==0)
    	{
    		calc(str,arr,filest,argv[1]);
    	}        
    } 
    

    filest.close();
    return 0;
}
/*																			 */
/*Fonsiyon islemlerin gerceklestirildigi yer.								 */
/*																			 */
/*@param: str 		; gelen komur satiri.									 */
/*@param: array[] 	; registerlerin degerleri tutulur.						 */
/*@param: file 		; dosya islemleri 										 */
/*@param: *arg 		; disaridan alınan input dosya							 */
/*																			 */
void calc(string str,int array[],ifstream& file,char* arg){
    
    clearParse(str);
    capFunc(str);
    string inst=instParse(str);       
    string left,right;    
    infoParse(str,left,right);
    eraseFunc(left);
    eraseFunc(right);       
    
    if(inst=="HLT")
    {
        return ;
    }
    if(comCont(str)==1)
    {
        if(left.size()==2 && left[0]=='R' && numCont(right)==1)
        {
            int number=myatoi(right);
            int reg=left[1]-'0';
            if(inst=="MOV")
            {
                myMoveConst(&array[reg-1],number);
            }
            else if(inst=="ADD")
            {
                myAdd(&array[reg-1],number);
            }
            else if(inst=="SUB")
            {

                mySub(&array[reg-1],number);

            }
            else if(inst=="JMP")
            {
                myJumpLine(&array[reg-1],number,file,arg);
            }
        }
        else if(left.size()==2 && right.size()==2 && left[0]=='R' && right[0]=='R')
        {
            int reg1=left[1]-'0';
            int reg2=right[1]-'0';

            if(inst=="MOV")
            {
                myMove(array[reg1-1],&array[reg2-1]);
            }
            else if(inst=="ADD")
            {
                myAdd(&array[reg1-1],array[reg2-1]);
            }
            else if(inst=="SUB")
            {
                cout<<array[reg2-1]<<endl;
                mySub(&array[reg1-1],array[reg2-1]);
            }

        }
    }
    else if(comCont(str)==0)
    {
        string inf = str.erase(0,3);
        eraseFunc(inf);
        if(inst=="JMP" && numCont(inf)==1)
        {
            myJump(myatoi(inf),file,arg);
        }
        if(inst=="PRN" && inf.size()==2 && inf[0]=='R' && numCont(&inf[1])==1)
        {               
            int reg=inf[1]-'0';
            myPrint(array[reg-1]);            
        }
        else if(inst=="PRN" && numCont(inf)==1)
        {           
            myPrintConst(myatoi(inf));
        }
    }
}
/*                                                                           */
/*Gelen option 1 ise ekrana yazdirmak icin kullanilir. 						 */
/*                                                                           */
/*@param: str 		; yazdirilacak komut satiri.							 */
/*@param: *array 	; registerlarin degerleri icin gonderilir.				 */
/*                                                                           */
void printOption(string str, int *array)
{
	clearParse(str);
	capFunc(str);
	cout<<str<<"-"<<"R1="<<array[0]<<","
				<<"R2="<<array[1]<<","
				<<"R3="<<array[2]<<","
				<<"R4="<<array[3]<<","
				<<"R5="<<array[4]<<endl;		
}
/*                                                                           */
/*Sayisal deger iceren string tipleri int veri tipine cevirir.               */
/*                                                                           */
/*@param: str       ; cevirilecek string ifade.                              */
/*@return:          ; int veri tipi olarak deger doner.                      */
/*http://stackoverflow.com/questions/28919861/atoi-implementation-in-c       */
/*                                                                           */
int myatoi(string str){
    int x = 0;    
    for (int i = 0; str[i]!='\0'; ++i)
        x = x*10 + str[i] - '0';
    return x;
}
/*                                                                           */
/*İki register arasinda move islemini gerceklestirir.                        */
/*                                                                           */
/*@param: reg1      ; tasinacak register.                                    */
/*@param: *reg2     ; yeni register.                                         */
/*@return:          ; pointer olarak yeni degeri dondurur.                   */
/*                                                                           */
void myMove(int reg1, int *reg2){
    *reg2=reg1;
}
/*                                                                           */
/*Register ve sabit deger arasinda move islemini gerceklestirir.             */
/*                                                                           */
/*@param: reg2      ; tasinacak register.                                    */
/*@param: *reg1     ; yeni registeri.                                        */
/*@return:          ; pointer olarak yeni degeri dondurur.                   */
/*                                                                           */
void myMoveConst(int *reg1, int reg2){
    *reg1=reg2;
}
/*                                                                           */
/*Toplama islemi gerceklestirilir.                                           */
/*                                                                           */
/*@param: *reg1     ;                                                        */
/*@param: reg2      ;                                                        */
/*@return:          ; pointer olarak yeni degeri dondurur.                   */
/*                                                                           */
void myAdd(int *reg1, int reg2){
    *reg1+=reg2;   
}
/*                                                                           */
/*Cikarma islemi gerceklestirilir.                                           */
/*                                                                           */
/*@param: *reg1     ;                                                        */
/*@param: reg2      ;                                                        */
/*@return:          ; pointer olarak yeni degeri dondurur.                   */
/*                                                                           */
void mySub(int *reg1, int reg2){
    *reg1-=reg2;
}
/*                                                                           */
/*Ekrana bastırma islemi gerceklestirilir.                                   */
/*                                                                           */
/*@param: reg      ; ekrana bastirilacak degerin registeri.                  */
/*                                                                           */
void myPrint(int reg){
    cout << reg << endl;
}
/*                                                                           */
/*Ekrana bastırma islemi gerceklestirilir.                                   */
/*                                                                           */
/*@param: reg      ; ekrana bastirilacak deger.                              */
/*                                                                           */
void myPrintConst(int reg){
    cout << reg << endl;
}
/*                                                                           */
/*Verilen string ifadenin basindaki ve sonundaki bosluklari siler.           */
/*  Fonksiyon referans olarak calisir.                                       */
/*                                                                           */
/*@param: str      ; islemin uygulanacagi string.                            */
/*                                                                           */
void eraseFunc(string& str){
    int i=0;
    while(str[i]==' ')
    {
        ++i;
    }
    str.erase(0,i);
    
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
/*                                                                           */
/*Verilen string ifade de (;) olup olmadigini kontrol eder.                  */
/*                                                                           */
/*@param: str      ; islemin uygulanacagi string.                            */
/*@return:         ; gerceklesen sarta gore 1 veya 0 doner.                  */
/*                                                                           */
int comEndCont(string str){
    for(int i=0; i<str.size();++i)
    {
        if(str[i]==';')
        {
            return 1;
        }
    }
    return 0;
}
/*                                                                           */
/*Genel string icin silme islemini gerceklestirir.                           */
/*  Fonksiyon referans olarak calisir.                                       */
/*                                                                           */
/*@param: str      ; islemin uygulanacagi string.                            */
/*                                                                           */
void clearParse(string& str){
    int i=0;
    while(str[i]==' ')//baştaki boşluklaır sil varise..
    {
        ++i;    
    }
    str.erase(0,i);

    if(comEndCont(str)==1)
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
/*                                                                           */
/*İnstruction komutunu parse eder.                                           */
/*                                                                           */
/*@param: str      ; islemin uygulanacagi string.                            */
/*@return:         ; string deger dondurur.                                  */
/*                                                                           */
string instParse(string str){    
    string inst;
    inst=str.substr(0,3);
    return inst;
}
/*                                                                           */
/*İnstruction dan sonraki kisimlari parse eder.                              */
/*  Fonksiyonun referans olarak calisan parametreleri vardir.                */
/*                                                                           */
/*@param: str      ; islemin uygulanacagi string.                            */
/*@param: str1     ; referans olarak virgul den onceki kismi return eder.    */
/*@param: str2     ; referans olarak virgul den sonraki kismi return eder.   */
/*                                                                           */
void infoParse(string str,string& str1,string& str2){
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
/*                                                                           */
/*Gelen satir komutunda virgül indexini bulur.                               */
/*                                                                           */
/*@param: str      ; islemin uygulanacagi string.                            */
/*@return :        ; virgulun indexi doner.                                  */
/*                                                                           */
int comCont(string str){

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
/*                                                                           */
/*Gelen string tipindeki degiskenin sayi olup olmadigina bakar.              */
/*                                                                           */
/*@param: str      ; islemin uygulanacagi string.                            */
/*@return :        ; sartin saglanmasina gore 1 veya 0 doner.                */
/*                                                                           */
int numCont(string str){
    for(int x=0; x<str.size(); ++x){
        if(str[x]<'0' || str[x]>'9')
        {
            return 0;
        }        
    }
    return 1;
}
/*                                                                           */
/*Gitmesi gereken satira gider ordan itibaren okur. 						 */
/*	Oncesinde register kontrolu yapar. 										 */
/*                                                                           */
/*@param: *reg1 		; 0 esitliginin kontrolunun yapildigi register.		 */
/*@param: line 			; gidecegi satir.									 */
/*@param: file 			; dosya islemi icin.	  							 */
/*@param: *arg 			; dosya adi.										 */
/*                                                                           */
void myJumpLine(int* reg1,int line,ifstream& file,char* arg){
    string jstr;
    int jarray[5];
    
    if(*reg1==0)
    {
        file.close();
        file.open(arg);
        for(int x=1; x<line; ++x)
        {
            getline(file,jstr);
        }
    }
    else
        return ;
}
/*                                                                           */
/*Gitmesi gereken satira gider ordan itibaren okur.							 */
/*                                                                           */
/*@param: line 			; gidecegi satir.									 */
/*@param: file 			; dosya islemi icin.	  							 */
/*@param: *arg 			; dosya adi.										 */
/*                                                                           */
void myJump(int line,ifstream& file, char* arg){
    string jstr;
    int jarray[5];
    file.close();
    file.open(arg);
    for(int x=1; x<line; ++x)
    {
        getline(file,jstr);
    }
}
/*																			 */
/*komut satirindaki tüm kucuk harfleri buyuk harf yapar.					 */
/*																			 */
/*@param: str 		; komut satiri.											 */
/*																			 */
void capFunc(string& strr){
    for(int i=0; i<strr.size(); ++i)
    {
        if(strr[i]>='a' && strr[i]<='z')
        {
            strr[i] -= 'a' - 'A'; 
        }
    }
    return ;
}