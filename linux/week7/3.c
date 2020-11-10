#include<tmp.h>

static jmp_buf gStackEnv;
static void func1(void);
static void func2(void);

int main(void)
{
    if(setjmp(gStackEnv) == 0)
    {
        printf("Normal flow!\n");
        func1();
    }
    else
        printf("Longjump flow!\n");
    printf("leave main func!\n");

    return 0;
}

static void func1(void)
{
    printf("Enter func1!\n");
    func2();
    printf("leave func1!\n");
}

static void func2(void)
{
    printf("Enter func2!\n");
    longjmp(gStackEnv, 1);
    printf("leave func2!\n");
}