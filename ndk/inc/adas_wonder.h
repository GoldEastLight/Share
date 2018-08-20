
/*万得嘉瑞数据结构定义头文件*/

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



//FWS主函数返回的错误信息
typedef enum eFWSErrorTypeTag
{
	ERR_NO = 0,    //正常
	ERR_FUNCTIONSELECT = 1,    // 功能选择错误
	ERR_VEHICLEINFOR_INVALIDATE = 2,    //车身信号无效
	ERR_CAMERA = 3,    //相机遮挡
	ERR_IMAGE = 4,     //图像对比度差

	ERR_RESERVED              //保留模式
} eFWSErrType;

//数据类型定义
struct sCPoint
{
	int x;
	int y;
};
typedef struct sCPoint CPoint;

struct sTRAPEZOID {						// 不支持负数
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
	Uint8 bValidate;	// 跟踪有效期 

	float k;		    // 斜率
	float b;		    // 截距

	Uint8 trust;

	CPoint EPoint;      // 直线终点	Top
	CPoint SPoint;      // 直线起点	Bottom

	Bool bVert;		    // 是否竖直
	Uint16 PointCnt;	// 点数
	Uint32 degree;	    // 可信度

					
	unsigned int iFailure; //连续失败的帧数 20130308 changan

	Bool RefOtherSide;

	int Angle;
	char FlagWarning;


	int AngleCorr;//由起始点坐标确定的角度
	Bool bDraw;
	Bool laneType;// 0:虚线，1：实线

};
typedef struct sLineFunc LineFunc;

struct sVEHICLE_STATUS
{
	Uint8  Speed_km;  //车速，km/h
	float  Speed_ms;  //车速：m/s
	Uint8  Right_turn;
	Uint8  Left_turn;
	Uint8  Brake;
	Uint8  Wipers;    // 无 - 0， 低 - 1，高 - 2
	Uint8  HighBeam; //前照灯信号，无 - 0， 近光灯 - 1， 远光灯 - 2
	Uint8  FogLight;  //雾灯信号：无 - 0，有 - 1

	Uint16 SignalValid;    //信号有效位

	float SteeringAngle;      //方向盘转角
	Uint8 SteeringAngleSpeed; //方向盘转角速度
	float YawRate; //Yaw Rate横摆角速度
	float GSensorSignal; //G-Sensor Signal;
	float AcceleratorX; //X方向加速度；向前为正
	float AcceleratorY; //Y方向加速度；向右为正
	float AcceleratorZ; //Z方向加速度；向上为正
	Uint8 ActualGear; //实际档位
	float PedalPostion;//踏板位置
	Uint32 Reserved;    //保留字节

};
typedef struct sVEHICLE_STATUS VEHICLESTATUS;

struct sVEHICLE_STATUS_CAN
{
	Uint8  FuctionSelect;  //功能选择
	Uint16 SignalValid;    //信号有效位
	float CarSpeedKmph;    //车速，km/h
	Uint8 CarInfo;          //车身信息，

	float SteeringAngle;      //方向盘转角
	Uint8 SteeringAngleSpeed; //方向盘转角速度
	float YawRate; //Yaw Rate横摆角速度
	float GSensorSignal; //G-Sensor Signal;
	float AcceleratorX; //X方向加速度；向前为正
	float AcceleratorY; //Y方向加速度；向右为正
	float AcceleratorZ; //Z方向加速度；向上为正
	Uint8 ActualGear; //实际档位
	float PedalPostion;//踏板位置
	Uint32 Reserved;    //保留字节

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
	Uint32 value;           //最大值
	Int16 Dist;             //距离
	Uint16 AngleNumber;     //角度
};
typedef struct sMaxValue MaxValue;

struct sDataArray
{
	float fVal[10];
	int   iVal[10];
	int index;
};
typedef struct sDataArray DataArray;


// FCW，LDW工作状态信号
typedef enum eStateTypeTag
{
	STATE_CLOSE = 0,    //关闭
	STATE_STANDBY = 1,    //待机
	STATE_WORK = 2,    //工作
	STATE_NO_WORK = 3,    //非工作模式
	RESERVED              //保留模式
} eStateType;

