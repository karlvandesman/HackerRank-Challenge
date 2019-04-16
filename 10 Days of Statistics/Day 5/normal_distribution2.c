//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 5: Normal Distribution II 
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
// HackerRank: https://www.hackerrank.com/challenges/s10-basic-statistics/problem
/*
Task:
The final grades for a Physics exam taken by a large group of students have a mean of 70 and a standard deviation of 10. If we can approximate the distribution of these grades by a normal distribution, what percentage of the students:

1. Scored higher than 80 (i.e., have a grade > 80)?
2. Passed the test (i.e., have a grade >= 60)?
3. Failed the test (i.e., have a grade < 60)?

Find and print the answer to each question on a new line, rounded to a scale of 2 decimal places.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float z(float time, float mean, float sigma){

    return (time - mean)/(sigma*sqrt(2));
}

int main() {

    float mean, sigma, grade1, grade2, erf1, erf2, p1, p2;

    scanf("%f %f\n%f\n%f", &mean, &sigma, &grade1, &grade2);

    p1 = 100*(0.5 * (1 + erf(z(grade1, mean, sigma))));
    p2 = 100*(0.5 * (1 + erf(z(grade2, mean, sigma))));

    printf("%.2f\n%.2f\n%.2f", 100 - p1, 100 - p2, p2);

    return 0;
}