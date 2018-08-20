
/*��ü������ݽṹ����ͷ�ļ�*/

#ifndef _ADAS_WONDER_H
#define _ADAS_WONDER_H



#define NULL 0
#define TRUE	1
#define FALSE	0 

typedef unsigned int Uint32;
typedef unsigned short Uint16;
typedef unsigned char Uint8;

typedef signed int Int32;
typedef signed short Int16;
typedef signed char Int8;

typedef signed int Bool;
typedef unsigned char BYTE;


#define PI 3.141592653589793f
#define TIME_INTERVAL 0.04f 


// @2015.12.23
#define SOURCE_IMG_WIDTH 720 
#define SOURCE_IMG_HEIGH 480

#ifndef min
#define min(a,b) (((a)<(b))?(a):(b))
#endif
#ifndef max
#define max(a,b) (((a)>(b))?(a):(b))
#endif

#ifndef HALF_PI
#define HALF_PI 1.57079632679f
#endif



//FWS���������صĴ�����Ϣ
typedef enum eFWSErrorTypeTag
{
	ERR_NO = 0,    //����
	ERR_FUNCTIONSELECT = 1,    // ����ѡ�����
	ERR_VEHICLEINFOR_INVALIDATE = 2,    //�����ź���Ч
	ERR_CAMERA = 3,    //����ڵ�
	ERR_IMAGE = 4,     //ͼ��ԱȶȲ�

	ERR_RESERVED              //����ģʽ
} eFWSErrType;

//�������Ͷ���
struct sCPoint
{
	int x;
	int y;
};
typedef struct sCPoint CPoint;

struct sTRAPEZOID {						// ��֧�ָ���
	Int16 top;
	Int16 bottom;
	Int16 leftbottom;
	Int16 rightbottom;
	Int16 lefttop;
	Int16 righttop;
};
typedef struct sTRAPEZOID TRAPEZOID;

struct sCFPoint
{
	float x;
	float y;
};
typedef struct sCFPoint CFPoint;

struct sCLine
{
	int x1;
	int y1;
	int x2;
	int y2;
};
typedef struct sCLine CLine;

struct sCFLine
{
	float x1;
	float y1;
	float x2;
	float y2;
};
typedef struct sCFLine CFLine;

struct sLineFunc
{
	Uint8 bValidate;	// ������Ч�� 

	float k;		    // б��
	float b;		    // �ؾ�

	Uint8 trust;

	CPoint EPoint;      // ֱ���յ�	Top
	CPoint SPoint;      // ֱ�����	Bottom

	Bool bVert;		    // �Ƿ���ֱ
	Uint16 PointCnt;	// ����
	Uint32 degree;	    // ���Ŷ�

					
	unsigned int iFailure; //����ʧ�ܵ�֡�� 20130308 changan

	Bool RefOtherSide;

	int Angle;
	char FlagWarning;


	int AngleCorr;//����ʼ������ȷ���ĽǶ�
	Bool bDraw;
	Bool laneType;// 0:���ߣ�1��ʵ��

};
typedef struct sLineFunc LineFunc;

struct sVEHICLE_STATUS
{
	Uint8  Speed_km;  //���٣�km/h
	float  Speed_ms;  //���٣�m/s
	Uint8  Right_turn;
	Uint8  Left_turn;
	Uint8  Brake;
	Uint8  Wipers;    // �� - 0�� �� - 1���� - 2
	Uint8  HighBeam; //ǰ�յ��źţ��� - 0�� ����� - 1�� Զ��� - 2
	Uint8  FogLight;  //����źţ��� - 0���� - 1

	Uint16 SignalValid;    //�ź���Чλ

	float SteeringAngle;      //������ת��
	Uint8 SteeringAngleSpeed; //������ת���ٶ�
	float YawRate; //Yaw Rate��ڽ��ٶ�
	float GSensorSignal; //G-Sensor Signal;
	float AcceleratorX; //X������ٶȣ���ǰΪ��
	float AcceleratorY; //Y������ٶȣ�����Ϊ��
	float AcceleratorZ; //Z������ٶȣ�����Ϊ��
	Uint8 ActualGear; //ʵ�ʵ�λ
	float PedalPostion;//̤��λ��
	Uint32 Reserved;    //�����ֽ�

};
typedef struct sVEHICLE_STATUS VEHICLESTATUS;

struct sVEHICLE_STATUS_CAN
{
	Uint8  FuctionSelect;  //����ѡ��
	Uint16 SignalValid;    //�ź���Чλ
	float CarSpeedKmph;    //���٣�km/h
	Uint8 CarInfo;          //������Ϣ��

