#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// Only need to focus this particular function i.e. custom Z-Function.
int stringSimilarity(char* s) {

    int currPos = 0;
    int similaritySum = 0;
    
    while (s[currPos] != '\0') {
        int startPosIndx = 0;
        int currPosIndx = currPos;

        while (s[startPosIndx] == s[currPosIndx] && s[currPosIndx] != '\0') {
            similaritySum++;

            startPosIndx++;
            currPosIndx++;
        }

        currPos++;
    }

    return similaritySum;
}

int main() {
    int t; 
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result = stringSimilarity(s);
        printf("%d\n", result);
    }
    return 0;
}
