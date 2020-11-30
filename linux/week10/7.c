#include<tmp.h>

int main()
{
    pid_t pid;

    pid = fork();
    if(pid < 0)
    {
        perror("error fork!\n");
        exit(-1);
    }
    else if(pid == 0)
    {
        printf("Child 1 : pid = %d, ppid = %d\n", getpid(), getppid());
        exit(1);
    }
    else
    {
        printf("Parent 1 : pid = %d, ppid = %d\n", getpid(), getppid());
        pid_t pid2 = fork();
        if(pid2 > 0)
        {
            pid_t pid3 = fork();
            if(pid3 == 0)
            {
                printf("Child 3 : pid = %d, ppid = %d\n", getpid(), getppid());
                exit(1);
            }
            else if(pid3 > 0)
                wait(NULL);
            wait(NULL);
        }
        else if(pid2 == 0)
        {
            printf("Child 2 : pid = %d, ppid = %d\n", getpid(), getppid());
            pid_t pid4 = fork();
            if(pid4 == 0)
            {
                printf("Child 4 : pid = %d, ppid = %d\n", getpid(), getppid());
                exit(1);
            }
            else if(pid4 > 0)
                wait(NULL);
            exit(2);
        }
        wait(NULL);
    }

    return 0;
}