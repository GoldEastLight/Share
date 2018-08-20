// hostCarData.h: interface for the ChostCarData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOSTCARDATA_H__278B0F65_2C98_4DFC_9721_71960DDB207F__INCLUDED_)
#define AFX_HOSTCARDATA_H__278B0F65_2C98_4DFC_9721_71960DDB207F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "kalman_canData.h"

#ifdef   __cplusplus   
extern   "C"   
{   
#endif 

	
struct SHostCarData_Tag; 

// pointer to hook function
typedef void (*absWorldResetHookFn_T) (struct SHostCarData_Tag const *, void *);

/*! Host car data collects measured sensor, frame and time data and allows the calculation of the host path.
*	For the calculation of the host path, it is assumed that we can approximate the host movement as movement on the border of a circle for small timesteps. 
*	(If the yaw rate is zero, the radius of the circle is infinite.)
*	The host path is calculated as follows:
*	Each time we receive a new yaw rate or velocity measurement, we use the old yaw rate and the old velocity to calculate the movement from the last time, we received a measurement up to the current time. 
*	The passed distance on the circle is calculated by multiplying the old velocity with the passed time dt between the last calculation and the current calculation. 
*	The new angle is calculated by multiplying the yaw rate with dt. The angle and the passed distance on the border is used to determine the circle radius. The circle radius allows to calculate a translation vector between the last and the current timestep.
*	After this step, the new yaw rate or velocity value is saved together with the time when it was measured. The yaw rate and velocity processing works like sample and hold.
*	The single calculated movements movements between the measurements are collected and appended to determine the complete movement between two frames. 
*	Mathematical details about the calculation can be found in the weekly reports.
*	The translation vector and the cos and sin values from the rotation are precomputed for easyly computing
*	"movement" of objects (relative to host) caused by host movement; e.g. used in 
*	the particle filtering process. This saves time, because they are calculated only once and during each filtering process.
*
*	Note that the above mentioned host movement is only a relative movement between the previous and 
*	the current time step. 
*
*	Additionally, the movement of the host relative to absolute world coordinates (AWC) can be stored.
*	The origin of the AWC system has to be set (once or repeatedly).
*	In contrast to the host movement in relative world coordinates (where the values of 
*	translationXMeters and translationYMeters are given in the host's SAE world coordinate system of
*	the *previous* time step), the absolute world coordinate system does not move (or at least,
*	does not move unless its origin is reset.)
*
*/
/*! host car data �ռ��˲�����������֡���Ͷ�ʱ�����ݣ��Լ������켣�ļ���
*   �ڱ����켣����ʱ�����豾����ѭһ����ʱ���ڣ���ɢʱ�䣩��Բ���˶������yaw rateΪ0��Բ���˶��İ뾶Ϊ�����
*   �����켣�ļ��㷽�����£�
*   ÿ�ν��յ�һ���µ�Yaw rate���ٶȲ���ֵ�����ݹ�ȥ��Yawrate���ٶ�ֵ�������һ�ε��˶������ǽ��ܵ�һ�����µ����ڵ�һ������ֵ
*   ��Բ������ʻ���ľ���distance = ��ȥ���ٶ� * dt �����ϴμ��㵽��μ���֮���ʱ������
*   �½Ƕ�angle  = dt * yawrate,�ǶȺ���Բ�����߹��ľ������ھ���Բ�뾶��Բ�뾶���ڼ�����һ���͵�ǰʱ�䲽��֮���һ��ƽ��ʸ��
*   �������������µ�yawrate���ٶȾͺ����ǵĲ���ʱ��һ�𱻱���������yawrate���ٶȵĴ���������Ʋ������֡�
*   ����֮��ĵ������˶��������ھ�����֮֡�����ȫ�˶�����

  *   �����ᵽ�ļ���ֻ��ǰһʱ���뱾ʱ��֮�������˶�
  
*/
typedef struct  SHostCarData_Tag  {
	double imageTime;		///<Only used for internal computation: This is the filtererd image time filtered by a proportional regulator.
	int frameCounter;		///<Only used for internal computation: The hardware frame counter from the camera.
	int frameNumber;		///<Only used for internal computation: The current frame numer iterated up from one.
	double lastVelocity;	///<Only used for internal computation: This is the last measured velocity value.
	double lastYawRate;		///<Only used for internal computation: Last measured yaw rate value.
	double lastTime;		///<Only used for internal computation: The time when the last velocity or yaw rate value was received.
	//intermediate results path calculation
	float groundplaneObjectTransX;	///<Result: The x component of the translation vector on the groundplane RELATIVE to a coordinate system rotated by the rotation angle.
	float groundplaneObjectTransY;	///<Result: The y component of the translation vector.
	float groundplaneObjectSinAngle;///<Result: Precomputed sin value of sin(-angleRadian). It is used later and only calculated here to save time.
	float groundplaneObjectCosAngle;///<Result: Precomputed cos value of cos(-angleRadian).
	//intermediate results
	float iterDistance;				///<Only used for internal computation: The distance for one iteration step.
	float iterAngle;				///<Only used for internal computation: The angle up to the current iteration step.
	float iterTranslationX;			///<Only used for internal computation: The x component of the translation vector up to the current timestep.
	float iterTranslationY;			///<Only used for internal computation: The y component of the translation vector up to the current timestep.
	//complete results
	float distanceMeters;			///<Result: The traveled distance in meters.
	float loopTimeSeconds;			///<Result: The calculated loopTime between the last and the current frame in seconds.
	float translationXMeters;		///<Result: The x component of the translation vector of the host relative to the unmodified coordinate system.
	float translationYMeters;		///<Result: The y component of the translation vector of the host relative to the unmodified coordinate system.
	float angleRadian;				///<Result: The new angle of the host at the current frame time. The angle at the last frame is defined to be zero.
	//Backward compatibility results
	double yawRateAtImageTime;		///<Result kept for backward kompatibility: The yaw rate at image time.
	double velocityAtImageTime;		///<Result kept for backward kompatibility: The velocity at image time.
	
									/* Variables for storing the host movement in an absolute world coordinate system.
									* For the current time step, they are valid after a call to hostCarDataCalculatePath() 
	* or hostCarDataResetAbsWorldCoords() */
	bool absWorldCoordActive;             /// following vars are only updated if 
	double absWorldCoordResetImageTime;    /// last imageTime (see above) at which hostCarDataResetAbsWorldCoords() was called
										   /** The x component of the host position vector in the absolute world coordinate system, in m.
	* It specifies the position at the current time step. */
	float absWorldPosXMeters;       
	/** The y component of the host position vector in the absolute world coordinate system, in m.
	* It specifies the position at the current time step. */
	float absWorldPosYMeters;
	/* The heading angle of the host in absolute world coordinates, in rad.
	* It specifies the heading at the *previous* time step (reason: translationX/YMeters are given
	* in the host-relative coordinate system of the *previous* time step. 
	* The current heading is  absWorldHeadingRad = absWorldPrevHeadingRad + angleRadian */
	float absWorldPrevHeadingRad;
	/* The heading angle of the host in absolute world coordinates, in rad, for the current time step  */
	//void (*absWorldResetHookFn)(void);
	float absWorldHeadingRad;
	/** Hook to be called when hostCarDataResetAbsWorldCoords() is called. Allows application
	* to react when absoulte coordinate system is reset. */
	absWorldResetHookFn_T absWorldResetHookFn;
	/** pointer passed to absWorldResetHookFn_T() */
	void *pAbsWorldHookInfo;
	
}SHostCarData;



//class ChostCarData  : public CcanData
//{
//public:
//	ChostCarData();
//	virtual ~ChostCarData();

	/*! Initialization function. Allocates the necessary memory for the structure and a pointer pointing at the object.
	*	@return A pointer to the data structure
	*/
	SHostCarData* hostCarDataInit();
	
	/*! Cleanup function. Deallocates the memory for the host car data structure. Should be used, whenever the structure has to be removed.
	*	/param pHostCarData pointer to the host car data structure
	*/
	void hostCarDataCleanup(SHostCarData* pHostCarData);
	
	/*! The function calculates the path of the host car as described above between the last and the current frame based on the data received from the can bus.
	*	The result is stored in the hostCarData structure.
	*	/param pHostCarData valid pointer to the host car data structure
	*	/param pCanData		valid pointer to the can data structure holding the source data from the can bus
	*/
	void hostCarDataCalculatePath(SHostCarData * pHostCarData, struct CanData * pCanData);
	
	void hostCarDataResetAbsWorldCoords(SHostCarData * pHostCarData);
	void hostCarDataSetResetHookFn (SHostCarData * pHostCarData, absWorldResetHookFn_T absWorldResetHookFn,
		void *pInfo);


#ifdef   __cplusplus   
}  
#endif

#endif // !defined(AFX_HOSTCARDATA_H__278B0F65_2C98_4DFC_9721_71960DDB207F__INCLUDED_)
