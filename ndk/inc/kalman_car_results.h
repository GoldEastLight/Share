

#ifndef VBPP_RESULTS_H
#define VBPP_RESULTS_H


#define MAX_NUMBER_OF_DETSEG_RESULTS			100
#define MAX_NUMBER_OF_TRACKING_RESULTS			50
#define MAX_NUMBER_OF_CLASSIFICATION_RESULTS	50
#define MAX_NUM_OBJ_IN_CLASSIFICATION_LIST		50
/// number of previous classification results stored
#define MAX_LEN_CLASSIF_HISTORY					40		

#define MAX_TRACK_ID 255
#define MAX_SEG_ID	 255

// for tracking result
#define MAX_MEASUREMENT_LIST_LENGTH			50

//  ===================来自 kalman_car_globals ==============================

#define VBPP_MAX_NUM_SEGMENTED_OBJ 100

//  always extract features with 16 bit
#define VBPP_FEAT_IMG_DEPTH_BIT (16)
#if VBPP_FEAT_IMG_DEPTH_BIT ==  16 
#define VBPP_FEAT_IMG_BINS 4096
#else 
#define VBPP_FEAT_IMG_BINS 256
#endif

/* Classification ************************************************************************/
#define VBPP_MAX_NUM_OBJ_TO_CLASSIFY 5 

/* Classification Control ************************************************************************/
/// object which are further away will not be classified; this threshold is the max. *squared* distance in  metres
// 60m 
#define VBPP_CTRL_MAX_SQUARED_OBJ_DIST_TO_BE_CLASSIFIED  3600
/*! TODO VBPP_MAX_NUM_OBJ_IN_CLASSIFICATION_LIST and VBPP_MAX_NUM_OBJ_TO_CLASSIFY should
be the same. Currently, they are different, for debugging purposes (UIU, 11.04.06)  */
#define VBPP_MAX_NUM_OBJ_IN_CLASSIFICATION_LIST 8
//#define VBPP_MAX_NUM_OBJ_IN_CLASSIFICATION_LIST 15

/*! Minimum age a track has to have before it is passed to the classifier*/
// #define VBPP_MIN_TRACK_AGE_TO_BE_CLASSIFIED 10
#define VBPP_MIN_TRACK_AGE_TO_BE_CLASSIFIED 0
// changed to 0 on 2006 July 11 only for testing
//#define VBPP_MIN_TRACK_AGE_TO_BE_CLASSIFIED 0

/*! Max. no of search steps (around object position predicted by tracker) to
* be performed.
* For omnisearch, this value has to be very high, since many positions
* are searched/classified.
* Omnisearch is for evaluation only and will not be active in the final production system!
* */
#define VBPP_CLC_MAX_NO_SEARCHSTEPS 30
//#define VBPP_CLC_MAX_NO_SEARCHSTEPS 20000


/** switch on different variants of how to get the final decision
* whether a ped has been classified
*/
#define VBPP_FINAL_PED_DECISION_VARIANT 2


// =====================来自 kalman_car_globals ======================================

//#include "../05_Utilities/crop_file_reader.h"

#include "adas_wonder.h"

//#include "kalman_car_globals.h"                // for VBPP_CLC_MAX_NO_SEARCHSTEPS
//#include "LDW.h"
//#include "type_define.h"  // for VBPD_S_ROI


//struct _FootpointPIMPL;


/////////////////////////////////////////////////////////////////////
// segmentation result object
/////////////////////////////////////////////////////////////////////
  



