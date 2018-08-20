
#ifndef _FCW_WARNING_H_
#define _FCW_WARNING_H_

#include "adas_wonder.h"
#include "kalman_car_results.h"


extern LineFunc lineWarnFcwLf;
extern LineFunc lineWarnFcwRt;

extern VEHICLESTATUS carSignalFcwWarning;


extern int m_fctWarningLevel;

void fctWarning_Kalman(sAdaptSetPara FCWsetPara, int iDistance, PSModuleResults pCombinedResults, signed char *m_indexLineCar, int ImgIndex);


#endif
