#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int fd;

    if (3 != argc) {
        fprintf(stderr, "Usagr: %s [path] [string]\n", argv[0]);
        return 1;
    }

    if (-1 == (fd = open(argv[1], O_CREAT | O_RDWR, 00644))) {
        perror("Can't open file for writing\n");
        return 1;
    }

    if (-1 == (write(fd, argv[2], strlen(argv[2])))) {
        perror("Can't write to file\n");
        return 1;
    }

    close(fd);

    return 0;
}