	float SteeringAngle;      //������ת��
	Uint8 SteeringAngleSpeed; //������ת���ٶ�
	float YawRate; //Yaw Rate��ڽ��ٶ�
	float GSensorSignal; //G-Sensor Signal;
	float AcceleratorX; //X������ٶȣ���ǰΪ��
	float AcceleratorY; //Y������ٶȣ�����Ϊ��
	float AcceleratorZ; //Z������ٶȣ�����Ϊ��
	Uint8 ActualGear; //ʵ�ʵ�λ
	float PedalPostion;//̤��λ��
	Uint32 Reserved;    //�����ֽ�

};

typedef struct sVEHICLE_STATUS_CAN VEHICLESTATUS_CAN;

struct sVEHICLE_PROPERTY
{
	Uint16 tread;
};
typedef struct  sVEHICLE_PROPERTY VEHICLEPROPERTY;


struct sCRect
{
	int left;
	int top;
	int right;
	int bottom;
};
typedef struct sCRect CRect;

struct  sMaxValue
{
	Uint32 value;           //���ֵ
	Int16 Dist;             //����
	Uint16 AngleNumber;     //�Ƕ�
};
typedef struct sMaxValue MaxValue;

struct sDataArray
{
	float fVal[10];
	int   iVal[10];
	int index;
};
typedef struct sDataArray DataArray;


// FCW��LDW����״̬�ź�
typedef enum eStateTypeTag
{
	STATE_CLOSE = 0,    //�ر�
	STATE_STANDBY = 1,    //����
	STATE_WORK = 2,    //����
	STATE_NO_WORK = 3,    //�ǹ���ģʽ
	RESERVED              //����ģʽ
} eStateType;

typedef enum eLDWWarningTypeTag
{
	LDW_NO_WARNING = 0,		//�������κα���
	LDW_LEFT_WARNING_IV = 1, //��෢��ͼ�����������
	LDW_LEFT_WARNING_I = 2, //����ʱ�������ֻ����ͼ�񱨾�����������������
	LDW_RIGHT_WARNING_IV = 3, //�Ҳ෢��ͼ�����������
	LDW_RIGHT_WARNING_I = 4,  //�Ҳ�ֻ����ͼ�񱨾�
	LDW_WARNING_RESERVED

}eLDWWarningType;


// FCW��������
typedef enum eCarWarningTypeTag
{
	NO_WARNING = 0,
	WARN_NEAR_DISTANCE = 1, //�����뱨��
	REMOVE_NEAR_DISTANCE = 2, //�����뱨�����
	WARN_PRE_COLLISIOM_WARNING = 3, //Ԥ��������һ����ײ��ʾ������һ������
	ReMOVE_PRE_COLLISIOM_WARNING = 4, //Ԥ�������
	WARN_COLLISION_WARNING = 5,     //��ײ������Ҳ����Σ�ձ���
	REMOVE_COLLISION_WARNING = 6      //��ײ�������
} eCarWarningType;

/*ϵͳ�����ʾ��Ϣ*/
struct sPackedWarning
{
	// about lane info
	Bool bLeftLaneSolid;// 0: dotted, 1: solid
	Bool bRightLaneSolid;

	Uint8 NearestMark;
	float  DriftAngle;//��ƫ��
	float ttlc;

	Uint8 warningLaneLevel;    //
	Uint8 laneDeResult;        //0x01:ʶ����೵����; 0x10��ʶ���Ҳ೵����

								// about car info
	float ttc;
	float thw;
	float FrontCarDistance;

	Bool bVehicleOnLane;  // ������ʻ, 0 δ������ʻ 1 ������ʻ

	Bool bCarFollowing;
	Uint8 warningCarLevel;
	Uint8 carDeResult;    //0,û��ʶ�𵽳�����1��ʶ�𵽳�����

							// about sys info 
	Uint8 sysWarning; // 0���� 1Ϊ�궨 2����ͷ���� 3����Ԥ��
};
typedef struct sPackedWarning PackedWarning;

/*** 2015.3 �ⲿ���ƿɵ����� ****/
struct sAdaptSetParaTag
{
	/*  LDW  */
	Bool LDW_bTurnSignal;          //�Ƿ���ת����źţ��������ò�ͬ�ı������ԣ���ת����źţ�����ת����źŵĿ������α����źţ�û��ת����źţ�ִ�иߵ���ģʽ
	int LDW_EnableWarningSpeed;     //LDW��������
	int LDW_EnableHighSpeedModel; //LDW��������ģʽ
	int LDW_WarningLine;    //LDW������λ�ã����ڵ���LDW����������

