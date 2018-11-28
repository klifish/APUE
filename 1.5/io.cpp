#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define BUFFSIZE 4096

int main(int argc, char const *argv[])
{
    float i = 0.5;
    int j = 3;

    cout << i * j << endl;
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            printf("write error\n");
            exit(1);
        }
    }

    if (n < 0)
    {
        printf("read error\n");
    }
    return 0;
}
