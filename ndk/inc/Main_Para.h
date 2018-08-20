#ifndef _MAIN_PARA_H
#define _MAIN_PARA_H




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
	Uint8 StopGo_MAxWorkingSpeed;  //���ٳ�������ֵ��stop&go���ڹ���
	Uint8 Vehicle_Width;           //�������
};
typedef struct sAlgParameters CAlgParameters;



#endif
