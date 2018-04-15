#include "stdio.h"
#include "memory.h"
#include <iostream>
#include <vector>

int main()
{
    std::cout << "### begin ###" << std::endl;

    const int CACHE_DATA_LENGTH = 64 * 1024;
    char cacheData[CACHE_DATA_LENGTH] = {'\0'};

    struct messageA
    {
        int a;
        int b;
        char array[0];
        messageA()
        {
            memset(this, 0, sizeof(*this));
        }
    };

    messageA *pMsg = (messageA *)cacheData;

    char message[] = "hello, little serven";

    memcpy_s(pMsg->array, sizeof(message), message, sizeof(message));

    std::cout << pMsg->array << std::endl;

    std::cout << "### end ###" << std::endl;
    getchar();
    return 0;
}