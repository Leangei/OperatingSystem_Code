#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>      // fork(), execvp()
#include <sys/types.h>
#include <sys/wait.h>    // wait()

int main() {
    pid_t pid;

    printf("Parent Process ID: %d\n", getpid());

    pid = fork();    // Create child process

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // CHILD PROCESS
        printf("Child Process ID: %d\n", getpid());

        char *args[] = {"ls", "-l", NULL};  // run "ls -l"
        execvp("ls", args);

        // Only runs if exec failed
        perror("exec failed");
        exit(1);
    }
    else {
        // PARENT PROCESS
        wait(NULL);   // wait for child to finish
        printf("Child finished.\n");
    }

    return 0;
}
