#ifndef _MEASUREMENT_LIST_H
#define _MEASUREMENT_LIST_H

#include "kalman_list.h"
#include "kalman_tracker_commons.h"


/*! \struct Measurement
	Structure containing measurement data.
*/
#define MEASUREMENT_LIST_SIZE 60

#ifdef   __cplusplus   
extern   "C"   
{   
#endif


typedef struct BoundingBoxMeas{
	float x;
	float y;
	float width;
	float height;
}SBoundingBoxMeas;

typedef struct Measurement{
	EMeasurementType mType;
	/*! Unique measurement id.*/
	short		measurementId;

	void*		pMeasurementData;
	void*		pAdditionalData;
	void*		pMeasurementAssignmentInfo;
	//unsigned int isPed:1;
}SMeasurement;

//LIST_DEFINE(MeasurementList, SMeasurement, MEASUREMENT_LIST_SIZE);
typedef struct MeasurementList
{
	SMeasurement elements[MEASUREMENT_LIST_SIZE]; 
	SMeasurement *pointers[MEASUREMENT_LIST_SIZE]; 
	unsigned short i; 
	unsigned short length; 
	/*static const */unsigned short maxLength;// = MEASUREMENT_LIST_SIZE; 
}SMeasurementList;

extern void* measurementBoundingBoxInit();
extern void  measurementBoundingBoxCleanup(void* pMeasurement);
extern void  measurementListInit(SMeasurementList* pMeasurementList, void* (*assignmentDataInit)(), void* (*measurementDataInit)());
extern void  measurementListCleanup(SMeasurementList* pMeasurementList, void (*assignmentDataCleanup)(void*), void (*measurementDataCleanup)(void*));


#ifdef   __cplusplus   
}  
#endif

#endif _MEASUREMENT_LIST_H

