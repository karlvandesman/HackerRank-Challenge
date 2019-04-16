//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 7: Pearson Correlation Coefficient I
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
// HackerRank: https://www.hackerrank.com/challenges/s10-basic-statistics/problem
/*
Task:
Given two n-element data sets, X and Y, calculate the value of the Pearson correlation coefficient.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    unsigned short n;
    float sum, meanX, meanY, stdevX, stdevY, sumX = 0, sumY = 0;

    scanf("%hu", &n);

    float x[n], y[n];

    for(int i = 0; i < n; i++){
        scanf("%f", &x[i]);
        sumX += x[i];
    }
    meanX = sumX/n;

    for(int i = 0; i < n; i++)
        sum += pow(x[i] - meanX, 2);

    stdevX = sqrt(sum/n);

    for(int i = 0; i < n; i++){
        scanf("%f", &y[i]);
        sumY += y[i];
    }
    meanY = sumY/n;
    
    for(int i = sum = 0; i < n; i++)
        sum += pow(y[i] - meanY, 2);

    stdevY = sqrt(sum/n);

    for(int i = sum = 0; i < n; i++)
        sum += (x[i] - meanX) * (y[i] - meanY);

    printf("%.3f", sum/(n * stdevX * stdevY));
    return 0;
}