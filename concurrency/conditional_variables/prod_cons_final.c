/*http://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf*/
/*page 12*/

#include <stdio.h>
#include <pthread.h>

#define MAX 100
#define LOOPS 1000

int buffer[MAX];
int fill = 0;
int use = 0;
int count = 0;

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
    count ++;
}

int get () {
    int tmp = buffer[use];
    use = (use + 1) % MAX;
    count--;
    return tmp;
}

pthread_cond_t empty, full;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg) {
    int i;
    for (i = 0; i < LOOPS; i++) {
        pthread_mutex_lock(&mutex);
        while(count == MAX) {
            pthread_cond_wait(&empty, &mutex);
        }
        put(i);
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *consumer(void *arg) {
    int i;
    int tmp;
    for (i = 0; i < LOOPS; i++) {
        while (count == 0) {
            pthread_cond_wait(&full, &mutex);
        }
        tmp = get();
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        printf("\n%d", tmp);
    }
    return NULL;
}

int main () {
    pthread_t producer_t, consumer_t;
    printf("\nmain begin");
    pthread_create(&producer_t, NULL, producer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);
    pthread_join(producer_t, NULL);
    pthread_join(consumer_t, NULL);
    printf("\nmain end");
}
