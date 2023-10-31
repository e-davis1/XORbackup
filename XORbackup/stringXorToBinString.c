//
// Created by evaoj on 31/10/2023.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stringXorToBinString.h"


int stringXorToBinString(char* stringA, char* stringB, char* dest){
    int stringALen = (int) strlen(stringA);
    int stringBLen = (int) strlen(stringB);

    //the ? operator here means they default to the longer one
    for (int i = 0; i < ((stringALen > stringBLen) ? stringALen : stringBLen); i++ ) {
        char nextString[9];
        charXorToBinString(*(stringA+i), *(stringB+i), &nextString);
        strcpy(nextString, nextString);

        strcat(dest, nextString);
    }
    int (destLen) = (int) strlen(dest);
    return destLen;
}
void charXorToBinString(char a, char b, char* output){
    //char output[] = "00000000";
    char result =  a ^ b;
    itoa(result, output, 2);
    prependZeros(output);//this is needed because itoa strips leading zeroes, and sprintf doesn't do binary.
    //I could make a "myitoa" for this specific circumstance, but that can come once I'm polishing it
    //TODO make a myitoa
}

void prependZeros(char * output) {
    int outLen = (int)strlen(output);//using int here because it'll never be bigger than 8
    int incAmount = 8 - outLen;
    if (outLen < 8) {
        for (int i = 0; i < outLen; i++) {
            output[7 - i] = output [(outLen - 1) - i ];
#ifdef DEBUG
            printf("%c%c%c%c%c%c%c%c\n",output[0],output[0],output[0],output[0],output[0],output[0],output[6],output[7]);
            fflush(stdout);
#endif
        }//shift over the bits

        for (int i = 0; i < 8 - outLen; i++) {
            output[i] = '0';
        }//set the other bits to zero
    }
}