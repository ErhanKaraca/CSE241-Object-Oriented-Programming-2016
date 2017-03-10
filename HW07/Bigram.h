/*----------------------------------------------------------------------------*/
/*-----------------------------------HW07-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*----------------------------------Bigram.h----------------------------------*/
/*----------------------------------------------------------------------------*/

#ifndef BIGRAM_H
#define BIGRAM_H

#include <iostream>
#include <string>
#include <utility>



using namespace std;

/*Exception sınıfından inherit edilen myexception sınıfım.                   */
class myyexception: public exception
{
    virtual const char* what() const throw()
    {
        return "Do not open file or incorrect file.";
    }
};
/*Template abstract base sınıfı.                                             */
/*İçindeki fonksiyonlar türetilen sınıflarda override edilir.                */
template <class T>
class Bigram {
    
    public:
       
        virtual void readFile(const char* filename)=0;
        virtual int numGrams()const=0;
        virtual int numOfGrams(T x, T y)=0;
        virtual void oprtr()=0;
        friend ostream& operator<<(ostream& opt,  Bigram& bgrm){
        
            bgrm.oprtr();
            return opt;
        }
        virtual pair<T , T > maxGrams()=0;
};

#endif 
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/