#include<tmp.h>

/*
查看进程命令 ps -ef
查看进程状态文件，可以知道是否是僵尸进程: cat /proc/"进程号"/status
*/

int main()
{
    pid_t pid;

    pid = fork();
    if(pid < 0)
    {
        perror("error fork!\n");
        exit(1);
    }
    else if(pid == 0)
        exit(0);
    else
    {
        sleep(300);
        wait(NULL);
    }

    return 0;
}