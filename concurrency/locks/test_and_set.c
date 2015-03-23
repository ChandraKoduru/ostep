//http://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks.pdf
// c-implementation of test_set_atomic_exchange machine instruction
#include <lock.h>
int TestAndSet(int *old_ptr, int new) {
    int old = *old_ptr; //fetch old value at old_ptr
    *old_ptr = new; //store 'new' into old_ptr
    return old;
}

void lock(lock_t *lock) {
    while(TestAndSet(&lock->flag, 1) == 1)
        ; //spin-wait
}

void unlock(lock_t *lock) {
    lock->flag = 0;
}
