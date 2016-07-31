#include "data_process.h"


StudentInfo_ST* g_puiHeadInfo = NULL;

int main()
{	
	UINT32 uiInput = 0;
	UINT32 uiOverFalg = 0;
	
	DisplayWelcomeWindow();
	DisplaySelectWindow();

	DataInit();
	

	while(1)
	{
		scanf("%d",&uiInput);
		
		switch(uiInput)
		{
			case 1:
				Agent_ProcessInputData(g_puiHeadInfo);				
				break;
				
			case 2:
				Agent_ProcessDisplayData(g_puiHeadInfo);
				break;
			case 3:
				Agent_ProcessDeleteData(g_puiHeadInfo);
				break;
			case 4:
				break;
			case 5:
				Agent_ProcessSortData(g_puiHeadInfo);
				break;
			case 6:
				Agent_Process_GoodBye(g_puiHeadInfo);
				uiOverFalg = 1;
				break;
			default:

				printf("illegal input!");
					
		}

		if (uiOverFalg == 1)
		{
			break;
		}
	
		DisplaySelectWindow();
		
	}


	
	
	return VOS_OK;
	
}


VOID DisplayWelcomeWindow()
{
	printf("/************Welcome to my student system ***************/ \r\n\r\n");
	
}

VOID DisplayByeWindow()
{
	printf("see you next time \r\n");
	
}

VOID DisplaySelectWindow()
{
	printf("\r\n\r\nwhat do you want to do \r\n");

	printf("1、logging studentinfo \r\n");

	printf("2、display studentinfo  \r\n");

	printf("3、delete studentinfo\r\n");
	
	printf("4、undpate studendinfo \r\n");

	printf("5、sort studentinfo \r\n");

	printf("6、quit \r\n\r\n");
	
}


VOID DataInit()
{
	g_puiHeadInfo = InitListHeadInfo();
	
}


UINT32 Agent_ProcessInputData(StudentInfo_ST* puiHeadInfo)
{   
	StudentInfo_ST stTempNodeInfo = { 0 };

	StudentInfo_ST *ptr = NULL;
	
	printf("Please input the id of student:\r\n");
	scanf("%d",&stTempNodeInfo.uiIdNumber);
	
	printf("Please input the age of student:\r\n");
	scanf("%d",&stTempNodeInfo.uiAge);
	

	printf("Please input the name of student:\r\n");
	scanf("%s",stTempNodeInfo.ucName);

	ptr = InSertListInfo(puiHeadInfo,&stTempNodeInfo);

	if (ptr == NULL)
	{
		printf("InserListInfo Failed!\r\n");
		return VOS_ERROR;
	}
	else
	{
		printf("InserListInfo success!\r\n\r\n");		
	}
	
	return VOS_OK;

}

UINT32 Agent_ProcessDisplayData(StudentInfo_ST* puiHeadInfo)
{   
	DisplayListInfoAll(puiHeadInfo);
	
	return VOS_OK;
}

UINT32 Agent_ProcessDeleteData(StudentInfo_ST* puiHeadInfo)
{
	DeleteListInfoByIdNum(puiHeadInfo);
	return VOS_OK;
}

UINT32 Agent_ProcessSortData(StudentInfo_ST* puiHeadInfo)
{	
	UINT32 uiSortMode = 0;
	
	printf("please input sort mode 0:by id  1: by age \r\n");

	scanf("%d",&uiSortMode);
	
	if (uiSortMode == 0)
	{
		SortListInfoById(puiHeadInfo);
	}
	
	return VOS_OK;
}
UINT32 Agent_Process_GoodBye(StudentInfo_ST* puiHeadInfo)
{
	DisplayByeWindow();
	
	return VOS_OK;
}


