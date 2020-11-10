#include<tmp.h>

static jmp_buf gStackEnv;
static void func1(int *a, int *b, int *c);

int main(void)
{
    int a = 1, b = 2, c = 3;

    int ret = setjmp(gStackEnv);
    if(ret == 0)
    {
        printf("Normal FLow!\n");
        printf("Normal a = %d, b = %d, c = %d\n", a, b, c);
        func1(&a, &b, &c);
    }
    else
    {
        printf("Back From Longjump flow!\n");
        printf("longjump a = %d, b = %d, c = %d\n", a, b, c);
    }

    return 0;
}

static void func1(int *a, int *b, int *c)
{
    printf("Enter func1!\n");
    (*a)++;
    (*b)++;
    (*c)++;
    printf("func1 a = %d, b = %d, c = %d\n", *a, *b, *c);
    longjmp(gStackEnv, 1);
    printf("Leave func1!\n");
}