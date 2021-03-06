#ifndef __LDW__
#define __LDW__


#include "adas_wonder.h"

#include "kalman_car_results.h"


#include <math.h>
#include <stdio.h>


#define OFFSET_LANE_WIDTH_WORLD 1000	//350 //统一车道宽度有效范围
#define LANE_WIDTH_WORLD 3750
#define LANE_WIDTH_NAROW 3300			//有的道路宽度不足3750
#define LANE_WIDTH_WORLD_HALF 1875


//变量
extern Uint8* m_pbImage;	// 不带符号图像

extern Uint16 m_iWidth;
extern Uint16 m_iHeight;

extern LineFunc m_LineLf;
extern LineFunc m_LineRt;
//2012.04.15根据标定参数计算出的标准3.75m的左右车道线
extern LineFunc m_NormalLineLeft;
extern LineFunc m_NormalLineRight;

extern Bool m_bCrossMark;

//extern int m_iNearestMark;     // 车体靠近哪条车道线；
extern int m_iCrossMarkSideNum;	 // 0 表示左侧， 1 表示右侧， 仅在m_bCrossMark为真时有意义

extern int m_iCurLaneWidth;
extern int m_iCurLaneWidthStdDev;

extern Uint16 m_iProcRowCnt;

extern int m_iFinalLfDist;
extern float m_fFinalAngle;
extern VEHICLESTATUS m_InputVehicleStatus;		// 当前车体状态
extern Bool m_bTrackValid;
extern Bool m_bCrossMark;
extern LineFunc m_WLfLine;	// 左侧线世界坐标	角度是车道线在车体坐标系内坐标，车头向左为负，车头向右为正
extern LineFunc m_WRtLine;
extern Uint8 m_iWarningLevelTemp;				// 数值越大，报警级别越高，0表示误无报警；

extern Uint16 m_iWarningCounter;
extern Bool m_bLaneWidthOK;
extern int m_iLfDist;
extern int m_iRtDist;
extern float m_fLfAngle;
extern float m_fRtAngle;

extern int m_iWarningCnt;

//extern float m_fVanishPoint[];
extern unsigned int m_Hist[];


//LDW_Measure()


extern Bool m_bHighSpeedModel;

extern Uint8* m_pbImage;	// 不带符号图像
extern Int16 m_pImgSobelY16[]; 

extern PackedWarning m_PackedWarn;


extern Uint8 pImgSGEdge[];
extern int prjSG[];
extern signed char info[];
extern int hSG;
  
extern int flagCarStatic;
extern float fSGAver;
extern int iSGWarningCount;
extern Bool bSGFrontExistCar;


/*打印Stop Go信息*/
extern Bool bSGKalmanWarning;
extern Bool bSGDetectCarWarning;
extern  float fSGDisX;
extern  float fSGVX;
extern  int m_iKalmanCnt;

/* 昼夜区分算法        */
extern Bool bIsNddNight;
extern Bool bNddNight;
extern Bool bNddGetTime;
extern RoadInfo roadInfo;

extern CRect m_LfTrackRect;
extern CRect m_RtTrackRect;

extern int edgeLaneTrackRoiLf[];
extern int edgeLaneTrackRoiRt[];
extern Uint8  m_iPRowTrackRgnWidth[];


//LDW_Measure()
extern float m_fVanishPoint[2];
extern int Shift_C2W_4096[2];
extern int RC2W20Focal;
extern int ShiftC2WFocal;
extern int Rotate_C2W[3][3];
extern int Rotate_W2C[3][3];
extern int Shift_C2W[3];
extern int Focal[2];
extern int Center[2];
extern int iRowNum;


// for lib
extern float m_uThresholdHorizontal; // 水平方向梯度阈值
extern float m_vThresholdvertical;
extern Uint8 m_pImgGradX8[];
extern int m_iNearestMarkLDW;



//void adi_sobel_3x3_vert_i8(const Uint8* pInBuff, Uint32 dimY, Uint32 dimX, Int16* pOutBuff);
void ImgProcInit(void);
void LDW_LaneDetectInit(void);
void LDW_WarningInit(void);

void LDW_DetectLane();
int LaneMeasure(LineFunc* lineLf, LineFunc* lineRt, Bool bCrossLine, int iCrossLineNum);


/* 函数定义 */
/*去除抖动问题*/
void  LDWFiltInit();


/*骑线行驶 */

void PackLaneWarnInfo(sAdaptSetPara LDWsetPara,PackedWarning* pLaneWarning);
void RecogniseLaneType(LineFunc* lineLf, LineFunc* lineRt);


void LaneMeasureInit(void);

void InitPackedWarn();

void LaneWidthThresh(int iWidth, int iDev);

void Grad_3x3_Vert_Horz( int height, char Condition);





void CaliUpdata(float xMean, float yMean, Bool bTilt, float tilt, Bool bHead, float head, Bool bHight, float h);


// updata lane detect init after cali auto
void LaneDetectInit_CaliAuto(void);
void LaneMeasureInit_CaliAuto(void);

void CreateRotateMatrix(float psi, float thet, float phi);






#endif
