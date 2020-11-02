#include "t.h"

user *usr = NULL;
int mode = 1;

void errExit(char *s)
{
    printf("Usage : %s is failed!\n", s);
    exit(1);
}

void updateOrderWay()
{
    int t;

    printf("\nWould you like to order by increasement?(1/0): ");
    fflush(stdin);
    scanf("%d", &t);
    fflush(stdin);
    if(t == 0)
        mode = 0;
    else if(t == 1)
        mode = 1;
    else
        errExit("scanf data error!");
}

int inputDataFromFile(char *path, int n)
{
    int num = sizeof(user), re = 0;
    FILE *fp = NULL;
    usr = malloc(num * n);

    if((fp = fopen(path, "w+")) == NULL)
        errExit("open error!\n");
    printf("\nPlease input data:\n");
    for(int i = 0; i < n; i++)
        scanf("%d %s %s %s", &usr[i].id, usr[i].name, usr[i].htel, usr[i].tel);
    for(int i = 0; i < n; i++)
        re += fprintf(fp, "%d %s %s %s\n", usr[i].id, usr[i].name, usr[i].htel, usr[i].tel);
    fclose(fp);
    free(usr);

    return re;
}

int outputDataFromFile(char *path, int n)
{
    int num = sizeof(user), re = 0;
    user *usr = malloc(num * n);
    FILE *fp = NULL;

    if((fp = fopen(path, "r")) == NULL)
        errExit("open error!\n");
    updateOrderWay();
    printf("What's in file %s :\n", path);
    for(int i = 0; i < n; i++)
        fscanf(fp, "%d %s %s %s\n", &usr[i].id, usr[i].name, usr[i].htel, usr[i].tel);
    sortDataByqsort(usr, num, n);
    printf("userid         name         htel         tel\n");
    for(int i = 0; i < n; i++)
        printf("%03d            %-8s     %-12s %-12s\n",
        usr[i].id, usr[i].name, usr[i].htel, usr[i].tel);
    fclose(fp);
    free(usr);

    return re;
}

int saveDataToFile(char *path, int n)
{
    int num = sizeof(user), re = 0;
    FILE *fp = NULL;
    user *usr = malloc(num * n);

    if((fp = fopen(path, "a+")) == NULL)
        errExit("open error!");
    printf("\nPlease input append data:\n");
    for(int i = 0; i < n; i++)
        scanf("%d %s %s %s", &usr[i].id, usr[i].name, usr[i].htel, usr[i].tel);
    for(int i = 0; i < n; i++)
        re += fprintf(fp, "%d %s %s %s\n", usr[i].id, usr[i].name, usr[i].htel, usr[i].tel);
    fclose(fp);
    free(usr);

    return re;
}

int cmp(const void *a, const void *b)
{
    user *usra = (user*)a;
    user *usrb = (user*)b;

    return strcmp(usra->name, usrb->name);
}

int recmp(const void *a, const void *b)
{
    user *usra = (user*)a;
    user *usrb = (user*)b;
    int t = strcmp(usra->name, usrb->name);
    if(t > 0)
        t = -1;
    else
        t = 1;

    return t;
}

void sortDataByqsort(user usr[], int num, int n)
{
    if(mode >= 1)
        qsort(usr, n, num, cmp);
    else if(mode <= 0)
        qsort(usr, n, num, recmp);
    else
        errExit("sort data error!");
}