#include<tmp.h>

int main(int argc, char *argv[])
{
    extern char **environ;
    printf("--------main function running!--------\n");
    printf("%s\n", getenv("PATH"));
    for(int i = 0; environ[i] != NULL; i++)
        printf("env[%d] : %s\n", i, environ[i]);

    return 0;
}