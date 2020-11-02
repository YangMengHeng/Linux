#inlcude "t.h"

typedef long long LL;
const LL numMax = (LL)pow(2, 32);

LL readKthRecord(char str[], int k)
{
    int fd, num, recordSize[numMax], sign;
    LL record, tmp;

    if((fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0644) == -1))
    {
        printf("open Error!\n");
        return -1;
    }
    if((num = read(fd, tmp, numMax) == -1 || num < k - 1)
    {
        printf("read nums Error!\n");
        return -1;
    }
    for(int i = 0; i < k; i++)
    {
        if((sign = read(fd, &recordSize[i], numMax)) == -1)
        {
            printf("read recordSize Error!\n");
            return -1;
        }
    }
    lseek(fd, numMax * (num - k), SEEK_CUR);
    for(int i = 0; i < k - 1; i++)
        lseek(fd, recordSize[i], SEEK_CUR);
    if((sign = read(fd, record, recordSize[k - 1])) == -1)
    {
        printf("read record Error!\n");
        return -1;
    }

    return record;
}