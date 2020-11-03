#include<tmp.h>

int main(int argc, char *argv[], char *env[])
{
    printf("--------main function running!--------\n");
    int i;
    for(i = 0; i < argc; i++)
        printf("atgv[%d] : %s\n", i, argv[i]);
    for(i = 0; i < argc; i++)
        printf("env[%d] : %s\n", i, env[i]);

    return 0;
}