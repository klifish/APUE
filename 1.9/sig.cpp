#include<sys/wait.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
static void sig_int(int);
const int MAXLINE = 4096;
int main(int argc, char const *argv[])
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT,sig_int) == SIG_ERR){
        fprintf(stderr, "%s\n",strerror(errno));
    }
    printf("%% ");
    while(fgets(buf,MAXLINE,stdin) != NULL){
        if(buf[strlen(buf)-1] =='\n'){
            buf[strlen(buf)-1] = 0;
        }

        if((pid = fork()) < 0){
            perror(NULL);
        }else if(0 == pid){
            execlp(buf,buf,(char*)0);
            exit(127);
        }
        waitpid(pid,&status,0);
        printf("%% ");
    }
    return 0;
}
void sig_int (int signo){
    printf("中断\n%%");
}
