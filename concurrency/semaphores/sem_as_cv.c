/*http://pages.cs.wisc.edu/~remzi/OSTEP/threads-sema.pdf*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;

void *child(void *arg) {
    printf("\nchild");
    sem_post(&s);
    return NULL;
}

int main(int argc, char *argv[]) {
    sem_init(&s, 0, 0);
    pthread_t p;
    printf("\nparent: begin");
    pthread_create(&p, NULL, child, NULL);
    sem_wait(&s);
    printf("\nparent: end");
    return 0;
}
