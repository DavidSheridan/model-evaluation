/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config Q:/openETCS/section/030_System/Components/OBU/S026_3_C3_5_ManagementOfRadioCommuniction/MoRC_System/MoRC_System_impl/KCG\kcg_s2c_config.txt
** Generation date: 2013-09-12T13:41:00
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "evaluateOrderToContactAnRBD.h"

void evaluateOrderToContactAnRBD_reset(outC_evaluateOrderToContactAnRBD *outC)
{
  outC->init = kcg_true;
  /* 1 */ FallingEdge_reset_digital(&outC->Context_1);
}

/** Subset 096, REQ 3.5.3.13, 3.5.3.16, 3.5.3.13.1, 3.5.3.14, 3.5.3.15: */
/** Evaluates the order to contact a RBC, i. e. establish, maintain or terminate a communication session. */
/** "Remark_1" {Description = "- Name: evaluateOrderToContactAnRBD - Description: Evaluates the orders to establish, maintain or terminate a communication session - Copyright Siemens AG, 2013 - Licensed under the EUPL V.1.1 ( http://joinup.ec.europa.eu/software/page/eupl/licence-eupl ) - Gist URL: --- - Cryptography: No - Author(s): Uwe Steinke  The use of this software is limited to non-vital applications.  It has not been developed for vital operation purposes and must not be used for applications which may cause harm to people, physical accidents or financial loss.  THEREFORE, NO LIABILITY WILL BE GIVEN FOR SUCH AND ANY OHER KIND OF USE."} */
/* evaluateOrderToContactAnRBD */
void evaluateOrderToContactAnRBD(
  /* evaluateOrderToContactAnRBD::order_in */orderToContactAnRBC_Type *order_in,
  /* evaluateOrderToContactAnRBD::onBoardStoredShortPhoneNo */rbc_phoneNo_Type onBoardStoredShortPhoneNo,
  outC_evaluateOrderToContactAnRBD *outC)
{
  /* evaluateOrderToContactAnRBD::_L35 */ orderToContactAnRBC_Type _L35;
  
  /* 1 */
  FallingEdge_digital(
    (kcg_bool)
      ((*order_in).valid & ((*order_in).rbc_id != cRBC_id_contactLastKnownRBC) &
        ((*order_in).telephoneNoOfTheRBC !=
          cRBC_phoneNo_UseOnboardStoredShortNo)),
    &outC->Context_1);
  if (outC->Context_1.FE_Output) {
    if (outC->init) {
      kcg_copy_orderToContactAnRBC_Type(
        &outC->_L16,
        (orderToContactAnRBC_Type *) &cInvalidOrderToContactAnRBC);
    }
    else {
      kcg_copy_orderToContactAnRBC_Type(&outC->_L16, &outC->rem_order_in);
    }
  }
  else if (outC->init) {
    kcg_copy_orderToContactAnRBC_Type(
      &outC->_L16,
      (orderToContactAnRBC_Type *) &cInvalidOrderToContactAnRBC);
  }
  if ((cRBC_id_contactLastKnownRBC == (*order_in).rbc_id) & (*order_in).valid) {
    kcg_copy_orderToContactAnRBC_Type(&_L35, &outC->_L16);
  }
  else {
    kcg_copy_orderToContactAnRBC_Type(&_L35, order_in);
  }
  kcg_copy_orderToContactAnRBC_Type(&outC->order_out, &_L35);
  if (_L35.telephoneNoOfTheRBC == cRBC_phoneNo_UseOnboardStoredShortNo) {
    outC->order_out.telephoneNoOfTheRBC = onBoardStoredShortPhoneNo;
  }
  else {
    outC->order_out.telephoneNoOfTheRBC = _L35.telephoneNoOfTheRBC;
  }
  kcg_copy_orderToContactAnRBC_Type(&outC->rem_order_in, order_in);
  outC->init = kcg_false;
}

/* $*************** KCG Version 6.1.3 (build i6) ****************
** evaluateOrderToContactAnRBD.c
** Generation date: 2013-09-12T13:41:00
*************************************************************$ */

