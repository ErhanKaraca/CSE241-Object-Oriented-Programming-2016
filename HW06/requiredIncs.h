#include <iostream>
#include "CPUProgramDyn.h"
#include "CPU.h"
#include "Computer.h"
#include "Memory.h"

using namespace std;
using namespace CPUProgramDYN;

int Atoi(string str){
    int x = 0;    
    for (int i = 0; str[i]!='\0'; ++i)
        x = x*10 + str[i] - '0';
    return x;
}
