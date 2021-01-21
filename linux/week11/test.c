#include<tmp.h>

int main(int argc, char **argv[])
{
    int i, fd;

    printf("test : pid = %d, ppid = %d\n", getpid(), getppid());)
    printf("test programe has been received %d args.\n", argc);
    for(int i = 0; i < argc; i++)
        printf("argv[%d] : %s\n", i, argv[i]);

    return argc;
}