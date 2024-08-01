#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void toLowerCase(char* str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char paragraph[10000];
    WordFrequency wordFreq[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);
    
    char* token = strtok(paragraph, " \n.,;:!?\"'()-");
    while (token != NULL) {
        toLowerCase(token);

        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(wordFreq[i].word, token) == 0) {
                wordFreq[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && wordCount < MAX_WORDS) {
            strcpy(wordFreq[wordCount].word, token);
            wordFreq[wordCount].count = 1;
            wordCount++;
        }

        token = strtok(NULL, " \n.,;:!?\"'()-");
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFreq[i].word, wordFreq[i].count);
    }

    return 0;
}
