#include <stdio.h>
#include <stdlib.h>

/*======================================================================
                        EASY DEMO TO SAIL
Description:
    As a easy but strong c demo, it has input/input check/error check/
output that composes a basic program.

Key:
    atoi(const char* ) and its siblings
    - atoi()    Transfer string or char to integer
    - atol()    To long
    - atoll()   To long long
    - atof()    To float

======================================================================*/

#define EINVAL  -1

void pr_help(char progname[]);

int main(int argc, char *argv[])
{
    int cout;
    int sum = 0;

    /* sanity check */
    if (1 == argc) {
        pr_help(argv[0]);
        return EINVAL;
    }

    for (cout = 0; cout < argc; cout++) {
        sum += atoi(argv[cout]); /* As argv[0] is not a valid param
            (a string that represent an integer, such as 0,1,2,3,4...)
        , atoi() then will return 0 */
    }

    printf("Total sum:%d\n", sum);
    return 0;
}

void pr_help(char progname[])
{
    printf("%s inter ...\n", progname);
    printf("This program takes any number of "
        "integer value and sums them up\n");
}