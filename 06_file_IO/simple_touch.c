#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <utime.h>

#define MAX_LENGTH  100

int main(int argc, char *argv[])
{
    char filename[MAX_LENGTH] = {0};

    if (2 != argc) {
        fprintf(stderr, "You must supply a filename "
            "as an argument\n");
        return 1;
    }
    strncat(filename, argv[1], sizeof(filename - 1));

    if (-1 == utime(filename, NULL)) {
        if (errno == ENOENT) {
            if (-1 == creat(filename, 00644)) {
                perror("Can't create file\n");
                return errno;
            }
        } else {
            perror("Can't update timestamp\n");
            return errno;
        }
    }

    return 0;
}