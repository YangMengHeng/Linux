#include "t.h"
#include<tmp.h>

int main(int argc, char *argv[])
{
    int i;
    extern char **environ;
    char **env = environ;

    for(i = 0; i < argc; i++)
        printf("%s", argv[i]);
    while(*env)
    {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}