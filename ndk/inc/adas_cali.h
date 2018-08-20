

#ifndef _ADAS_CALI_H_
#define _ADAS_CALI_H_

#include "adas_wonder.h"

#ifndef __linux
#ifdef DLL_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
	#define DLLEXPORT
#endif


DLLEXPORT int ADASAutoCaliInit();

DLLEXPORT int  ADASAutoCaliProcess(VEHICLESTATUS vehStatus, const OutInfoLDW* libOutInfoLDW, const OutInfoFCW *libInfoFcw);

DLLEXPORT int ADASAutoCaliGetInfo();



#endif
