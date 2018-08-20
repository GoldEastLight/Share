
#ifndef _LDW_WARNING_H_
#define _LDW_WARNING_H_


#include "adas_wonder.h"

#include "kalman_car_results.h"

extern LineFunc lineWarningLf;
extern LineFunc lineWarningRt;

extern LineFunc lineWorldWarningLf;
extern LineFunc lineWorldWarningRt;

extern PSModuleResults pLDWCombinedResults;

extern signed char indexLineCarLDW[];

// for lib;

extern signed char m_linelf_flagwarning;
extern signed char m_linert_flagwarning;

extern Uint8	m_ldtWarningLevel;
extern int		m_iNearestMark;
extern Bool		b_lane_width_ok;


void LDW_WarningInit();

void ldtWarningKalman( sAdaptSetPara LDWsetPara, VEHICLESTATUS *VehicleStatus, int iPos, float fOri,
	Bool bTrust,
	Bool bCrossMark, unsigned char iMeasureResultCode,
	signed char *FlagLeft, signed char *FlagRight,
	Bool LfLaneType, Bool RtLaneType);




#endif