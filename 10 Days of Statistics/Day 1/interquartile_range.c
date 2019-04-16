
//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 1: Interquartile Range
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
/*
https://www.hackerrank.com/challenges/s10-basic-statistics/problem

Task:
The interquartile range of an array is the difference between its first (Q1) and third (Q3) quartiles (i.e., Q3 - Q1).

Given an array, X, of n integers and an array, F, representing the respective frequencies of X's elements, construct a data set, s, where each xi occurs at frequency fi. Then calculate and print S's interquartile range, rounded to a scale of 1 decimal place (i.e., 12.3 format).

Tip: Be careful to not use integer division when averaging the middle two elements for a data set with an even number of elements, and be sure to not include the median in your upper and lower data sets.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    unsigned short n, size = 0, *elements, *x, *f;
    float q1, q3;

    scanf("%hu", &n);

    x = (unsigned short*) malloc (n * sizeof(unsigned short*));
    f = (unsigned short*) malloc (n * sizeof(unsigned short*));

    for(int i = 0; i < n; i++)
        scanf("%hu", &x[i]);

    for(int i = 0; i < n; i++){
        scanf("%hu", &f[i]);
        size += f[i];
    }

    elements = (unsigned short*) malloc (size * sizeof(unsigned short*));

    int index = 0;

    for(int i = 0; i < n; i++){     //Creating the complete array
        for(int j = 0; j < f[i]; j++){
            elements[index] = x[i];
            index++;
        }
    }

    for(int i = 0; i < size; i++){  //Sorting the complete array
        for(int j = i + 1; j < size; j++){
            if(elements[i] > elements[j]){
                unsigned short temp;
                temp = elements[j];
                elements[j] = elements[i];
                elements[i] = temp;
            }
        }
    }

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

    printf("%.1f", q3 - q1);

    free(x, f, elements);
    return 0;
}