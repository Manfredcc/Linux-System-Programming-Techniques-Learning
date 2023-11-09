#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    printf("My PID is %d\n", getpid());
    if (-1 == (pid = fork())) {
        perror("Can't fork");
        return 1;
    }
    
    if (0 == pid) {
        printf("Hello from the child process!\n");
        for (int i = 0; i < 10; i++) {
            printf("Counter in child: %d\n", i);
        }
    } else if (pid > 0) {
        printf("My child has PID %d\n", pid);
        wait(&pid);
    }

    return 0;
}