#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linkstack.h"
void main()
{
	LinkStack* stack = NULL;
	int arr[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i] = i + 1;
	}
	stack = LinkStack_Create(10);
	for (int i = 0; i < 5; i++)
	{
		LinkStack_Push(stack, &arr[i]);
	}

	printf("size:%d\n", LinkStack_Size(stack));
	printf("top:%d\n", *((int *)LinkStack_Top(stack)));

	for (int i = 0; i < 5; i++)
	{
		int tmp = *( (int *)LinkStack_Pop(stack));
		printf("%d\n", tmp);
	}
	LinkStack_Destroy(stack);

	/*LinkStack* LinkStack_Create();

	void LinkStack_Destroy(LinkStack* stack);

	void LinkStack_Clear(LinkStack* stack);

	int LinkStack_Push(LinkStack* stack, void* item);

	void* LinkStack_Pop(LinkStack* stack);

	void* LinkStack_Top(LinkStack* stack);

	int LinkStack_Size(LinkStack* stack);*/
	printf("hello\n");
	system("pause");
}