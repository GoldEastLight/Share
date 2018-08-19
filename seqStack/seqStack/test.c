#include "SeqStack.h"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int a[10];
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		a[i] = i+1;
	}
	SeqStack* stack = SeqStack_Create(20);
	for (i = 0; i < 10; i++)
	{
		SeqStack_Push(stack,&a[i]);
	}
	printf("len:%d\n", SeqStack_Size(stack));
	printf("capacity:%d\n", SeqStack_Capacity(stack));

	printf("top:%d\n", *((int *)SeqStack_Top(stack)));

	while (SeqStack_Size(stack) > 0)
	{
		printf("%d\n", *((int *)SeqStack_Pop(stack)));
	}
	SeqStack_Destroy(stack);

	printf("Hello\n");
	system("pause");
}