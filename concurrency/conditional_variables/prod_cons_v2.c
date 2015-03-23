/*http://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf*/
/*page 11*/
#include <stdio.h>
#include <pthread.h>

pthread_cond_t cond;
pthread_mutex_t mutex;
int count = 0;

void *producer(void *arg) {
    int i;
    int loops = 10;
    for (i = 0; i < loops; i++) {
        pthread_mutex_lock(&mutex);
        if (count == 1) {
            pthread_cond_wait(&cond, &mutex);
        }
        put(i);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

void *consumer(void *arg) {
    int i;
    int tmp;
    int loops = 10;
    for (i = 0; i < loops; i++) {
        pthread_mutex_lock(&mutex);
        if (count == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        tmp = get();
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        printf("\n%d", tmp);
    }
}

