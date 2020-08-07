#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAGIC_HEADER        (0xDEAD)
#define SECRET_XOR_VALUE    (0xAE)

int main(int argc, char* argv[]) {
    FILE* fp = fopen("secret_file.txt", "r");
    if(fp == NULL) {
        printf("file is null\n");
        return 1;
    }

    unsigned int ext_f1 = 0;
    unsigned long long ext_f2 = 0;

    int index = 0, offset = 0, fragment = 0;
    do {
        // Initialize byte offset
        offset = -1;

        // Pack current byte into payload
        char byte = fgetc(fp);
        if (!feof(fp)) {
            offset = (index % 8);
            ext_f2 |= ((byte << (offset * 8)) ^ SECRET_XOR_VALUE);
        }

        // Send packet
        if(index != 0 && offset <= 0) {
            // set ext_f1
            ext_f1 = (MAGIC_HEADER << 16) | (fragment << 8) | (index % 9);
            printf("ext_f1= %x\next_f2 = %x\n", ext_f1, ext_f2);

            // update values
            ext_f1 = ext_f2 = 0; 
            fragment += 1;
        }

        // output current char
        printf("[%c]\n", byte);
        index++;
    } while(offset != -1);

    fclose(fp);
    return 0;
}
