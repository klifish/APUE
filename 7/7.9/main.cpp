#include<stdlib.h>
#include<stdio.h>

int main(int argc, char const *argv[])
{
    char* env = getenv("HOME");

    printf("%s\n",env);

    return 0;
}
