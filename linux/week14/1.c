#include<tmp.h>

int tickets = 20;

void* ticketport1(void* arg);
void* ticketport2(void* arg);

int main(void)
{
    pthread_t id1, id2;
    int ret;

    ret = pthread_create(&id1, NULL, ticketport1, NULL);
    if(ret < 0)
        err_exit("create thread1 error!");

    ret = pthread_create(&id2, NULL, ticketport2, NULL);
    if(ret < 0)
        err_exit("create thread2 error!");

    pthread_join(id1, NULL);
    pthread_join(id2, NULL);

    return 0;
}

void* ticketport1(void* arg)
{
    while(1)
    {
        if(tickets > 0)
            printf("ticketport1 sells ticket: %d\n", tickets--);
        else
            break;
    }

    return (void*)0;
}

void* ticketport2(void* arg)
{
    while(1)
    {
        if(tickets > 0)
            printf("ticketport2 sells ticket: %d\n", tickets--);
        else
            break;
    }

    return (void*)0;
}