#include <lock.h>

int CompareAndSwap(int *ptr, int expected, int new) {
    int actual = *ptr;
    if (actual == expected) {
        *ptr = new;
    }
    return actual;
}

void lock(lock_t *lock) {
    while(CompareAndSwap(&lock->flag, 0, 1) == 1)
        ; //spin forever
}

void unlock(lock_t *lock) {
    lock->flag = 0;
}
