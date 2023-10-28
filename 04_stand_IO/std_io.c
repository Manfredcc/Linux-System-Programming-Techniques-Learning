#include <stdio.h>

/*===========================================================
                    STANDARD I/O
Description:
    Interact with standard I/O

In this case, fprintf is the same as dprintf. Parameter 
is the only difference.

More info:
|Name           |Identifier | File stream | File descriptor |
|Standard input |     0     |     stdin   |  STDIN_FILENO   |
|Standard output|     1     |     stdout  |  STDOUT_FILENO  |
|Standard error |     2     |     stderr  |  STDERR_FILENO  |

=============================================================*/

int main(int argc, const char *argv[])
{
    printf("It's me\n");

    fprintf(stdout, "%s std output \n", __func__);

    fprintf(stderr, "%s err output \n", __func__);

    dprintf(1, "%s std output\n", __func__);

    dprintf(2, "%s err output\n", __func__);
}
