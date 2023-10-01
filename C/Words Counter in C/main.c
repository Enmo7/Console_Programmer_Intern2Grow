#include <stdio.h>
#include <ctype.h>

int countWords(const char* text) {
    int count = 0;
    int isWord = 0;
    while (*text) {
        if (isalpha(*text)) {
            if (!isWord) {
                count++;
                isWord = 1;
            }
        } else {
            isWord = 0;
        }
        text++;
    }
    return count;
}

int countSentences(const char* text) {
    int count = 0;
    while (*text) {
        if (*text == '.' || *text == '?' || *text == '!') {
            count++;
        }
        text++;
    }
    return count;
}

int main() {
    char filename[100];
    printf("Words Counter\n");
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char* content = (char*)malloc(sizeof(char) * (fileSize + 1));
    if (!content) {
        printf("Memory allocation error\n");
        fclose(file);
        return 1;
    }

    fread(content, sizeof(char), fileSize, file);
    content[fileSize] = '\0';

    fclose(file);

    int numChars = fileSize;
    int numWords = countWords(content);
    int numSentences = countSentences(content);

    printf("Number of characters: %d\n", numChars);
    printf("Number of words: %d\n", numWords);
    printf("Number of sentences: %d\n", numSentences);

    free(content);

    return 0;
}