typedef struct _ParentSegmentationResultObj{
unsigned short segmentation_ID;		// unique id from 0 to 255
float footpoint_ic_x;				// footpoint in image coordinate x in pixel
float footpoint_ic_y;				// footpoint in image coordinate y in pixel
float height_ic;					// height of detection in image in pixel
// world coordinates are derived from image coordinates
float footpoint_wc_x;				// footpoint in world coordinate x in meter
float footpoint_wc_y;				// footpoint in world coordinate y in meter
float height_wc;					// height of detection in world coordinate in meter
/* box coordinates are derived from the image coordinates by using standard height and width*/
float boundingbox_ic_x;				// x image coordinate of left top point of bounding box in pixel
float boundingbox_ic_y;				// y image coordinate of left top point of bounding box in pixel
float boundingbox_width;				// width of bounding box in image in pixel
float boundingbox_height;			// height of bounding box in image in pixel

//link to pointer of HEQ;		// standard size of (Guanglin) bigger than 32x64
//short int width_ic;			// width of the HEQ image
//short int height_ic;			// height of the HEQ image

Bool b_image_source;				// 1 = image has been used as source for detection and segmentation; 0 = not possible
Bool b_tracking_source;				// 1 = tracking results has been used as source for detection and segmentation; 0 = tracking results has not been used
Bool b_classification_source;		// 1 = classification results has been used as source for detection and segmentation; 0 = classification results has not been used
}SParentSegmentationResultObj, *PParentSSegmentationResultObj;

typedef struct _SegmentationResultObj
{
	unsigned short segmentation_ID;		// unique id from 0 to 255
	unsigned char MyType;
//union 
//{
    float footpoint_ic_x;			// footpoint in image coordinate x in pixel
    float center_ic_x;              // center of sign x in pixel
//};
//union 
//{
    float footpoint_ic_y;			// footpoint in image coordinate y in pixel
    float center_ic_y;              // center of sign y in pixel
//};
	float height_ic;					// height of detection in image in pixel
// world coordinates are derived from image coordinates
	float footpoint_wc_x;				// footpoint in world coordinate x in meter
	float footpoint_wc_y;				// footpoint in world coordinate y in meter
	float height_wc;					// height of detection in world coordinate in meter
/* box coordinates are derived from the image coordinates by using standard height and width*/
	float boundingbox_ic_x;				// x image coordinate of left top point of bounding box in pixel
	float boundingbox_ic_y;				// y image coordinate of left top point of bounding box in pixel
	float boundingbox_width;				// width of bounding box in image in pixel
	float boundingbox_height;			// height of bounding box in image in pixel

//link to pointer of HEQ;		// standard size of (Guanglin) bigger than 32x64
//short int width_ic;			// width of the HEQ image
//short int height_ic;			// height of the HEQ image
	Bool isPedestrian;
	Bool b_image_source;				// 1 = image has been used as source for detection and segmentation; 0 = not possible
	Bool b_tracking_source;				// 1 = tracking results has been used as source for detection and segmentation; 0 = tracking results has not been used
	Bool b_classification_source;		// 1 = classification results has been used as source for detection and segmentation; 0 = classification results has not been used
	SParentSegmentationResultObj	parent[30];
	int								iParentCount;
	int  ROI_number;                    // The number of the region of interest where the object has been
                                    // found. This is TSR only.
}SSegmentationResultObj, *PSSegmentationResultObj;


/////////////////////////////////////////////////////////////////////
// tracking result object
/////////////////////////////////////////////////////////////////////

