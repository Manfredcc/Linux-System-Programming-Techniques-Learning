#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

int main(void)
{
    pid_t pid;
    FILE *fp;
    time_t now;
    const char pidfile[] = "/var/run/my-daemon.pid";
    const char daemonfile[] = "/tmp/my-daemon-is-alive.txt";

    if (-1 == (pid = fork())) {
        perror("Can't fork\n");
        return 1;
    } else if (0 != pid) {
        exit(0);
    }
    setsid();

    if (-1 == (pid = fork())) {
        perror("Can't fork\n");
        return 1;
    } else if (pid > 0) {
        if ((fp = fopen(pidfile, "w")) == NULL) {
            perror("Can't open file for writing\n");
            return 1;
        }
        fprintf(fp, "%d\n", pid);
        fclose(fp);
        exit(0);
    }

    umask(022);
    chdir("/");
    if ((fp = fopen(daemonfile, "w")) == NULL) {
        perror("Can't open daemonfile");
        return 1;
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    open("/dev/null", O_RDONLY);
    open("/dev/null", O_WRONLY);
    open("/dev/null", O_RDWR);

    for (;;) {
        time(&now);
        fprintf(fp, "Damon alive at %s", ctime(&now));
        fflush(fp);
        sleep(30);
    }

    return 0;
}