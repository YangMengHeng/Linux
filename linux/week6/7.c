#include<tmp.h>

static void __attribute__ ((constructor))before_main(void)
{
    printf("--------Before Main Function--------\n");
}

static void __attribute__ ((destructor))after_main(void)
{
    printf("--------After Main Function--------\n");
}

void callBack1()
{
    printf("--------callBack1--------\n");
}

void callBack2()
{
    printf("--------callBack2--------\n");
}

void callBack3()
{
    printf("--------callBack3--------\n");
}

int main(int argc, char *argv[])
{
    atexit(callBack3);
    atexit(callBack2);
    atexit(callBack1);
    while(1)
        printf("--------main function running!--------\n");
    printf("--------Program Finished!--------\n");

    return 0;
}