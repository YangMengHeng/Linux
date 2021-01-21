#include<tmp.h>

int main()
{
    int serverFifofd, clientFifofd;
    fifoData myData;
    int nBytes;
    char clientFifoName[256], *tmpCharPtr, c;

    mkfifo(SERVERFIFONAME, 0777);
    serverFifofd = open(SERVERFIFONAME, O_RDONLY);
    if(serverFifofd == -1)
        err_exit("Server fifo failure!\n");
    printf("---Server run.\n");
    do
    {
        nBytes = read(serverFifofd, &myData, sizeof(myData));
        if(nBytes > 0)
        {
            tmpCharPtr = myData.data;
            while(*tmpCharPtr)
            {
                if(islower(*tmpCharPtr))
                    *tmpCharPtr = toupper(*tmpCharPtr);
                else if(isupper(*tmpCharPtr))
                    *tmpCharPtr = tolower(*tmpCharPtr);
                else if(*tmpCharPtr == '\n')
                    *tmpCharPtr = '\0';
                tmpCharPtr++;
            }
            sprintf(clientFifoName, CLIENTFIFONAME, myData.clientPid);
            clientFifofd = open(clientFifoName, O_WRONLY);
            if(clientFifofd != -1)
            {
                write(clientFifofd, &myData, sizeof(myData));
                printf("---Server %d send message(%s) to Client %d\n", getpid(), myData.data, myData.clientPid);
                close(clientFifofd);
            }
        }
    }while(nBytes > 0);
    printf("---Server down.\n");
    close(serverFifofd);
    unlink(SERVERFIFONAME);

    return 0;
}