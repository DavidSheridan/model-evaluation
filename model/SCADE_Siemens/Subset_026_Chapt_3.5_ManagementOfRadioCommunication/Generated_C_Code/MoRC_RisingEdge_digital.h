/* $*************** KCG Version 6.1.3 (build i6) ****************
** Command: s2c613 -config S:/SDVAL_RAMS/F�rderprojekte/openETCS/section/030_System/Components/OBU/S026_3_C3_5_ManagementOfRadioCommuniction/MoRC/KCG\kcg_s2c_config.txt
** Generation date: 2013-08-01T09:52:21
*************************************************************$ */
#ifndef _MoRC_RisingEdge_digital_H_
#define _MoRC_RisingEdge_digital_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_bool /* digital::RisingEdge::RE_Output */ RE_Output;
  /* -----------------------  no local probes  ----------------------- */
  /* -------------------- initialization variables  ------------------ */
  kcg_bool init;
  /* ----------------------- local memories  ------------------------- */
  kcg_bool /* digital::RisingEdge::RE_Input */ rem_RE_Input;
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
} MoRC_outC_RisingEdge_digital;

/* ===========  node initialization and cycle functions  =========== */
/* digital::RisingEdge */
extern void MoRC_RisingEdge_digital(
  /* digital::RisingEdge::RE_Input */kcg_bool RE_Input,
  MoRC_outC_RisingEdge_digital *outC);

extern void MoRC_RisingEdge_reset_digital(MoRC_outC_RisingEdge_digital *outC);

#endif /* _MoRC_RisingEdge_digital_H_ */
/* $*************** KCG Version 6.1.3 (build i6) ****************
** MoRC_RisingEdge_digital.h
** Generation date: 2013-08-01T09:52:21
*************************************************************$ */

