#include<tmp.h>

int main()
{
    int fifofd, n, totalBytes = 0;
    char readBuf[PIPEBUF];

    if (access(FIFOFILE, F_OK) == -1)
        if(mkfifo(FIFOFILE, 0666) != 0)
        {
            printf("Could not create fifo %s\n", FIFOFILE);
            exit(-1);
        }
    if((fifofd = open(FIFOFILE, O_RDONLY)) < 0)
    {
        printf("Could not open fifo %s\n", FIFOFILE);
        exit(-1);
    }
    printf("Parent %d 's child %d opened : %s\n", getppid(), getpid(), FIFOFILE);
    while((n = read(fifofd, readBuf, PIPEBUF)) > 0)
    {
        printf("%d received %d bytes\n", getpid(), n);
        totalBytes += n;
    }
    close(fifofd);
    printf("Process %d received %d bytes\n", getpid(), totalBytes);

    return 0;
}