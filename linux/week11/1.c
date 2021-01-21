#include<tmp.h>

int main()
{
    int fd[2], i;
    pid_t k;
    char buf[1024];

    memset(buf, 0, sizeof(buf));
    pipe(fd);
    k = fork();
    if(k < 0)
    {
        perror("fork error!\n");
        exit(-1);
    }
    else if(k == 0)
    {
        close(fd[1]);
        sleep(1);
        i = read(fd[0], buf, sizeof(buf));
        if(!i)
        {
            printf("Child read failed!\n");
            exit(0);
        }
        else
        {
            fprintf(stdout, "read form pipe : %s\n", buf);
            close(fd[0]);
            sprintf(buf, "%d say I have received %d message!", getpid(), getppid());
            i = write(fd[1], buf, sizeof(buf));
            if(!i)
                printf("Child read failed!\n");
            else
                printf("write to pipe : %s\n", buf);
            exit(0);
        }
    }
    else
    {
        close(fd[0]);
        sprintf(buf, "%d say hello! to %d!", getpid(), k);
        i = write(fd[1], buf, sizeof(buf));
        if(!i)
            printf("Child read failed!\n");
        else
            printf("write to pipe : %s\n", buf);
        wait(NULL);
        exit(0);
    }

    return 0;
}