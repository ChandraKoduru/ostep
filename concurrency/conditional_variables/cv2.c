#include <stdio.h>
#include <pthread.h>

volatile int done = 0;

void *child(void *arg) {
    printf("\nchild");
    done = 1;
    return NULL;
}

int main(int argc, char *argv[]) {
    printf("\nparent: begin");
    pthread_t c;
    pthread_create(&c, NULL, child, NULL); //create child
    while(done == 0) {
        printf("\nspinning...");
    }
    printf("\n");

    printf("\nparent: end");
    return 0;
}
