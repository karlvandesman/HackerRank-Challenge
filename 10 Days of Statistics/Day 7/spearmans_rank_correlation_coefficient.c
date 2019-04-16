//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 7: Spearman's Rank Correlation Coefficient
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
// HackerRank: https://www.hackerrank.com/challenges/s10-basic-statistics/problem
/*
Task:
Given two n-element data sets, X and Y, calculate the value of Spearman's rank correlation coefficient.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned short n;
    float sum = 0;

    scanf("%hu", &n);

    float x[n], y[n];
    unsigned short rX[n], rY[n];

    for(int i = 0; i < n; i++){
        rX[i] = 0;
        scanf("%f", &x[i]);
        for(int j = i; j >= 0; j--){
            if(x[i] > x[j])
                rX[i]++;
            else
                rX[j]++;
        }
    }

    for(int i = 0; i < n; i++){
        rY[i] = 0;
        scanf("%f", &y[i]);
        for(int j = i; j >= 0; j--){
            if(y[i] > y[j])
                rY[i]++;
            else
                rY[j]++;
        }
    }

    for(int i = 0; i < n; i++){
        sum += pow(rX[i] - rY[i], 2);
    }
  
    printf("%.3f", 1 - 6 * sum/(n * (n * n - 1)));
    return 0;
}