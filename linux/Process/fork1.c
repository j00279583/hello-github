#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

	pid_t pid;
	pid_t child_pid;
	int status;

	pid = fork();

	if(pid == 0)
	{
		printf("hello, this is child \r\n");
	}
	else if(pid > 0)
	{
		child_pid = wait(&status);
		
		printf("hello, this is parent, the child pid is = 0x%x\r\n",child_pid);
	}
	else if(pid == -1)
	{
		printf("fork failed \r\n");
	}
	
	exit(0);
}
