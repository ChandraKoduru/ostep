//http://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks.pdf
//page 13

int FetchAndAdd(int *ptr) {
    int old = *ptr;
    *ptr = old + 1;
    return old;
}

typedef struct __lock_t {
    int ticket;
    int turn;
} lock_t;

void lock_init(lock_t *lock) {
    lock->ticket = 0;
    lock->turn = 0;
}

void lock(lock_t *lock) {
    int myturn = FetchAndAdd(&lock->ticket);
    while(lock->turn != myturn) {
        //spin till someone else releases and it is his turn
    }
}

void unlock(lock_t *lock) {
    FetchAndAdd(&lock->turn);
}

