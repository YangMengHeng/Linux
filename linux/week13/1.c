#include<tmp.h>

int main(int argc, char* argv[])
{
    struct stat statBuf;

    if(argc != 2)
    {
        fprintf(stderr, "Usage : ftok <pathname>");
        return 1;
    }
    stat(argv[1], &statBuf);
    key_t key = ftok(argv[1], 0x1234);
    printf("st_dev : %lx, st_inode : %lx, key : %x\n", statBuf.st_dev, statBuf.st_ino, key);

    return 0;
}