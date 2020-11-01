#include "tmp.h"

int main(void)
{
    printf("Hello setBuf!\n");
    for(int i  = 0; i < 1024; i++)
        printf("ab");
    while(1);
    
    return 0;
}