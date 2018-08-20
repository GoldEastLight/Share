#ifndef _TRACKER_COMMONS
#define _TRACKER_COMMONS

//#define CLASSIFIER_UPDATE_BY_REPLACE


#ifdef   __cplusplus   
extern   "C"   
{   
#endif



typedef enum measurementType
{
	LDW_Left_Line,
	LDW_Right_Line,
	carDetection, 
//	carClassification, 
//	cropData, 
//	carTrack
}EMeasurementType;

typedef struct InitializationFunctor{
	void (*assignFilterToTrackFile)(void*);
	void (*assignAssignmentAlgorithmToTrackFile)(void*);
	void (*assignAssignmentAlgorithmToMeasurement)(void*);
	void (*assignDataToTrackFile)(void*);

	void* (*measurementAssignmentDataInit)();
	void  (*measurementAssignmentDataCleanup)(void*);
	void* (*measurementDataInit)();
	void  (*measurementDataCleanup)(void*);
}SInitializationFunctor;


//#ifdef _DEBUG
//Tracker debug
//	#define TRACKER_DEBUG
	//use ground truth as tracker output
	//#define TRACKER_USE_GT_POS_AS_OUTPUT
	//text output for debugging purposes
	//#define TRACKER_DEBUG_TEXT
	//#define TRACKER_DEBUG_CHECK
	//view tracker debug output
//	#define TRACKER_DEBUG_VIEW
//#endif

//#define TRACKER_INCLUDE_HOST_MOVEMENT
//#define TRACKER_ITERATIVE_ASSIGNMENT
//#define GROUNDPLANE_TRACKING

//use the classification result in tracking
//#define TRACKER_USE_CLASSIFIER_POS
//If this define is set, the tracker updates the the estimate a second time
//with the classifier result. If not, the classifier result is used INSTEAD of the detection
//to update the classifier
//#define TRACKER_MIX_CLASSIFIER_POS
//If this define is set, the tracker uses optical tracking to get a second position measurement and
//the tracker is updated using this value.
//#define TRACKER_USE_OPTICAL_TRACKING

//#define TRACKER_FILTER_MEASUREMENTS
//#ifdef TRACKER_FILTER_MEASUREMENTS
//	#define TRACKER_EXCLUSION_RANGE_WIDTH 0.5f
//	#define TRACKER_EXCLUSION_RANGE_DIST  2.0f
//#endif TRACKER_FILTER_MEASUREMENTS

//#define SWITCH_TRESHOLD 1.0f

//#define MODEL_SWITCH
//#define MNTABLE		{1,2,2,3,4,4,3}

//tracker settings
//#define AV_DT 0.04f

//Maximum number of measurements
//#define ASSIGNMENT_ID_LIST_SIZE  7
//#define TRACK_ROI_X_MIN		  0
//#define TRACK_ROI_X_MAX		  640
//#define TRACK_ROI_Y_MIN		  0
//#define TRACK_ROI_Y_MAX		  480

//#define SWITCH_TRESHOLD	4.0f
//#define SWITCH_TIME 3

/*
typedef struct filterFunctor{
	void* (*filterInit)();
	void  (*filterCleanup)(void*);
	void  (*filterPredict)(void*, const void*, SProjection*, const SHostCarData*);
	void  (*filterCalcMeasurementArea)(void*, const void*, SProjection*);
	void  (*filterUpdate)(void*, SProjection*, const float**);
	void  (*filterStart) (void*, SProjection*, const float**);
	float (*filterGetDistance)(void*, const float**);
	void  (*filterStop)(void*);
	void  (*filterGetImagePos)(void*, float*, float*);
}SFilterFunctor;

typedef struct assignmentFunctor{
	void*  (*assignInit();
	void   (*assignCleanup)();
	void   (*assign)(void*, void*);
	void   (*getUnassignedMeasurements)();
}SAssignmentFunctor;
*/

#ifdef   __cplusplus   
}  
#endif

#endif _TRACKER_COMMONS


