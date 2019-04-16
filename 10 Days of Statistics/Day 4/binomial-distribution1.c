//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 4: Binomial Distribution I
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
// HackerRank: https://www.hackerrank.com/challenges/s10-basic-statistics/problem
/*
Task:
The ratio of boys to girls for babies born in Russia is 1.09 : 1. If there is 1 child born per birth, what proportion of Russian families with exactly 6 children will have at least 3 boys?

Write a program to compute the answer using the above parameters. Then print your result, rounded to a scale of 3 decimal places (i.e., 1.234 format).
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
    float rBoys, rGirls;

    scanf("%f %f", &rBoys, &rGirls);

    float p = rBoys/(rBoys+rGirls);

    /*
    b(x, n, p) = nCx q^(n-x)p^x
    x: is the number of successes
    n: is the total number of trials
    p: is the probability of success of 1 trial

    In this case:
    n = 6;
    x >= 3;
    p = 1.09/2.09;

    So, 
    b(x >= 3, 6, 1.09/2.09)
    */

    printf("%.3f", binomial(3, 6, p) + binomial(4, 6, p) + binomial(5, 6, p) + binomial(6, 6, p) ); 

    return 0;
}