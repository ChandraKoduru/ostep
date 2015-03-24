/*http://pages.cs.wisc.edu/~remzi/OSTEP/threads-events.pdf*/

#include <stdio.h>
#include <signal.h>

void handle(int arg) {
    printf("stop wakin' me up ..\n");
}
int main(int argc, char *argv[]) {
    signal(SIGHUP, handle);
    while (1) {
        ; //doing nothing except catching some signals
    }
    return 0;
}

