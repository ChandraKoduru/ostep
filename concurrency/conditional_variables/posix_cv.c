//http://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf
//page 3
#include <stdio.h>
#include <pthread.h>

int done = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

void thr_exit() {
    pthread_mutex_lock(&m);
    printf("\n thr_exit");
    done = 1;
    pthread_cond_signal(&c);
    printf("\n thr_exit exit");
    pthread_mutex_unlock(&m);
}

void *child(void *arg) {
    printf("\nchild");
    thr_exit();
    return NULL;
}

void thr_join() {
    pthread_mutex_lock(&m);
    while (done == 0) {
        printf("\nwaiting cond");
        pthread_cond_wait(&c, &m);
    }
    pthread_mutex_unlock(&m);
}

int main(int argc, char *argv[]) {
    printf("\nparent: begin\n");
    pthread_t p;
    pthread_create(&p, NULL, child, NULL);
    thr_join();
    printf("\nparent: end");
    return 0;
}


