
#ifndef _KALMAN_UI_H_
#define _KALMAN_UI_H_

#include "adas_wonder.h"

#include "kalman_hostCarData.h"
#include "kalman_car_results.h"
#include "kalman_CarTrack.h"


extern PSModuleResults pCombinedResults;
extern SHostCarData * pHostCarData;				//  iImageCnt * 0.04f; 不起作用；
extern SCanData *pCanData;					// 虽然Init， 但是还是不起作用；
extern SSegmentationResultObj* m_pCarResult;		// 但是还是不起作用；
extern PSModuleResults pCombinedResults;			//  在CarDetectInit中申请的空间，都是代表指针的形式，并不是全局变量；


extern signed char m_indexLineCar[];


extern LineFunc kalmanLineLf;
extern LineFunc kalmanLineRt;
extern CarBodyArea kalmanCarData;


void FCW_Car_KalmanHost();
void FCW_GetValue_KalmanMeasure();



#endif
