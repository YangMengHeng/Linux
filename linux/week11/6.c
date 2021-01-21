#include<tmp.h>

int main()
{
    int fd[2], fd1[2], fd2[2], fd3[2], i, j;
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
            i = write(fd[1], buf, sizeof(buf));
            if(strcmp(buf, "end") == 0)
                break;
            if(i = read(fd1[0], buf, sizeof(buf)) != 0)
                fprintf(stdout, "%d received %s\n", getpid(), buf);
        }
        exit(0);
    }
    else
    {
        k2 = fork();
        if(k2 == 0)
        {
            printf("Child 2 pid: %d\n", getpid());
            close(fd2[0]);
            close(fd3[1]);
            while(1)
            {
                scanf("%s", buf);
                i = write(fd2[1], buf, sizeof(buf));
                if(strcmp(buf, "end") == 0)
                    break;
                if(i = read(fd3[0], buf, sizeof(buf)) != 0)
                    fprintf(stdout, "%d received %s\n", getpid(), buf);
            }
        }
        else
        {
            printf("Parent pid : %d\n", getpid());

            close(fd[0]);
            close(fd1[1]);
            // Child 1

            close(fd2[1]);
            close(fd3[0]);
            // Child 2

            while(1)
            {
                if(j = read(fd[1], buf, sizeof(buf)) != 0)
                    write(fd1[0], buf, sizeof(buf));
                if(j = read(fd3[1], buf, sizeof(buf)) != 0)
                    write(fd2[0], buf, sizeof(buf));
                if(strcmp(buf, "end") == 0)
                    break;
            }

            wait(NULL);
            wait(NULL);

            exit(0);
        }
    }

    return 0;
}