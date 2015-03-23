/*http://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf*/
/*page 9*/

#include <stdio.h>
#include <pthread.h>

pthread_cond_t empty, fill;
pthread_mutex_t mutex;
int count = 0;
int loops = 10;

void *producer(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 1) {
            pthread_cond_wait(&empty, &mutex);
        }
        put(i);
        pthread_cond_signla(&fill);
        pthread_mutex_unlock(&mutex);
    }
}

void *consumer(void *arg) {
    int i;
    int tmp;
    for (i = 0; i < loops; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            pthread_cond_wait(&fill, &mutex);
        }
        tmp = get();
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        printf("\n%d", tmp);
    }
}
