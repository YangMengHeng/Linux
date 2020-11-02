#include"t.h"

int main(void)
{
    short int si;
    int i;
    long int li;
    long long int lli;

    si = si & 0;
    i = i & 0;
    li = li & 0;
    lli = lli & 0;

    printf("INTEGER:\n");
    printf("max short int value: %hd\n", (unsigned short int)~si >> 1);
    printf("min short int value: %hd\n", ++si << (sizeof(short int) * 8 - 1));
    printf("max int value: %d\n", (unsigned int)~i >> 1);
    printf("min int value: %d\n", ++i << (sizeof(int) * 8 - 1));
    printf("max long int value: %ld\n", (unsigned long int)~li >> 1);
    printf("min long int value: %ld\n", ++li << (sizeof(long int) * 8 - 1));
    printf("max ll int value: %lld\n", (unsigned long long int)~lli >> 1);
    printf("min ll int value: %lld\n", ++lli << (sizeof(long long int) * 8 - 1));
    printf("FLOAT:\n");
    printf("max float value: %f\n", FLT_MAX);
    printf("min float value: %f\n", -FLT_MAX);
    printf("DOUBLE:\n");
    printf("max double value: %lf\n", DBL_MAX);
    printf("min double value: %lf\n", -DBL_MAX);

    return 0;
}