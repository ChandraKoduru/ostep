/*http://pages.cs.wisc.edu/~remzi/OSTEP/threads-cv.pdf*/
/*page 6*/

#include <stdio.h>
#include <assert.h>

int buffer;
int count = 0; //intially, empty

void put(int value) {
    assert(count == 0);
    count = 1;
    buffer = value;
}

int get() {
    assert(count == 1);
    count = 0;
    return buffer;
}

void *producer(void *arg) {
    int i;
    int loops = (int) arg;
    for(i = 0;i < loops; i++) {
        put(i);
    }
}

void *consumer(void *arg) {
    int i;
    while(1) {
        int tmp = get();
        printf("%d\n", tmp);
    }
}


