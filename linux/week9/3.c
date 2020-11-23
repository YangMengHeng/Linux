#include<tmp.h>

int main()
{
    char *args[] = {"./1", "hello", "world", NULL};
    printf("3.c : pid = %d, ppid = %d\n", getpid(), getppid());
    if(execve("./1", args, NULL) == -1)
    {
        perror("execve failed!\n");
        exit(1);
    }
    printf("after calling!\n");

    return 0;
}