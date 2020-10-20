#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits>
#include<sys/types.h>
using namespace std;

int main(void)
{
    char buf[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int fd;
    sleep(1);
    if((fd = open("test", O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
    {
        printf("Create Error!\n");
        exit(1);
    }
    if(write(fd, buf, 26) != 26)
    {
        printf("buf Error!\n");
        exit(1);
    }

    return 0;
}