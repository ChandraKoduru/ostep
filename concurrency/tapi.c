//http://pages.cs.wisc.edu/~remzi/OSTEP/threads-api.pdf

#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#include <stdlib.h>

typedef struct __myarg_t {
    int a;
    int b;
} myarg_t;

typedef struct __myret_t {
    int x;
    int y;
} myret_t;

void *mythread (void *arg) {
    myarg_t *m = (myarg_t *)arg;
    printf("%d %d\n", m->a, m->b);
    myret_t *r = malloc(sizeof(myret_t));
    r->x = 2 * m->a;
    r->y = 3 * m->b;
    return (void *)r;
}

int main(int argc, char *argv) {
    int rc;
    pthread_t p;
    myret_t *m;

    printf("\nTAPI -------------------\n");
    myarg_t args;
    args.a = 10;
    args.b = 20;
    pthread_create(&p, NULL, mythread, &args);
    pthread_join(p, (void **)&m);
    printf("returned %d %d\n", m->x, m->y);
    return 0;
}