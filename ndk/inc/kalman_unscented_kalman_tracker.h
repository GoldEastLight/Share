#ifndef _UNSCENTED_KALMAN_TRACKER_H
#define _UNSCENTED_KALMAN_TRACKER_H

#include "kalman_hostCarData.h"
//#include "kalman_projection.h"
#include "kalman_list.h"

#include "kalman_tracker_commons.h"
//#include "track_file.h"
#include "kalman_measurement_list.h"

#ifdef   __cplusplus   
extern   "C"   
{   
#endif


typedef struct UnscentedMovementTrackerSettings{
	unsigned int setInitNoise : 1;
	float initMovementNoiseX;
	float initMovementNoiseY;
	float initMeasurementNoiseX;
	float initMeasurementNoiseY;
	float wHeight;
	
	unsigned int setMovementNoise : 1;
	float sqrMovementNoiseX;
	float sqrMovementNoiseY;
	unsigned int setMeasurementNoise : 1;
	float sqrMeasurementNoiseXWp;
	float sqrMeasurementNoiseYWp;
	float sqrMeasurementNoiseZWp;
	float zMeasurementOffsetWp;

	float sqrMeasurementNoiseXIp;
	float sqrMeasurementNoiseYIp;

	//float sqrMeasNoiseClassifierX;
	//float sqrMeasNoiseClassifierY;
	unsigned int setRecordHistory : 1;
	unsigned int recordHistory :    1;
}SUnscentedMovementTrackerSettings;

typedef enum 
{
    inactive = 0, 
    tentative = 1, 
    active = 2
} EFilterState;

typedef struct unscentedMovementTracker
{
	
	EFilterState filterState;

	unsigned short stateDim;

	float alpha;
	float beta;
	float kappa;
	float lambda;


	float initMovementNoiseX;
	float initMovementNoiseY;

	float initMeasurementNoiseX;
	float initMeasurementNoiseY;

	float sqrMovementNoiseX;
	float sqrMovementNoiseY;

	float sqrMeasurementNoiseXWp;
	float sqrMeasurementNoiseYWp;
	float sqrMeasurementNoiseZWp;

	float zMeasurementOffsetWp;
	float sqrMeasurementNoiseXIp;
	float sqrMeasurementNoiseYIp;
	float wHeight;

	unsigned int recordHistory : 1;

	float** initCov;
	float** state;
	float** covarianceMat;
	float** predMeasurement;


	float** measCov;
	float** invMeasurementCov;

	float** temp1;
	float** temp2;
	float** temp3;

	float** temp4;


	float** sigmaPointsX;
	float** sigmaPointsY;


	unsigned int invCovCalculated : 1;
	unsigned int activated		  : 1;
//	unsigned int measType;
    // @peng 2015.3.24
	EMeasurementType measType;

//	struct KalmanMovementTrackerHistoryArray* pKalmanMovementTrackerHistoryArray;

}SUnscentedMovementTracker;

/*	Prediction of the estimate on the groundplane compenstated for host ego motion.
*/
#if 0
void unscentedKalmanTrackerSetParameters(void* pUTracker, const void* pUSettings);
SUnscentedMovementTracker* unscentedKalmanTrackerInit();
void unscentedTrackerCleanup(void* pTracker);
void unscentedKalmanTrackerPredict(void* pTracker,  SProjection* pProjection, const SHostCarData* pHostCarData);
void unscentedKalmanTrackerCalcMeasurementCov(void* pTracker, SProjection* pProjection, EMeasurementType measType);
void unscentedKalmanTrackerUpdate(void* pTracker, SProjection* pProjection, const void* pMeasurementData);
int  unscentedKalmanTrackerStart(void* pTracker, SProjection* pProjection, const void* pMeasurement);
void unscentedKalmanTrackerStop(void* pTracker);
float   unscentedKalmanTrackerGetDistance(void* pTracker, const void* pMeasurement);
void    unscentedKalmanTrackerGetImagePos(const void* pTracker, float* posX, float* posY);
float** unscentedKalmanTrackerGetAssignmentEllipse(void* pTracker);
void unscentedKalmanTrackerAssignToTrackFile(void* TrackFile);
void unscentedKalmanTrackerGeneratePedOutput(void* pTracker, SProjection* pProjection, void* pOutput,bool bUpdate);
void unscentedKalmanTrackerCopy(const void* pSrcFilter, void* pTargetFilter);
void unscentedKalmanTrackerPrintFilterState(void* pFilter);
void unscentedKalmanTrackerDrawFilterState(void* pFilter);
unsigned char unscentedKalmanTrackerSampleFromMeasCov(void* pFilter, SProjection* pProjection, float* xRes, float* yRes, float *wRes, float* hRes);
float checkForOverlapping(void* pFilterA, void* pFilterB, SProjection* pProjection);
#else
void unscentedKalmanTrackerSetParameters(void* pUTracker, const void* pUSettings);
SUnscentedMovementTracker* unscentedKalmanTrackerInit();
void unscentedTrackerCleanup(void* pTracker);
void unscentedKalmanTrackerPredict(void* pTracker,   const SHostCarData* pHostCarData);
void unscentedKalmanTrackerCalcMeasurementCov(void* pTracker,  EMeasurementType measType);
void unscentedKalmanTrackerUpdate(void* pTracker,  const void* pMeasurementData);
int  unscentedKalmanTrackerStart(void* pTracker,  const void* pMeasurement);
void unscentedKalmanTrackerStop(void* pTracker);
float   unscentedKalmanTrackerGetDistance(void* pTracker, const void* pMeasurement);
void    unscentedKalmanTrackerGetImagePos(const void* pTracker, float* posX, float* posY);
float** unscentedKalmanTrackerGetAssignmentEllipse(void* pTracker);
void unscentedKalmanTrackerAssignToTrackFile(void* TrackFile);
void unscentedKalmanTrackerGeneratePedOutput(void* pTracker,  void* pOutput,bool bUpdate);
void unscentedKalmanTrackerCopy(const void* pSrcFilter, void* pTargetFilter);
void unscentedKalmanTrackerPrintFilterState(void* pFilter);
void unscentedKalmanTrackerDrawFilterState(void* pFilter);
unsigned char unscentedKalmanTrackerSampleFromMeasCov(void* pFilter,  float* xRes, float* yRes, float *wRes, float* hRes);
float checkForOverlapping(void* pFilterA, void* pFilterB);
#endif

/*! start the unscented tracker using an fixed covariance and projecting it to the ground.
*/
/*! start the unscented tracker from image plane tracking and project the estimates and the covariance to the ground.
*/
#if 0
void getFootpointFromBB(const void* pMeas, float *x, float* y, EMeasurementType *measType);
void unscentedKalmanTrackerGenerateBoundingBox(const void* pTracker, SProjection* pProjection, float *x, float *y, float *width, float* height,float *width_max,float *height_max);
#else
void getFootpointFromBB(const void* pMeas, float *x, float* y, EMeasurementType *measType);
void unscentedKalmanTrackerGenerateBoundingBox(const void* pTracker, float *x, float *y, float *width, float* height,float *width_max,float *height_max);
#endif

#ifdef   __cplusplus   
}  
#endif
#endif _UNSCENTED_KALMAN_TRACKER_H
