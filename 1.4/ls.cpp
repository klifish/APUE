#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <string>
#include<iostream>

using namespace std;

const char* default_path = ".";
int main(int argc, char const *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    char *path = (char*) malloc(256);
    memset(path,0,256);

    if (argc == 2)
    {
        strcpy(path,argv[1]);
    }else{
        strcpy(path,default_path);
    }

    if ((dp = opendir(path)) == NULL)
    {
        printf("can't open %s", path);
        exit(-1);
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }
    closedir(dp);
    free(path);
    return 0;
}
