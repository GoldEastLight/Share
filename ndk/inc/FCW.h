#ifndef __FCW__
#define __FCW__

#include "adas_wonder.h"


#include "LBPUtility.h"

//--#include "LDW.h"
//-- #include "kalman_CarTrack.h"

//#define DISTANCE_SAVE_NUMBER  25  // 50
#define MAX_ACCELERATION  10      // m/s^2
//#define TIME_CAR_WARNING  1.8

extern CarBodyArea m_carData;            // ��һ֡ʶ����

extern float thresH;
extern float thresV;
extern unsigned char m_pDataU[];
//extern unsigned char m_pDataV8[];

extern int m_wNorm; // = 30
extern int m_hNorm;  // = 20
extern short int m_iCarDistance[];


extern float m_TTC;
extern float m_TTM;

extern float m_v;

//extern svm_node* x;
extern Bool m_bLDADetec;

extern int m_fctWarningLevel;
extern int tShade;

//����ʶ��
//extern unsigned char *m_pImageData;

extern CarBodyArea m_CarDetectResult;
extern Bool m_bCarSame;

//extern Bool m_bDay;
extern signed char m_exCondition;
extern float VanishPointFCW[];

//extern float m_uThresholdHorizontal; //ˮƽ�����ݶ���ֵ
extern float m_vThresholdvertical;   //��ֱ�����ݶ���ֵ
extern Bool m_bDay;
//extern Bool m_bCrossMark;

//extern Int16 pImgSobelY16[];
//extern Uint8 m_pImgGradX8[];

extern Bool m_bCarTrack;

extern LineFunc m_lineLCar;
extern LineFunc m_lineRCar;


//--extern STracker* pTracker;
//--extern SUnscentedMovementTracker *pTrackerFilter;
extern int m_iCntImg;


//extern Bool bSGFrontExistCar;
//extern int m_iSGExistCarFrms;
//extern float aSGInfo[4];
//

//extern PSModuleResults pCombinedResults;

extern signed char m_indexLineCar[3];

extern Bool m_b1Warned;
extern Bool m_b2Warned;

extern unsigned char *m_pImage_Car; 

void InitCarDetect();
void InitNightMask();
void Classify_Edge_NoLinear_SVMInit();
void WaveletInit();
void feature_edges_initialize();
void FeatureEOHInit();

//--void FCW_WarningInit();


void FCW_LDW_Kalman(unsigned int iImageCnt,Uint8 function);
//--void fctWarning_Kalman(sAdaptSetPara FCWsetPara,int iDistance,PSModuleResults pCombinedResults, signed char *m_indexLineCar,int ImgIndex);

/*��װ��Ϣ*/
//--void PackCarWarnInfo(PackedWarning* pCarWarning, CarBodyArea*resultCar);



// CaliAuto
extern float m_tilt_cali;
extern float m_head_cali;
extern float m_tilt_old;
extern float m_head_old;
extern float m_tilt_new;
extern float m_head_new;
extern Bool m_tilt_cali_updata;
extern Bool m_head_cali_updata;
extern float m_xMeanVanish;
extern float m_yMeanVanish;
extern int m_iSum;
extern Bool m_btilt_cali_ok;
extern Bool m_bhead_cali_ok;
extern Bool m_bCaliFalsh; 
extern Bool m_bCaliFirst;
extern signed char m_bWriteFlash;
extern float m_tilt_wFlash;
extern float m_head_wFlash;

extern DataArray m_tilt_data;
extern DataArray m_head_data;

extern unsigned char m_cali_res;

void CCaliAutoInit();

//Bool CaliAutoMain(PackedWarning pCarWarning,Bool bCurve);
//--void InitCarDetect_CaliAuto(void);


extern float fcwWarnInfo[];
extern int cardetectInfo[];


extern int m_nTotalDetectedCars;
extern CarBodyArea m_carBodyAreaTest[];


// =================  for lib ģ����ļ� ============================
extern  LineFunc m_LineFCWLf;
extern  LineFunc m_LineFCWRt;
extern  float VanishPointFCW[];


extern   LineFunc m_LineFCWDefaultLf;
extern   LineFunc m_LineFCWDefaultRt;


extern   int heightImageFCW;
extern   int widthImageFCW;

extern   int disToLineLeft;
extern   int disToLineRight;

extern   float angleRoadLineLf;
extern   float angleRoadLineRt;

extern   int iCrossMarkNum;		//  ����LDW��m_iCrossMarkNum
extern   float thHorizontal;	// ����m_uThresholdHorizontal
extern   float thVertical;		// ����m_vThresholdVertical;
extern   Bool  bCrossMark;		// ���� m_bCrossMark
extern   Int16* pImgSobelY16;   // ���: extern Int16 pImgSobelY16[];
extern   Uint8* pImgGradX8;		// ��� Uint8 m_pImgGradX8[];


#endif