	int LDW_EarliestWarningLine; //LDW���籨���ٽ��ߣ�����ٱ����ٽ��ߣ����ڲ�ͬ���͵ı�������������
	int LDW_LatestWarningLine;   //LDW��ٱ����ٽ���

	int LDW_WarningLength; //LDW��������ʱ�䳤��

							/*  FCW */
	int FCW_EnableSpeed;          //FCW��������
	float FCW_FirstWarningTTC;      //TTCԤ����ʱ����ֵ�������ȼ�1��
	float FCW_SecondWarningTTC;     //TTCΣ�ձ�����ֵ�������ȼ�2��
	float FCW_ThresTHW;            //THW������ֵ(��������ٶȽ�С������Ծ���Ƚ�Сʱ�ı���)

									/*  ������ʻ�������� �Լ�����ʱ����ֵ */
	int Online_EnableSpeed;
	int Online_EnableWarningTime;

	/* Stop&go ��������ٶ�*/
	int StopGo_MAxWorkingSpeed;  //���ٳ�������ֵ��stop&go���ڹ���

									/* �����ṹ��Ϣ */
	int Vehicle_Width;  //������ȣ�ָ��������ǰ������̥֮��Ŀ��
};
typedef struct sAdaptSetParaTag sAdaptSetPara;

//FCW
struct  CarBodyArea1
{
	int iTopY;
	int iBottomY, iBottomXL, iBottomXR;
	int iDist;
	int iDistance;   //ǰ����������Ծ��룬��mmΪ��λ
	int iNMI;
	int iMatch;      //ֻ����ͶƱ�����������ƥ��ϵ��
	int  iShadeEdge;
	Bool bValidate;
	Bool bValCurrent;
	Bool bTrack;
	int label;       //  Is it a car?  1: yes; -1: no  add Yang.GM 2011-9-7
						//	int RatioLeft;
						//	int RatioRight;


						// 2014
						//	int haar[10];
						//	int edge[10];
						//	int eoh[10];
						//	int edgeNoLinear[10];
	float wCar;
	float hCar;
	int footpoint_center_wx;
	int footpoint_center_wy;
	int iWidthAvg;
};
typedef struct CarBodyArea1 CarBodyArea;


struct  CarDetectArea1
{
	int iTopX, iTopY;
	int iBottomY, iBottomXL, iBottomXR;
	float kl, kr;
	float bl, br;
	float thresV, thresU;
};
typedef struct CarDetectArea1 CarDetectArea;


struct CGaussHarrisTag1
{
	int winx;
	int winy;
	double sigma;
	int size; // ?
};
typedef struct CGaussHarrisTag1 GaussParaHarris;


struct FeatureGLCMTag1
{
	float  f0[5];
	float  f45[5];
	float  f90[5];
	float  f135[5];
};
typedef struct FeatureGLCMTag1 FeatureGLCM;


//@2012.01.09 Added by haijuan.peng
//��̬ѧ������mask
typedef struct MaskMorphologyTag
{
	short x;
	short y;
	short gray;
} MaskMorphology;


typedef struct TailLightTag
{
	int squr; //��ɫ�������
	int circ; //��ɫ�����ܳ�
	short left;
	short right;
	short top;
	short bottom;

	int xCenter;
	int yCenter;

	int yBottom;

	int aSize; //������ѡ�����С = w*h
	float whRatio; //�����
	float siyuandu; //��Բ��
	float aRatio; //���/����* ��
	int bLable;
} TailLight;


typedef struct TailLightMatchTag
{
	int index1;
	int index2;
	int overlap;
	int iMatch;

} TailLightMatch;


typedef struct CarEdgeLableTag
{
	int xLeft;
	int xRight;
	int y;
} CarEdgeLabe;


typedef struct CarLineArrayTag
{
	//	float kLeft;
	//	float kRight;
	//	float bLeft;
	//	float bRight;
	float AngleLeft;
	float AngleRight;
	int   dLeft; //����೵���ߵľ���
	int   dRight; //���Ҳ೵���ߵľ���
} CarLineArray;


typedef struct CarVerticalEdgeTag
{
	int x;
	int yStart;
	int yEnd;
} CarVerticalEdge;


// ·��״̬
typedef struct _RoadInfo
{
	Bool rainy; // 1:���죬0������
	Bool day;// 1:���죬0��ҹ��
	Bool light;//1:����ƣ�0��δ�����

}RoadInfo;


