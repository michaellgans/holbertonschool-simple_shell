#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** splitString(const char* input, int* numWords) {
    // Calculate the number of words in the input string
    int wordCount = 0;
    char* copy = strdup(input); // Make a copy of the input string, as strtok modifies the string
    char* token = strtok(copy, " \t\n"); // Split by spaces, tabs, and newlines

    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " \t\n");
    }
    free(copy);

    // Allocate memory for the array of words
    char** words = (char**)malloc(wordCount * sizeof(char*));
    if (words == NULL) {
        // Memory allocation failed
        *numWords = 0;
        return NULL;
    }

    // Split the string again and store each word in the array
    copy = strdup(input);
    token = strtok(copy, " \t\n");
    int i = 0;

    while (token != NULL) {
        words[i] = strdup(token);
        token = strtok(NULL, " \t\n");
        i++;
    }
    free(copy);

    *numWords = wordCount;
    return words;
}

int main() {
    const char* input = "We're trying to split this string using strtok";
    int numWords;
    char** words = splitString(input, &numWords);

    if (words != NULL) {
        printf("The string has been split into %d words:\n", numWords);
        for (int i = 0; i < numWords; i++) {
            printf("%s\n", words[i]);
            free(words[i]); // Free the memory for each word
        }
        free(words); // Free the memory for the array of words
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

