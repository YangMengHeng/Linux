#include<tmp.h>

int main()
{
    char *args = "Hello";
    char *args2 = "World!";
    char *args3 = "good morning!";
    if(execle("./1", args, args2, args3, NULL) == -1)
    {
        perror("execle!\n");
        exit(EXIT_FAILURE);
    }
    puts("after calling!\n");

    return 0;
}