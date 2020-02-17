#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{  pid_t outcome;  
/* fork a child process */  
outcome = fork();  
if (outcome < 0) 
{ /* error occurred */    
fprintf(stderr, "Fork Failed\n");    
return 1;  }  
if (outcome == 0) 
{ /* child process */    
execlp("/bin/ls", "ls", NULL);  
}  
else 
{ /* parent process */    
wait(NULL);    
fork();
fork();
printf("Child process complete\n");  
}  
return 0;
}