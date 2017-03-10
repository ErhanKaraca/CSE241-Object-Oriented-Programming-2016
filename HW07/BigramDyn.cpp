/*----------------------------------------------------------------------------*/
/*-----------------------------------HW07-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*-----------------------------BigramDyn.cpp----------------------------------*/
/*----------------------------------------------------------------------------*/

#include "BigramDyn.h"

#include <fstream>
#include <utility>

using namespace std;

template<class T>
int BigramDyn<T>::Ngram=2;
/*Dosyadan okuma işlemin gerçekleşir.                                        */
template<class T>
void BigramDyn<T>::readFile(const char* filename)throw(myyexception){
    
    arr = new T[cap];
    ifstream dof;
    dof.open(filename,ios::in);
    if(!dof.is_open()){
        
        throw myyexception();
    
    }
    int k=0;
    while(!dof.eof()){
        if(dof>>arr[k]){
            
            ++k;
        }
        else    
        {
            
            throw myyexception();
        }
    }
    
    cap=k;
    
    delete[] arr;
    dof.close();
    
    arr = new T[cap];
    
    ifstream dofile;
    dofile.open(filename,ios::in);
    int i=0;
    while(!dofile.eof()){
        if(dofile>>arr[i]){
            
            ++i;
        }
        else{    
            throw myyexception();
        }
    }  
       
    dofile.close();
}
/*Verilen dizi içindeki gram sayısını döndürür.                              */
template<class T>
int BigramDyn<T>::numGrams()const{
    
    return cap-1;
}
/*Verilen ikili değerin gram sayısını döndürür.                              */
template<class T>
int BigramDyn<T>::numOfGrams(T x, T y){
    
    T* arrT = new T[Ngram];
    arrT[0]=x;
    arrT[1]=y;
    int count=0;
    for(int i=0; i<cap; ++i){
        
        if(arr[i]==arrT[0] && arr[i+1]==arrT[1]){
            
            ++count;
                
        }    
    }    
    return count;    
}
/*Maximum gram sayısına sahip olan ikiliyi return eder.                      */
template<class T>
std::pair<T , T > BigramDyn<T>::maxGrams(){
    
    std::pair<T, T> temp;
    
    int a=0,b=0;
    for(int y=0; y<cap-1;++y){
        
        if(numOfGrams(arr[y],arr[y+1])>a){
            a=numOfGrams(arr[y],arr[y+1]);
            b=y;
        }
    }    
    temp.first = arr[b];
    temp.second = arr[b+1];

    return temp;
}
/*<< operatorunu overload edebilmek için bu fonksiyon implement edilir.      */
template<class T>
void BigramDyn<T>::oprtr(){

    std::pair<T,T> bgrmpair;
    
    pair<T,T>* art = new pair<T,T>[200];
    int* dat = new int[200];
    
    
    pair<T,T> tmp;
    for(int i=0; i<cap-1; ++i){
        
        bgrmpair.first=arr[i];
        bgrmpair.second=arr[i+1];
        art[i]=bgrmpair;
    }
    
    //pairlere pararll bir arrayda gramlarını tutacaz
    for(int i=0; i<cap-1;++i){
        
        dat[i]=numOfGrams(art[i].first,art[i].second);
    }
    
    for(int i=0; i<cap;++i){        
        int t=0;
        for(int m=0; m<cap-1;++m){
            if(dat[m]<dat[m+1]){
                t=dat[m];
                dat[m]=dat[m+1];
                dat[m+1]=t;
                
                tmp=art[m];
                art[m]=art[m+1];
                art[m+1]=tmp;
            }
        }
    }
                
    for(int i=0; i<cap-1; ++i){        
        if(art[i]==art[i+1]){
        }
        else{
            cout<<art[i].first<<"-";
            cout<<art[i].second<<endl;
        }
    }
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/