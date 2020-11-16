#include<tmp.h>
#include"t.h"

int main()
{
    int fd_out, pid[7], num = 0;
    char buf[1024];
    pid_t pid1, pid2, pid3, pid4;

    strncpy(buf, "Hello World!\n", 14);
    fd_out = open(TMPFILE, O_WRONLY|O_CREAT|O_TRUNC, MODE);
    if(fd_out < 0)
    {
        fprintf(stderr, "failed to open %s, reson(%s)\n", TMPFILE, strerror(errno));
        return -1;
    }

    pid1 = fork();
    if(pid1 < 0)
    {
        fprintf(stderr, "failed to fork, reason(%s)\n", strerror(errno));
        return -1;
    }
    else if(pid1 == 0)
    {
        printf("pid1 child:\n%d %d : %s", getppid(), getpid(), buf);
        sprintf(buf, "%d Hello World!\n", getpid());
        write(fd_out, buf, strlen(buf));
        pid[num++] = getpid();
    }
    else
    {
        printf("pid1 parent:\n%d %d : %s", getppid(), getpid(), buf);
        sprintf(buf, "%d Hello World!\n", getpid());
        write(fd_out, buf, strlen(buf));
        pid[num++] = getpid();
        wait(NULL);
    }

    pid2 = fork();
    if(pid2 < 0)
    {
        fprintf(stderr, "failed to fork, reason(%s)\n", strerror(errno));
        return -1;
    }
    else if(pid2 == 0)
    {
        printf("pid2 child:\n%d %d : %s", getppid(), getpid(), buf);
        sprintf(buf, "%d Hello World!\n", getpid());
        write(fd_out, buf, strlen(buf));
        pid[num++] = getpid();
    }
    else
    {
        printf("pid2 parent:\n%d %d : %s", getppid(), getpid(), buf);
        sprintf(buf, "%d Hello World!\n", getpid());
        write(fd_out, buf, strlen(buf));
        pid[num++] = getpid();
        wait(NULL);
    }

    pid3 = fork();
    if(pid3 < 0)
    {
        fprintf(stderr, "failed to fork, reason(%s)\n", strerror(errno));
        return -1;
    }
    else if(pid3 == 0)
    {
        for(int i = 0; i < num; i++)
        {
            if(getpid() == pid[i])
            {
                printf("pid3 child:\n%d %d : %s", getppid(), getpid(), buf);
                sprintf(buf, "%d Hello World!\n", getpid());
                write(fd_out, buf, strlen(buf));
                break;
            }
        }
    }
    else
    {
        printf("pid3 parent:\n%d %d : %s", getppid(), getpid(), buf);
        sprintf(buf, "%d Hello World!\n", getpid());
        write(fd_out, buf, strlen(buf));
        pid[num++] = getpid();
        wait(NULL);
    }

    pid4 = fork();
    if(pid4 < 0)
    {
        fprintf(stderr, "failed to fork, reason(%s)\n", strerror(errno));
        return -1;
    }
    else if(pid4 == 0)
    {
        for(int i = 0; i < num; i++)
        {
            if(getpid() == pid[i])
            {
                printf("pid3 child:\n%d %d : %s", getppid(), getpid(), buf);
                sprintf(buf, "%d Hello World!\n", getpid());
                write(fd_out, buf, strlen(buf));
                break;
            }
        }
    }
    else
    {
        printf("pid4 parent:\n%d %d : %s", getppid(), getpid(), buf);
        sprintf(buf, "%d Hello World!\n", getpid());
        write(fd_out, buf, strlen(buf));
        pid[num++] = getpid();
        wait(NULL);
    }

    memset(buf, 0, 1024);
    //wait(NULL);

    return 0;
}