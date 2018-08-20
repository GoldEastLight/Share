// CarTrack.h: interface for the CCarTrack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARTRACK_H__6E6BA2B0_71A7_4F96_A138_7DB77D58B30A__INCLUDED_)
#define AFX_CARTRACK_H__6E6BA2B0_71A7_4F96_A138_7DB77D58B30A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//#include "kalman_projection.h"
#include "kalman_hostCarData.h"
#include "kalman_unscented_kalman_tracker.h"
#include "kalman_car_results.h"
#include "kalman_nn_assign.h"



#ifdef   __cplusplus   
extern   "C"   
{   
#endif 


typedef struct Tracker
{
	SRoi				sRoi;

	/*! contains actual assignment table.*/
	SAssignmentTable    sAssignmentTable;

	/*! Contains actual sensor data.*/
	SHostCarData*		pCarData;

	/*! Contains calculation from and to gp*/
//	SProjection*		pProjection;

	/*! Contains the current measurement list*/
	SMeasurementList	*pMeasurementList;


	/*! Contains the current track file list*/
	STrackFileList		*pTrackFileList;


	/*! Assignment data*/
	void*				pAssignmentData;

	SMeasurementList   *pClassificationList;

}STracker;


void trackFileInit(STrackFile* pTrackFile, SInitializationFunctor* pFunctor, short assignmentListSize, unsigned short id);
void trackerInit(STracker* pTracker, unsigned char draw, unsigned char evaluation);
void trackFileDelete(STrackFile* pTrackFile);
void tracker_generate_result_set(STracker* pTracker, SModuleResults* pCombinedResults,bool bUpdate);
int trackFileAssignmentCheck(STrackFile* pTrackFile, const SAssignmentTable* pAssignmentTable);
int trackFileInRoi(STrackFile* pTrackFile,  const SRoi* pRoi);
void pedestrianCreateMeasurementListFromSegmentationResult(SMeasurementList* pMeasurementList, const void* pResults);
void CarTrackUpdate( PSModuleResults	pCombinedResults,bool bTrack,float *Distance);
void CarTrackPredict(SHostCarData *pCar, PSModuleResults	pCombinedResults);
void CarTrackInit(void);

#ifdef   __cplusplus   
}  
#endif

#endif // !defined(AFX_CARTRACK_H__6E6BA2B0_71A7_4F96_A138_7DB77D58B30A__INCLUDED_)


