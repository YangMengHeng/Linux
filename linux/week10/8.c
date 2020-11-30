#include<tmp.h>
#include<time.h>
void writeToFile(FILE *file, int pid, int ppid);
void printInfo(FILE *file);

int main(int argc, char *argv[])
{
    pid_t pid, pid2, pid1, pid3;
    FILE *file = fopen("./log.dat", "r+");

    pid = fork();
    if(pid < 0)
    {
        perror("error fork!\n");
        exit(1);
    }
    else if(pid == 0)
    {
        pid2 = fork();
        if(pid2 == 0)
        {
            printf("Child 2 : pid = %d, ppid = %d\n", getpid(), getppid());
            writeToFile(file, getpid(), getppid());

            exit(4);
        }
        else
        {
            printf("Child 1 : pid = %d, ppid = %d\n", getpid(), getppid());
            writeToFile(file, getpid(), getppid());

            exit(1);
        }
    }
    else
    {
        pid1 = fork();
        if(pid1 == 0)
        {
            pid3 = fork();
            if(pid3 == 0)
            {
                printf("Child 3 : pid = %d, ppid = %d\n", getpid(), getppid());
                writeToFile(file, getpid(), getppid());

                exit(3);
            }
            else
            {
                printf("Child 2 : pid = %d, ppid = %d\n", getpid(), getppid());
                writeToFile(file, getpid(), getppid());

                exit(2);
            }
        }
        else
        {
            int s1, t1, s2, t2, s3, t3, s4, t4;
            t1 = waitpid(pid, &s1, 0);
            t2 = waitpid(pid1, &s2, WNOHANG);
            t3 = waitpid(pid2, &s3, WNOHANG);
            t4 = waitpid(pid3, &s4, WNOHANG);

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
            if(WIFEXITED(s4))
                printf("Child 4 exit code = %d, wait pid = %d\n", WEXITSTATUS(s4), t4);
            else
                printf("Child 4 process stoped with signal %d!\n", WTERMSIG(s4));

            printInfo(file);

            exit(0);
        }
    }

    return 0;
}

void writeToFile(FILE *file, int pid, int ppid)
{
    unsigned long long a = 0;
    time_t timer;
    struct tm *tblock;
    time(&timer);
    tblock = gmtime(&timer);


    a = (tblock->tm_year+1900)*100;
    a = (a+tblock->tm_mon+1)*100;
    a = (a+tblock->tm_mday)*100;
    a = (a+tblock->tm_hour+8)*100;
    a = (a+tblock->tm_min)*100;
    a = (a+tblock->tm_sec);

    printf("现在时间是 %d 年 %d 月 %d 日 %d 时 %d 分 %d 秒.\n",\
            tblock->tm_year+1900, tblock->tm_mon+1, tblock->tm_mday,\
            tblock->tm_hour+8, tblock->tm_min, tblock->tm_sec);
    printf("a = %llu\n", a);

    fprintf(file, "%d %d %llu\n", pid, ppid, a);
}

void printInfo(FILE *file)
{
    int pid, ppid;
    unsigned long long a = 0;

    while(fscanf(file, "%d %d %llu", pid, ppid, a) != EOF)
        printf("process %d, parent process %d, exit time %llu\n", pid, ppid, a);
}