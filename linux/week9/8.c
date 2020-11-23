#include<tmp.h>

int main()
{
    int r1 = 99, r2 = 99;

    r1 = fork();
    if(r1 < 0 || r2 < 0)
    {
        perror("error fork!\n");
        exit(1);
    }
    else if(r1 == 0)
    {
        printf("Child 1 : pid = %d, ppid = %d, r1 = %d, r2 = %d\n", getpid(), getppid(), r1, r2);
        exit(99);
    }
    else
    {
        r2 = fork();
        if(r2 == 0)
        {
            printf("Child 2 : pid = %d, ppid = %d, r1 = %d, r2 = %d\n", getpid(), getppid(), r1, r2);
            exit(88);
        }
        else
        {
            int t1, t2, s1, s2;
            t1 = wait(&s1);
            t2 = wait(&s2);
            // wait(NULL);
            // wait(NULL);
            printf("Parent : t1 = %d, s1 = %d, t2 = %d, s2 = %d\n", t1, WEXITSTATUS(s1), t2, WEXITSTATUS(s2));
            printf("Parent : pid = %d, ppid = %d, r1 = %d, r2 = %d\n", getpid(), getppid(), r1, r2);
            exit(1);
        }
    }

    return 0;
}