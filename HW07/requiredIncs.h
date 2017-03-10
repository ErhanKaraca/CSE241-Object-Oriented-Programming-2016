#ifndef REQUIREDINCS_H
#define REQUIREDINCS_H

#include <iostream>

using namespace std;

#include "Bigram.h"
#include "BigramDyn.h"
#include "BigramMap.h"
#include "BigramDyn.cpp"
#include "BigramMap.cpp"

int atoi(string str){
    int x = 0;    
    for (int i = 0; str[i]!='\0'; ++i)
        x = x*10 + str[i] - '0';
    return x;
}

#endif /* REQUIREDINCS_H */