typedef enum eLDWWarningTypeTag
{
	LDW_NO_WARNING = 0,		//不发出任何报警
	LDW_LEFT_WARNING_IV = 1, //左侧发出图像和语音报警
	LDW_LEFT_WARNING_I = 2, //报警时间过长，只发出图像报警，不发出语音报警
	LDW_RIGHT_WARNING_IV = 3, //右侧发出图像和语音报警
	LDW_RIGHT_WARNING_I = 4,  //右侧只发出图像报警
	LDW_WARNING_RESERVED

}eLDWWarningType;


// FCW报警类型
typedef enum eCarWarningTypeTag
{
	NO_WARNING = 0,
	WARN_NEAR_DISTANCE = 1, //近距离报警
	REMOVE_NEAR_DISTANCE = 2, //近距离报警解除
	WARN_PRE_COLLISIOM_WARNING = 3, //预报警：第一次碰撞提示报警，一级报警
	ReMOVE_PRE_COLLISIOM_WARNING = 4, //预报警解除
	WARN_COLLISION_WARNING = 5,     //碰撞报警，也就是危险报警
	REMOVE_COLLISION_WARNING = 6      //碰撞报警解除
} eCarWarningType;

/*系统输出警示信息*/
struct sPackedWarning
{
	// about lane info
	Bool bLeftLaneSolid;// 0: dotted, 1: solid
	Bool bRightLaneSolid;

	Uint8 NearestMark;
	float  DriftAngle;//航偏角
	float ttlc;

	Uint8 warningLaneLevel;    //
	Uint8 laneDeResult;        //0x01:识别到左侧车道线; 0x10：识别到右侧车道线

								// about car info
	float ttc;
	float thw;
	float FrontCarDistance;

	Bool bVehicleOnLane;  // 骑线行驶, 0 未骑线行驶 1 骑线行驶

	Bool bCarFollowing;
	Uint8 warningCarLevel;
	Uint8 carDeResult;    //0,没有识别到车辆，1：识别到车辆。

							// about sys info 
	Uint8 sysWarning; // 0正常 1为标定 2摄像头故障 3其他预留
};
typedef struct sPackedWarning PackedWarning;

/*** 2015.3 外部控制可调参数 ****/
struct sAdaptSetParaTag
{
	/*  LDW  */
	Bool LDW_bTurnSignal;          //是否有转向灯信号，用于配置不同的报警策略，有转向灯信号，按照转向灯信号的开启屏蔽报警信号，没有转向灯信号，执行高低速模式
	int LDW_EnableWarningSpeed;     //LDW启动车速
	int LDW_EnableHighSpeedModel; //LDW启动高速模式
	int LDW_WarningLine;    //LDW报警线位置，用于调节LDW报警灵敏度

	int LDW_EarliestWarningLine; //LDW最早报警临界线，和最迟报警临界线，用于不同车型的报警灵敏度设置
	int LDW_LatestWarningLine;   //LDW最迟报警临界线

	int LDW_WarningLength; //LDW报警声音时间长短

							/*  FCW */
	int FCW_EnableSpeed;          //FCW启动车速
	float FCW_FirstWarningTTC;      //TTC预报警时间阈值（报警等级1）
	float FCW_SecondWarningTTC;     //TTC危险报警阈值（报警等级2）
	float FCW_ThresTHW;            //THW报警阈值(用于相对速度较小、但相对距离比较小时的报警)

									/*  骑线行驶启动车速 以及报警时间阈值 */
	int Online_EnableSpeed;
	int Online_EnableWarningTime;

	/* Stop&go 最大运行速度*/
	int StopGo_MAxWorkingSpeed;  //车速超过本阈值后，stop&go不在工作

									/* 车辆结构信息 */
	int Vehicle_Width;  //车辆宽度，指车辆左右前轮外轮胎之间的宽度
};
typedef struct sAdaptSetParaTag sAdaptSetPara;

