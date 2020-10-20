#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits>
#include<sys/types.h>
using namespace std;

int main(int argc, char **argv)
{
    int n, to, from;
    char buf[1024];

    if(argc != 3)
    {
        printf("Usage : %s form-file to-file\n", argv[0]);
        exit(1);
    }
    if((from = open(argv[1], O_RDONLY)) < 0)
    {
        printf("Usage : %s form-file to-file\n", argv[1]);
        exit(1);
    }
    if((to = open(argv[2], O_WRONLY | O_CREAT | O_APPEND, 0644)) < 0)
    {
        printf("Usage : %s form-file to-file\n", argv[2]);
        exit(1);
    }
    while((n = read(from, buf, sizeof(buf))) > 0)
        write(to, buf, n);
    close(from);
    close(to);

    return 0;
}