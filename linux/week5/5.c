#include <stdio.h>
int main(void)
{
    char str[30];
    char ch;
    printf("请输入字符串：");
    gets(str);
    printf("%s\n", str);
    scanf("%c", &ch);
    printf("ch = %c\n", ch);
    return 0;
}