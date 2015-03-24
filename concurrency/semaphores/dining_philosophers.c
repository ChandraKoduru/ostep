/*http://pages.cs.wisc.edu/~remzi/OSTEP/threads-sema.pdf*/
/*page 13*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define PHILS 5

sem_t forks[PHILS];

void think(int name) {
    printf("\nthinking - %d", name);
}

void eat(int name) {
    printf("\neating   - %d", name);
}

int left(int p) {
    return p;
}

int right(int p) {
    return (p+1) % PHILS;
}

void getforks(int p) {
    if (p == (PHILS -1 )) {
        sem_wait(&forks[right(p)]);
        sem_wait(&forks[left(p)]);
    } else {
        sem_wait(&forks[left(p)]);
        sem_wait(&forks[right(p)]);
    }
}

void putforks(int p) {
    sem_post(&forks[left(p)]);
    sem_post(&forks[right(p)]);
}

void *philosopher(void *arg) {
    int name = *(int *)arg;
    while(1) {
        think(name);
        getforks(name);
        eat(name);
        putforks(name);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int i;
    pthread_t philosophers[PHILS];
    int philNames[PHILS];

    for(i = 0; i < PHILS; i++) {
        sem_init(&forks[i], 0, 1);
        philNames[i] = i;
    }

    for(i = 0; i < PHILS; i++) {
        pthread_create(&philosophers[i], NULL, philosopher, &philNames[i]);
    }
    for(i = 0; i < PHILS; i++) {
        pthread_join(philosophers[i], NULL);
    }
    return 0;
}