typedef struct _TrackingResultObj
{
	unsigned short  detectionQuality;	//backward compatibility
	unsigned short	trackId;			//unique track id in the range from 0 to 255
	unsigned int	age;				//age: starts at 2 and is incremented each time
	int ROI_number;                     // TSR: this is the id of the ROI
	float tracked_point_ic_pos_x;		//position based tracking calculates a new point in the image plane
	float tracked_point_ic_pos_y;
	float tracked_point_ic_vel_x;		//velocity in the image plane in pixels per second.
	float tracked_point_ic_vel_y;
	float tracked_footpoint_wc_x;		//footpoint in meters
	float tracked_footpoint_wc_y;
	float tracked_footpoint_wc_vel_x; 	//speed in meters per second (very inaccurate), u.a. linearization errors...
	float tracked_footpoint_wc_vel_y;

	float tracked_footpoint_wc_acc_x; 	//speed in meters per second (very inaccurate), u.a. linearization errors...
	float tracked_footpoint_wc_acc_y;


	float bb_width;
	float bb_height;
	
	float bb_width_max;
	float bb_height_max;

	/*
	-The assignment list indicates, which segments are assigned to a track.
	-The list contains i=0 ... assignmentListLength-1 items
	-Each item is coded in the following way:
	-1	- no assignment
	>=0	- the id of the assigned segmentation result
	- Every assignment assignmentList[i] has attached an assignmentProbability[i]. 
	This number between 0 and 100 that contains the probability of the current assignment.
	In case of a 1 to 1 assignment, the assignment list contains only one item and the binding probability will be 100. The assignment is only available, after an assignment took place (currently, if the state is assigned or updated).
	*/

	short	assignmentList[MAX_MEASUREMENT_LIST_LENGTH];			
	short	assignmentProbability[MAX_MEASUREMENT_LIST_LENGTH];	
	short	assignmentListLength;									
	Bool	bCreated;		// created is an indicator bit and is set to 1, if this track was created in the current timestep.
	Bool	bDeleted;		// - deleted is an indicator bit: if a track with the corresponding id is deleted, it is set to one, else to zero.

	//@peng 2015.03.24
	unsigned char track_Type; // 1 : LDW_Left_Line,  2: LDW_Right_Line  3: CarDetection
	unsigned char filterState; // 0: inactive   1: active   2: tentative
	/*
	If this bit is set, all other entries in the result set may not be valid, except the id. There may exist one other track with the same id at one timestep:
	This might happen, if a track is deleted in one time step and the same id was reused for a newly created track. The purpose of this bit is to allow other modules to delete results, that refer to a track.
	*/
}STrackingResultObj, *PSTrackingResultObj;


/////////////////////////////////////////////////////////////////////
// classification result object
/////////////////////////////////////////////////////////////////////
typedef enum {RBI_NOT_IGNORED=0, RBI_TOO_MANY, RBI_OBJ_TOO_FAR, RBI_YOUNG_TRACK, RBI_IS_NO_TRACK, RBI_FOOTPT_ABOVE_HORIZON} RBI;


