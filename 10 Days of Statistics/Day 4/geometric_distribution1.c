//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 4: Geometric Distribution I
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
// HackerRank: https://www.hackerrank.com/challenges/s10-basic-statistics/problem
/*
Task:
The probability that a machine produces a defective product is 1/3. What is the probability that the 1st defect is found during the 5th inspection?
*/

#include <stdio.h>
#include <stdlib.h>

float geometric_dist(float p, int nth){

    return pow((1-p), nth - 1) * p;
}


int main() {
    int n, d, nth;

    scanf("%d %d\n%d", &n, &d, &nth); 

    printf("%.3f", geometric_dist((float) n/d, nth));

    return 0;
}