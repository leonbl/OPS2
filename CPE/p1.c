#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    printf("PID tega programa: %d\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork ni uspel; izhod
        fprintf(stderr, "fork ni uspel\n");
        exit(1);
    } else if (rc == 0) {
        // otrok (nov proces)
        printf("Zivijo, sem otrok s PID: %d\n", (int) getpid());
    } else {
        // starš nadaljuje izvajanje prvotnega procesa
        printf("Jaz sem stars otroka s PID: %d. Moj PID je: %d\n",
	       rc, (int) getpid());
    }
    return 0;
}
