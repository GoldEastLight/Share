#ifndef _NN_ASSIGN_H
#define _NN_ASSIGN_H

#include "kalman_measurement_list.h"
//#include "track_file.h"
//#include "kalman_projection.h"
#include "kalman_unscented_kalman_tracker.h"
//#include "kalman_projection.h"

#define ASSIGNMENT_LIST_SIZE 30
#define TRACK_LIST_SIZE		40


#ifdef   __cplusplus   
extern   "C"   
{   
#endif

typedef struct Roi{
	float xMin;	//! Minimum x value of the ROI.
	float xMax; //! Maximum x value of the ROI.
	float yMin; //! Minimum y value of the ROI.
	float yMax; //! Maximum y value of the ROI.
}SRoi;

/*! Assignment table structure. 
*	This table stores the information, how many times a track should be detected in a given time window, until it is deleted.
*/
typedef struct AssignmentTable{
	int tableLength;										//! Assignment table length, must be <= ASSIGNMENT_LIST_SIZE.
	int requiredNumberOfAssignments[ASSIGNMENT_LIST_SIZE];  //! Minimum detection number.
}SAssignmentTable;

/*! Track file structure. 
*	This table stores all information related to a track.
*/
typedef struct TrackFile
{
	//filter and filter functions


	SUnscentedMovementTracker *pTrackerFilter;
//	unscentedMovementTracker *pTrackerFilter;									//! Pointer to the tracker filter file.
									//! Pointer to the filterCopy function. Makes a deep copy of the filter contents to pTrg.			
	//debug functions
	
	//assignment functions
	void* pTrackAssignmentData;								    //! Pointer to the assignment data structure. Assignment data can be stored here in order to help algorithms in the assignment process.
		 //! Pointer to the copy function
	//#endif _OBJ_DATA 
	//eval
	unsigned short	trackId;								//! Unique track id
	unsigned int	age;									//! Track age starting by one.
	unsigned short  overrideDeleteCounter;					//! OverrideDeleteCounter. Overrides any delete decisions, if a target is classified as pedestrian for a certain time.
    int ROI_number;                                         //! For TSR this int indicates the current ROI
	
	unsigned int isDeleted ;								//! track is deleted info bit.
	unsigned int trackOutsideRoi ;						//! track is outside the ROI info bit.
	unsigned int trackNotEnoughUpdates ;					//! track had not enough updates info bit.
	
	unsigned char trackAssignedOverTime[ASSIGNMENT_LIST_SIZE];	//! Assignment table. In this table is stored, how many times the track was assigned to a measurement.
	short maxAssignmentListSize;								//! maximum assignment list size, must be <= ASSIGNMENT_LIST_SIZE
	short assignmentElem;										//! current assignment list size.
	
}STrackFile;

/*! Track list structure. 
*	This list stores all track files.
*/
//LIST_DEFINE(TrackFileList, STrackFile, TRACK_LIST_SIZE);

typedef struct TrackFileList
{
	STrackFile elements[TRACK_LIST_SIZE]; 
	STrackFile *pointers[TRACK_LIST_SIZE]; 
	unsigned short i; 
	unsigned short length; 
	/*static const */unsigned short maxLength;//=TRACK_LIST_SIZE; 
}STrackFileList;
//-------------------------------------------------------------------------------//

typedef struct NNTrackAssignmentData{
	short			assignedMeasurementIndices[MEASUREMENT_LIST_SIZE+1];
	float			assignedMeasurementDistances[MEASUREMENT_LIST_SIZE+1];
	short			indexListSize;
	short			assignmentPriority;
	SMeasurement*	pMeasurement;
	
}SNNTrackAssignmentData;

typedef struct NNMeasurementAssignmentData{
	float		   trackDistance;
	unsigned short assignmentPriority;
	short		   trackIndex;
	short		   trackId;
	unsigned char  trackInRange;
}SNNMeasurementAssignmentData;

typedef struct NNGlobalAssignmentData{
	float gamma;
	float initRange;
}SNNGlobalAssignmentData;

#if 0
extern void* nnAssignmentInitTrackData();
extern void nnAssignmentCleanupTrackData(void* pTrackInfo);
extern void nnWriteAssignmentDataToResultSet(void* pTrackInfo, void* pOutput);
extern void nnAssignmentCopyTrackData(void* trg, const void *src);
extern void nnAssignmentCopyTrackInfo(const void* pTrackInfoSrc, void* pTrackInfoTarg);
extern void* nnAssignmentInitMeasurementData();
extern void nnAssignmentCleanupMeasurementData(void* pMeasurementInfo);
extern void* nnTrackAssignedTo(void* pTrackInfo);
extern void assignNNAssignmentToTrackFile(void* TrackFile);
extern void assignNNAssignmentToMeasurement(void* Measurement);
extern void* nnAssignmentInitGlobalData(float distGamma);
extern void nnAssignmentCleanup(void* pGlobalAssignmentData);
static void nnCalculateAssignmentList(STrackFile* pTrackFile, SMeasurementList* pMeasurementList, float gamma,float *Distance,bool bTrack);
static void nnIterativeAssignment(STrackFileList* pTrackFileList, SMeasurementList* pMeasurementList, int trackIndex);
static void nnFinalizeAssignment(STrackFile* pTrackFile, SMeasurement* pMeasurement);
static void nnCreateNewTracks(STrackFileList* pTrackFileList, SMeasurementList* pMeasurementList, SProjection* pProjection, void* pGlobalAssignmentData);
extern void nnAssignUpdateAndCreate(STrackFileList* pTrackFileList, SMeasurementList* pMeasurementList, SProjection* pProjection, void* pGlobalAssignmentData,float *Distance,bool bTrack);

//
int trackFileCreate(STrackFile* pTrackFile, SProjection* pProjection, const void* pMeasurement);
void trackFileUpdate(STrackFile* pTrackFile, SProjection* pProjection, const void* pMeasurement);
#else
extern void* nnAssignmentInitTrackData();
extern void nnAssignmentCleanupTrackData(void* pTrackInfo);
extern void nnWriteAssignmentDataToResultSet(void* pTrackInfo, void* pOutput);
extern void nnAssignmentCopyTrackData(void* trg, const void *src);
extern void nnAssignmentCopyTrackInfo(const void* pTrackInfoSrc, void* pTrackInfoTarg);
extern void* nnAssignmentInitMeasurementData();
extern void nnAssignmentCleanupMeasurementData(void* pMeasurementInfo);
extern void* nnTrackAssignedTo(void* pTrackInfo,int* nr);
extern void assignNNAssignmentToTrackFile(void* TrackFile);
extern void assignNNAssignmentToMeasurement(void* Measurement);
extern void* nnAssignmentInitGlobalData(float distGamma);
extern void nnAssignmentCleanup(void* pGlobalAssignmentData);
static void nnCalculateAssignmentList(STrackFile* pTrackFile, SMeasurementList* pMeasurementList, float gamma,float *Distance,bool bTrack);
static void nnIterativeAssignment(STrackFileList* pTrackFileList, SMeasurementList* pMeasurementList, int trackIndex);
static void nnFinalizeAssignment(STrackFile* pTrackFile, SMeasurement* pMeasurement);
static void nnCreateNewTracks(STrackFileList* pTrackFileList, SMeasurementList* pMeasurementList,  void* pGlobalAssignmentData);
extern void nnAssignUpdateAndCreate(STrackFileList* pTrackFileList, SMeasurementList* pMeasurementList,  void* pGlobalAssignmentData,float *Distance,bool bTrack);

//
int trackFileCreate(STrackFile* pTrackFile,  const void* pMeasurement);
void trackFileUpdate(STrackFile* pTrackFile, const void* pMeasurement);
#endif

#ifdef   __cplusplus   
}  
#endif

#endif  _NN_ASSIGN_H

