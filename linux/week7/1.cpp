#include<tmp.h>
#include<iostream>
using namespace std;

static jmp_buf gStackEnv;

class Test{
    public:
    Test(){cout << "Constructor" << endl;};
    ~Test(){cout << "Dstructor" << endl;};
}

int main(void)
{
    int a = 1, b = 2, c = 3;

    int ret = setjmp(gStackEnv);
    if(ret == 0)
    {
        cout << "Normal FLow!" << endl;
        cout << "Normal a = " << a << ", b = " << b << ", c = " << c << endl);
        func1(&a, &b, &c);
    }
    else
    {
        cout << "Back From Longjump flow!!" << endl;
        cout << "longjump a = " << a << ", b = " << b << ", c = " << c << endl);
    }

    return 0;
}