typedef struct _ClassificationResultObj{
	unsigned short	classification_ID;			// id of this object
	unsigned short	trackId;					// id of the track this classification result belongs to
	unsigned char	classification_confidence;	// confidence between 100 and 0

	int classFinal;						// classification control decision: +1: pedestrian, -1: non-pedestrian  0: not sure
	int classConfidFinal;             	// confidence between 100 (100% sure it is a ped) and 0 (100% sure it is not a ped)
	int classNN;							///< last NN classification decision: +1: pedestrian, -1: non-pedestrian
	int classTemplate;						// last Template classifier decision (TSR Only): 0: 30kph, 1: 50kph, 2: 60kph, 3: 70kph, 4: 80kph, 5: 90kph, 6: 100kph, 7: 120kph
	int classConfidNN;						///< last classification confidence of NN; (+/-) 0 to 100; 100 is very confident; sign: + = pedestrian
	/*! number of times this object has been previously classifyed as a pedestrian
	 * by the NN classifier. Skips are counted as classified.*/
	int nClassCntPedNN; 
	/*! number of times this object has been previously classifyed as a non-pedestrian
	 * by the NN classifier. Skips are counted as classified. */
  //  union 
//	{
	    int nClassCntNonPedNN;
        int nClassCntNonTrafficSignNN;
 //   };
	//int nClassifSkipped;				///< number of consecutive time steps the classification step has been skipped
	int nClassCntPedNNConsec;
	int nClassCntNonPedNNConsec;
	/*! classification result of NN by previous classification */
	int nClassNNPrev; 
	/** numer of times this objects has been passed to a classifier, i.e. actively classified.
	As opposed, skipping is passive classification */
	int nActiveClassificationCount;  
	int nSumSearchSteps;  		///< sum of search steps performed
	/// History of search steps: for each active classification, keep number of search steps performed
	int anHistorySearchSteps[MAX_LEN_CLASSIF_HISTORY];   
	/// number of entries in anHistorySearchSteps; should be equal to nHistoryClassNNCount
	int nHistorySearchStepsCount;
	/** Previous classification results. Active classifications only (i.e., no skips)
	 * [0] contains the newest, [MAX_LEN_CLASSIF_HISTORY-1] the oldest one. */
	int anHistoryClassNN[MAX_LEN_CLASSIF_HISTORY];
	/** number of previous classification results stored in anHistoryClassNN[]  */
	int nHistoryClassNNCount;
	/** number of previous classification results in anHistoryClassNN[] that are
	 * used for the final pedestrian decision  */
	int nHistoryClassNNCountForFinalPedDecision;
	int nClassifYetToSkipCnt;				///< number of times the classification step is to be skipped
	/// set by classification control: should the object be classified
	Bool toBePassedToClassifier; 
	Bool passedToClassifier;				///< has object been actively classified in this time step?
	/*!< object is being ignored in this time step, i.e. not passed to the classifier.
	 * Reasons: object too far away, or alerady too many objects passed to classifier
	 **/
	Bool	beingIgnored;
	RBI		reasonBeingIgnored;				///< reason for being ignored 
	float nPriority; 							///< classification / system priority of object; 0 is lowest priority

//    union 
//	{                                 // this union construction is needed to get an alias for the footpoint for TSR
	    float footpoint_ic_x;				///< footpoint in image coordinate x in pixel
        float center_ic_x;                  ///< center of TSR in image coordinate x in pixel
 //   };
  //  union 
//	{
	    float footpoint_ic_y;				///< footpoint in image coordinate y in pixel
        float center_ic_y;                  ///< center of TSR in image coordinate y in pixel
  //  };

	float height_ic;						///< height of detection in image in pixel


	/** world coordinates are derived from image coordinates*/
	float footpoint_wc_x;					///< footpoint in world coordinate x in meter
	float footpoint_wc_y;					///< footpoint in world coordinate y in meter
	float height_wc;						///< height of detection in world coordinate in meter

	/* bounding box coordinates */
	// float boundingbox_ic_x_left;				///< x image coordinate of left line of bounding box in pixel
	// float boundingbox_ic_y_top;				///< y image coordinate of top line of bounding box in pixel
	// float boundingbox_ic_x_right;				///< x image coordinate of right line of bounding box in pixel
	// float boundingbox_ic_y_bottom;			///< y image coordinate of bottom line of bounding box in pixel. The bottom line has / should have the same y coordinate as the footpoint 

	/** bounding box with border: a border is added before cutting the images for classification.
	 * Reason: The classifier has been trained with such a border. */
	float boundingboxWithBorder_ic_x_left;				 
	float boundingboxWithBorder_ic_y_top;					
	float boundingboxWithBorder_ic_x_right;			
	float boundingboxWithBorder_ic_y_bottom;		

	/** margin added to *each* side (left and right) in order to obtain boundingboxWithBorder_ic_x_right and boundingboxWithBorder_ic_x_left, i.e.
	 * bboxWithoutBorder_left = boundingboxWithBorder_ic_x_left - bbox_margin_ic_horiz
	 *
	 * The bbox_margin_ic* values refer to the bounding box in its original size (boundingboxWithBorder_ic_*),
	 * not to the resized bounding box (which has a size of 32x64, with the margin being 1 and 2).
	 *
	 */

	int bbox_margin_ic_horiz; 
	/** margin added to both top *and* to bottom. 
	 * The line that has the same coordinate as the fooppoint is calculated as:
	 * footpoint_ic_y = bboxWithoutBorder_bottom = boundingboxWithBorder_ic_y_bottom - bbox_margin_ic_vert
	 */
	int bbox_margin_ic_vert; 


	/**  only true if the above boundingbox_* values have been calculated from the foot point in the 
	  current time step */
	Bool bBoundingBoxValuesValid; 
	/** when searching during classification: index of the search position that has been 
	 * actively classified last */
	int iLastSearchIdx;

    int ROI_number; // TSR : This is the id for the detected region

}SClassificationResultObj, *PSClassificationResultObj;

struct CropFileReader;

