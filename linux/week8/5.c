#include "t.h"
#include<tmp.h>

char *env_init[] = {"USER=stu", "PATH=/tmp", NULL};

int main()
{
    char *args = "Hello World!\n";
    if(execle("./test", args, NULL, env_init/*NULL*/) == -1)
    {
        perror("execle!\n");
        exit(EXIT_FAILURE);
    }
    puts("Never get there!\n");

    exit(EXIT_SUCCESS);
}