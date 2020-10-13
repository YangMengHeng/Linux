#include<stdio.h>
#include<string.h>

int main(void)
{
    FILE *fp = fopen("./test", "r");
    char buf[80];
    int t = 0, s = 1;
    while(s)
    {
        s = fread(buf, sizeof(char), sizeof(buf), fp);
        t += s;
    }
    buf[strlen(buf)] = '\0';
    printf("the data from file 'test' is '%s'\n%d %d\n", buf, t, fp->_fileno);
    fclose(fp);

    return 0;
}