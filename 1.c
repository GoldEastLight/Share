#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linklist.h"
typedef struct _Teather 
{
	LinkListNode node;
	char name[32];
	int age;
}Teather;

void main()
{
	Teather t1, t2, t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	LinkList*list = NULL;

	list =  LinkList_Create();

	int ret = 0;
	ret = LinkList_Insert(list, (LinkListNode*)&t1, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t2, 0);
	ret = LinkList_Insert(list, (LinkListNode*)&t3, 0);

	for (int i = 0; i < LinkList_Length(list); i++)
	{
		
		Teather* tmp = (Teather*)LinkList_Get(list, i);
		if (tmp != NULL)
		{
			printf("age:%d\n", tmp->age);
		}
	}
	for (int i = 0; i < LinkList_Length(list); i++)
	{
		Teather* tem = (Teather*) LinkList_Delete( list,0);
		if (tem == NULL)
		{
			return;
		}
		printf("age:%d\n");
	}

	LinkList_Destroy(list);

	/*void LinkList_Clear(LinkList* list);

	int LinkList_Length(LinkList* list);

	int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

	LinkListNode* LinkList_Get(LinkList* list, int pos);

	LinkListNode* LinkList_Delete(LinkList* list, int pos);*/
	printf("Hello\n");
	system("pause");
}