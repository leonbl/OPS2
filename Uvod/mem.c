#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[]) {
    if (argc != 2) { 
	fprintf(stderr, "uporaba: mem <value>\n"); 
	exit(1); 
    } 
    int *p; 
    p = malloc(sizeof(int));
    assert(p != NULL);
    printf("p (%d) kaze na naslov: %p\n", (int) getpid(), p);
    *p = atoi(argv[1]); // shranimo vrednost na naslov, na katerega kaže p
    while (1) {
	Spin(1);
	*p = *p + 1;
	printf("(%d) vrednost na naslovu p: %d\n", getpid(), *p);
    }
    return 0;
}

