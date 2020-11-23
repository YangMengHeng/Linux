#include<tmp.h>

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        pid_t pid;
        pid = fork();
        if(pid < 0)
        {
            perror("error fork!\n");
            exit(1);
        }
        else if(pid == 0)
        {
            printf("9.c : pid = %d, ppid = %d\n", getpid(), getppid());
            if(execve("./1", argv, NULL) == -1)
            {
                perror("execve failed!\n");
                exit(1);
            }
            printf("after calling!\n");
        }
        else
        {
            int s1, t1;
            t1 = wait(&s1);
            printf("Parent : t1 = %d, s1 = %d\n", t1, WEXITSTATUS(s1));
            printf("Parent : pid = %d, ppid = %d\n", getpid(), getppid());
            exit(0);
        }
    }

    return 0;
}