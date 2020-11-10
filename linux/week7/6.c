#include<tmp.h>

int gInt = 1;

int main(void)
{
    pid_t ret;
    int localInt = 1;
    int *pt = (int*)malloc(sizeof(int));

    *pt = 1;
    ret = fork();
    if(ret == 0)
    {
        gInt = 111;
        localInt = 222;
        *pt = 333;
        printf("Child gInt = %d, localInt = %d, *pt = %d\n", gInt, localInt, *pt);
        free(pt);
        printf("Child ret = %d, pid = %d, ppid = %d\n", ret, getpid(), getppid());
        sleep(10);
        exit(0);
    }
    else if(ret < 0)
    {
        perror("fork failed!\n");
        exit(-1);
    }
    else
    {
        waitpid(ret, NULL, 0);
        printf("After child process exit.\n");
        printf("Child gInt = %d, localInt = %d, *pt = %d\n", gInt, localInt, *pt);
        printf("Father ret = %d, pid = %d, ppid = %d\n", ret, getpid(), getppid());
        free(pt);
    }

    return 0;
}