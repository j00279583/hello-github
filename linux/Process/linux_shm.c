#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main()
{
	int i = 0;
	int key = 0;
	pid_t pid = 0;
	pid_t child_pid = 0;
	int status = 0;
	int shmid = 0;
	char *pchTemp = NULL;
	char *pchGetTemp = NULL;
	
	key = ftok("/jin/process_linux",i);
	if (key == -1)
	{
		printf("ftok failed \r\n");
	}

	pid = fork();
	if (pid == 0)
	{
		
		shmid = shmget(key,4096,IPC_CREAT|0600);
		if (shmid == -1)
		{
			printf(" child shmget failed\r\n");
			exit(1);
		}
		
	pchTemp = (char*)shmat(shmid, NULL,0);
	
	memcpy(pchTemp,"hello,linux for shm method,child process wite and parent read!",100);
	
	shmdt(pchTemp);
	exit(0);
	
	}
	else if (pid > 0)
	{	
		
		child_pid = wait(&status);

		shmid = shmget(key,4096,IPC_CREAT|0600);
		if (shmid == -1)
		{
			printf("Parent shmget failed\r\n");
			exit(1);
		}
		
		pchGetTemp = (char*)shmat(shmid, NULL,0);
		printf("%s\r\n",pchGetTemp);
		shmdt(pchGetTemp);
		shmctl(shmid,IPC_RMID,NULL);
	}	
	else if (pid == -1)
	{
		printf("fork failed\r\n");
		exit(1);
	}
		
	exit(0);
}
