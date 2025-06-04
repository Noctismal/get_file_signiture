/* Implimentation of gfs_file_info.h */ 
#include "gfs_file_info.h"

/* Dependencies */ 
#include <stdio.h>
#include <stdlib.h>

/* Data structures */ 
struct file_info {
    char *file_name;
    unsigned char signiture[SIG_SIZE];
};


/* Prototypes */ 
void *allocate(size_t size);

/* Public functions */ 
FileInfo get_file_info(char *file_name) {
    // where all the file info will be stored
    struct file_info *file = allocate(sizeof(struct file_info));

    // holds a pointer to the open file in read binary mode
    FILE *fptr = fopen(file_name, "rb");

    // if fptr is NULL the file couldnt be opend or isnt a file
    if (fptr == NULL) {
        fprintf(stderr, "File: - %s - couldnt be opend", file_name);
        return NULL;
    }

    // file name is supplied to function
    file->file_name = file_name;

    // read the signiture 
    fread(file->signiture, SIG_SIZE, 1, fptr);

    return file;
}

void print_sig(FileInfo file) {
    for (int ch = 0; ch < SIG_SIZE; ch++) {
         printf("%02X ", file->signiture[ch]);
    }
    putchar('\n');

    return;
}

/* Private functions */ 
void *allocate(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Malloc failed to allocate space.\nExiting");
        exit(1);
    }

    return ptr;
}
