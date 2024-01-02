#include <sys/types.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    pid_t pid;
    int status;

    pid = fork ();
    if( pid != 0)
    {
        while(pid != wait(&status));
    }

    else
    {
        sleep(5);
        exit(5);
    }

    pid = fork();
    if(pid != 0)
    {
        while(pid != wait(&status));
    }

    else
    {
        sleep(1);
        exit(1);
    }

}