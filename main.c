/* Dependencies */
#include <stdio.h>
#include <stdlib.h>

/* Globals */ 
#define MIN_ARGC 2

int main(int argc, char *argv[]) {
    // Make sure minimum amount of arguments were given
    if (argc < MIN_ARGC) {
        fprintf(stderr, "Error: Not enough arguments.\n");
        exit(1);
    }

    for (int i =0; i < argc; i++) {
         printf("%s\n", argv[i]);
    }
    return 0;
}
