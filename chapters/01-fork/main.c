#define _POSIX_C_SOURCE 200809L
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    int value = 7;
    /* fork öncesi stdio tamponunu boşalt: aynı çıktı iki kez yazılmasın. */
    if (fflush(NULL) == EOF) return 1;
    pid_t child = fork();
    if (child == -1) { perror("fork"); return 1; }
    if (child == 0) {
        value = 42;
        int rc = printf("child value=%d pid=%ld parent=%ld\n",
                        value, (long)getpid(), (long)getppid());
        _exit(rc < 0 || fflush(stdout) == EOF ? 1 : 0);
    }
    int status;
    while (waitpid(child, &status, 0) == -1) {
        if (errno != EINTR) { perror("waitpid"); return 1; }
    }
    if (!WIFEXITED(status)) return 1;
    printf("parent value=%d child_exit=%d\n", value, WEXITSTATUS(status));
    return WEXITSTATUS(status);
}
