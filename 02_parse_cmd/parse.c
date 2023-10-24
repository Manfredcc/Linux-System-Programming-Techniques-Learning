#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*======================================================================
                        PARSE CMD FOR ACTION
Description:
    This program is running into different flow depends on the cmd:
    -s:sums all the integers
    -m:multiply all the integers
    -h:get help information

Key:
    getopt(), parse command-line options, return -1 when encouter err

======================================================================*/

#define XOPEN_SOURCE    500
#define EINVAL  -1

void pr_help(char progname[]);

int main(int argc, char *argv[])
{
    int cout, opt, sum;
    
    /* sanity check */
    if (1 == argc) {
        pr_help(argv[0]);
        return EINVAL;
    }

    opt = getopt(argc, argv, "smh");
    while (-1 != opt) {
        switch (opt) {
        case 's': /* sum */
            sum = 0;
            for(cout = 2; cout < argc; cout++)
                sum += atoi(argv[cout]);
            break;
        case 'm': /* multiply */
            sum = 1;
            for (cout = 2; cout < argc; cout++)
                sum *= atoi(argv[cout]);
            break;
        case 'h': /* help */
            pr_help(argv[0]);
            return 0;
        default:
            pr_help(argv[0]);
            return 1;
        }

        printf("Result: %d", sum);
        return 0;
    }
}

void pr_help(char progname[])
{
    printf("%s [-s] [-m] integer ...\n", progname);
    printf("-s sums all the integers\n"
        "-m multiply all the integers\n"
        "This program taks any number of integer "
        "values and either add pr multiply them.\n"
        "For example: %s -m 2 0 0 3 1 6\n", progname);
}
