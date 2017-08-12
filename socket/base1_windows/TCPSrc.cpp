#include <WINSOCK2.H>
#include <stdio.h>

void main()
{
	WORD wVersionRequested;
	WSADATA wsadata;
	int Error;
    SOCKET sockConnet;

	
	wVersionRequested = MAKEWORD(1,1);
	Error = WSAStartup(wVersionRequested,&wsadata);
    if (Error != 0)
	{
		return ;
	}
    
	/*�����׽��� on 2015-8-23*/
	SOCKET sockSrc = socket(AF_INET,SOCK_STREAM,0);
	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	/*���׽���*/
	bind(sockSrc,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));

	//���׽�������Ϊ����ģʽ
	listen(sockSrc,5);

	SOCKADDR_IN addrClient;
	int addlen = sizeof(SOCKADDR);


	sockConnet =accept(sockSrc,(SOCKADDR*)&addrClient,&addlen);
	char sendBuf[100];
	sprintf(sendBuf,"welcome %s to meimei world",inet_ntoa(addrClient.sin_addr));
	send(sockConnet,sendBuf,strlen(sendBuf)+1,0);
	
	char recvBuf[100];
	recv(sockConnet,recvBuf,100,0);
	printf("%s",recvBuf);

	printf("\r\nplease input the data: \r\n");

	while (1)
	{
		if ((recvBuf[0] == 'q') || (recvBuf[0] == 'Q'))
		{
			printf("Client say bye bye! \r\n");	
			getchar();
			break;
		}

		printf("meimei say: ");
		gets(sendBuf);
		send(sockConnet,sendBuf,strlen(sendBuf)+1,0);

		recv(sockConnet,recvBuf,100,0);
	    printf("Client say: ");
		printf("%s \r\n",recvBuf);
			
	}

	closesocket(sockConnet);	
	WSACleanup();

}