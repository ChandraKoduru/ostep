//http://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks.pdf
//page 11
#include <lock.h>

int LoadLinked(int *ptr) {
    return *ptr;
}

int StoreConditional(int *ptr, int value) {
    if (no-one-has-updated-*ptr-since-the-loadlinked-call-to-this-address) {
        *ptr = value;
        return 1; //success
    } else {
        return 0; //failed to update
    }
}

void lock(lock_t *lock) {
    while(1) {
        while(LoadLinked(&lock->flag) == 1)
            return; //spin until it's zero (i.e lock held)
        if (StoreConditional(&lock->flag, 1) == 1) {
            return; //if set-it-to-1 ..means..we are successful in updating the value
                    //before somebody could jumped in-between
                    //we can assume we got the lock
        else {
            //someone got the lock in the mean time..
            //hence try it all over again
        }
    }
}

void unlock(lock_t *lock) {
    lock->flag = 0;
}
