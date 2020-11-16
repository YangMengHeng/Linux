#include<tmp.h>

int g = 9;

int main()
{
    pid_t pid;
    int l = 99;

    pid = fork();
    if(pid < 0)
    {
        perror("Fork Failed!\n");
        exit(-1);
    }
    else if(pid == 0)
    {
        printf("Child : ppid = %d, pid = %d\n", getppid(), getpid());
        printf("Child: init g = %d, l = %d\n", g, l);
        g--;
        l++;
        printf("Child: g = %d, l = %d\n", g, l);
        exit(0);
    }
    else
    {
        printf("parent : child-pid = %d, pid = %d\n", pid, getpid());
        printf("parent : init g = %d, l = %d\n", g, l);
        g++;
        l--;
        printf("parent : g = %d, l = %d\n", g, l);
        return 0;
    }
}