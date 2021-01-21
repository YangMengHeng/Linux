#include<tmp.h>

int main(void)
{
    int running = 1, msgID;
    struct myMsg msgBuf;
    long int msgType = -57;

    if((msgID == msgget((key_t)1235, 0666 | IPC_CREAT)) == -1)
        err_exit("msgget failed!\n");
    while (running)
    {
        if(msgrcv(msgID, (void*)&msgBuf, BUFSIZ, -57, IPC_NOWAIT) != -1)
            printf("Msessage Receive: %s", msgBuf.text);
        else if(errno == ENOMSG && msgrcv(msgID, (void*)&msgBuf, BUFSIZ, 0, 0) != -1)
            printf("Msessage Receive: %s", msgBuf.text);
        else
            err_exit("msgrcv failed!\n");
        if(!strncmp(msgBuf.text, "end", 3))
            break;
    }
    if(msgctl(msgID, IPC_RMID, 0) == -1)
        err_exit("msgctl failed!\n");

    return 0;
}