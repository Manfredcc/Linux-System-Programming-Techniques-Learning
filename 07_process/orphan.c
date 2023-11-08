#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;
    printf("PID:%d\n", getpid());

    if (-1 == (pid = fork())) {
        perror("Can't fork\n");
        return 1;
    }

    if (0 == pid) { /* child flow */
        printf("I am the child and will run for 5 minutes\n");
        sleep(300);
        exit(0);
    } else if (pid > 0) { /* parent flow */
        printf("My child has PID %d\n"
            "I, the parent, will exit when you "
            "press enter\n", pid);
        getchar();
        return 0;
    } else {
        fprintf(stderr, "sth went wrong\n");
        return 1;
    }

    return 0;
}