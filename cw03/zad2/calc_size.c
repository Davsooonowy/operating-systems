#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char** argv) {
    if(argc < 2) {
        printf("Wrong number of arguments!\n");
        return -1;
    }

    DIR *dir;
    struct dirent *entry;
    struct stat file_status;
    long long total_size = 0;
    char path[1024];

    dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error: Cannot open directory '%s'\n", argv[1]);
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) { // iteracja po wszystkich elementach w katalogu
            snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name); // tworzenie sciezki do pliku, snprintf zabezpiecza przed buffer overflow
            if(stat(path, &file_status) == 0 && !S_ISDIR(file_status.st_mode)) { // sprawdzenie czy plik istnieje i czy nie jest katalogiem
                printf("%8ld %s\n",file_status.st_size, path); // wypisanie rozmiaru pliku i sciezki
                total_size += file_status.st_size;

        }
    }
    closedir(dir);

    printf("%llu total\n", total_size);

    return 0;
}