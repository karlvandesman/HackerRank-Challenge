//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 6: The Central Limit Theorem I
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
// HackerRank: https://www.hackerrank.com/challenges/s10-basic-statistics/problem
/*
Task:
A large elevator can transport a maximum of 9800 pounds. Suppose a load of cargo containing 49  boxes must be transported via the elevator. The box weight of this type of cargo follows a distribution with a mean of 205 pounds and a standard deviation of 15 pounds. Based on this information, what is the probability that all 49 boxes can be safely loaded into the freight elevator and transported?
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float z(float x, float mean, float sigma){

    return (x - mean)/(sigma*sqrt(2));
}

int main() {
    int n, weightMax;
    float mean, stdev, p;

    scanf("%d\n%d\n%f\n%f", &weightMax, &n, &mean, &stdev);

    //updating the parameters for this large value of n, so the distribution of sample sums is close to normal distribution
    mean = n * mean;
    stdev = sqrt(n) * stdev;

    p = 0.5 * (1 + erf(z(weightMax, mean, stdev)));

    printf("%.4f", p);
    return 0;
}