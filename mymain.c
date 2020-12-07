#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t pid;
     srandom(1);
     pid = fork();
     if (pid == 0) 
          ChildProcess();
     else {
          pid_t pid2 = fork();
          if (pid2 == 0) {
            ChildProcess();
          } else {
            ParentProcess();
          }
     }
}

void  ChildProcess(void)
{
     int   i;
     for (i = 1; i <= random() % 31; i++)
          printf("Child Pid: %d is going to sleep!", getpid());
          printf("\n");
          sleep(random() % 11);
          printf("Child Pid: %d is awake!", getpid());
          printf("\n");
          printf("Where is my Parent: %d?", getppid());
          printf("\n");
     exit(0);
}

void  ParentProcess(void)
{
     pid_t childpid1 = wait(NULL);
     printf("Child Pid: %d has completed\n", childpid1);
     
     pid_t childpid2 = wait(NULL);
     printf("Child Pid: %d has completed\n", childpid2);
     
}
