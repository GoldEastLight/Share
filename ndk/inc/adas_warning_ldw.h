

#ifndef _ADAS_WARNING_LDW_H_
#define _ADAS_WARNING_LDW_H_

#ifndef __linux
#ifdef DLL_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
#define DLLEXPORT 
#endif
#include "adas_wonder.h"
#include "kalman_car_results.h"

DLLEXPORT int ADASLdwWarningInit();
DLLEXPORT int ADASLdwWarningProcess(sAdaptSetPara AdaptsetPara, VEHICLESTATUS VehicleStatus, const OutInfoLDW* infoLDW, const OutInfoKalman* outInfoKalman);
DLLEXPORT int ADASLdwWarningGetInfo(OutInfoWarningLDW *outWarningLDW);


#endif

