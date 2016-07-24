#include "sort.h"


void main()
{	
	UINT32 uiArrayData[] = {1, 98,0,98,54,76,33,21,12,53};

	(VOID)Agent_Straight_Insertion(uiArrayData,sizeof(uiArrayData)/sizeof((uiArrayData[0])));
	(VOID)Agent_Shell_Sort(uiArrayData,sizeof(uiArrayData)/sizeof((uiArrayData[0])));
	

}

UINT32 Agent_Straight_Insertion(UINT32 array[], UINT32 length)
{	
	UINT32 uiTempData = 0;
	INT32 i,j;
	i = j =0;

	printf("after straight sort \r\n");

	for (i = 1; i <= length-1; i++)
	{	
		if (array[i] < array[i-1])
		{	
		    uiTempData = array[i];
			
			for (j = i - 1; j >= 0;j--)
			{
				if (uiTempData >= array[j])
				{
					break; 
				}
				else
				{
					array[j+1] = array[j]; 	
				}
			}

		    array[j+1] = uiTempData;
			
		}

	
		
	}
	
	DisPlayArrayData(array,length);
	
	printf("\r\n");
	
	return VOS_OK;
}

UINT32 Agent_Shell_Sort(UINT32 array[], UINT32 length)
{
	INT32 uiGap = 0;
	INT32 i,j;

	UINT32 uiTempData = 0;
	
	
	printf("after Shell_Sort  \r\n");
	
	for (uiGap = length/2; uiGap > 0; uiGap = uiGap/2)
	{
		for (i = uiGap; i < length; i++)
		{   
			if (array[i] < array[i-uiGap])
			{
				uiTempData = array[i];

				for (j = i-uiGap; (j >= 0)&&(uiTempData < array[j]);j= j-uiGap)
				{
					array[j+uiGap] = array[j]; 		
				}

				array[j+uiGap] = uiTempData;
					
			}
			
		}
	}

	DisPlayArrayData(array,length);
	
	printf("\r\n");
	
	return VOS_OK;

}


VOID DisPlayArrayData(UINT32 array[], UINT32 length)
{
	UINT32 uiLoop = 0;

	for (uiLoop = 0; uiLoop <= length-1; uiLoop++)
	{
		printf("%5d ",array[uiLoop]);
		if (uiLoop == 4)
		{
			printf("\r\n");
		}
	}
}

