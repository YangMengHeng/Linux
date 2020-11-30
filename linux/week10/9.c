#include<tmp.h>

int main(int argc, char *argv[])
{
    pid_t pid, pid2, pid1, pid3;
    FILE *file = fopen("./log.dat", "w+");


    pid = fork();
    if(pid < 0)
    {
        perror("error fork!\n");
        exit(1);
    }
    else if(pid == 0)
    {
        pid3 = fork();
        if(pid3 == 0)
        {

        }
        else
        {

        }
        char *args[] = {"./test", NULL};
        printf("Child1 : pid = %d, ppid = %d re = %d\n", getpid(), getppid(), pid);
        // execve("./1", args, NULL);
        for(int i = 0; i < 2; i++)
            printf("%d : 111!\n", i);

        exit(1);
    }
    else
    {
        pid1 = fork();
        if(pid1 < 0)
        {
            perror("error fork!\n");
            exit(1);
        }
        else if(pid1 == 0)
        {
            pid2 = fork();
            if(pid2 == -1)
            {
                perror("error fork!\n");
                exit(1);
            }
            else if(pid2 == 0)
            {
                printf("Child3 : pid = %d, ppid = %d re = %d\n", getpid(), getppid(), pid1);
                // for(int i = 0; i < 2; i++)
                //     printf("%d : 333!\n", i);
                while(1);

                exit(3);
            }
            else
            {
                printf("Child2 : pid = %d, ppid = %d re = %d\n", getpid(), getppid(), pid1);
                for(int i = 0; i < 2; i++)
                    printf("%d : 222!\n", i);

                exit(2);
            }
        }
        else
        {
            int s1, t1, s2, t2, s3, t3;
            t1 = waitpid(pid, &s1, WNOHANG);
            t2 = waitpid(pid1, &s2, WUNTRACED);
            t3 = waitpid(pid2, &s3, 0);

            if(WIFEXITED(s1))
                printf("Child 1 exit code = %d, wait pid = %d\n", WEXITSTATUS(s1), t1);
            else
                printf("Child 1 process stoped with signal %d!\n", WTERMSIG(s1));
            if(WIFEXITED(s2))
                printf("Child 2 exit code = %d, wait pid = %d\n", WEXITSTATUS(s2), t2);
            else
                printf("Child 2 process stoped with signal %d!\n", WTERMSIG(s2));
            if(WIFEXITED(s3))
                printf("Child 3 exit code = %d, wait pid = %d\n", WEXITSTATUS(s3), t3);
            else
                printf("Child 3 process stoped with signal %d!\n", WTERMSIG(s3));

            


            exit(0);
        }
    }

    return 0;
}