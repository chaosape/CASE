#ifndef __TB_AADL_AssignmentTreeBranchBoundService_types__H
#define __TB_AADL_AssignmentTreeBranchBoundService_types__H

#include <tb_uxas_processor_types.h>

/**************************************************************************
  Copyright (c) 2013-2016 Rockwell Collins and the University of
  Minnesota. Developed with the sponsorship of the Defense Advanced
  Research Projects Agency (DARPA).

  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this data, including any software or models
  in source or binary form, as well as any drawings,
  specifications, and documentation (collectively "the Data"), to
  deal in the Data without restriction, including without
  limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Data, and to
  permit persons to whom the Data is furnished to do so, subject to
  the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Data.

  THE DATA IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, SPONSORS,
  DEVELOPERS, CONTRIBUTORS, OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE DATA OR THE USE OR OTHER DEALINGS IN THE
  DATA.
 **************************************************************************/

/**************************************************************************

  ***AUTOGENERATED CODE: DO NOT MODIFY***

This header section contains the AADL gluecode interfaces used by the
client for the thread implementations.

 **************************************************************************/


// reader prototype for tb_TaskPlanOptions_in
bool tb_TaskPlanOptions_in_dequeue(UXTASK__TaskPlanOptions_i * tb_TaskPlanOptions_in);
 // reader prototype for tb_AssignmentCostMatrix_in
bool tb_AssignmentCostMatrix_in_dequeue(UXTASK__AssignmentCostMatrix_i * tb_AssignmentCostMatrix_in);
 // reader prototype for tb_UniqueAutomationRequest_in
bool tb_UniqueAutomationRequest_in_dequeue(UXTASK__UniqueAutomationRequest_i * tb_UniqueAutomationRequest_in);
 bool tb_ServiceStatus_out_enqueue(const CMASI__ServiceStatus_i * tb_ServiceStatus_out);
 bool tb_TaskAssignmentSummary_out_enqueue(const UXTASK__TaskAssignmentSummary_i * tb_TaskAssignmentSummary_out);
 

//////////////////////////////////////////////////////////////////////////
//
// Note: thread is declared EXTERNAL; user should provide run() function.
//
//////////////////////////////////////////////////////////////////////////

#endif // __TB_AADL_AssignmentTreeBranchBoundService_types__H