#ifndef _MAIN_PARA_H
#define _MAIN_PARA_H




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
	Uint8 StopGo_MAxWorkingSpeed;  //车速超过本阈值后，stop&go不在工作
	Uint8 Vehicle_Width;           //车辆宽度
};
typedef struct sAlgParameters CAlgParameters;



#endif
