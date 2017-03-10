/*----------------------------------------------------------------------------*/
/*-----------------------------------HW07-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*-----------------------------BigramMap.cpp----------------------------------*/
/*----------------------------------------------------------------------------*/
#include "BigramMap.h"

#include <fstream>
#include <set>


using namespace std;

template<class T>
int BigramMap<T>::Ngram=2;
/*Dosyadan okuma işlemin gerçekleşir.                                        */
template<class T>
void BigramMap<T>::readFile(const char* filename)throw(myyexception){
    
    ifstream dofile;
    
    dofile.open(filename);
    if(!dofile.is_open()){    
    	
        throw myyexception();
    }
    
    int i=0;    
    T temp;    
    while(!dofile.eof()){          
            
        if(dofile>>temp){
        arr[i]=temp;
        
            i++;
        }
        else{
       		 //if(!dofile.eof())
            throw myyexception();
        }
    } 
    cap=i;
    
    
    dofile.close();
}
/*Verilen dizi içindeki gram sayısını döndürür.                              */
template<class T>
int BigramMap<T>::numGrams()const{
    return cap-1;
}
/*Verilen ikili değerin gram sayısını döndürür.                              */
template <class T>
int BigramMap<T>::numOfGrams(T x , T y){

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
/*<< operatorunu overload edebilmek için bu fonksiyon implement edilir.      */
template<class T>
void BigramMap<T>::oprtr(){
    
    map<int,pair<T,T> > mpbgrm;
    pair<T,T> bgrmpair;
    
    set<pair<T,T>> setbgrm;
    
    map<int,pair<T,T> > oddmp;
    
    pair<int,int> pairGram;
    set<pair<int,int>> setGram;
    
    for(int i=0; i<cap-1; ++i){
        
        bgrmpair.first=arr[i];
        bgrmpair.second=arr[i+1]; 
        
        mpbgrm[i]=bgrmpair;
    }
        
    //set e ekleme yapıyor. teke düşürmek için. mapten ekliyor
    for(auto p=mpbgrm.begin(); p!=mpbgrm.end(); ++p){
        
        setbgrm.insert(p->second);
       
    }
       
    //tekleri mape aldım tekrardan... setten. tekk MAP.
    int k=0;
    
    for(auto i=setbgrm.begin(); i!=setbgrm.end(); ++i){
        
        oddmp[k].first=i->first;
        oddmp[k].second=i->second;
        ++k;
    }
    //gram sayıları sete alınır.
    for(int i=0; i<oddmp.size(); ++i){
        
        pairGram.first=numOfGrams(oddmp[i].first,oddmp[i].second);
        pairGram.second=numOfGrams(oddmp[i].first,oddmp[i].second);
        
        setGram.insert(pairGram);
    }
    
    for(auto p=setGram.rbegin(); p!=setGram.rend();++p){        
        
        for(int i=0; i<oddmp.size(); ++i){
            
            if(numOfGrams(oddmp[i].first,oddmp[i].second)==p->second){
        
                cout<<oddmp[i].first<<"-"<<oddmp[i].second<<endl;
            }
        }
    }
}
/*Maximum gram sayısına sahip olan ikiliyi return eder.                      */
template<class T>
pair<T , T> BigramMap<T>::maxGrams(){
    
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
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/