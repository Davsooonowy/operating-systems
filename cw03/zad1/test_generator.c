#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    if(argc < 3){
        printf("There are less then 3 arguments\n");
        return -1;
    }

    FILE* file = fopen(argv[2], "w");
    if(file == NULL){
        printf("Failed to open file: %s!\n", argv[2]);
        return -1;
    }

    long char_count = atol(argv[1]);

    srand(time(NULL));
    char* buffer = malloc(char_count + 1);
    for(int i = 0; i < char_count; i++) {
        buffer[i] = rand()%('z' - 'a' + 1) + 'a';
    }
    buffer[char_count] = '\0'; // null-terminator at the end of the string

    fwrite(buffer, sizeof(char), char_count, file);

    free(buffer);
    fclose(file);
}