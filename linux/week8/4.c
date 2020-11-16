#include "t.h"
#include<tmp.h>

char *env_init[] = {"USER=stu", "PATH=/tmp", NULL};

int main()
{
    char *args[] = {"Hello", " World!\n", NULL};
    if(execve("./test", args, env_init) == -1)
    {
        perror("execve!\n");
        exit(EXIT_FAILURE);
    }
    puts("Never get there!\n");

    exit(EXIT_SUCCESS);
}