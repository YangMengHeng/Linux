#include<tmp.h>

int main(int argc, char **argv[])
{
    printf("1.c : pid = %d, ppid = %d\n", getpid(), getppid());
    for(int i = 0; i < argc; i++)
        printf("argv[%d] : %s\n", i, argv[i]);

    return argc;
}