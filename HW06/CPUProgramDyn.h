/*----------------------------------------------------------------------------*/
/*-----------------------------------HW06-------------------------------------*/
/*---------------------------MUSTAFA BİNGÜL 141044077-------------------------*/
/*------------------------------CPUProgramDyn.h-------------------------------*/
/*----------------------------------------------------------------------------*/

#ifndef CPUPROGRAMDYN_H
#define CPUPROGRAMDYN_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace CPUProgramDYN
{
    class CPUProgramDyn{

        public:

            CPUProgramDyn();
            CPUProgramDyn(int opt);
            CPUProgramDyn(char* fName);
            CPUProgramDyn(const CPUProgramDyn& progObject);
            ~CPUProgramDyn();
            void ReadFile(const char* fileName);
            string getLine(int lineNo)const;
            int size()const;        
            int getCapacity()const;
            char* getFilename()const;

            string& operator[](int lineNo);
            CPUProgramDyn operator+=(string instruction);       
            CPUProgramDyn operator--();
            CPUProgramDyn operator--(int l);
            CPUProgramDyn operator()(int x, int y);        
            friend ostream& operator<<(ostream& opt, const CPUProgramDyn& other);
            friend CPUProgramDyn operator+(CPUProgramDyn& other,const char* inst);
            friend CPUProgramDyn operator+(const CPUProgramDyn& other1CPUProgram,const CPUProgramDyn& other2CPUProgram);

            const bool operator==(const CPUProgramDyn& o1)const;
            const bool operator!=(const CPUProgramDyn& o1)const;
            const bool operator<=(const CPUProgramDyn& o1)const;
            const bool operator>=(const CPUProgramDyn& o1)const;
            const bool operator<(const CPUProgramDyn& o1)const;
            const bool operator>(const CPUProgramDyn& o1)const;
        private:

            char* filename;
            string* strArray;
            int option;
            int capacity;

    };
}
#endif /* CPUPROGRAMDYN_H */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/