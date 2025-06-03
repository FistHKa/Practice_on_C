#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BYTES_PER_LINE 16

void print_hex_and_ascii_line(size_t offset, const unsigned char *buffer, size_t count)
{
    printf("%08zx", offset);

    for (size_t i = 0; i < BYTES_PER_LINE; i++) {
        if (i < count)
            printf("%02x", buffer[i]);
        else
            printf(" ");
        
        if (i == 7)
            printf(" ");
    }

    printf(" |");

    for (size_t i = 0; i < count; i++) {
        if(isprint(buffer[i]))
            printf("%c", buffer[i]);
        else
            printf(".");
    }

    printf("\n");
}

int main(int argc, char **argv) 
{
    if (argc<2) {
        fprintf(stderr, "You need to enter a file name. Example: %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s", argv[1]);
        perror("fopen");
        return 2;
    }

    unsigned char buffer[BYTES_PER_LINE];
    size_t offset = 0;
    size_t bytes_read;

    while ((bytes_read=fread(buffer, 1, BYTES_PER_LINE, file)) > 0)
    {
        print_hex_and_ascii_line(offset, buffer, bytes_read);
        offset += bytes_read; /* code */
    }

    fclose(file);
    return 0;
}