#include <WINSOCK2.H>
#include <stdio.h>

void main()
{
	WORD wVersionRequested;
	WSADATA wsadata;
	int Error;

	int uiRet = 0;
	
	wVersionRequested = MAKEWORD(1,1);
	Error = WSAStartup(wVersionRequested,&wsadata);
    if (Error != 0)
	{
		return ;
	}
    
	/*创建套接字 on 2015-8-23*/
	SOCKET sockClient = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrClient;
	addrClient.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrClient.sin_family = AF_INET;
	addrClient.sin_port = htons(6000);
	
    /*向服务器发出请求*/
	connect(sockClient,(SOCKADDR*)&addrClient,sizeof(SOCKADDR));

	char RecBuf[100];
	char sendBuf[100];
	recv(sockClient,RecBuf,100,0);
	printf("%s",RecBuf);
	
	send(sockClient,"this is agent_jin come in",strlen("this is agent_jin come in")+1,0);
    printf("\r\nplease input the data: \r\n");

	while(1)
	{	
		if ((RecBuf[0] == 'q') || (RecBuf[0] == 'Q'))
		{
			printf("Server say bye bye! \r\n");	
			getchar();
			break;
		}
		
		if ( recv(sockClient,RecBuf,100,0))
		{
			printf("Server say: ");
			printf("%s \r\n",RecBuf);
		}

		printf("agent say: ");
		gets(sendBuf);
		send(sockClient,sendBuf,strlen(sendBuf)+1,0);
		
	}
	
	closesocket(sockClient);
	WSACleanup();
	
}