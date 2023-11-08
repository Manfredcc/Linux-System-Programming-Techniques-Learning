#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAXSIZE 4096

int main(int argc, char *argv[])
{
    int fd;
    int max_read;
    off_t file_size;
    struct stat file_info;
    char r_buf[MAXSIZE] = {0};

    if (2 != argc) {
        fprintf(stderr, "Usagr: %s [path]\n", argv[0]);
        return 1;
    }

    if (-1 == (fd = open(argv[1], O_CREAT | O_RDWR, 00644))) {
        perror("Can't open file for reading\n");
        return 1;
    }

    fstat(fd, &file_info);
    file_size = file_info.st_size;

    if (file_size >= MAXSIZE)
        max_read = MAXSIZE - 1;
    else
        max_read = file_size;
    
    if (-1 == read(fd, r_buf, max_read)) {
        perror("Can't read file\n");
        return 1;
    }

    printf("%s", r_buf);
    return 0;
}