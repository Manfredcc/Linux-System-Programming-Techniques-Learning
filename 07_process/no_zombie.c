#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;
    printf("PID:%d\n", getpid());

    if (-1 == (pid = fork())) {
        perror("Can't fork\n");
        return 1;
    }

    if (0 == pid) { /* child */
        printf("Hello from child\n");
        exit(0);
    } else if (pid > 0) { /* parent */
        printf("Hello from the parent process! "
            "My child had PID %d\n", pid);
        waitpid(pid, &status, 0); /* wait for child */
        sleep(20);
    } else {
        fprintf(stderr, "Something went wrong "
            "forking\n");
        return 1;
    }

    return 0;
}