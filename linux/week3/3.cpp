#include<stdio.h>
#include<string.h>

int main(void)
{
    FILE *fp = fdopen(3, "w+");
    char buf[80] = {"Hello BaiZai!"};
    //fgets(buf, sizeof(char), fp);
    fputs(buf, fp);
    //printf("the data from file 'test' is '%s'\n%d\n", buf, fp->_fileno);
    fclose(fp);

    return 0;
}