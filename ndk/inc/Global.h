#ifndef GLOBAL_H
#define GLOBAL_H

#include "adas_wonder.h"



#define VE_IN_WD	 720     //��?��?��???��?DD????��???��y
#define VE_IN_PITCH  736     //2��?����?��????����?���?��?D��?DD��y?Y����?��??��?��??����?????��?�䨮D?��?��?D?��?32��?��?��y��?
#define VE_IN_HT	 480     //��?��?��????����D��?DD��y
#define VE_OUT_WD    720     //��?3?��???��?DD????��???��y
#define VE_OUT_PITCH 1440    //��?DD��y?Y����?��??��?��??����?????��?�䨮D?
#define VE_OUT_HT    576     //��?3?��???��????��
#define VE_OUT_HT_D  480     //��?3?��???��????��_


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
