#ifndef GLOBAL_H
#define GLOBAL_H

#include "adas_wonder.h"



#define VE_IN_WD	 720     //那?豕?赤???辰?DD????米???那y
#define VE_IN_PITCH  736     //2谷?‘米?赤????迆∩?∩⊿?¯?D辰?DD那y?Y那米?那??車?米??迆∩?????米?∩車D?㏒?㊣?D?那?32米?㊣?那y㏒?
#define VE_IN_HT	 480     //那?豕?赤????迄車D米?DD那y
#define VE_OUT_WD    720     //那?3?赤???辰?DD????米???那y
#define VE_OUT_PITCH 1440    //辰?DD那y?Y那米?那??車?米??迆∩?????米?∩車D?
#define VE_OUT_HT    576     //那?3?赤???米????豕
#define VE_OUT_HT_D  480     //那?3?赤???米????豕_


extern unsigned char ErrorStats;
extern unsigned char VehSpeed;
extern unsigned char LeftLight;
extern unsigned char RightLight;
extern unsigned char FootBrake;

extern Uint32 Xiaoshixian1;
extern Uint32 Xiaoshixian2;
extern Int32  Flag_Cali_F;
extern Uint8 FlashFlagT;
extern Uint8  Camera_Error;
extern Uint8 AlgParaUpdatedInFlash;
extern Uint8 ut_TTC;
extern Uint8 ut_THW;
extern Uint8 ut_RANGE;
extern Int8 ut_ANGEL;
extern Int8 ut_TTLC;
extern Uint8 ut_VEHICLE;
extern Uint8 ut_ONLANE;
extern Uint8 ut_LINE;
extern Uint8 ut_SYS; 

extern Bool m_bCaliFalsh;


#endif
