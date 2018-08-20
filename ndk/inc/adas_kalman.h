
#ifndef ADAS_KALMAN_H
#define ADAS_KALMAN_H


#include "adas_wonder.h"
#include "kalman_car_results.h"

#ifndef __linux
#ifdef DLL_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
	#define DLLEXPORT
#endif




DLLEXPORT int	ADASKalmanInit();

DLLEXPORT int	ADASKalmanPredict();

DLLEXPORT int	ADASKalmanMeasure(const OutInfoLDW* outInfoLDW, const OutInfoFCW* outInfoFCW);

DLLEXPORT int	ADASKalmanUpDate();

DLLEXPORT int	ADASKalmanGetInfo(OutInfoKalman*  ppModuleResults);

#endif
