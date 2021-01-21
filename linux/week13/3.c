#include<tmp.h>

int main(void)
{
    int running = 1, msgID;
    struct myMsg msgBuf;
    struct msqid_ds buf;

    if((msgID == msgget((key_t)1235, 0666 | IPC_CREAT)) == -1)
        err_exit("msgget failed!\n");
    while (running)
    {
        printf("Input some text: ");
        fgets(msgBuf.text, BUFSIZ, stdin);
        msgBuf.myMsgType = (long int)msgBuf.text[0];
        if(msgsnd(msgID, (void*)&msgBuf, sizeof(msgBuf.text), IPC_NOWAIT) == -1)
            err_exit("msgsnd failed!\n");
        if(!strncmp(msgBuf.text, "end", 3))
            break;
    }

    return 0;
}