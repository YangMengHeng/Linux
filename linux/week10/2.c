#include<tmp.h>

int main(int argc, char **argv[])
{
    printf("2.c : pid = %d, ppid = %d\n", getpid(), getppid());
    for(int i = 0; i < argc; i++)
        printf("argv[%d] : %s\n", i, argv[i]);
    system("./1 hello world 2020-11-23");
    printf("after calling!\n");

    return 0;
}