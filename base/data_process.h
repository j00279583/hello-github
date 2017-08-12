#include "list.h"

VOID DataInit();
VOID DisplayWelcomeWindow();
VOID DisplayByeWindow();
VOID DisplaySelectWindow();

UINT32 Agent_Process_GoodBye(StudentInfo_ST* puiHeadInfo);
UINT32 Agent_ProcessInputData(StudentInfo_ST* puiHeadInfo);
UINT32 Agent_ProcessDisplayData(StudentInfo_ST* puiHeadInfo);
UINT32 Agent_ProcessDeleteData(StudentInfo_ST* puiHeadInfo);
UINT32 Agent_ProcessSortData(StudentInfo_ST* puiHeadInfo);


