#include<tmp.h>

int main(void)
{
    int fifofd, n, totalBytes = 0;
    char sendBUf[PIPEBUF];

    if((fifofd = open(FIFOFILE, O_WRONLY)) < 0)
    {
        printf("Could not open fifo %s\n", FIFOFILE);
        exit(-1);
    }
    printf("Parent %d 's child %d opened : %s\n", getppid(), getpid(), FIFOFILE);
    do
    {
        if((n = write(fifofd, sendBUf, PIPEBUF)) == -1)
        {
            perror("write error\n");
            exit(-2);
        }
        printf("%d write %d bytes\n", getpid(), n);
        totalBytes += n;
    }while(totalBytes < TENMSG);
    close(fifofd);
    unlink(FIFOFILE);
    printf("Process %d written %d bytes\n", getpid(), totalBytes);

    return 0;
}