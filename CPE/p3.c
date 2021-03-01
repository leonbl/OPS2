#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
        printf("Zivijo, sem otrok s PID: %d\n\n", (int)getpid());
        char *myargs[3];
        myargs[0] = strdup("wc");   // program: "wc" (word count)
        myargs[1] = strdup("p3.c"); // argument: datoteka za štetje znakov
        myargs[2] = NULL;           // konec tabele
        execvp(myargs[0], myargs);  // zažene program "wc"
        printf("to se ne bi smelo izpisat");
    } else {
        // starš nadaljuje izvajanje prvotnega procesa
        int wc = wait(NULL);
        printf("Jaz sem stars otroka s PID: %d (wc:%d). Moj PID je: %d\n",
               rc, wc, (int)getpid());
    }
    return 0;
}
