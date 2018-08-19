#include "SeqStack.h"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

SeqStack* SeqStack_Create(int Capacity)
{
	return SeqList_Create(Capacity);
}

void SeqStack_Destroy(SeqStack* stack)
{
	SeqList_Destroy(stack);
}

void SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
}

int SeqStack_Push(SeqStack* stack, void* item)
{
	return SeqList_Insert(stack,item,SeqList_Length(stack));
}

void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delete(stack, SeqList_Length(stack) -1);
}

void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}

int SeqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);
}
