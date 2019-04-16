//  - - - - - - - - - - - - - - - - - - - -
// |          10 Days of Statistics        |
//  - - - - - - - - - - - - - - - - - - - -
// Day 0: Mean, Median, and Mode
// Author: Karl Sousa <karlvandesman@gmail.com>
// - - - - - - - - - - - - - - - - - - - - -
/*
https://www.hackerrank.com/challenges/s10-basic-statistics/problem

Task:
Given an array, X, of N integers, calculate and print the respective mean, median, and mode on separate lines. If your array contains more than one modal value, choose the numerically smallest one.

Note: Other than the modal value (which will always be an integer), your answers should be in decimal form, rounded to a scale of 1 decimal place (i.e., 12.3, 7.0 format).
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int mode[2] = {0, 1};   //array with the mode, mode[0], and its frequency, mode[1]
    unsigned int sum = 0;
    unsigned int arraySize, *arrayElements, *arrayFreq;

    scanf("%d\n", &arraySize);

    arrayElements = (int*) malloc(arraySize * sizeof(int)); 
    arrayFreq = (int*) malloc(arraySize * sizeof(int));

    for (int i; i < arraySize; i++){
        scanf("%d", &arrayElements[i]);
        sum+= arrayElements[i];
    }

    printf("%.1f\n", (float) sum/arraySize);  //print the mean value

    //sorting the array in an ascending order
    for (int i = 0; i < arraySize; ++i){
        for (int j = i + 1; j < arraySize; ++j){
            if (arrayElements[i] > arrayElements[j]) {
                int temp = arrayElements[i];
                arrayElements[i] = arrayElements[j];
                arrayElements[j] = temp;
            }
        }
    }

    //printing the median (central number)
    if(arraySize%2) //if the arraySize is odd, then there is a the central number
        printf("%d", arrayElements[(int)ceil(arraySize/2)]); 
    else            //if is even, the median is the mean between the 2 central numbers
        printf("%.1f\n", (float) (arrayElements[(arraySize/2)-1] + arrayElements[arraySize/2])/2);
    
    mode[0] = arrayElements[0];     //first value to start iterations

    for (int i = 0, j = 1; i < arraySize;){
        while(arrayElements[i] == arrayElements[i+j])
            j++;
        if(j > mode[1]){
            mode[1] = j;
            mode[0] = arrayElements[i];
        }
        j = 1;
        i += j;
    }
    
    printf("%d", mode[0]);      //print the smallest mode (for multiple ocurrences)

    free(arrayElements);
    free(arrayFreq);

    return 0;
}
