#include<tmp.h>

int main()
{
    int fd[2], fd1[2], i;
    pid_t k;
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
        close(fd[1]);
        close(fd1[0]);
        while(1)
        {
            if((i = read(fd[0], buf, sizeof(buf))) != 0)
            {
                if(strcmp(buf, "end") == 0)
                    break;
                fprintf(stdout, "read form pipe : %s\n", buf);
                sprintf(buf1, "%d say I have received %d message : %s!", getpid(), getppid(), buf);
                i = write(fd1[1], buf1, sizeof(buf1));
                if(!i)
                    printf("Child write failed!\n");
                else
                    printf("Child write to pipe : %s\n", buf1);
            }
        }
        exit(0);
    }
    else
    {
        close(fd[0]);
        close(fd1[1]);
        while(1)
        {
            scanf("%s", buf);
            if(strcmp(buf, "end") == 0)
            {
                write(fd[1], "end", sizeof("end"));
                break;
            }
            i = write(fd[1], buf, sizeof(buf));
            if((i = read(fd1[0], buf1, sizeof(buf1))) != 0)
            {
                fprintf(stdout, "read form pipe : %s\n", buf);
                sprintf(buf1, "%d say I have received %d message : %s!", getpid(), k, buf);
                i = write(fd1[1], buf1, sizeof(buf1));
                if(!i)
                    printf("Parent read failed!\n");
                else
                    printf("Parent read from pipe : %s\n", buf1);
            }
        }
        wait(NULL);
        exit(0);
    }

    return 0;
}