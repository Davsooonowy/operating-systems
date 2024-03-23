#include <stdio.h>

#ifdef BYTE_MODE
void reverse(FILE* inputFile, FILE* outputFile){
    fseek(inputFile, -1, SEEK_END);
    long remainingBytes = ftell(inputFile) + 1;

    while(remainingBytes > 0){
        fprintf(outputFile, "%c", getc(inputFile)); // getc bierze nastepny znak, stąd -1 w fseek i przesuwanie o -2
        remainingBytes--;
        fseek(inputFile, -2, SEEK_CUR);
    }
}
#else
#define CHUNK_SIZE 1024
void reverse(FILE* inputFile, FILE* outputFile){
    fseek(inputFile, 0, SEEK_END);
    long remainingBytes = ftell(inputFile);

    char chunk[CHUNK_SIZE];

    while(remainingBytes > 0){
        long bytesToRead = remainingBytes > CHUNK_SIZE ? CHUNK_SIZE : remainingBytes;
        fseek(inputFile, -bytesToRead, SEEK_CUR);

        size_t bytesRead = fread(chunk, sizeof(char), bytesToRead, inputFile); // size_t to typ zwracany przez funkcje fread, zwraca ilosc przeczytanych bajtow

        char temp;
        for(int i = 0; i < bytesRead/2; i++){
            temp = chunk[i];
            chunk[i] = chunk[bytesRead - 1 - i];
            chunk[bytesRead - 1 - i] = temp;
        }

        fwrite(chunk, sizeof(char), bytesRead, outputFile);
        fseek(inputFile, -CHUNK_SIZE, SEEK_CUR);

        remainingBytes -= bytesRead;
    }
}
#endif

int main(int argCount, char** argValues) {
    if (argCount != 3) {
        printf("Failed to read 3 arguments\n");
        return -1;
    }

    FILE* inputFile = fopen(argValues[1], "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open file '%s'\n", argValues[1]);
        return -1;
    }

    FILE* outputFile = fopen(argValues[2], "w");
    if (outputFile == NULL) {
        printf("Error: Cannot open file '%s'\n", argValues[2]);
        return -1;
    }

    reverse(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);
}