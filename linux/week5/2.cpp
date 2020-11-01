#include "tmp.h"

int main(void)
{
    char buf[1024];
    setvbuf(stdout, buf, _IOLBF,  20);
    for(int i = 1; i <= 10; i++)
        printf("%d ", i);
    sleep(2);
    printf("11");

    return 0;
}