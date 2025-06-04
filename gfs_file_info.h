#ifndef GFS_FILE_INFO_H
#define GFS_FILE_INFO_H

/* Macros */

// program only reads first 8 bytes of the signiture 
#define SIG_SIZE 8

/* Data structures */
struct file_info;

/* Data types */
typedef struct file_info *FileInfo;

/* Public API */
FileInfo get_file_info(char *file_name);

void print_sig(FileInfo file);

#endif
