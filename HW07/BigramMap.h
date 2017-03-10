/*----------------------------------------------------------------------------*/
/*-----------------------------------HW07-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*-----------------------------BigramMap.h----------------------------------*/
/*----------------------------------------------------------------------------*/

#ifndef BIGRAMMAP_H
#define BIGRAMMAP_H

#include <exception>
#include "Bigram.h"
#include <map>

/*Template base sınıfından türetilen template derived sınıf.                 */
template <class T>
class BigramMap: public Bigram<T>{
    
    public:
        BigramMap(){}
        BigramMap(int dtype):dtp(dtype){}        
        virtual void oprtr() override;
        virtual void readFile(const char* filename) throw(myyexception)override;
        virtual int numGrams()const override;
        virtual int numOfGrams(T x, T y) override;
        virtual pair<T , T > maxGrams() override;
    
    private:
        map<int,T> arr;
        int dtp;
        int cap;
        static int Ngram;
};
#endif
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/