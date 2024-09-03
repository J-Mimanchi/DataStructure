#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the prefix table used by the KMP algorithm
void computePrefixTable(char* pattern, int patternSize, int* prefixTable) {
    int length = 0;
    prefixTable[0] = 0;  // The length of the longest proper prefix which is also suffix
    int i = 1;

    while (i < patternSize) {
        if (pattern[i] == pattern[length]) {
            length++;
            prefixTable[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = prefixTable[length - 1];
                // Note: We do not increment i here
            } else {
                prefixTable[i] = 0;
                i++;
            }
        }
    }
}

// KMP search algorithm
void KMP(char* text, char* pattern) {
    int textSize = strlen(text);
    int patternSize = strlen(pattern);
    int* prefixTable = (int*)malloc(patternSize * sizeof(int));

    computePrefixTable(pattern, patternSize, prefixTable);


    //print prefix table
    for (int i = 0; i < patternSize; i++) {
        printf("%d ", prefixTable[i]);
    }
    printf("\n");

    int i = 0;  // index for text
    int j = 0;  // index for pattern

    while (i < textSize) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == patternSize) {
            printf("Found pattern at index %d\n", i - j);
            j = prefixTable[j - 1];
        } else if (i < textSize && pattern[j] != text[i]) {
            if (j != 0)
                j = prefixTable[j - 1];// Note: We do not increment i here

            else
                i = i + 1;
        }
    }

    free(prefixTable);
}

int main() {
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    KMP(text, pattern);
    return 0;
}
