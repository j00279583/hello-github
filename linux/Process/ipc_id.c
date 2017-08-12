#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
	int i = 0;
	int key = 0;
	
	key = ftok("/jin/process_linux",i);
	printf("key is = %d",key);
}
