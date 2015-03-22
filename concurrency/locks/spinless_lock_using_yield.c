//http://pages.cs.wisc.edu/~remzi/OSTEP/threads-locks.pdf
// page 14

void init() {
    flag = 0;
}

void lock() {
    while(TestAndSet(&flag, 1) == 1) {
        yield(); //give up the CPU
        /* In this approach we assume an *OPERATING SYSTEM* primitive yield()
         * which a thread can call when it wants to give up the CPU and let
         * another thread run.*/
        /* This reduces the wastage of cpu-clock cycles that happens during
         * the spinning.*/
    }
}

void unlock() {
    flag = 0;
}
