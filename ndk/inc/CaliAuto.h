
#ifndef _CALI_AUTO_
#define _CALI_AUTO_

#include "adas_wonder.h"


extern  LineFunc	lineInfoCaliLf;
extern  LineFunc	lineInfoCaliRt;
extern  int			CameraFocal[2];

extern  float		m_fLfAngleCali;
extern  float		m_fRtAngleCali;


void CCaliAutoInit();
unsigned char  CaliAutoMain(VEHICLESTATUS carSignalIn, unsigned char Flag_Flash_Read, PackedWarning pCarWarning, Bool bCurve);





#endif