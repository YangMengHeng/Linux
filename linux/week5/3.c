#include "t.h"

int main(void)
{
    inputDataFromFile("user.dat", 5);
    outputDataFromFile("user.dat", 5);
    saveDataToFile("user.dat", 2);
    outputDataFromFile("user.dat", 7);

    return 0;
}