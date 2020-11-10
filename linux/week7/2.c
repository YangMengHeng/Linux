#include<tmp.h>

int main(void)
{
    int *x = (int*)malloc(1 * sizeof(int));
    int i = 2;

    while(1)
    {
        if(x != NULL)
            free(x);
        else
        {
            free(x);
            i--;
            break;
        }
        x = (int*)malloc(i++ * 1024 * sizeof(int));
    }
    printf("address of x : %x, max i : %d, max bytes : %dKB\n", x, --i, i * 4);

    return 0;
}