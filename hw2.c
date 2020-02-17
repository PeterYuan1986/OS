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
printf("outcome==0 process\n");  
outcome =fork();
if(outcome==0){printf("outcome==00 process\n");
else {printf("nest parent process\n")}
}  
else 
{ /* parent process */    
wait(NULL);    
fork();
printf("Child process complete\n");  
}  
return 0;
}