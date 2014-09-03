#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int run_command(char* command) {
    int pid = fork();
    switch(pid) {
    case -1: 
        return -1;
    case 0:
        execl("/bin/sh", "sh", "-c", command, NULL);
        exit(127);
    default:
        wait(NULL);
    }
    return 0;
}

main(int argc, char* argv[]) {
    run_command(argv[1]);
    exit(0);
}
