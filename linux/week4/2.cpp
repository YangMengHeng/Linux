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
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";
    int fd;
    if((fd = open("file.hole", O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
    {
        printf("Create Error!\n");
        exit(1);
    }
    if(write(fd, buf1, 10) != 10)
    {
        printf("buf1 Error!\n");
        exit(1);
    }
    if(lseek(fd, 40, SEEK_SET) == -1)
    {
        printf("lseek Error!\n");
        exit(1);
    }
    if(write(fd, buf2, 10) != 10)
    {
        printf("buf2 Error!\n");
        exit(1);
    }

    return 0;
}