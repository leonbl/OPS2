#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    printf("PID tega programa: %d\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        // fork ni uspel; izhod
        fprintf(stderr, "fork ni uspel\n");
        exit(1);
    } else if (rc == 0) {
        // otrok (nov proces)
        printf("Zivijo, sem otrok s PID: %d\n", (int)getpid());
        sleep(1);
    } else {
        // starš nadaljuje izvajanje prvotnega procesa
        int wc = wait(NULL);
        printf("Jaz sem stars otroka s PID: %d (wc:%d). Moj PID je: %d\n",
               rc, wc, (int)getpid());
    }
    return 0;
}
