
#ifndef _LIST_LIB
#define _LIST_LIB

#include <assert.h>
#include <string.h>

/* This structure contains an abstract vector. It is implemented using an array of pointers to the array.
*  The array is changed by changing the array of pointers instead of inserting elements to the element array. This saves time and space for large elements.
*  For these operations, smart insert and remove templates are available.
*/
#define LIST_DEFINE(LISTNAME, DATATYPE, LENGTH) \
	typedef struct LISTNAME{ \
		DATATYPE elements[(LENGTH)]; \
		DATATYPE *pointers[(LENGTH)]; \
		unsigned short i; \
		unsigned short length; \
		static const unsigned short maxLength=(LENGTH); \
	}S##LISTNAME


/* This function inserts an element into an array at the specified position and shifts all subsequent elements forward by one
*  ARRAY array variable
*  ELEMENT Pointer to the newly inserted element that is returned from the template.
*  POS the position, where the element should be inserted
*  LENGTH the length of the array. The variable is modified after the insertion. You can not insert elements into an array, that is full.
*/
#define ARRAY_INSERT_ELEMENT(ARRAY, ELEMENT, POS, LENGTH) \
	{ \
	assert(((POS)>=0) && ((POS)<=(LENGTH)) && (sizeof((ARRAY))/sizeof((ARRAY[0]))<(LENGTH))); \
	if ((POS)<(LENGTH)) \
	memmove((ARRAY)+(POS)+1, (ARRAY)+(POS), (((LENGTH)-(POS))*sizeof((ARRAY)[0])) ); \
	(ARRAY)[(POS)]=(ELEMENT); \
	++(LENGTH); \
	}

/* This function removes an element from an array at the specified position and shifts all subsequent elements back by one
*  ARRAY array variable
*  POS the position, where the element should be inserted
*  LENGTH the length of the array. The variable is modified after the removal.
*/
#define ARRAY_REMOVE_ELEMENT(ARRAY, POS, LENGTH) \
	{ \
	assert(((POS)>=0) && ((POS)<(LENGTH)) && (sizeof((ARRAY))/sizeof((ARRAY[0]))<=(LENGTH)) && ((LENGTH)>0)); \
	if ((POS)<(LENGTH)-1) \
	memmove((ARRAY)+(POS), (ARRAY)+(POS)+1, (((LENGTH)-1-(POS))*sizeof((ARRAY)[0])) ); \
	--(LENGTH); \
	}

#define LIST_CREATE(PLIST, LISTNAME) \
	{ \
	S##LISTNAME *PLIST=(S##LISTNAME*)malloc(sizeof(S##LISTNAME)); \
	for ((PLIST)->i=0; (PLIST)->i<(PLIST)->maxLength; ((PLIST)->i)++) \
	{ \
		(PLIST)->pointers[PLIST->i]=(PLIST)->elements+i; \
	} \
	(PLIST)->length=0; \
	}

/* This function inits a list structure. All pointers are linked to the element structures and the length is initialized to zero.
*	PLIST pointer to the list structure.
*/
#define LIST_INIT(PLIST) \
	{ \
	for ((PLIST)->i=0; (PLIST)->i<(PLIST)->maxLength; ((PLIST)->i)++) \
	{ \
		(PLIST)->pointers[(PLIST)->i]=(PLIST)->elements+(PLIST)->i; \
	} \
	PLIST->length=0; \
	} 

#define LIST_DELETE(PLIST) \
	free((PLIST))

/* This template swaps two elements.
   PLIST pointer to the list structure
   PELEMENT empty pointer (has to have the type of an element)
   POS1 first position to swap
   POS2 second position to swap
*/
#define LIST_SWAP(PLIST, PELEMENT, POS1, POS2)\
	{ \
	(PELEMENT)=(PLIST)->pointers[(POS1)]; \
	(PLIST)->pointers[(POS1)]=(PLIST)->pointers[(POS2)]; \
	(PLIST)->pointers[(POS2)]=(PELEMENT); \
	}

