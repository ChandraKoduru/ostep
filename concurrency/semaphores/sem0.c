/*http://pages.cs.wisc.edu/~remzi/OSTEP/threads-sema.pdf*/
/*page 2*/

#include <stdio.h>
#include <semaphore.h>

sem_t s;

int main(int argc, char *argv[]) {
    sem_init(&s, 0, 1);
    return 0;
}

int sem_wait(sem_t *s) {
    /*
     * decrement the value of semaphore s by one
     * wait if the value of the semaphore s is negative
     */
}

int sem_post(sem_t *s) {
    /*
     * increment the value of semaphores s by one
     * if there are one or more threads waiting, wake one
     */
}

void binary_semaphore_in_action() {
    sem_t m; //should be at a place that is accessible by all threads.
    sem_init(&m, 0, 1); //1 -> number of concurrent threads within a critical section

    sem_wait(&m);
    //critical section here
    sem_post(&m);
}
