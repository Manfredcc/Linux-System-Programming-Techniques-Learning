#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (2 != argc) {
        fprintf(stderr, "UsageL %s [path]\n", argv[0]);
        return 1;
    }

    if (-1 == unlink(argv[1])) {
        perror("Can't remove file");
        return errno;
    }

    return 0;
}
