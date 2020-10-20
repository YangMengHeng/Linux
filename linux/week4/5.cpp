#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits>
#include<sys/types.h>
using namespace std;

int main()
{
    int nfd = dup(STDOUT_FILENO);
    close(STDOUT_FILENO);
    int fd = open("ot", O_CREAT|O_RDWR, 0644);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    printf("fd = %d\n", fd);
    printf("hello ! How are you ?!\n");
    write(nfd, "nfd\n", 4);
    write(fd, "fd\n", 3);

    return 0;
}