typedef  struct sResultOfImgProc
{
	Uint8 DayStatus;    //�����״̬
	Uint8 NightStatus;   //���ϵ�״̬
	Uint8 Image;        //ͼ������ṹ
	Uint8 Reserved;      //����
}ResultOfImgProc;


/* ��ˢ�ṹ�壬ѡ��������λ�õ�x,y���꣬�Ͷ����ҽ��� */
typedef struct _WiperRoi
{
	int x0;
	int y0;
	int x1;
	int y1;
}WiperRoi;


/*day & night detect*/
typedef struct _NightDayRoi
{
	int top;
	int left;
	int width;
	int height;

}NightDayRoi;


/*** �㷨�ɵ����� ****/
struct sAlgParameters
{
	/*  LDW  */
	Bool  LDW_bTurnSignal;            //�Ƿ���ת����źţ��������ò�ͬ�ı������ԣ���ת����źţ�����ת����źŵĿ������α����źţ�û��ת����źţ�ִ�иߵ���ģʽ
	Uint8 LDW_EnableWarningSpeed;     //LDW��������
	Uint8 LDW_EnableHighSpeedModel;   //LDW��������ģʽ
	Uint8 LDW_Sensitivity_Level;      //LDW������
	Uint8 LDW_WarningLength;          //LDW��������ʱ�䳤��

									  /*  FCW */
	Uint8 FCW_EnableSpeed;            //FCW��������
	Uint8 FCW_Sensitivity_Level;      //FCW������

									  /*  ������ʻ�������� �Լ�����ʱ����ֵ */
	Uint8 Online_EnableSpeed;
	Uint8 Online_EnableWarningTime;

	/* Stop&go ��������ٶ�*/
	Uint8 StopGo_MAxWorkingSpeed;		//	���ٳ�������ֵ��stop&go���ڹ���
	Uint8 Vehicle_Width;				//	�������
};
typedef struct sAlgParameters CAlgParameters;


//===================== ģ������ṹ��==================================
//  ���ڳ�������Ϣ���
typedef struct _OutInfoLDW {

	
	Bool m_b_track_valid;

	Uint8 warningLevel;
	Bool lane_width_ok;

	
	int		final_left_distance;

	int		m_i_nearest_mark_ldw;


	float final_angle;
	float posVanish[2];

	float lineAngleWorldCordLeft;		// ��������ϵ�³����ߵĽǶȣ�
	float lineAngleWorldCordRight;
	

	LineFunc lfLine;
	LineFunc rtLine;

	LineFunc lfLineWorld;
	LineFunc rtLineWorld;

	LineFunc leftLineDefault;
	LineFunc rightLineDefault;
	

	// CarLineRefer(m_LineLf, m_LineRt, m_iLfDist, m_fLfAngle, m_iRtDist, m_fRtAngle, &m_lineLCar, &m_lineRCar);
	// CarLineRefer(m_LineFCWLf, m_LineFCWRt, disToLineLeft, angleRoadLineLf, disToLineRight, angleRoadLineRt, &m_lineLCar, &m_lineRCar);

	int dw_left_lane ;			// ������೵���ߵľ��� 
	int dw_right_lane;			// ��������ϵ�³����ߵĽǶȣ� 

	float angle_lane_left;		// �����ߵĽǶ�
	float angle_lane_right;		// 

	int i_cross_mark_side_num;		//  ����LDW��m_iCrossMarkNum
	float th_horizontal;	// ����m_uThresholdHorizontal
	float th_vertical;		// ����m_vThresholdVertical;
	Bool  m_b_cross_mark;		// ���� m_bCrossMark
	Int16* p_img_sobel_y16;   // ���: extern Int16 pImgSobelY16[];
	Uint8* p_img_grad_x8;		// ��� Uint8 m_pImgGradX8[];



}OutInfoLDW;

typedef struct _OutInfoFCW {
	CarBodyArea carResult;
	//LineFunc rtLine;
	//int warningLevel;

}OutInfoFCW;



typedef struct _OutInfoAutoCali {

	LineFunc lfLine;

	// LineFunc rtLine;
	// int warningLevel;

}OutInfoAutoCali;


typedef struct _OutInfoWarningLDW {

	Uint8 warningLDW;
	int warningLDWSide; //�ı߱�����


} OutInfoWarningLDW;



typedef struct _OutInfoWarningFCW {
	int warningFCW;
}OutInfoWarningFCW;






#endif
