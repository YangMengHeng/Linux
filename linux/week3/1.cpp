#include<stdio.h>
#include<string.h>

int main(void)
{
    FILE *fp = fopen("./test", "w");
    char buf[80];
    fgets(buf, sizeof(buf), stdin);
    buf[strlen(buf) - 1] = '\0';
    fwrite(buf,  sizeof(char), strlen(buf), fp);
    printf("the data will be written is '%s'.%d\n", buf, fp->_fileno);
    fclose(fp);

    return 0;
}