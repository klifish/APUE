#include<sys/stat.h>
#include<stdio.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    struct stat buf;
    char* ptr;

    for(int i = 1; i < argc;i++){
        printf("%s: ",argv[i]);
        if(lstat(argv[i],&buf) < 0){
            perror(argv[0]);
            exit(1);
        }
        
        if(S_ISREG(buf.st_mode)){
            ptr = "regular";
        }else if(S_ISDIR(buf.st_mode)){
            ptr="directory";
        }else{
            ptr = "unknown";
        }
        printf("%s\n",ptr);
    }


    return 0;
}
