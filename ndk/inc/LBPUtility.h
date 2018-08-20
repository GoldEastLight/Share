
#ifndef _UTILITY_TOOL_
#define _UTILITY_TOOL_



#include "FWS_define.h"
//#include "LDW.h"


#ifndef min
#define min(a,b) (((a)<(b))?(a):(b))
#endif
#ifndef max
#define max(a,b) (((a)>(b))?(a):(b))
#endif


#define CALC_SUM_OFS_(p0, p1, p2, p3, ptr) \
((ptr)[p0] - (ptr)[p1] - (ptr)[p2] + (ptr)[p3])


typedef struct _CLBPObj
{
	int x;
	int y;
	int width;
	int height;
	int nMember;// 矩形的个数；
	
}CLBPObj;

typedef struct _ScaleData
{
	float scale;
	int sziWidth;
	int sziHeight;
	//Size szi;			//  进行了+1的操作，此操作是作为积分图来进行的。
	int ystep;			//  积分图空间，每个尺寸的起始位置，
	int layer_ofs;
	
}ScaleData;

typedef struct _CSize
{
	int width;
	int height;
}CSize;


typedef struct _LBPThreadPara
{
	int *pIntegData;
	Bool lbpTrack;
	int segflag;
	
	int scaleStart;
	int scaleEnd;
	
}LBPThreadPara;



extern CSize origWin; // 原始的尺寸
extern int scaleIdxCenter;
extern int scaleIdx[];





extern int lbp_image_cols;
extern int lbp_image_rows;


extern int nscales;

extern int stump_feature_idx[];
extern float stump_threshold[];
extern float stump_left[];
extern float stump_right[];

extern int feature_ptr_ofs[];
extern int stage_first[];
extern int stage_ntrees[];
extern float stage_threshold[];

extern int cascade_subsets[];
extern ScaleData scale_data[];


extern int enlarge;
extern int Bit_Offer;
extern int scaleFactorInt[];
extern int scaleFactorInvInt[];
extern int rweightsInvInt[]; 


extern int* pIntegData;
extern int idxRectList;
extern Bool flagNearRoiExistCar;
extern Bool bLBPVehicleTracked;
extern int idxObjAnalyzed;
extern int nObjAnalyzed;

extern CLBPObj rectList[]; 
extern CLBPObj trackedObj;
extern CLBPObj lastObj;
extern CLBPObj preDetectObj;
extern CRect searchRoi;
extern CRect imgProcessRoi;
extern Uint8 pLbpSrcDataCrop[];
extern Uint8 pLbpSrcData[];
extern Uint8 pLbpSrcSobel[];

extern LineFunc lbpLineLf;
extern LineFunc lbpLineRt; 

extern int vehicleRoiTop;
extern int vehicleRoiBottom; 

extern Bool flagDetectNearRegion;

extern int vehOffCenterMax;
extern float fCropRto;

extern int vehicleRoiTop;
extern int vehicleRoiBottom;
extern int vehicleRoiLeft;
extern int vehicleRoiRight;

extern Bool bLBPDetectFlag;
extern Bool bProcessLaneTrackRoiOnly;


extern int heightImageFCW;
extern  int widthImageFCW;

void lbpInit();
void lbpImgResize2(Uint8* srcData, int srcWidth, int srcHeight, int srcStep, Uint8* dstData, int dstWidth, int dstHeight, int widthStep);
void lbpImgResize(Uint8* srcData, int srcWidth, int srcHeight, int srcStep, Uint8* dstData, int dstWidth, int dstHeight, int widthStep);
void lbpIntegral(int *pIntg, int offer,int itgStep, Uint8* pScaleData, int sIntegW, int sIntegH, int scaleStep);
void lbpIntegral2(int *pIntg, int offer,int itgStep, Uint8* pScaleData, int sIntegW, int sIntegH, int scaleStep,float scl);
//int lbpGetProposalArea(int *pIntegData,  Bool lbpTrack);
Bool lbpFiltObjectInDetecting();
void lbpFiltObjectInTraining();
void drawInfo();
Bool lbpIsVehicleStartTracked();
Bool lbpIsVehicleTrackedEnd();
void  lbpVehicleDetectionInit();
void lbpResizeSourceImage(Uint8* dataSrc);
void LBPCarDetection();
void lbpInfoCopy();
void lbpSourceImageDataCrop(Uint8* dataSrc);
void lbpCvtCoordinate(CLBPObj a, CLBPObj* b,Bool flag);

void lbpSobelImage();
void lbpBinaImage();
void *lbpGetProposalArea( void *para );
int   lbpGroup();





#endif 