/* This template inserts an element to the list by adding a pointer at the given position and shifting all subsequent pointers forward by one.
	PLIST pointer to the list structure
	PELEMENT points to the element that was inserted
	POS position, where the element should be removed
*/
#define LIST_INSERT_ELEMENT(PLIST, PELEMENT, POS) \
	{ \
	assert(((POS)>=0) && ((POS)<=(PLIST)->length)); \
	if((PLIST)->length<(PLIST)->maxLength) \
	{ \
	(PELEMENT)=(PLIST)->pointers[(PLIST)->length]; \
	if ((POS)<(PLIST)->length) \
	memmove((PLIST)->pointers+(POS)+1, (PLIST)->pointers+(POS), ((PLIST)->length-(POS))*sizeof(PELEMENT)); \
	(PLIST)->pointers[POS]=(PELEMENT); \
	(PLIST)->length++; \
	} \
	}

/*  This template removes an element from the list by removing the pointer from the pointer array and shifting all subsequent pointers.
	The element is not physically removed
	PLIST pointer to the list structure
	PELEMENT points to the element that was removed
	POS position, where the element should be removed
*/
#define LIST_REMOVE_ELEMENT(PLIST, PELEMENT, POS) \
	{ \
	assert(((POS)<(PLIST)->length) && ((POS)>=0)); \
	(PELEMENT)=PLIST->pointers[(POS)]; \
	if ((POS)<(PLIST)->length-1) \
	memmove((PLIST)->pointers+(POS), (PLIST)->pointers+(POS)+1, ((PLIST)->length-1-(POS))*sizeof((PELEMENT))); \
	(PLIST)->length--; \
	(PLIST)->pointers[(PLIST)->length]=(PELEMENT); \
	} 

#define LIST_GET_ELEMENT(PLIST, PELEMENT, POS) \
	{ \
	assert(((POS)>=0) && ((POS)<(PLIST)->maxLength)); \
	(PELEMENT)=(PLIST)->pointers[(POS)]; \
	}

#define LIST_GET_LENGTH(PLIST) \
	((PLIST)->length)

#define LIST_GET_MAX_LENGTH(PLIST) \
	((PLIST)->maxLength)

/*
#define QUEUE_DEFINE(QUEUENAME, DATATYPE, LENGTH) \
	typedef struct QUEUENAME{ \
		DATATYPE elements[(LENGTH)]; \
		DATATYPE *firstElem; \
		DATATYPE *lastElem; \
		unsigned short length; \
		static const unsigned short maxLength=(LENGTH); \
	}S##LISTNAME	

#define QUEUE_INIT(PQUEUE) \
	{ \
		PQUEUE->firstElem=PQUEUE->elements; \
		PQUEUE->lastElem=PQUEUE->elements; \
		PQUEUE->length=0; \
	} 
	
#define QUEUE_APPEND_ELEMENT(PQUEUE, PELEMENT) \
	{ \
		PQUEUE->lastElem++; \
		(PQUEUE->lastElem==PQUEUE->elements+PQUEUE->maxLength-1) ? PQUEUE->lastElem=PQUEUE->elements : PQUEUE->lastElem++;\
		if (PQUEUE->length==PQUEUE->maxLength)\
		{\
			(PQUEUE->firstElem==PQUEUE->elements+PQUEUE->maxLength-1) ? (PQUEUE->firstElem=PQUEUE->elements) : (PQUEUE->firstElem++);\
		}\
		else\
		{\
			PQUEUE->length++;\
		}\
	}

#define QUEUE_REMOVE_ELEMENT(PQUEUE) \
	{ \
		if (PQUEUE->length>0) \
		{ \
			(PQUEUE->lastElem==PQUEUE->elements) ? (PQUEUE->lastElem=PQUEUE->elements+PQUEUE->maxLength-1) : PQUEUE->lastElem--; \
			PQUEUE->length--; \
		} \
	} 

#define QUEUE_READ_ELEMENT(PQUEUE, PELEMENT, POS) \
	{ \
		PELEMENT=PQUEUE->firstElem+POS; \
		if (PELEMENT>=PQUEUE->elements+PQUEUE->maxLength) \
			PELEMENT=PELEMENT-PQUEUE->maxLength; \
	} 
*/
#endif _LIST_LIB







