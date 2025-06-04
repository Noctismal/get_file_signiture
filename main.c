/* Moduals */ 
#include "gfs_file_info.h"

/* Dependencies */
#include <stdio.h>
#include <stdlib.h>

/* Macros */ 
#define MIN_ARGC 2

int main(int argc, char *argv[]) {
    // Make sure minimum amount of arguments were given
    if (argc < MIN_ARGC) {
        fprintf(stderr, "Error: Not enough arguments.\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        FileInfo file = get_file_info(argv[i]);
        
        if (file == NULL) {
            fprintf(stderr, "File: %s is not a file or could not be opened.\n", argv[i]);
            continue;
        }

        printf("File name: \t%s\nFile Signiture: ", argv[i]);
        print_sig(file);
        
    }
    return 0;
}

