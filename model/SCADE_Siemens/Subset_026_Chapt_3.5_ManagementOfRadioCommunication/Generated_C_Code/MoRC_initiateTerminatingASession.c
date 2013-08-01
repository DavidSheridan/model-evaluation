/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config S:/SDVAL_RAMS/F�rderprojekte/openETCS/section/030_System/Components/OBU/S026_3_C3_5_ManagementOfRadioCommuniction/MoRC/KCG\kcg_s2c_config.txt
** Generation date: 2013-08-01T09:52:22
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "MoRC_initiateTerminatingASession.h"

void MoRC_initiateTerminatingASession_reset(
  MoRC_outC_initiateTerminatingASession *outC)
{
  outC->init = kcg_true;
  /* 1 */ MoRC_waitAndRepeatTimer_reset(&outC->Context_1);
}

/** Subset 096, REQ 3.5.5.1 */
/** Initiates and processes the termination of a communication session. */
/** "Remark_1" {Description = "- Name: initiateTerminatingASession - Description: Initiates and processes the termination of a communication session.  - Copyright Siemens AG, 2013 - Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl ) - Gist URL: --- - Cryptography: No - Author(s): Uwe Steinke  The use of this software is limited to non-vital applications.  It has not been developed for vital operation purposes and must not be used for applications which may cause harm to people, physical accidents or financial loss.  THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OHER KIND OF USE."} */
/* initiateTerminatingASession */
void MoRC_initiateTerminatingASession(
  /* initiateTerminatingASession::orderReceivedFromTrackside */MoRC_orderToContactAnRBC_Type *orderReceivedFromTrackside,
  /* initiateTerminatingASession::errorConditionRequiringTerminationDetected */kcg_bool errorConditionRequiringTerminationDetected,
  /* initiateTerminatingASession::trainIsRejectedByRBC_duringStartOfMission */kcg_bool trainIsRejectedByRBC_duringStartOfMission,
  /* initiateTerminatingASession::driverClosesTheDeskduringStartOfMission */kcg_bool driverClosesTheDeskduringStartOfMission,
  /* initiateTerminatingASession::trainExitedFromAnRBCArea */kcg_bool trainExitedFromAnRBCArea,
  /* initiateTerminatingASession::receivedOrderToTerminateTheSession */MoRC_orderToContactAnRBC_Type *receivedOrderToTerminateTheSession,
  /* initiateTerminatingASession::actualTime */MoRC_time_Type actualTime,
  /* initiateTerminatingASession::isInCommunicationSessionWithAnRIU */kcg_bool isInCommunicationSessionWithAnRIU,
  /* initiateTerminatingASession::level_1_isLeft */kcg_bool level_1_isLeft,
  /* initiateTerminatingASession::endOfMissionIsExecuted */kcg_bool endOfMissionIsExecuted,
  MoRC_outC_initiateTerminatingASession *outC)
{
  MoRC_SSM_TR_TrainExitedFromRBCArea_SM tmp1;
  kcg_bool tmp;
  /* initiateTerminatingASession::TrainExitedFromRBCArea_SM::WaitForOrderToTerminateTheSession */ kcg_bool WaitForOrderToTerminateTheSession_weakb_clock_TrainExitedFromRBCArea_SM;
  /* initiateTerminatingASession::TrainExitedFromRBCArea_SM */ MoRC_SSM_ST_TrainExitedFromRBCArea_SM TrainExitedFromRBCArea_SM_state_sel;
  /* initiateTerminatingASession::TrainExitedFromRBCArea_SM */ MoRC_SSM_ST_TrainExitedFromRBCArea_SM TrainExitedFromRBCArea_SM_state_act;
  /* initiateTerminatingASession::TrainExitedFromRBCArea_SM */ kcg_bool TrainExitedFromRBCArea_SM_reset_act;
  
  tmp = (*receivedOrderToTerminateTheSession).valid &&
    (*receivedOrderToTerminateTheSession).actionToBePerformed ==
    MoRC_morc_rbca_terminateSesssion;
  if (outC->init) {
    outC->init = kcg_false;
    TrainExitedFromRBCArea_SM_state_sel =
      MoRC_SSM_st_Idle_TrainExitedFromRBCArea_SM;
  }
  else {
    TrainExitedFromRBCArea_SM_state_sel =
      outC->TrainExitedFromRBCArea_SM_state_nxt;
  }
  switch (TrainExitedFromRBCArea_SM_state_sel) {
    case MoRC_SSM_st_WaitForOrderToTerminateTheSession_TrainExitedFromRBCArea_SM :
      if (tmp) {
        TrainExitedFromRBCArea_SM_state_act =
          MoRC_SSM_st_Idle_TrainExitedFromRBCArea_SM;
      }
      else {
        TrainExitedFromRBCArea_SM_state_act =
          MoRC_SSM_st_WaitForOrderToTerminateTheSession_TrainExitedFromRBCArea_SM;
      }
      TrainExitedFromRBCArea_SM_reset_act = tmp;
      break;
    case MoRC_SSM_st_Idle_TrainExitedFromRBCArea_SM :
      if (trainExitedFromAnRBCArea) {
        TrainExitedFromRBCArea_SM_state_act =
          MoRC_SSM_st_WaitForOrderToTerminateTheSession_TrainExitedFromRBCArea_SM;
      }
      else {
        TrainExitedFromRBCArea_SM_state_act =
          MoRC_SSM_st_Idle_TrainExitedFromRBCArea_SM;
      }
      TrainExitedFromRBCArea_SM_reset_act = trainExitedFromAnRBCArea;
      break;
    
  }
  switch (TrainExitedFromRBCArea_SM_state_act) {
    case MoRC_SSM_st_WaitForOrderToTerminateTheSession_TrainExitedFromRBCArea_SM :
      switch (TrainExitedFromRBCArea_SM_state_sel) {
        case MoRC_SSM_st_Idle_TrainExitedFromRBCArea_SM :
          if (trainExitedFromAnRBCArea) {
            tmp1 = MoRC_SSM_TR_Idle_1_TrainExitedFromRBCArea_SM;
          }
          else {
            tmp1 = MoRC_SSM_TR_no_trans_TrainExitedFromRBCArea_SM;
          }
          break;
        case MoRC_SSM_st_WaitForOrderToTerminateTheSession_TrainExitedFromRBCArea_SM :
          if (tmp) {
            tmp1 =
              MoRC_SSM_TR_WaitForOrderToTerminateTheSession_1_TrainExitedFromRBCArea_SM;
          }
          else {
            tmp1 = MoRC_SSM_TR_no_trans_TrainExitedFromRBCArea_SM;
          }
          break;
        
      }
      WaitForOrderToTerminateTheSession_weakb_clock_TrainExitedFromRBCArea_SM =
        tmp1 != MoRC_SSM_TR_no_trans_TrainExitedFromRBCArea_SM;
      if (TrainExitedFromRBCArea_SM_reset_act) {
        /* 1 */ MoRC_waitAndRepeatTimer_reset(&outC->Context_1);
      }
      /* 1 */
      MoRC_waitAndRepeatTimer(
        actualTime,
        kcg_false,
        kcg_false,
        MoRC_cPositionReportRepetitionInterval,
        MoRC_cPositionReoport_MaxNoOfRepetitions,
        &outC->Context_1);
      if (WaitForOrderToTerminateTheSession_weakb_clock_TrainExitedFromRBCArea_SM) {
        tmp = kcg_false;
        outC->TrainExitedFromRBCArea_SM_state_nxt =
          MoRC_SSM_st_WaitForOrderToTerminateTheSession_TrainExitedFromRBCArea_SM;
      }
      else if (outC->Context_1.elapsed) {
        tmp = kcg_true;
        outC->TrainExitedFromRBCArea_SM_state_nxt =
          MoRC_SSM_st_Idle_TrainExitedFromRBCArea_SM;
      }
      else {
        tmp = kcg_false;
        outC->TrainExitedFromRBCArea_SM_state_nxt =
          MoRC_SSM_st_WaitForOrderToTerminateTheSession_TrainExitedFromRBCArea_SM;
      }
      outC->sendAPositionReport = outC->Context_1.triggerAction;
      break;
    case MoRC_SSM_st_Idle_TrainExitedFromRBCArea_SM :
      tmp = kcg_false;
      outC->TrainExitedFromRBCArea_SM_state_nxt =
        MoRC_SSM_st_Idle_TrainExitedFromRBCArea_SM;
      outC->sendAPositionReport = kcg_false;
      break;
    
  }
  outC->initiateTermination = ((*orderReceivedFromTrackside).valid &&
      (*orderReceivedFromTrackside).actionToBePerformed ==
      MoRC_morc_rbca_terminateSesssion) ||
    errorConditionRequiringTerminationDetected ||
    trainIsRejectedByRBC_duringStartOfMission ||
    driverClosesTheDeskduringStartOfMission || tmp || ((level_1_isLeft &&
        isInCommunicationSessionWithAnRIU) ||
      (isInCommunicationSessionWithAnRIU && endOfMissionIsExecuted));
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** MoRC_initiateTerminatingASession.c
** Generation date: 2013-08-01T09:52:22
*************************************************************$ */

