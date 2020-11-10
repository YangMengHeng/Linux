#include<tmp.h>

static int x1 = 0, x2;
int x3 = 100, x4;

int main(void)
{
    int x5 = 0xffffffff, x6;
    static int x7 = 0x11111111;
    int x8[10];
    //int *x9 = (int*)malloc(1524853 * 1024 * sizeof(int));

    printf("address of x1 : %x, x2 : %x\n", &x1, &x2);
    printf("address of x3 : %x, x4 : %x\n", &x3, &x4);
    printf("address of x5 : %x, x6 : %x\n", &x5, &x6);
    printf("address of x7 : %x, x8 : %x\n", &x7, x8);
    //printf("address of x9 : %x , %d\n", x9, sizeof(x9));
    //free(x9);

    return 0;
}