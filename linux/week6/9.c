#include<tmp.h>

static void set_env_string(void)
{
    char test_env[] = "test_env";
    if(setenv(test_env, "testset", 1) != 0)
        printf("Failed to set new env var!\n");
    printf("1. The test_env string is %s\n", getenv("test_env"));
}

static void set_env_string2()
{
    char test_env[] = "testEnv";
    if(setenv(test_env, "testset2", 1) != 0)
        printf("Failed to set new env var!\n");
    printf("1. The testEnv string is %s\n", getenv("testEnv"));
}

static void put_env_string(void)
{
    char test_env[] = "testEnv=test";
    if(putenv(test_env) != 0)
        printf("Failed to put new env var!\n");
    printf("1. The testEnv string is %s\n", getenv("testEnv"));
}

static void show_env_string(void)
{
    printf("2. The testEnv string is %s\n", getenv("testEnv"));
    printf("2. The test_env string is %s\n\n", getenv("test_env"));
}

int main(int argc, char *argv[])
{
    put_env_string();
    show_env_string();
    set_env_string();
    show_env_string();
    set_env_string2();
    show_env_string();

    return 0;
}