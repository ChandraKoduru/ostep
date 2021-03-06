/*http://pages.cs.wisc.edu/~remzi/OSTEP/threads-sema.pdf*/
/*page 11*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct _rwlock_t {
    sem_t lock; //binary semaphore baisc lock
    sem_t writelock; //used to allow one writer or many readers
    int readers;
} rwlock_t;

void rwlock_init(rwlock_t *rw) {
    rw->readers = 0;
    sem_init(&rw->lock, 0, 1);
    sem_init(&rw->writelock, 0, 1);
}

void rwlock_acquire_readlock(rwlock_t *rw) {
    sem_wait(&rw->lock);
    rw->readers++;
    if (rw->readers == 1) {
        sem_wait(&rw->writelock); //first reader acquires writelock
    }
    sem_post(&rw->lock);
}

void rwlock_release_readlock(rwlock_t *rw) {
    sem_wait(&rw->lock);
    rw->readers--;
    if (rw->readers == 0) {
        sem_post(&rw->writelock); //last reader releases writelock
    }
    sem_post(&rw->lock);
}

void rwlock_acquire_writelock(rwlock_t *rw) {
    sem_wait(&rw->writelock);
}

void rwlock_release_writelock(rwlock_t *rw) {
    sem_post(&rw->writelock);
}

int main (int argc, char *argv[]) {
    rwlock_t rw;
    rwlock_init(&rw);
}
