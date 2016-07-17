#include "agent_common.h"

#define NAME_MAX_LENGTH 20

typedef struct Tag_StudentInfo
{
	UINT32 uiIdNumber;
	UINT32 uiAge;
	UCHAR ucName[NAME_MAX_LENGTH];
	
	struct Tag_StudentInfo *pNext;
	
}StudentInfo_ST;


#define CHECK_PTR1(ptr1)  \
if ((ptr1) == NULL) \
{                      \
printf("THE POINTER IS ILLEGEAL"); \
return NULL;            \
}


#define CHECK_PTR2(ptr1, ptr2)  \
if (((ptr1) == NULL) || ((ptr2)== NULL)) \
{  \
printf("THE POINTER IS ILLEGEAL"); \
return NULL; \
}

/*º¯ÊýÉùÃ÷ÇøÓò*/

StudentInfo_ST* InitListHeadInfo();
StudentInfo_ST* InSertListInfo(StudentInfo_ST* pstListHeadNode,StudentInfo_ST *pstNodeInfo);
StudentInfo_ST* DisplayListInfoAll(StudentInfo_ST* pstListHeadNode);
StudentInfo_ST* DeleteListInfoByIdNum(StudentInfo_ST* pstListHeadNode);
StudentInfo_ST *SortListInfoById(StudentInfo_ST *pstListHeadNode);





VOID DisplayMallocFailed();
