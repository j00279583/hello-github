#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

	pid_t pid;

	pid = fork();

	if(pid == 0)
	{
		printf("hello, this is child \r\n");
	}
	else if(pid > 0)
	{
		printf("hello, this is parent\r\n");
	}
	else if(pid == -1)
	{
		printf("fork failed \r\n");
	}
	
	exit(0);
}
