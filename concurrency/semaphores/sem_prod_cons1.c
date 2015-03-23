/*http://pages.cs.wisc.edu/~remzi/OSTEP/threads-sema.pdf*/
/*page 7*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define LOOPS 1000
#define MAX 100

int buffer[MAX];
int fill = 0;
int use = 0;

void put(int value) {
    buffer[fill] = value;
    fill = (fill + 1) % MAX;
}

int get() {
    int tmp = buffer[use];
    use = (use + 1) % MAX;
    return tmp;
}

sem_t empty; //number of empty buffers;
sem_t full; //buffer is not empty
sem_t mutex;

void *producer(void *arg) {
    int i;
    for (i = 0; i < LOOPS; i++) {
        printf("\nproducer..");
        sem_wait(&empty);
        sem_wait(&mutex);
        put(i);
        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void *consumer(void *arg) {
    int i, tmp = 0;
    for (i = 0; i < LOOPS; i++) {
        printf("\nconsumer..");
        sem_wait(&full);
        sem_wait(&mutex);
        tmp = get();
        sem_post(&mutex);
        sem_post(&empty);
        printf("\n%d", tmp);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t pt, ct;
    sem_init(&empty, 0, MAX); // MAX buffers are empty to begin with
    sem_init(&full, 0, 0); //and 0 are full
    sem_init(&mutex, 0, 1);
    pthread_create(&pt, NULL, producer, NULL);
    pthread_create(&ct, NULL, consumer, NULL);
    pthread_join(pt, NULL);
    pthread_join(ct, NULL);
}
