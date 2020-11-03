#include<tmp.h>
static void __attribute__ ((constructor))before_main(void)
{
    printf("--------Before Main Function--------\n");
}

static void __attribute__ ((destructor))after_main(void)
{
    printf("--------After Main Function--------\n");
}

int main()
{
    printf("--------main function running!--------\n");

    return 0;
}