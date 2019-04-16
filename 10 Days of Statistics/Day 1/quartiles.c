//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 1: Quartiles
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
/*
https://www.hackerrank.com/challenges/s10-basic-statistics/problem

Task:
Given an array, X, of n integers, calculate the respective first quartile (Q1), second quartile (Q2), and third quartile (Q3). It is guaranteed that Q1, Q2, and Q3 are integers.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    unsigned short size, *elements, q1, q2, q3;

    scanf("%hu", &size);

    elements = (unsigned short*) malloc(size * sizeof(unsigned short*));

    for (int i = 0; i < size; i++)
        scanf("%hu", &elements[i]);
    
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(elements[i] > elements[j]){
                unsigned short temp;
                temp = elements[j];
                elements[j] = elements[i];
                elements[i] = temp;
            }
        }
    }

    if(size%2)
        q2 = elements[size/2];
    else
        q2 = (elements[size/2] + elements[size/2-1])/2;

    if((size/2)%2){
        q1 = elements[size/4];
        q3 = elements[3*size/4];
    }
    else{
        q1 = (elements[size/4] + elements[size/4-1])/2;
        if(size%2)
            q3 = (elements[3*size/4] + elements[3*size/4+1])/2;
        else
            q3 = (elements[3*size/4] + elements[3*size/4-1])/2;
    }

    printf("%d\n%d\n%d", q1, q2, q3);

    free(elements);
    return 0;
}