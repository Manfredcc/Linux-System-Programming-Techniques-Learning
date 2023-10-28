#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define _XOPEN_SOURCE   500

void pr_help(FILE *stream, char progname[]);

int main(int argc, char *argv[])
{
    char mph[10] = {0};
    int opt;
    int cont = 0;

    while (-1 != (opt = getopt(argc, argv, "ch"))) {
        switch (opt) {
        case 'h':
            pr_help(stdout, argv[0]);
            return 0;
        case 'c':
            cont = 1;
            break;
        default:
            pr_help(stderr, argv[0]);
            return 1;
        }
    }

    while (fgets(mph, sizeof(mph), stdin) != NULL) {
        if (strspn(mph, "0123456789.-\n") == strlen(mph)) {
            printf("%.1f\n", atof(mph) * 1.60934);
        } else {
            fprintf(stderr, "Found non-numeric value\n");
            if (1 == cont) {
                continue;
            } else {
                return 1;
            }
        }
    }

    return 0;
}

void pr_help(FILE *stream, char progname[])
{
    fprintf(stream, "%s [-c] [-h]\n", progname);
    fprintf(stream, " -c continues even though a non "
        "-numeric value was detected in the input\n"
        "-h print help\n");
}