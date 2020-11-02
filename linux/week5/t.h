#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<float.h>

#define INCREASMENT 0
#define DECREASMENT 1

typedef struct USER{
    int id;
    char name[8];
    char htel[12];
    char tel[12];
}user;

void errExit(char *s);
void updateOrderWay();
int cmp(const void *a, const void *b);
int recmp(const void *a, const void *b);
void sortDataByqsort(user usr[], int num, int n);
int inputDataFromFile(char *path, int n);
int outputDataFromFile(char *path, int n);
int saveDataToFile(char *path, int n);