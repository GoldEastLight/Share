// canData.h: interface for the CcanData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CANDATA_H__3CD7540D_597B_4C59_9CDD_18CEEF52CD45__INCLUDED_)
#define AFX_CANDATA_H__3CD7540D_597B_4C59_9CDD_18CEEF52CD45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#ifndef MAX_MSG_ARRAY_LEN
#define MAX_MSG_ARRAY_LEN  10		// store 10 subsequent speed / yaw rate msgs
#endif
#define RAW_CAN_MSG_MAX_ARRAY_LEN 5000

// mutable and bool not C-compatible
#ifndef __cplusplus
#define mutable
#define bool int
#endif 

#ifdef   __cplusplus   
extern   "C"   
{   
#endif

typedef enum eCarType{
	Audi=0,         ///<running special handling for Audis.
		MercedesE,		///<running special handling for MercedesE.
		BMW,			///<running special handling for BMW
		Other           ///<running just another car
}ECarType;

/*! The can data structure is a queue for the can velocity and yaw rate measures until they can be processed by the host car data structure. 
*	The access functions are thread save, this means that the thread collecting the data from the can bus and the main thread can simultaneously access the data using the provided functions without corrrupting or loosing the data.
*/
typedef struct CanData{
//	mutable			CRITICAL_SECTION cs;
	double			velocity[MAX_MSG_ARRAY_LEN][2];	///<Only used for internal computation: This array always contains a data pair: The velocity value received from the can bus (velocity[i][0]) and the time, when the message was received (velocity[i][1]). The data starts at velStartIndex and ends at velStartIndex+velLength-1%MAX_MSG_ARRAY_LEN.
	unsigned int	velStartIndex;					///<Only used for internal computation: The index where the first data pair in the velocity index will be located.
	unsigned int	velReadIndex;					///<Only used for internal computation: This is the current read index for the reader thread in the velocity field. A read access is allowed from velStartIndex to min(ArrayLength, velStartIndex+velLength-1). If arrayLength is the minimum, the read access can continue at 0 up to velStartIndex+velLength-1%MAX_MSG_ARRAY_LEN.
	unsigned int	velLength;						///<Only used for internal computation: This is the current length of the velocity data field. The first entity of the data is located at velStartIndex and the last entity at velStartIndex+velLength-1%MAX_MSG_ARRAY_LEN
	double			yawRate[MAX_MSG_ARRAY_LEN][2];	///<Only used for internal computation: This array contains a data pair: The yaw rate value received from the can bus (yawRate[i][0]) and the time, when the message was received (yawRate[i][1]).
	unsigned int	yawStartIndex;					///<Only used for internal computation: This is the current read index for the reader thread in the yawRate field
	unsigned int	yawReadIndex;					///<Only used for internal computation: This is the current read index for the reader thread in the yawRate field.
	unsigned int	yawLength;						///<Only used for internal computation: This is the current length of the yawRate data field. The first entity of the data is located at yawStartIndex and the last entity at yawStartIndex+yawLength-1%MAX_MSG_ARRAY_LEN
	double			frameTime;						///<The timestamp of the last from from the computer clock
	int				frameCounter;					///<The value of the hardware frame counter of the camera
	unsigned int	frameNumber;					///<The current frame number. The number is iterated by one in each timestep
	/*const static */unsigned int maxArrayLength;//=MAX_MSG_ARRAY_LEN;	///<The maximum possible array length
	int				blinker;						///<Blinker sensor value
	unsigned char	light_sensor;					///<Light sensor value
	int				brake;							///<brake value
	int				wiper_active;					///<wiper state
	int             new_vehicle_data;				///<If new vehicle date is available, this field is set to one.
	ECarType		carType;						///<The car type: EClass/Mercedes. determines the data that is available from the sensors.

	unsigned		low_beam_on:1;					/// low beam switched on
	unsigned		high_beam_on:1;					/// high beam switched on
	unsigned		is_SMaL:1;						/// SMaL camera properties active
	// GPS properties
	double			GPSMeasurementTime;				// timer value of the last GPS measurement
	float			Latitude;						// North is positive (degree)
	float			Longitude;						// East is positive (degree)
	float			Altitude;						// [m]
	float			GPSSpeed;
	float			Bearing;
	float			Distance;
	int				GPSTime;
	
	// raw CAN messages (which are recorded to and read from dvl files)
//	VideoCanStream::CANmessage	raw_messages[RAW_CAN_MSG_MAX_ARRAY_LEN];
	unsigned raw_messages_len;
	
}SCanData;


//class CcanData  
//{
//public:
//	CcanData();
//	virtual ~CcanData();

	/*! Initialization function. Allocates the necessary memory for the can data structure and returns a pointer pointing to the object.
*	@return A pointer to the can data structure
*/
SCanData* canDataInit();

/*!	Cleanup function. Deallocates the memory for the can data structure. Should be used, whenever the structure has to be removed.
*	/param pCanData pointer to the can data structure that should be removed
*/
void canDataCleanup(SCanData* pCanData);

/*!	Thread-safe can data copy function. Copies the content of pCanDataSrc to pCanDataTrg
*	/param[in]  pCanDataSrc source of the can data
*	/param[out] pCanDataTrg target of the can data
*/
void canDataCopy(SCanData* pCanDataTrg, const SCanData* pCanDataSrc);

/*!	This thread-safe function adds a velocity element and the corresponding time value to the queue.
*	/param[inout] pCanData pointer to the can data structure
*	/param[in] velocity velocity value
*	/param[in] time		time value
*/
void addVelocityToQueue(SCanData* pCanData, double velocity, double time);

/*!	This thread-safe function adds a yaw element and the corresponding time value to the queue.
*	/param[inout] pCanData pointer to the can data structure
*	/param[in] yaw		yaw value
*	/param[in] time		time value
*/
void addYawRateToQueue(SCanData* pCanData, double yaw, double time);

/*!	This function sets the blinker value in the can data structure.
*	/param[inout] pCanData pointer to the can data structure
*	/param[in] blinker	blinker value
*/
void setBlinker(SCanData* pCanData, int blinker);

/*!	This function sets the brake value in the can data structure.
*	/param[inout] pCanData pointer to the can data structure
*	/param[in]	  blinker	brake value
*/
void setBrake(SCanData* pCanData, int brake);

/*!	This function sets the light sensor value in the can data structure.
*	/param[inout] pCanData		pointer to the can data structure.
*	/param[in]    lightSensor	light sensor value.
*/
void setLightSensor(SCanData* pCanData, unsigned char lightSensor);

/*!	This function sets the data from the camera to the can data structure.
*	/param[inout]	pCanData	 pointer to the can data structure.
*	/param[in]		time		 the time value from the computer clock
*	/param[in]		frameCounter the frame counter value from the camera
*	/param[in]		frameIndex	 the frame index
*/
void setImageTime(SCanData* pCanData, double time, int frameCounter, int frameIndex);

/*!	This function sets the data from the camera to the can data structure.
*	/param[inout]	pCanData	 pointer to the can data structure.
*	/param[in]		low_beam	 low beam is on
*	/param[in]		high_beam	 high beam is on
*/
void setBeamStatus(SCanData* pCanData, int low_beam, int high_beam);

/*!	This thread-save function removes a value pair from the velocity queue in a first-in first-out order.
*	/param[inout] pCanData	a pointer to the can data structure
*	/param[out]	velocity	a pointer to the memory where the velocity value should be saved.
*	/param[out] time		a pointer to the memory where the time value should be saved.
*/
void removeVelocityPairFromQueue(SCanData* pCanData, double* velocity, double* time);

/*!	This thread-save function removes a value pair from the yaw queue in a first-in first-out order.
*	/param[inout] pCanData	a pointer to the can data structure
*	/param[out]	yaw			a pointer to the memory where the yaw value should be saved.
*	/param[out] time		a pointer to the memory where the time value should be saved.
*/
void removeYawPairFromQueue(SCanData* pCanData, double* yaw, double* time);

/*!	This function starts a thread-save read iterator for the queue.
*	/param[in]  pCanData	a pointer to the can data structure
*	/param[out]	velocity	a pointer to the memory where the first velocity value should be saved.
*	/param[out] yawRate		a pointer to the memory where the first yawRate value should be saved.
*	/param[out] time		a pointer to the memory where the first time value should be saved.
*/
void startReadingSampleHold(SCanData* pCanData, double* velocity, double* yawRate, double startTime);

/*!	This function continues the thread-save read access to the queue.
*	/param[in]  pCanData	a pointer to the can data structure
*	/param[out]	velocity	a pointer to the memory where the next velocity value should be saved.
*	/param[out] yawRate		a pointer to the memory where the next yawRate value should be saved.
*	/param[out] time		a pointer to the memory where the next time value should be saved.
*/
unsigned int readNextValuesSampleHold(SCanData* pCanData, double* vel, double* yaw, double* time, double endTime);

/* add raw CAN message to the array */
//void addRawCanMessage(SCanData* pCanData, VideoCanStream::CANmessage const* message);

/*! This function prints the contents to stdout
*	/param[in]	pCanData	a pointer to the can data structure
*/
void printContent(SCanData const* pCanData);

/*! This function copies the can data to a RAWfile
*	/param[in]	pCanData	a pointer to the can data structure
*/



//};


#ifdef   __cplusplus   
}  
#endif

#endif // !defined(AFX_CANDATA_H__3CD7540D_597B_4C59_9CDD_18CEEF52CD45__INCLUDED_)
