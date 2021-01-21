#include<tmp.h>

int main()
{
    int fd[2], i, fdt;
    pid_t k;
    char buf[1024];
    char *t[4] = {"test", "Hello", "World!", "end"};

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
        fdt = open("./test.dat", O_CREAT | O_APPEND | O_RDWR);
        dup2(fdt, fd[0]);

        // while(fgets(buf, sizeof(buf), stdin) != NULL)
        //     puts(buf);
        //execlp("/bin/cat", "cat", NULL, NULL);
        while(1)
        {
            if((i = read(fd[0], buf, sizeof(buf))) != 0)
            {
                if(strcmp(buf, "end") == 0)
                    break;
                fprintf(stdout, "read form test.dat : %s\n", buf);
            }
        }
        exit(0);
    }
    else
    {
        close(fd[0]);
        dup2(fd[1], 1);
        //close(fd[1]);
        execlp("./test", t[0], t[1], t[2], t[3], NULL);
        wait(NULL);

        exit(0);
    }

    return 0;
}