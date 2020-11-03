#include<tmp.h>

int main(int argc, char *argv[])
{
    printf("--------main function running!--------\n");
    if(argc != 3)
        err_exit("Input Error! You just can input two referrences!");
    int op1 = atoi(argv[1]), op2 = atoi(argv[2]);
    printf("two referrences added result is : %d\n", op1 + op2);

    return 0;
}