#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

void pr_use(FILE *stream, char progname[]);

int main(int argc, char *argv[])
{
    long int access_mode;
    if (3 != argc) {
        pr_use(stderr, argv[0]);
        return 1;
    }

    if (strspn(argv[1], "0123456789\n") != strlen(argv[1]) 
        || (3 != strlen(argv[1]) && 4 != strlen(argv[1]))) {
            pr_use(stderr, argv[0]);
            return 1;
        }
    
    access_mode = strtol(argv[1], NULL, 8);
    if (-1 == chmod(argv[2], access_mode)) {
        perror("Can't change permissions");
    }
    return 0;
}

void pr_use(FILE *stream, char progname[])
{
    fprintf(stream, "Usage: %s <numberical permissions> <path>\n", progname);
}