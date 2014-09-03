#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main(int argc, char* argv[]) {
    int pid;
    printf("Now only one process\n");
    printf("Calling fork… \n");
    pid = fork();
    if (!pid) {
        char* arguments[argc - 1];
        int i = 0;
        while(++i < argc) {
            arguments[i - 1] = argv[i]; 
        }
        arguments[argc - 1] = NULL;
        execvp(argv[1], arguments);
        exit(0);
    } else if (pid > 0) {
        wait(NULL);
        printf("I’m the parent, child has pid %d\n", pid);
        exit(0);
    } else {
        printf("Fork fail!\n");
        exit(1);
    }
}
