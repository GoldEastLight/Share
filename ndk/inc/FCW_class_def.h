
// class_def.h

#ifndef FCW_class_def
#define FCW_class_def

//#include "LDW.h"
#include "FCW.h"

//! error returns given by FEAT
#define CLASS_OK 1
#define CLASS_ERROR								400
#define CLASS_ERROR_WAVELET_MODEL_ID_UNKNOWN    401
#define CLASS_ERROR_PROBABILITY0				402
#define CLASS_ERROR_CANNOT_LOAD_SVM_MODEL		403


#define WIDTH_WINDOW 64
#define HEIGHT_WINDOW 64
#define SIZE_WINDOW 4096

#ifdef   __cplusplus   
extern   "C"   
{   
#endif

/*
//----------------
typedef struct RANGE_STRUCT1 
{
	float		*pfSVM_min;		// stores the min values for the x-scaling
	float  	    *pfSVM_max;		// stores the max values for the x-scaling
	float		lower;			// lower bound for x-scaling
	float		upper;			// upper bound for x-scaling

	float		y_max;						// max scale factor for y-scaling
	float		y_min;						// min scale factor for y-scaling
	float		y_lower,y_upper;			// lower/upper factor for y-scaling
	int			y_scaling;				// =1 if y-scaling is required

}RANGE_STRUCT;
typedef struct _RANGE_STRUCT feat_range;


//-------------------
struct feature_node_Linear_SVMTag
{
	int index;
	double value;
};
typedef struct feature_node_Linear_SVMTag feature_node_Linear_SVM;

struct problem_Linear_SVMTag
{
	int l, n;
	int *y;
	struct feature_node **x;
	double bias;            // < 0 if no bias term   
};
typedef struct problem_Linear_SVMTag problem_Linear_SVM;

enum { L2R_LR, L2R_L2LOSS_SVC_DUAL, L2R_L2LOSS_SVC, L2R_L1LOSS_SVC_DUAL, MCSVM_CS, L1R_L2LOSS_SVC, L1R_LR, L2R_LR_DUAL }; // solver_type 

struct Parameter_Linear_SVMTag
{
	int solver_type;

	// these are for training only 
	double eps;	        // stopping criteria 
	double C;
	int nr_weight;
	int *weight_label;
	double* weight;
};
typedef struct Parameter_Linear_SVMTag Parameter_Linear_SVM;

struct Model_Linear_SVMTag
{
	Parameter_Linear_SVM param;
	int nr_class;		// number of classes 
	int nr_feature;
	double *w;
	int *label;		// label of each class 
	double bias;
};
typedef struct Model_Linear_SVMTag Model_Linear_SVM;

*/
//---------- carclassify -----------------
struct   _svm_mode_dsp 
{
    float gamma;
	int total_sv;
	float rho;
	int nr_sv[2];
	
};

typedef struct _svm_mode_dsp svm_mode_dsp;

//------eoh-----
void EohClassify(unsigned char* img, int* predict_value);

//----nolinear svm---
int classify_SVM_dsp(int* feature);

//-------------wavelet--------------------- 

void WaveletClassify(unsigned char *img, int* predict_value);


//---------edge---------------
void EdgeClassify(unsigned char* img, int* predict_value);

//----- carclassify ------------
void GetNormImage(unsigned char *pImage, unsigned char *pImgNorm, CarBodyArea carInfo);
void HistogramEqualization(unsigned char* pScaleImage, unsigned char* pHistEquImage);
void VerifyCarsBasedSVM(CarBodyArea *pHgCarList, int nCars,Bool bTrack);

  
#ifdef   __cplusplus   
}  
#endif


#endif
