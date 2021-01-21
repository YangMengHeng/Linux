#include<tmp.h>

int main()
{
    int serverFifofd, clientFifofd;
    fifoData sendData, readData;
    pid_t myPid;
    char clientFifoName[256];

    serverFifofd = open(SERVERFIFONAME, O_WRONLY);
    if(serverFifofd == -1)
        err_exit("Server fifo failure!\n");
    myPid = getpid();
    sprintf(clientFifoName, CLIENTFIFONAME, myPid);
    if(mkfifo(clientFifoName, 0777) == -1)
        err_exit("No server!\n");
    while(1)
    {
        printf("Enter your request:\n");
        memset(sendData.data, 0, FIFOBUFSIZE);
        memset(readData.data, 0, FIFOBUFSIZE);
        fgets(sendData.data, FIFOBUFSIZE, stdin);
        if(!strcmp(sendData.data, "end\n") || !strcmp(sendData.data, "END\n")
        || !strcmp(sendData.data, "End\n") || !strcmp(sendData.data, "ENd\n")
        || !strcmp(sendData.data, "eNd\n") || !strcmp(sendData.data, "enD\n")
        || !strcmp(sendData.data, "eND\n"))
            break;
        sendData.clientPid = myPid;
        readData.clientPid = myPid;
        write(serverFifofd, &sendData, sizeof(sendData));
        clientFifofd = open(clientFifoName, O_RDONLY);
        if(clientFifofd != -1)
        {
            if(read(clientFifofd, &readData, sizeof(readData)) > 0)
                printf("---%d process get answer: %s\n", myPid, readData.data);
            close(clientFifofd);
        }
    }
    close(serverFifofd);
    unlink(clientFifoName);

    return 0;
}