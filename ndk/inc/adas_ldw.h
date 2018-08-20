#ifndef ADAS_LDW_H
#define ADAS_LDW_H

#ifndef __linux
#ifdef DLL_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
#else
	#define DLLEXPORT
#endif
#include "adas_wonder.h"


DLLEXPORT int ADASLdwInit();
DLLEXPORT int ADASLdwMain(unsigned char *p);
DLLEXPORT int ADASLdwGetInfo(OutInfoLDW *pLdwOut);


DLLEXPORT Bool ADASLdwPoint_P2W_I(int i, int j, int zw, int* xw, int* yw);
DLLEXPORT Bool ADASLdwPoint_W2P_I(int x, int y, int z, int* xp, int* yp);
DLLEXPORT void ADASLdwCreateRotateMatrix(float, float, float);
DLLEXPORT void ADASLdwGetParaLine(LineFunc *lineLf, LineFunc *lineRt, Bool bCrossLine, int iCrossLineNum);

DLLEXPORT void  ADASLdwLaneDetectInit_CaliAuto();

// InitCarDetect_CaliAuto();

DLLEXPORT void  ADASLdwLaneMeasureInit_CaliAuto();



// FCW




#endif

