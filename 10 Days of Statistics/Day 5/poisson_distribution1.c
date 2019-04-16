//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 5: Poisson Distribution I
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
// HackerRank: https://www.hackerrank.com/challenges/s10-basic-statistics/problem
/*
Task:
A random variable, X, follows Poisson distribution with mean of 2.5. Find the probability with which the random variable X is equal to 5.
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int fact(int a){

    if(a > 1)
        return a * fact(a - 1);
    else
        return 1;
}

float poisson_dist(int k, float lambda){
    
    return (pow(lambda, k) * exp(-lambda))/fact(k);
}

int main() {

    float lambda;
    unsigned short k;

    scanf("%f\n%hu", &lambda, &k);

    printf("%.3f", poisson_dist(k, lambda));

    return 0;
}