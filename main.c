/* Dependencies */
#include <stdio.h>
#include <stdlib.h>

/* Macros */ 
#define MIN_ARGC 2

struct file_info {
    char *f_name;
    unsigned char *sig;
};

/* Prototypes */ 
void *allocate(size_t size);
struct file_info *get_file_info(char *file);
unsigned char *get_sig(char *file);

int main(int argc, char *argv[]) {
    // Make sure minimum amount of arguments were given
    if (argc < MIN_ARGC) {
        fprintf(stderr, "Error: Not enough arguments.\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        struct file_info *file = get_file_info(argv[i]);
        
        if (file == NULL) {
            fprintf(stderr, "File: %s is not a file or could not be opened.\n", file->f_name);
            continue;
        }

        printf("File name: %s\nFile Signiture: ", file->f_name);
        
        for (int s = 0; s < 7; s++) {
         printf("%02X ", file->sig[s]);
        }
        printf("\n");
    }
    return 0;
}
 
void *allocate(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Error malloc failled\n");
        exit(1);
    }

    return ptr;
}

struct file_info *get_file_info(char *file) {
    struct file_info *f1 = allocate(sizeof(struct file_info));

    f1->f_name = file;

    f1->sig = get_sig(file);
    
    return f1;
}

unsigned char *get_sig(char *file) {
    FILE *f = fopen(file, "rb");

    unsigned char *buff = allocate(sizeof(unsigned char) * 8);

    if (f == NULL) {
        fprintf(stderr, "Error opening file: %s\n", file);
        return NULL;
    }

    fread(buff, 8, 1, f);

    return buff;
}

