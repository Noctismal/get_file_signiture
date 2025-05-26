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

    // Working with only one file atm TODO 
    struct file_info *f1 = get_file_info(argv[1]);

    printf("%s\n", f1->f_name);

    for (int i = 0; i < 7; i++) {
        printf("%02X ", f1->sig[i]);
    };

    return 0;
}

void *allocate(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Error malloc failled\n");
        exit(1);
    };

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
        exit(1);
    };

    fread(buff, 8, 1, f);

    return buff;
}

