#include<tmp.h>

int main()
{
    int fd[2], fd1[2], i;
    pid_t k, k2;
    char buf[1024], buf1[1024];

    memset(buf, 0, sizeof(buf));
    pipe(fd);
    pipe(fd1);
    k = fork();
    if(k < 0)
    {
        perror("fork error!\n");
        exit(-1);
    }
    else if(k == 0)
    {
        printf("Child 1 pid: %d\n", getpid());
        close(fd[1]);
        close(fd1[0]);
        while(1)
        {
            // if((i = read(fd[0], buf, sizeof(buf))) != 0)
            // {
            //     if(strcmp(buf, "end") == 0)
            //         break;
            //     fprintf(stdout, "Child1 read form pipe : %s\n", buf);
            //     scanf("%s", buf);
            //     sprintf(buf1, "%d say : %s!", getpid(), buf);
            //     i = write(fd1[1], buf1, sizeof(buf1));
            //     if(!i)
            //         printf("Child1 write failed!\n");
            //     else
            //         printf("Child1 write to pipe : %s\n", buf1);
            // }
            scanf("%s", buf);
            i = write(fd1[1], buf, sizeof(buf));
            fprintf(stdout, "%d say : %s\n", getpid(), buf);
            if(strcmp(buf, "end") == 0)
                break;
        }
        exit(0);
    }
    else
    {
        k2 = fork();
        if(k2 == 0)
        {
            printf("Child 2 pid: %d\n", getpid());
            close(fd[0]);
            close(fd1[1]);
            while(1)
            {
                scanf("%s", buf);
                i = write(fd[1], buf, sizeof(buf));
                fprintf(stdout, "%d say : %s\n", getpid(), buf);
                if(strcmp(buf, "end") == 0)
                    break;
            }
        }
        else
        {
            printf("Parent pid : %d\n", getpid());
            wait(NULL);
            wait(NULL);

            exit(0);
        }
    }

    return 0;
}