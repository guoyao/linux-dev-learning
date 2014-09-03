#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main(int argc, char* argv[]) {
    int pid;
    pid = fork();
    if (!pid) {
        char* arguments[] = {"cmd.out", "go", "version", NULL};
        execv("cmd.out", arguments);
        exit(0);
    } else if (pid > 0) {
        wait(NULL);
        printf("I’m the caller, child has pid %d\n", pid);
        exit(0);
    } else {
        printf("Fork fail!\n");
        exit(1);
    }
}
