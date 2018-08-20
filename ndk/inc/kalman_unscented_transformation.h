#ifndef _UNSCENTED_TRANSFORMATION_H
#define _UNSCENTED_TRANSFORMATION_H


#define TRANS_SCALE 0.1f
#define STD_ALPHA   0.4f//0.5f//0.1f
#define STD_BETA    2.0f
#define STD_KAPPA   0.0f



#ifdef   __cplusplus   
extern   "C"   
{   
#endif   


float calculateLambda(short stateDim, float alpha, float kappa);

/*!	Generates the mean value from a set of sigma points. (Have a look at the unscented filter algorithm)
	@param	sigmaPointArray	source sigma point array
	@param  mean			pointer to the resulting mean vector
	@param	sigmaPointDim   dimension of the resulting sigma points (can be less then the input state dim)
	@param  stateDim	    dimension of the source stateDimension
*/
void generateSigmaPoints(const float** mean, const float** covariance, float** temp, float lambda, short stateDim, float** sigmaPointArray);


/*!	Generates the mean value from a set of sigma points. (Have a look at the unscented filter algorithm)
	@param	sigmaPointArray	source sigma point array
	@param  mean			pointer to the resulting mean vector
	@param	sigmaPointDim   dimension of the resulting sigma points (can be less then the input state dim)
	@param  stateDim	    dimension of the source stateDimension
*/
void generateMeanFromSigmaPoints(const float** sigmaPointArray, float** mean, float lambda, short stateDim, short sigmaPointDim);


void generateCovFromSigmaPoints(const float** sigmaPointArray1, const float** mean1, const float** sigmaPointArray2, const float** mean2, float lambda, float alpha, float beta, short stateDim, short sigmaPointDim1, short sigmaPointDim2, float** cov);


int transferStateSigmaPointsToGroundplane(const float** srcSigmaPointArray, float **resSigmaPointArray, short stateDim);


void useSigmaPointsToCalculateAdditionalCov(float** mean, float** cov, float** temp, float** sigmaPoints, float x, float y, float z, float sqrDevX, float sqrDevY, float sqrDevZ, float zOffset);

void transferTsrSigmaPointsToImagePlane(float** sigmaPoints, float** resSigmaPoints, float signSize, short arraySize);


#ifdef   __cplusplus   
}  
#endif 


#endif  _UNSCENTED_TRANSFORMATION_H