/////////////////////////////////////////////////////////////////////
// combined module results  
/////////////////////////////////////////////////////////////////////

typedef struct _ModuleResults{
	short int frame_number;		//frame number to which the results refer

	/*Segmentation result*/
	/*static const*/ short		max_numberSegmentations;// = MAX_NUMBER_OF_DETSEG_RESULTS;	
	SSegmentationResultObj	segmentationResult[MAX_NUMBER_OF_DETSEG_RESULTS+1];
	short					numberSegmentations;	//current number of segmentations

	/*Tracking result*/
	/*static const*/ short		max_number_tracks;//=MAX_NUMBER_OF_TRACKING_RESULTS;			
	STrackingResultObj		trackingResult[MAX_NUMBER_OF_TRACKING_RESULTS+1];				
	short					numberTracks;		

	PSTrackingResultObj 	TrackObjFromTrackId[MAX_TRACK_ID+1];
	PSSegmentationResultObj SegObjFromSegId[MAX_SEG_ID + 1];

	/*Classification result*/
	/*static const*/ short			max_num_obj_in_classification_list;//=MAX_NUM_OBJ_IN_CLASSIFICATION_LIST;
	/** Classification result list. Contains also objects which have not been classified in 
	 * the current time step. 
	 * The order is not prioritized or otherwise defined.
	 * In the current implementation, each track in trackingResult 
	 * also appears in classificationResult */
	SClassificationResultObj	classificationResult[MAX_NUM_OBJ_IN_CLASSIFICATION_LIST];
	/** Indices to ClassificationResult, in order of priority. 
	 * The element in ClassificationResult with highest priority 
	 * is indexed first in classifResPrioritizedIdx */ 
	unsigned short       classifResPrioritizedIdx[MAX_NUM_OBJ_IN_CLASSIFICATION_LIST+1]; 

	/// current number of classification results, is smaller or equal MAX_NUM_OBJ_IN_CLASSIFICATION_LIST
	short						numberClassifications;	
	int 						maxNumToBeClassified;   ///< maximum number of objects that may be passed to the classifier
	int 						cntToBeClassified;  ///< number of objects which have the flag toBePassedToClassifier set
	/// maximum number in classificationResult[].anHistorySearchSteps and .anHistoryClassNN
	int 						nMaxLenClassifHistory;  
	int						nMaxLenSearchStepsHistory;
	int						nMaxLenClassifHistoryForFinalPedestrianDecision;
	/** minimum number of times an object has to be classified a pedestrian (in the past,
	 * classificationResult[].anHistoryClassNN is analysed) before 
	 * it is considered a final pedestrian (classificationResult[].classFinal)
	 */
	int						nMinPedClassForFinalPed;
	/** minimum number of times an object has to be classified as non-pedestrian (in the past,
	 * classificationResult[].anHistoryClassNN is analysed) before 
	 * it is considered a final non-pedestrian (classificationResult[].classFinal)
	 */
	int						nMinNonPedClassForFinalNonPed;

/// get the classification object that thas the trackId (passed as index)
	PSClassificationResultObj	ClassifObjFromTrackId[MAX_TRACK_ID+1];	

	//// general purpose area  
	struct CropFileReader*	pVliReader;		// ptr to VLI reader
	int						iDetection_Mode;	// 0: regular--- 1: use ground truth instead of real detection
	int						iTracking_Mode;		// 0: regular--- 1: use ground truth instead of real tracking


}SModuleResults, *PSModuleResults;




// for Lib
typedef struct _OutInfoKalman {
	PSModuleResults moduleResults;
	signed char index[3];

}OutInfoKalman;



/*
int  results_init ( SModuleResults ** ppResults, int iDetection_Mode, int iTracking_Mode );

void results_cleanup( PSModuleResults pResults );

// result utility functions
void results_fill_trackObjFromTrackId ( PSModuleResults pResults );
void results_fill_segObjFromSegId ( PSModuleResults pResults );
Bool results_TrackIsMeasured (  PSTrackingResultObj psTrackObj );

*/



#endif

