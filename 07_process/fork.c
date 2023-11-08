#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;

    printf("PID:%d\n", getpid());
    if (-1 == (pid = fork())) {
        perror("Can't fork");
        return 1;
    }

    if (0 == pid) {
       if (-1 == (execl("/usr/bin/man", "man", "ls", (char *)NULL))) {
            perror("Can't exec");
       }
       return 1;
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
        printf("Child executed with PID:%d\n", pid);
        printf("Its return status was %d\n", status);
    } else {
        fprintf(stderr, "Sth went wrong\n");
        return 1;
    }

    return 0;
}