//FCW
struct  CarBodyArea1
{
	int iTopY;
	int iBottomY, iBottomXL, iBottomXR;
	int iDist;
	int iDistance;   //前后辆车的相对距离，以mm为单位
	int iNMI;
	int iMatch;      //只保留投票结果，不保存匹配系数
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
//形态学计算用mask
typedef struct MaskMorphologyTag
{
	short x;
	short y;
	short gray;
} MaskMorphology;


typedef struct TailLightTag
{
	int squr; //白色区域面积
	int circ; //白色区域周长
	short left;
	short right;
	short top;
	short bottom;

	int xCenter;
	int yCenter;

	int yBottom;

	int aSize; //整个候选区域大小 = w*h
	float whRatio; //长宽比
	float siyuandu; //似圆度
	float aRatio; //面积/（长* 宽）
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
	int   dLeft; //到左侧车道线的距离
	int   dRight; //到右侧车道线的距离
} CarLineArray;


typedef struct CarVerticalEdgeTag
{
	int x;
	int yStart;
	int yEnd;
} CarVerticalEdge;


// 路况状态
typedef struct _RoadInfo
{
	Bool rainy; // 1:雨天，0：晴天
	Bool day;// 1:白天，0：夜晚
	Bool light;//1:开大灯，0：未开大灯

}RoadInfo;


typedef  struct sResultOfImgProc
{
	Uint8 DayStatus;    //白天的状态
	Uint8 NightStatus;   //晚上的状态
	Uint8 Image;        //图像分析结构
	Uint8 Reserved;      //保留
}ResultOfImgProc;


/* 雨刷结构体，选择两个点位置的x,y坐标，低端左右角落 */
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


/*** 算法可调参数 ****/
struct sAlgParameters
{
	/*  LDW  */
	Bool  LDW_bTurnSignal;            //是否有转向灯信号，用于配置不同的报警策略，有转向灯信号，按照转向灯信号的开启屏蔽报警信号，没有转向灯信号，执行高低速模式
	Uint8 LDW_EnableWarningSpeed;     //LDW启动车速
	Uint8 LDW_EnableHighSpeedModel;   //LDW启动高速模式
	Uint8 LDW_Sensitivity_Level;      //LDW灵敏度
	Uint8 LDW_WarningLength;          //LDW报警声音时间长短

									  /*  FCW */
	Uint8 FCW_EnableSpeed;            //FCW启动车速
	Uint8 FCW_Sensitivity_Level;      //FCW灵敏度

									  /*  骑线行驶启动车速 以及报警时间阈值 */
	Uint8 Online_EnableSpeed;
	Uint8 Online_EnableWarningTime;

	/* Stop&go 最大运行速度*/
	Uint8 StopGo_MAxWorkingSpeed;		//	车速超过本阈值后，stop&go不在工作
	Uint8 Vehicle_Width;				//	车辆宽度
};
typedef struct sAlgParameters CAlgParameters;


//===================== 模块输出结构体==================================
//  用于车道线信息输出
typedef struct _OutInfoLDW {

	
	Bool m_b_track_valid;

	Uint8 warningLevel;
	Bool lane_width_ok;

	
	int		final_left_distance;

	int		m_i_nearest_mark_ldw;


	float final_angle;
	float posVanish[2];

	float lineAngleWorldCordLeft;		// 世界坐标系下车道线的角度；
	float lineAngleWorldCordRight;
	

	LineFunc lfLine;
	LineFunc rtLine;

	LineFunc lfLineWorld;
	LineFunc rtLineWorld;

	LineFunc leftLineDefault;
	LineFunc rightLineDefault;
	

	// CarLineRefer(m_LineLf, m_LineRt, m_iLfDist, m_fLfAngle, m_iRtDist, m_fRtAngle, &m_lineLCar, &m_lineRCar);
	// CarLineRefer(m_LineFCWLf, m_LineFCWRt, disToLineLeft, angleRoadLineLf, disToLineRight, angleRoadLineRt, &m_lineLCar, &m_lineRCar);

	int dw_left_lane ;			// 距离左侧车道线的距离 
	int dw_right_lane;			// 世界坐标系下车道线的角度； 

	float angle_lane_left;		// 车道线的角度
	float angle_lane_right;		// 

	int i_cross_mark_side_num;		//  来自LDW的m_iCrossMarkNum
	float th_horizontal;	// 代替m_uThresholdHorizontal
	float th_vertical;		// 代替m_vThresholdVertical;
	Bool  m_b_cross_mark;		// 代替 m_bCrossMark
	Int16* p_img_sobel_y16;   // 替代: extern Int16 pImgSobelY16[];
	Uint8* p_img_grad_x8;		// 替代 Uint8 m_pImgGradX8[];



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
	int warningLDWSide; //哪边报警？


} OutInfoWarningLDW;



typedef struct _OutInfoWarningFCW {
	int warningFCW;
}OutInfoWarningFCW;






#endif
