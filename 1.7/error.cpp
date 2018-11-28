#include<errno.h>
#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    fprintf(stderr,"EACCES: %s\n",strerror(EACCES));

    errno = ENOENT;
    /*
    将程序名作为参数传递给perror，是一个标准的UNIX惯例。
    使用这种方法，在程序作为管道的一部分时，例如：
    prog1 < input_file | prog2 | prog3 > output_file
    我们就能分清3个程序中哪一个产生了一条特定的出错消息
    */
    perror(argv[0]);
    return 0;
}
