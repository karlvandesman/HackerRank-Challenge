//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 8: Least Square Regression Line
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
// HackerRank: https://www.hackerrank.com/challenges/s10-basic-statistics/problem
/*
Task:
A group of five students enrolls in Statistics immediately after taking a Math aptitude test. Each student's Math aptitude test score, x, and Statistics course grade, y, can be expressed as the following list of (x, y) points:

1. (95, 85)
2. (85, 95)
3. (80, 70)
4. (70, 65)
5. (60, 70)

If a student scored an 80 on the Math aptitude test, what grade would we expect them to achieve in Statistics? Determine the equation of the best-fit line using the least squares method, then compute and print the value of y when x = 80.
*/

#include <stdio.h>

#define N   5       //# of pairs (x, y)
#define X1  80      //Value of X that will be calculated

int main() {

    unsigned short i = 0, x[N], y[N];
    float a, b, sumX, sumY, sumX2, sumXY;

    sumX = sumY = sumX2 = sumXY = 0;

    while(scanf("%hu %hu\n", &x[i], &y[i]) == 2){
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        ++i;
    }

    b = (N * sumXY - sumX * sumY)/(N * sumX2 - sumX * sumX);
    a = (sumY - b * sumX)/5;

    printf("%.3f", a + b * X1);
    return 0;
}