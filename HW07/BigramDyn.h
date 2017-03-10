/*----------------------------------------------------------------------------*/
/*-----------------------------------HW07-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*-----------------------------BigramDyn.h------------------------------------*/
/*----------------------------------------------------------------------------*/

#ifndef BIGRAMDYN_H
#define BIGRAMDYN_H

#include <exception>
#include "Bigram.h"

/*Template base sınıfından türetilen template derived sınıf.                 */
template <class T>
class BigramDyn: public Bigram<T>{
    
    public:
        BigramDyn():cap(200){};
        BigramDyn(int dtype):dtp(dtype),cap(200){};        
        virtual void oprtr() override;
        virtual void readFile(const char* filename) throw(myyexception) override;
        virtual int numGrams()const override;
        virtual int numOfGrams(T x, T y) override;
        virtual pair<T , T > maxGrams() override;
        ~BigramDyn(){
            delete[] arr;
        }
    private:
        T* arr;
        int dtp;
        int cap;
        static int Ngram;
};

#endif
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/