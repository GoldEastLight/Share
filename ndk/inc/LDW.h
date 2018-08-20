#ifndef __LDW__
#define __LDW__


#include "adas_wonder.h"

#include "kalman_car_results.h"


#include <math.h>
#include <stdio.h>


#define OFFSET_LANE_WIDTH_WORLD 1000	//350 //ͳһ����������Ч��Χ
#define LANE_WIDTH_WORLD 3750
#define LANE_WIDTH_NAROW 3300			//�еĵ�·���Ȳ���3750
#define LANE_WIDTH_WORLD_HALF 1875


//����
extern Uint8* m_pbImage;	// ��������ͼ��

extern Uint16 m_iWidth;
extern Uint16 m_iHeight;

extern LineFunc m_LineLf;
extern LineFunc m_LineRt;
//2012.04.15���ݱ궨����������ı�׼3.75m�����ҳ�����
extern LineFunc m_NormalLineLeft;
extern LineFunc m_NormalLineRight;

extern Bool m_bCrossMark;

//extern int m_iNearestMark;     // ���忿�����������ߣ�
extern int m_iCrossMarkSideNum;	 // 0 ��ʾ��࣬ 1 ��ʾ�Ҳ࣬ ����m_bCrossMarkΪ��ʱ������

extern int m_iCurLaneWidth;
extern int m_iCurLaneWidthStdDev;

extern Uint16 m_iProcRowCnt;

extern int m_iFinalLfDist;
extern float m_fFinalAngle;
extern VEHICLESTATUS m_InputVehicleStatus;		// ��ǰ����״̬
extern Bool m_bTrackValid;
extern Bool m_bCrossMark;
extern LineFunc m_WLfLine;	// �������������	�Ƕ��ǳ������ڳ�������ϵ�����꣬��ͷ����Ϊ������ͷ����Ϊ��
extern LineFunc m_WRtLine;
extern Uint8 m_iWarningLevelTemp;				// ��ֵԽ�󣬱�������Խ�ߣ�0��ʾ���ޱ�����

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

extern Uint8* m_pbImage;	// ��������ͼ��
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


/*��ӡStop Go��Ϣ*/
extern Bool bSGKalmanWarning;
extern Bool bSGDetectCarWarning;
extern  float fSGDisX;
extern  float fSGVX;
extern  int m_iKalmanCnt;

/* ��ҹ�����㷨        */
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
extern float m_uThresholdHorizontal; // ˮƽ�����ݶ���ֵ
extern float m_vThresholdvertical;
extern Uint8 m_pImgGradX8[];
extern int m_iNearestMarkLDW;



//void adi_sobel_3x3_vert_i8(const Uint8* pInBuff, Uint32 dimY, Uint32 dimX, Int16* pOutBuff);
void ImgProcInit(void);
void LDW_LaneDetectInit(void);
void LDW_WarningInit(void);

void LDW_DetectLane();
int LaneMeasure(LineFunc* lineLf, LineFunc* lineRt, Bool bCrossLine, int iCrossLineNum);


/* �������� */
/*ȥ����������*/
void  LDWFiltInit();


/*������ʻ */

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