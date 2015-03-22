//http://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks.pdf

// c-implementation of test_set_atomic_exchange machine instruction
int TestAndSet(int *old_ptr, int new) {
    int old = *old_ptr; //fetch old value at old_ptr
    *old_ptr = new; //store 'new' into old_ptr
    return old;
}

typedef struct __lock_t {
    int flag;
} lock_t;

void init(lock_t *lock) {
    //0 - indicates that lock is available
    //1 - indicates lock not available
    lock->flag = 0; //initially available
}

void lock(lock_t *lock) {
    while(TestAndSet(&lock->flag, 1) == 1)
        ; //spin-wait
}

void unlock(lock_t *lock) {
    lock->flag = 0;
}
