
#ifndef _KALMAN_UI_H_
#define _KALMAN_UI_H_

#include "adas_wonder.h"

#include "kalman_hostCarData.h"
#include "kalman_car_results.h"
#include "kalman_CarTrack.h"


extern PSModuleResults pCombinedResults;
extern SHostCarData * pHostCarData;				//  iImageCnt * 0.04f; �������ã�
extern SCanData *pCanData;					// ��ȻInit�� ���ǻ��ǲ������ã�
extern SSegmentationResultObj* m_pCarResult;		// ���ǻ��ǲ������ã�
extern PSModuleResults pCombinedResults;			//  ��CarDetectInit������Ŀռ䣬���Ǵ���ָ�����ʽ��������ȫ�ֱ�����


extern signed char m_indexLineCar[];


extern LineFunc kalmanLineLf;
extern LineFunc kalmanLineRt;
extern CarBodyArea kalmanCarData;


void FCW_Car_KalmanHost();
void FCW_GetValue_KalmanMeasure();



#endif
