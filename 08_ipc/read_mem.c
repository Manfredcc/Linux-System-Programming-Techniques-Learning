#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define DATASIZE    128

int main(void)
{
    int fd;
    float *addr;
    const char memid[] = "/my_memory";
    float numbers[3];

    fd = shm_open(memid, O_RDONLY, 0600);
    if (-1 == fd) {
        perror("Can't open mem fd");
        return 1;
    }

    addr = mmap(NULL, DATASIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("Memory mapping failed");
        return 1;
    }
    memcpy(numbers, addr, sizeof(numbers));
    for (int i =0; i < 3; i++) {
        printf("Number %d: %.3f\n", i, numbers[i]);
    }

    return 0;
}