#include"t.h"

int main(void)
{
    long int li = 857349200661370;
    int i = 0;
    long tli = 0;

    printf("%d %d\n", sizeof(int), sizeof(long long int));
    printf("max int value: %d\n", (unsigned int)~i >> 1);
    printf("min int value: %d\n", ++i << (sizeof(int) * 8 - 1));
    printf("max long int value: %ld\n", (unsigned long int)~tli >> 1);
    printf("min long int value: %ld\n", ++tli << (sizeof(long int) * 8 - 1));
    printf("%i %li\n", li, li);
    printf("%d %ld\n", li, li);

    return 0;
}