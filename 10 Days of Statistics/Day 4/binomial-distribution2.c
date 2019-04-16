//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 4: Binomial Distribution II
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
/*
// HackerRank: https://www.hackerrank.com/challenges/s10-basic-statistics/problem
Task:
A manufacturer of metal pistons finds that, on average, 12% of the pistons they manufacture are rejected because they are incorrectly sized. What is the probability that a batch of 10 pistons will contain:

1. No more than 2 rejects?
2. At least 2 rejects?
*/

#include <stdio.h>
#include <stdlib.h>

int fact (int x){
    if (x > 1)
        return x*fact(x-1);
    else
        return 1;
}

float binomial (int x, int n, float p){

    return fact(n)/(fact(n - x) * fact(x)) * pow(1 - p, n - x) * pow(p, x);
}

int main() {
    float p;
    int n;

    scanf("%f %d", &p, &n);

    p = p/100;

    /*  
    b(x, n, p) = nCx q^(n-x)p^x
    x: is the number of successes
    n: is the total number of trials
    p: is the probability of success of 1 trial

    In this case:
    n = 10;
    p = 12% = 0.12;
    */

    printf("%.3f\n%.3f", binomial(0, n, p) + binomial(1, n, p) + binomial(2, n, p) , 1 - (binomial(0, n, p) + binomial(1, n, p)));

    return 0;
}