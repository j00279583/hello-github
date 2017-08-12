#include "list.h"

StudentInfo_ST* InitListHeadInfo()
{
	StudentInfo_ST* pstHeadNode = NULL;
	pstHeadNode = (StudentInfo_ST*)malloc(sizeof(StudentInfo_ST));
	if (pstHeadNode == NULL)
	{	
		DisplayMallocFailed();
		
		return NULL;
	}

	pstHeadNode->pNext = NULL;
	return pstHeadNode;
}

StudentInfo_ST* InSertListInfo(StudentInfo_ST* pstListHeadNode,StudentInfo_ST *pstNodeInfo)
{   
	StudentInfo_ST *pTempHead = NULL;
	StudentInfo_ST *pTempNodeInfo = NULL;
	StudentInfo_ST *pNewNode = NULL;
	
	CHECK_PTR2(pstListHeadNode,pstNodeInfo);

	pTempNodeInfo = pTempHead = pstListHeadNode;

	while(pTempHead->pNext != NULL)
	{
		pTempNodeInfo = pTempHead->pNext;
		pTempHead = pTempHead->pNext;
	}

	pNewNode = (StudentInfo_ST *)malloc(sizeof(StudentInfo_ST));
	if (pNewNode == NULL)
	{	
		DisplayMallocFailed();
		return NULL;
	}
	
	pNewNode->uiIdNumber = pstNodeInfo->uiIdNumber;
	pNewNode->uiAge = pstNodeInfo->uiAge;
	memcpy(pNewNode->ucName,pstNodeInfo->ucName,20);

	pTempNodeInfo->pNext = pNewNode;
	pNewNode->pNext = NULL;
	
	return pstListHeadNode;
}

StudentInfo_ST* DisplayListInfoAll(StudentInfo_ST* pstListHeadNode)
{

	StudentInfo_ST *pstTempHeadNode = NULL;
	CHECK_PTR1(pstListHeadNode);
	pstTempHeadNode = pstListHeadNode->pNext;
	
	while(pstTempHeadNode)
	{	
		printf("the id of student is = %d:\r\n",pstTempHeadNode->uiIdNumber);
		printf("the age of student is = %d:\r\n",pstTempHeadNode->uiAge);
		printf("the id of name is = %s:\r\n",pstTempHeadNode->ucName);
		
		pstTempHeadNode = pstTempHeadNode->pNext;
	}
	
	return pstListHeadNode;
}

StudentInfo_ST* DeleteListInfoByIdNum(StudentInfo_ST* pstListHeadNode)
{	
	UINT32 uiDeleteId = 0;
	UINT32 uiFindFlag = 0;
	
	StudentInfo_ST *pstTempHeadNode = NULL;
	StudentInfo_ST *pstTempLastNode = NULL;
	StudentInfo_ST *pstTempNode = NULL;
	CHECK_PTR1(pstListHeadNode);
	pstTempLastNode = pstListHeadNode;
	pstTempHeadNode = pstListHeadNode->pNext;


	printf("Please input the id you want delete \r\n");

	scanf("%d",&uiDeleteId);

	while(pstTempHeadNode != NULL)
	{	
		pstTempNode = pstTempHeadNode;
		if (pstTempNode->uiIdNumber == uiDeleteId)
		{	
			uiFindFlag = 1;
			break;
		}
		
		pstTempLastNode = pstTempNode;
		pstTempHeadNode = pstTempHeadNode->pNext;
	}

	if(uiFindFlag == 1)
	{	
		pstTempLastNode->pNext = pstTempHeadNode->pNext;
		free(pstTempHeadNode);
		
		printf("delete success \r\n");	
	}
	else
	{
		printf("sorry, not find this id \r\n");
	}

	return pstListHeadNode;
			
}

StudentInfo_ST *SortListInfoById(StudentInfo_ST *pstListHeadNode)
{
	StudentInfo_ST *pstTempNode1 = NULL;
	StudentInfo_ST *pstTempNode2 = NULL;
	StudentInfo_ST stTempNdoeInfo = {0};
	
	CHECK_PTR1(pstListHeadNode);

	for (pstTempNode1 = pstListHeadNode->pNext; pstTempNode1 != NULL ;pstTempNode1 = pstTempNode1->pNext)
	{
		for(pstTempNode2 = pstTempNode1 ->pNext;pstTempNode2 != NULL ;pstTempNode2 = pstTempNode2->pNext)
		{	
			if (pstTempNode2->uiIdNumber < pstTempNode1->uiIdNumber)
			{
				stTempNdoeInfo.uiAge = pstTempNode2->uiAge;
				stTempNdoeInfo.uiIdNumber = pstTempNode2->uiIdNumber;
				memcpy(stTempNdoeInfo.ucName,pstTempNode2->ucName,20);

				pstTempNode2->uiAge = pstTempNode1->uiAge;
				pstTempNode2->uiIdNumber = pstTempNode1->uiIdNumber;
				memcpy(pstTempNode2->ucName ,pstTempNode1->ucName, 20);

				pstTempNode1->uiAge = stTempNdoeInfo.uiAge;
				pstTempNode1->uiIdNumber = stTempNdoeInfo.uiIdNumber;
				memcpy(pstTempNode1->ucName ,stTempNdoeInfo.ucName,20);
			}
			
		}
	}
	
	DisplayListInfoAll(pstListHeadNode);
		
	return pstListHeadNode;
}

VOID DisplayMallocFailed()
{

	printf("malloc failed line is = %d",__LINE__);
	
}
